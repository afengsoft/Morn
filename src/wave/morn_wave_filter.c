/*
Copyright (C) 2019  Jing Lee
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morn_wave.h"

void mWaveConvolve(MWave *src,float core[],int core_size,MWave *dst)
{
    int i,j,k;
    int cn;
    int l;
    MWave *p;
    
    mException((INVALID_WAVE(src))||(INVALID_POINTER(core))||(core_size <= 0),EXIT,"invalid input");
    p = dst;
    if(INVALID_POINTER(dst))
    {
        dst = mWaveCreate(src->channel,src->size,NULL);
        dst->info = src->info;
    }
    else
    {
        mWaveRedefine(dst,src->size,src->channel,dst->data);
        dst->info = src->info;
    }
    
    l = core_size>>1;
    for(cn=0;cn<src->channel;cn++)
    {
        for(j=0;j<l;j++)
        {
            dst->data[cn][j] = 0.0;
            for(i=j-l,k=0;k<core_size;i++,k++)
                dst->data[cn][j] = src->data[cn][j] + src->data[cn][((i<0)?0:i)]*core[k];
        }
        for(j=l;j<(src->size+l-core_size);j++)
        {
            dst->data[cn][j] = 0.0;
            for(i=j-l,k=0;k<core_size;i++,k++)
                dst->data[cn][j] = dst->data[cn][j] + src->data[cn][i]*core[k];
        }
        for(;j<src->size;j++)
        {
            dst->data[cn][j] = 0.0;
            for(i=j-l,k=0;k<core_size;i++,k++)
                dst->data[cn][j] = src->data[cn][j] + src->data[cn][((i>=src->size)?(src->size-1):i)]*core[k];
        }
    }
    
    if(p!=dst)
    {
        mWaveExchange(src,dst);
        mWaveRelease(dst);
    }    
}

void mWaveDeBackground(MWave *src,MWave *dst,int win_length)
{
    int i,cn;
    int sum;
    int l;
    
    MWave *p;
   
    mException((INVALID_WAVE(src))||(win_length <= 1),EXIT,"invalid input");
    p = dst;
    if(INVALID_POINTER(dst))
    {
        dst = mWaveCreate(src->channel,src->size,NULL);
        dst->info = src->info;
    }
    else
    {
        mWaveRedefine(dst,src->size,src->channel,dst->data);
        dst->info = src->info;
    }
    
    l = win_length>>1;
    win_length = (l<<1)+1;
    for(cn=0;cn<src->channel;cn++)
    {
        sum = src->data[cn][0]*l;
        for(i=0;i<=l;i++)
            sum = sum + src->data[cn][l];
        
        for(i=0;i<l;i++)
        {
            dst->data[cn][i] = src->data[cn][i] - (sum/win_length);
            sum = sum - src->data[cn][0] + src->data[cn][i+l+1];
        }
        for(;i<src->size -l-1;i++)
        {
            dst->data[cn][i] = src->data[cn][i] - (sum/win_length);
            sum = sum - src->data[cn][i-l] + src->data[cn][i+l+1];
        }
        for(;i<src->size;i++)
        {
            dst->data[cn][i] = src->data[cn][i] - (sum/win_length);
            sum = sum - src->data[cn][i-l] + src->data[cn][src->size-1];
        }
    }
    
    if(p!=dst)
    {
        mWaveExchange(src,dst);
        mWaveRelease(dst);
    }
}
