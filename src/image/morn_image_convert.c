/*
Copyright (C) 2019  JingWeiZhangHuai
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "morn_image.h"

short v_to_r[256] = {-180 ,-178 ,-177 ,-175 ,-174 ,-173 ,-171 ,-170 ,-168 ,-167 ,-166 ,-164 ,-163 ,-161 ,-160 ,-159 ,-157 ,-156 ,-154 ,-153 ,-152 ,-150 ,-149 ,-147 ,-146 ,-145 ,-143 ,-142 ,-140 ,-139 ,-137 ,-136 ,-135 ,-133 ,-132 ,-130 ,-129 ,-128 ,-126 ,-125 ,-123 ,-122 ,-121 ,-119 ,-118 ,-116 ,-115 ,-114 ,-112 ,-111 ,-109 ,-108 ,-107 ,-105 ,-104 ,-102 ,-101 ,-100 ,-98 ,-97 ,-95 ,-94 ,-93 ,-91 ,-90 ,-88 ,-87 ,-86 ,-84 ,-83 ,-81 ,-80 ,-79 ,-77 ,-76 ,-74 ,-73 ,-72 ,-70 ,-69 ,-67 ,-66 ,-65 ,-63 ,-62 ,-60 ,-59 ,-58 ,-56 ,-55 ,-53 ,-52 ,-51 ,-49 ,-48 ,-46 ,-45 ,-43 ,-42 ,-41 ,-39 ,-38 ,-36 ,-35 ,-34 ,-32 ,-31 ,-29 ,-28 ,-27 ,-25 ,-24 ,-22 ,-21 ,-20 ,-18 ,-17 ,-15 ,-14 ,-13 ,-11 ,-10 ,-8 ,-7 ,-6 ,-4 ,-3 ,-1 ,0 ,1 ,3 ,4 ,6 ,7 ,8 ,10 ,11 ,13 ,14 ,15 ,17 ,18 ,20 ,21 ,22 ,24 ,25 ,27 ,28 ,29 ,31 ,32 ,34 ,35 ,36 ,38 ,39 ,41 ,42 ,43 ,45 ,46 ,48 ,49 ,51 ,52 ,53 ,55 ,56 ,58 ,59 ,60 ,62 ,63 ,65 ,66 ,67 ,69 ,70 ,72 ,73 ,74 ,76 ,77 ,79 ,80 ,81 ,83 ,84 ,86 ,87 ,88 ,90 ,91 ,93 ,94 ,95 ,97 ,98 ,100 ,101 ,102 ,104 ,105 ,107 ,108 ,109 ,111 ,112 ,114 ,115 ,116 ,118 ,119 ,121 ,122 ,123 ,125 ,126 ,128 ,129 ,130 ,132 ,133 ,135 ,136 ,137 ,139 ,140 ,142 ,143 ,145 ,146 ,147 ,149 ,150 ,152 ,153 ,154 ,156 ,157 ,159 ,160 ,161 ,163 ,164 ,166 ,167 ,168 ,170 ,171 ,173 ,174 ,175 ,177 ,178};
short u_to_g[256] = {-44 ,-44 ,-43 ,-43 ,-43 ,-42 ,-42 ,-42 ,-41 ,-41 ,-40 ,-40 ,-40 ,-39 ,-39 ,-39 ,-38 ,-38 ,-38 ,-37 ,-37 ,-37 ,-36 ,-36 ,-36 ,-35 ,-35 ,-35 ,-34 ,-34 ,-34 ,-33 ,-33 ,-33 ,-32 ,-32 ,-32 ,-31 ,-31 ,-31 ,-30 ,-30 ,-29 ,-29 ,-29 ,-28 ,-28 ,-28 ,-27 ,-27 ,-27 ,-26 ,-26 ,-26 ,-25 ,-25 ,-25 ,-24 ,-24 ,-24 ,-23 ,-23 ,-23 ,-22 ,-22 ,-22 ,-21 ,-21 ,-21 ,-20 ,-20 ,-20 ,-19 ,-19 ,-19 ,-18 ,-18 ,-17 ,-17 ,-17 ,-16 ,-16 ,-16 ,-15 ,-15 ,-15 ,-14 ,-14 ,-14 ,-13 ,-13 ,-13 ,-12 ,-12 ,-12 ,-11 ,-11 ,-11 ,-10 ,-10 ,-10 ,-9 ,-9 ,-9 ,-8 ,-8 ,-8 ,-7 ,-7 ,-7 ,-6 ,-6 ,-5 ,-5 ,-5 ,-4 ,-4 ,-4 ,-3 ,-3 ,-3 ,-2 ,-2 ,-2 ,-1 ,-1 ,-1 ,0 ,0 ,0 ,1 ,1 ,1 ,2 ,2 ,2 ,3 ,3 ,3 ,4 ,4 ,4 ,5 ,5 ,5 ,6 ,6 ,7 ,7 ,7 ,8 ,8 ,8 ,9 ,9 ,9 ,10 ,10 ,10 ,11 ,11 ,11 ,12 ,12 ,12 ,13 ,13 ,13 ,14 ,14 ,14 ,15 ,15 ,15 ,16 ,16 ,16 ,17 ,17 ,17 ,18 ,18 ,19 ,19 ,19 ,20 ,20 ,20 ,21 ,21 ,21 ,22 ,22 ,22 ,23 ,23 ,23 ,24 ,24 ,24 ,25 ,25 ,25 ,26 ,26 ,26 ,27 ,27 ,27 ,28 ,28 ,28 ,29 ,29 ,29 ,30 ,30 ,31 ,31 ,31 ,32 ,32 ,32 ,33 ,33 ,33 ,34 ,34 ,34 ,35 ,35 ,35 ,36 ,36 ,36 ,37 ,37 ,37 ,38 ,38 ,38 ,39 ,39 ,39 ,40 ,40 ,40 ,41 ,41 ,42 ,42 ,42 ,43 ,43 ,43 ,44};
short v_to_g[256] = {-91 ,-91 ,-90 ,-89 ,-89 ,-88 ,-87 ,-86 ,-86 ,-85 ,-84 ,-84 ,-83 ,-82 ,-81 ,-81 ,-80 ,-79 ,-79 ,-78 ,-77 ,-76 ,-76 ,-75 ,-74 ,-74 ,-73 ,-72 ,-71 ,-71 ,-70 ,-69 ,-69 ,-68 ,-67 ,-66 ,-66 ,-65 ,-64 ,-64 ,-63 ,-62 ,-61 ,-61 ,-60 ,-59 ,-59 ,-58 ,-57 ,-56 ,-56 ,-55 ,-54 ,-54 ,-53 ,-52 ,-51 ,-51 ,-50 ,-49 ,-49 ,-48 ,-47 ,-46 ,-46 ,-45 ,-44 ,-44 ,-43 ,-42 ,-41 ,-41 ,-40 ,-39 ,-39 ,-38 ,-37 ,-36 ,-36 ,-35 ,-34 ,-34 ,-33 ,-32 ,-31 ,-31 ,-30 ,-29 ,-29 ,-28 ,-27 ,-26 ,-26 ,-25 ,-24 ,-24 ,-23 ,-22 ,-21 ,-21 ,-20 ,-19 ,-19 ,-18 ,-17 ,-16 ,-16 ,-15 ,-14 ,-14 ,-13 ,-12 ,-11 ,-11 ,-10 ,-9 ,-9 ,-8 ,-7 ,-6 ,-6 ,-5 ,-4 ,-4 ,-3 ,-2 ,-1 ,-1 ,0 ,1 ,1 ,2 ,3 ,4 ,4 ,5 ,6 ,6 ,7 ,8 ,9 ,9 ,10 ,11 ,11 ,12 ,13 ,14 ,14 ,15 ,16 ,16 ,17 ,18 ,19 ,19 ,20 ,21 ,21 ,22 ,23 ,24 ,24 ,25 ,26 ,26 ,27 ,28 ,29 ,29 ,30 ,31 ,31 ,32 ,33 ,34 ,34 ,35 ,36 ,36 ,37 ,38 ,39 ,39 ,40 ,41 ,41 ,42 ,43 ,44 ,44 ,45 ,46 ,46 ,47 ,48 ,49 ,49 ,50 ,51 ,51 ,52 ,53 ,54 ,54 ,55 ,56 ,56 ,57 ,58 ,59 ,59 ,60 ,61 ,61 ,62 ,63 ,64 ,64 ,65 ,66 ,66 ,67 ,68 ,69 ,69 ,70 ,71 ,71 ,72 ,73 ,74 ,74 ,75 ,76 ,76 ,77 ,78 ,79 ,79 ,80 ,81 ,81 ,82 ,83 ,84 ,84 ,85 ,86 ,86 ,87 ,88 ,89 ,89 ,90 ,91};
short u_to_b[256] = {-227 ,-225 ,-223 ,-221 ,-219 ,-218 ,-216 ,-214 ,-212 ,-211 ,-209 ,-207 ,-205 ,-204 ,-202 ,-200 ,-198 ,-196 ,-195 ,-193 ,-191 ,-189 ,-188 ,-186 ,-184 ,-182 ,-181 ,-179 ,-177 ,-175 ,-173 ,-172 ,-170 ,-168 ,-166 ,-165 ,-163 ,-161 ,-159 ,-158 ,-156 ,-154 ,-152 ,-150 ,-149 ,-147 ,-145 ,-143 ,-142 ,-140 ,-138 ,-136 ,-135 ,-133 ,-131 ,-129 ,-127 ,-126 ,-124 ,-122 ,-120 ,-119 ,-117 ,-115 ,-113 ,-112 ,-110 ,-108 ,-106 ,-104 ,-103 ,-101 ,-99 ,-97 ,-96 ,-94 ,-92 ,-90 ,-89 ,-87 ,-85 ,-83 ,-81 ,-80 ,-78 ,-76 ,-74 ,-73 ,-71 ,-69 ,-67 ,-65 ,-64 ,-62 ,-60 ,-58 ,-57 ,-55 ,-53 ,-51 ,-50 ,-48 ,-46 ,-44 ,-42 ,-41 ,-39 ,-37 ,-35 ,-34 ,-32 ,-30 ,-28 ,-27 ,-25 ,-23 ,-21 ,-19 ,-18 ,-16 ,-14 ,-12 ,-11 ,-9 ,-7 ,-5 ,-4 ,-2 ,0 ,2 ,4 ,5 ,7 ,9 ,11 ,12 ,14 ,16 ,18 ,19 ,21 ,23 ,25 ,27 ,28 ,30 ,32 ,34 ,35 ,37 ,39 ,41 ,42 ,44 ,46 ,48 ,50 ,51 ,53 ,55 ,57 ,58 ,60 ,62 ,64 ,65 ,67 ,69 ,71 ,73 ,74 ,76 ,78 ,80 ,81 ,83 ,85 ,87 ,89 ,90 ,92 ,94 ,96 ,97 ,99 ,101 ,103 ,104 ,106 ,108 ,110 ,112 ,113 ,115 ,117 ,119 ,120 ,122 ,124 ,126 ,127 ,129 ,131 ,133 ,135 ,136 ,138 ,140 ,142 ,143 ,145 ,147 ,149 ,150 ,152 ,154 ,156 ,158 ,159 ,161 ,163 ,165 ,166 ,168 ,170 ,172 ,173 ,175 ,177 ,179 ,181 ,182 ,184 ,186 ,188 ,189 ,191 ,193 ,195 ,196 ,198 ,200 ,202 ,204 ,205 ,207 ,209 ,211 ,212 ,214 ,216 ,218 ,219 ,221 ,223 ,225};

unsigned char r_to_y[256] = {0 ,0 ,1 ,1 ,1 ,1 ,2 ,2 ,2 ,3 ,3 ,3 ,4 ,4 ,4 ,4 ,5 ,5 ,5 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,8 ,8 ,8 ,9 ,9 ,9 ,10 ,10 ,10 ,10 ,11 ,11 ,11 ,12 ,12 ,12 ,13 ,13 ,13 ,13 ,14 ,14 ,14 ,15 ,15 ,15 ,16 ,16 ,16 ,16 ,17 ,17 ,17 ,18 ,18 ,18 ,19 ,19 ,19 ,19 ,20 ,20 ,20 ,21 ,21 ,21 ,22 ,22 ,22 ,22 ,23 ,23 ,23 ,24 ,24 ,24 ,25 ,25 ,25 ,25 ,26 ,26 ,26 ,27 ,27 ,27 ,28 ,28 ,28 ,28 ,29 ,29 ,29 ,30 ,30 ,30 ,30 ,31 ,31 ,31 ,32 ,32 ,32 ,33 ,33 ,33 ,33 ,34 ,34 ,34 ,35 ,35 ,35 ,36 ,36 ,36 ,36 ,37 ,37 ,37 ,38 ,38 ,38 ,39 ,39 ,39 ,39 ,40 ,40 ,40 ,41 ,41 ,41 ,42 ,42 ,42 ,42 ,43 ,43 ,43 ,44 ,44 ,44 ,45 ,45 ,45 ,45 ,46 ,46 ,46 ,47 ,47 ,47 ,48 ,48 ,48 ,48 ,49 ,49 ,49 ,50 ,50 ,50 ,51 ,51 ,51 ,51 ,52 ,52 ,52 ,53 ,53 ,53 ,54 ,54 ,54 ,54 ,55 ,55 ,55 ,56 ,56 ,56 ,57 ,57 ,57 ,57 ,58 ,58 ,58 ,59 ,59 ,59 ,60 ,60 ,60 ,60 ,61 ,61 ,61 ,62 ,62 ,62 ,62 ,63 ,63 ,63 ,64 ,64 ,64 ,65 ,65 ,65 ,65 ,66 ,66 ,66 ,67 ,67 ,67 ,68 ,68 ,68 ,68 ,69 ,69 ,69 ,70 ,70 ,70 ,71 ,71 ,71 ,71 ,72 ,72 ,72 ,73 ,73 ,73 ,74 ,74 ,74 ,74 ,75 ,75 ,75 ,76 ,76 ,76};
unsigned char g_to_y[256] = {0 ,1 ,1 ,2 ,2 ,3 ,4 ,4 ,5 ,5 ,6 ,6 ,7 ,8 ,8 ,9 ,9 ,10 ,11 ,11 ,12 ,12 ,13 ,14 ,14 ,15 ,15 ,16 ,16 ,17 ,18 ,18 ,19 ,19 ,20 ,21 ,21 ,22 ,22 ,23 ,23 ,24 ,25 ,25 ,26 ,26 ,27 ,28 ,28 ,29 ,29 ,30 ,31 ,31 ,32 ,32 ,33 ,33 ,34 ,35 ,35 ,36 ,36 ,37 ,38 ,38 ,39 ,39 ,40 ,41 ,41 ,42 ,42 ,43 ,43 ,44 ,45 ,45 ,46 ,46 ,47 ,48 ,48 ,49 ,49 ,50 ,50 ,51 ,52 ,52 ,53 ,53 ,54 ,55 ,55 ,56 ,56 ,57 ,58 ,58 ,59 ,59 ,60 ,60 ,61 ,62 ,62 ,63 ,63 ,64 ,65 ,65 ,66 ,66 ,67 ,68 ,68 ,69 ,69 ,70 ,70 ,71 ,72 ,72 ,73 ,73 ,74 ,75 ,75 ,76 ,76 ,77 ,77 ,78 ,79 ,79 ,80 ,80 ,81 ,82 ,82 ,83 ,83 ,84 ,85 ,85 ,86 ,86 ,87 ,87 ,88 ,89 ,89 ,90 ,90 ,91 ,92 ,92 ,93 ,93 ,94 ,95 ,95 ,96 ,96 ,97 ,97 ,98 ,99 ,99 ,100 ,100 ,101 ,102 ,102 ,103 ,103 ,104 ,104 ,105 ,106 ,106 ,107 ,107 ,108 ,109 ,109 ,110 ,110 ,111 ,112 ,112 ,113 ,113 ,114 ,114 ,115 ,116 ,116 ,117 ,117 ,118 ,119 ,119 ,120 ,120 ,121 ,122 ,122 ,123 ,123 ,124 ,124 ,125 ,126 ,126 ,127 ,127 ,128 ,129 ,129 ,130 ,130 ,131 ,131 ,132 ,133 ,133 ,134 ,134 ,135 ,136 ,136 ,137 ,137 ,138 ,139 ,139 ,140 ,140 ,141 ,141 ,142 ,143 ,143 ,144 ,144 ,145 ,146 ,146 ,147 ,147 ,148 ,149 ,149 ,150};
unsigned char b_to_y[256] = {0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,1 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,2 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,3 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,4 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,6 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,7 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,8 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,9 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,10 ,11 ,11 ,11 ,11 ,11 ,11 ,11 ,11 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,12 ,13 ,13 ,13 ,13 ,13 ,13 ,13 ,13 ,13 ,14 ,14 ,14 ,14 ,14 ,14 ,14 ,14 ,14 ,15 ,15 ,15 ,15 ,15 ,15 ,15 ,15 ,16 ,16 ,16 ,16 ,16 ,16 ,16 ,16 ,16 ,17 ,17 ,17 ,17 ,17 ,17 ,17 ,17 ,17 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,18 ,19 ,19 ,19 ,19 ,19 ,19 ,19 ,19 ,19 ,20 ,20 ,20 ,20 ,20 ,20 ,20 ,20 ,21 ,21 ,21 ,21 ,21 ,21 ,21 ,21 ,21 ,22 ,22 ,22 ,22 ,22 ,22 ,22 ,22 ,22 ,23 ,23 ,23 ,23 ,23 ,23 ,23 ,23 ,23 ,24 ,24 ,24 ,24 ,24 ,24 ,24 ,24 ,25 ,25 ,25 ,25 ,25 ,25 ,25 ,25 ,25 ,26 ,26 ,26 ,26 ,26 ,26 ,26 ,26 ,26 ,27 ,27 ,27 ,27 ,27 ,27 ,27 ,27 ,27 ,28 ,28 ,28 ,28 ,28 ,28 ,28 ,28 ,29 ,29 ,29 ,29 ,29 ,29};
unsigned char r_to_v[512] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,2 ,3 ,3 ,4 ,5 ,5 ,6 ,7 ,8 ,8 ,9 ,10 ,10 ,11 ,12 ,12 ,13 ,14 ,15 ,15 ,16 ,17 ,17 ,18 ,19 ,20 ,20 ,21 ,22 ,22 ,23 ,24 ,25 ,25 ,26 ,27 ,27 ,28 ,29 ,30 ,30 ,31 ,32 ,32 ,33 ,34 ,35 ,35 ,36 ,37 ,37 ,38 ,39 ,40 ,40 ,41 ,42 ,42 ,43 ,44 ,45 ,45 ,46 ,47 ,47 ,48 ,49 ,50 ,50 ,51 ,52 ,52 ,53 ,54 ,55 ,55 ,56 ,57 ,57 ,58 ,59 ,60 ,60 ,61 ,62 ,62 ,63 ,64 ,65 ,65 ,66 ,67 ,67 ,68 ,69 ,70 ,70 ,71 ,72 ,72 ,73 ,74 ,75 ,75 ,76 ,77 ,77 ,78 ,79 ,80 ,80 ,81 ,82 ,82 ,83 ,84 ,85 ,85 ,86 ,87 ,87 ,88 ,89 ,89 ,90 ,91 ,92 ,92 ,93 ,94 ,94 ,95 ,96 ,97 ,97 ,98 ,99 ,99 ,100 ,101 ,102 ,102 ,103 ,104 ,104 ,105 ,106 ,107 ,107 ,108 ,109 ,109 ,110 ,111 ,112 ,112 ,113 ,114 ,114 ,115 ,116 ,117 ,117 ,118 ,119 ,119 ,120 ,121 ,122 ,122 ,123 ,124 ,124 ,125 ,126 ,127 ,127,
                    128 ,129 ,129 ,130 ,131 ,132 ,132 ,133 ,134 ,134 ,135 ,136 ,137 ,137 ,138 ,139 ,139 ,140 ,141 ,142 ,142 ,143 ,144 ,144 ,145 ,146 ,147 ,147 ,148 ,149 ,149 ,150 ,151 ,152 ,152 ,153 ,154 ,154 ,155 ,156 ,157 ,157 ,158 ,159 ,159 ,160 ,161 ,162 ,162 ,163 ,164 ,164 ,165 ,166 ,167 ,167 ,168 ,169 ,169 ,170 ,171 ,171 ,172 ,173 ,174 ,174 ,175 ,176 ,176 ,177 ,178 ,179 ,179 ,180 ,181 ,181 ,182 ,183 ,184 ,184 ,185 ,186 ,186 ,187 ,188 ,189 ,189 ,190 ,191 ,191 ,192 ,193 ,194 ,194 ,195 ,196 ,196 ,197 ,198 ,199 ,199 ,200 ,201 ,201 ,202 ,203 ,204 ,204 ,205 ,206 ,206 ,207 ,208 ,209 ,209 ,210 ,211 ,211 ,212 ,213 ,214 ,214 ,215 ,216 ,216 ,217 ,218 ,219 ,219 ,220 ,221 ,221 ,222 ,223 ,224 ,224 ,225 ,226 ,226 ,227 ,228 ,229 ,229 ,230 ,231 ,231 ,232 ,233 ,234 ,234 ,235 ,236 ,236 ,237 ,238 ,239 ,239 ,240 ,241 ,241 ,242 ,243 ,244 ,244 ,245 ,246 ,246 ,247 ,248 ,248 ,249 ,250 ,251 ,251 ,252 ,253 ,253 ,254 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255};
unsigned char b_to_u[512] = {0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,1 ,1 ,2 ,2 ,3 ,3 ,4 ,4 ,5 ,6 ,6 ,7 ,7 ,8 ,8 ,9 ,10 ,10 ,11 ,11 ,12 ,12 ,13 ,14 ,14 ,15 ,15 ,16 ,16 ,17 ,17 ,18 ,19 ,19 ,20 ,20 ,21 ,21 ,22 ,23 ,23 ,24 ,24 ,25 ,25 ,26 ,26 ,27 ,28 ,28 ,29 ,29 ,30 ,30 ,31 ,32 ,32 ,33 ,33 ,34 ,34 ,35 ,36 ,36 ,37 ,37 ,38 ,38 ,39 ,39 ,40 ,41 ,41 ,42 ,42 ,43 ,43 ,44 ,45 ,45 ,46 ,46 ,47 ,47 ,48 ,48 ,49 ,50 ,50 ,51 ,51 ,52 ,52 ,53 ,54 ,54 ,55 ,55 ,56 ,56 ,57 ,58 ,58 ,59 ,59 ,60 ,60 ,61 ,61 ,62 ,63 ,63 ,64 ,64 ,65 ,65 ,66 ,67 ,67 ,68 ,68 ,69 ,69 ,70 ,70 ,71 ,72 ,72 ,73 ,73 ,74 ,74 ,75 ,76 ,76 ,77 ,77 ,78 ,78 ,79 ,79 ,80 ,81 ,81 ,82 ,82 ,83 ,83 ,84 ,85 ,85 ,86 ,86 ,87 ,87 ,88 ,89 ,89 ,90 ,90 ,91 ,91 ,92 ,92 ,93 ,94 ,94 ,95 ,95 ,96 ,96 ,97 ,98 ,98 ,99 ,99 ,100 ,100 ,101 ,101 ,102 ,103 ,103 ,104 ,104 ,105 ,105 ,106 ,107 ,107 ,108 ,108 ,109 ,109 ,110 ,111 ,111 ,112 ,112 ,113 ,113 ,114 ,114 ,115 ,116 ,116 ,117 ,117 ,118 ,118 ,119 ,120 ,120 ,121 ,121 ,122 ,122 ,123 ,123 ,124 ,125 ,125 ,126 ,126 ,127 ,127 ,
                    128 ,129 ,129 ,130 ,130 ,131 ,131 ,132 ,133 ,133 ,134 ,134 ,135 ,135 ,136 ,136 ,137 ,138 ,138 ,139 ,139 ,140 ,140 ,141 ,142 ,142 ,143 ,143 ,144 ,144 ,145 ,145 ,146 ,147 ,147 ,148 ,148 ,149 ,149 ,150 ,151 ,151 ,152 ,152 ,153 ,153 ,154 ,155 ,155 ,156 ,156 ,157 ,157 ,158 ,158 ,159 ,160 ,160 ,161 ,161 ,162 ,162 ,163 ,164 ,164 ,165 ,165 ,166 ,166 ,167 ,167 ,168 ,169 ,169 ,170 ,170 ,171 ,171 ,172 ,173 ,173 ,174 ,174 ,175 ,175 ,176 ,177 ,177 ,178 ,178 ,179 ,179 ,180 ,180 ,181 ,182 ,182 ,183 ,183 ,184 ,184 ,185 ,186 ,186 ,187 ,187 ,188 ,188 ,189 ,189 ,190 ,191 ,191 ,192 ,192 ,193 ,193 ,194 ,195 ,195 ,196 ,196 ,197 ,197 ,198 ,199 ,199 ,200 ,200 ,201 ,201 ,202 ,202 ,203 ,204 ,204 ,205 ,205 ,206 ,206 ,207 ,208 ,208 ,209 ,209 ,210 ,210 ,211 ,211 ,212 ,213 ,213 ,214 ,214 ,215 ,215 ,216 ,217 ,217 ,218 ,218 ,219 ,219 ,220 ,220 ,221 ,222 ,222 ,223 ,223 ,224 ,224 ,225 ,226 ,226 ,227 ,227 ,228 ,228 ,229 ,230 ,230 ,231 ,231 ,232 ,232 ,233 ,233 ,234 ,235 ,235 ,236 ,236 ,237 ,237 ,238 ,239 ,239 ,240 ,240 ,241 ,241 ,242 ,242 ,243 ,244 ,244 ,245 ,245 ,246 ,246 ,247 ,248 ,248 ,249 ,249 ,250 ,250 ,251 ,252 ,252 ,253 ,253 ,254 ,254 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255 ,255};

void mImageYUVToRGB(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    mException((src->channel!=3)||(image_type!=MORN_IMAGE_YUV),EXIT,"invalid input");
    
    if(dst==NULL) dst = src;
    if(dst!=src) mImageRedefine(dst,MAX(3,dst->channel),src->height,src->width,dst->data);

    if(!INVALID_POINTER(src->border)) dst->border = src->border;
    
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)for(int i=ImageX1(dst,j);i<ImageX2(dst,j);i++)
    {
        unsigned char y = src->data[0][j][i];
        unsigned char u = src->data[1][j][i];
        unsigned char v = src->data[2][j][i];
        
        short r = y + v_to_r[v];
        short g = y - u_to_g[u] - v_to_g[v];
        short b = y + u_to_b[u];
        
        if(r<0) dst->data[2][j][i]=0; else if(r>255) dst->data[2][j][i]=255; else dst->data[2][j][i] = r;
        if(g<0) dst->data[1][j][i]=0; else if(g>255) dst->data[1][j][i]=255; else dst->data[1][j][i] = g;
        if(b<0) dst->data[0][j][i]=0; else if(b>255) dst->data[0][j][i]=255; else dst->data[0][j][i] = b;
    }
        
    if(dst->channel==3) mInfoSet(&(dst->info),"image_type",MORN_IMAGE_RGB);
    else                mInfoSet(&(dst->info),"image_type",MORN_IMAGE_RGBA);
}

void mImageYUVToGray(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    mException(((image_type != MORN_IMAGE_YUV)||(src->channel<3)),EXIT,"invalid input");
    
    if(INVALID_POINTER(dst)) dst = src;
    if(dst!=src) mImageRedefine(dst,1,src->height,src->width,dst->data);
    
    if(!INVALID_POINTER(src->border)) dst->border = src->border;
    
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)
        memcpy(dst->data[0][j]+ImageX1(dst,j),src->data[0][j],(ImageX2(src,j)-ImageX1(dst,j))*sizeof(unsigned char));
    
    mInfoSet(&(dst->info),"image_type",MORN_IMAGE_GRAY);
    dst->channel = 1;
}

void mImageRGBToYUV(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    int flag = 0;
         if((src->channel==3)&&(image_type==MORN_IMAGE_RGB )) flag=1;
    else if((src->channel==4)&&(image_type==MORN_IMAGE_RGBA)) flag=1;
    mException(flag==0,EXIT,"invalid input");
    
    if(dst==NULL) dst = src;
    if(dst!=src) mImageRedefine(dst,3,src->height,src->width,dst->data);

    if(!INVALID_POINTER(src->border))
        dst->border = src->border;
    
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)for(int i=ImageX1(dst,j);i<ImageX2(dst,j);i++)
    {
        unsigned char b = src->data[0][j][i];
        unsigned char g = src->data[1][j][i];
        unsigned char r = src->data[2][j][i];
        
        unsigned char y = r_to_y[r] + g_to_y[g] + b_to_y[b];
        dst->data[0][j][i] = y;
        
        dst->data[1][j][i] = b_to_u[256+b-y];
        dst->data[2][j][i] = r_to_v[256+r-y];
    }
        
    mInfoSet(&(dst->info),"image_type",MORN_IMAGE_YUV);
}

void mImageRGBToGray(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    int flag = 0;
         if((src->channel==3)&&(image_type==MORN_IMAGE_RGB )) flag=1;
    else if((src->channel==4)&&(image_type==MORN_IMAGE_RGBA)) flag=1;
    mException(flag==0,EXIT,"invalid input");
    
    if(dst==NULL) dst = src;
    if(dst!=src) mImageRedefine(dst,1,src->height,src->width,dst->data);

    if(!INVALID_POINTER(src->border)) dst->border = src->border;
       
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)for(int i=ImageX1(dst,j);i<ImageX2(dst,j);i++)
    {
        unsigned char b = src->data[0][j][i];
        unsigned char g = src->data[1][j][i];
        unsigned char r = src->data[2][j][i];
        
        dst->data[0][j][i] = r_to_y[r] + g_to_y[g] + b_to_y[b];
    }
    
    mInfoSet(&(dst->info),"image_type",MORN_IMAGE_GRAY);
    dst->channel = 1;
}

void mImageToGray(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    if(image_type == MORN_IMAGE_GRAY)
        mImageCopy(src,dst);
    else if((image_type == MORN_IMAGE_RGB)||(image_type == MORN_IMAGE_RGBA))
        mImageRGBToGray(src,dst);
    else if(image_type == MORN_IMAGE_YUV)
        mImageYUVToGray(src,dst);
    else
        mException(1,EXIT,"invalid image type %d",image_type);
}

void mImageRGBToHSV(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    int flag = 0;
         if((src->channel==3)&&(image_type==MORN_IMAGE_RGB )) flag=1;
    else if((src->channel==4)&&(image_type==MORN_IMAGE_RGBA)) flag=1;
    mException(flag==0,EXIT,"invalid input");
    
    if(dst==NULL) dst = src;
    if(dst!=src) mImageRedefine(dst,3,src->height,src->width,dst->data);

    if(!INVALID_POINTER(src->border)) dst->border = src->border;
    
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)for(int i=ImageX1(dst,j);i<ImageX2(dst,j);i++)
    {
        unsigned char b = src->data[0][j][i];
        unsigned char g = src->data[1][j][i];
        unsigned char r = src->data[2][j][i];
        
        int max,min;
        if(r>g) {max=r;  min=g;} else {max=g;  min=r;}
        if(b>max) {max=b;} else if(b<min) {min=b;}
        
        if(max==0)
        {
            dst->data[0][j][i]=0;dst->data[1][j][i]=0;dst->data[2][j][i]=0;
            continue;
        }
        
        int value = max-min;
        dst->data[2][j][i] = max*240/256;
        dst->data[1][j][i] = (value*240)/max;
        
        if(value==0)    dst->data[0][j][i]=0;
        else if(max==r)
        {
            if(min==b)  dst->data[0][j][i]=((g-b)*40)/value;
            else        dst->data[0][j][i]=240-((g-b)*40)/value;
        }
        else if(max==g) dst->data[0][j][i]= 80+((b-r)*40)/value;
        else if(max==b) dst->data[0][j][i]=160+((r-g)*40)/value;
    }
    mInfoSet(&(dst->info),"image_type",MORN_IMAGE_HSV);
}

void mImageHSVToRGB(MImage *src,MImage *dst)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int image_type = mInfoGet(&(src->info),"image_type");
    mException((src->channel<3)||(image_type != MORN_IMAGE_HSV),EXIT,"invalid input");
    
    if(dst==NULL) dst = src;
    if(dst!=src) mImageRedefine(dst,MAX(3,dst->channel),src->height,src->width,dst->data);
    
    if(!INVALID_POINTER(src->border)) dst->border = src->border;
    
    int j;
    for(j=ImageY1(dst);j<ImageY2(dst);j++)for(int i=ImageX1(dst,j);i<ImageX2(dst,j);i++)
    {
        unsigned char h = src->data[0][j][i];
        unsigned char s = src->data[1][j][i];
        unsigned char v = src->data[2][j][i];
        
        int max = v*256/240;
        int value = (max*s/240);
        int min = max-value;
        
        unsigned char r,g,b;
             if(h< 40) {r=max;b=min;g=min+( h     *value/40);}
        else if(h< 80) {g=max;b=min;r=min+(( 80-h)*value/40);}
        else if(h<120) {g=max;r=min;b=min+((h- 80)*value/40);}
        else if(h<160) {b=max;r=min;g=min+((160-h)*value/40);}
        else if(h<200) {b=max;g=min;r=min+((h-160)*value/40);}
        else           {r=max;g=min;b=min+((240-h)*value/40);}
        
        dst->data[0][j][i] = b;
        dst->data[1][j][i] = g;
        dst->data[2][j][i] = r;
    }
    if(dst->channel==3) mInfoSet(&(dst->info),"image_type",MORN_IMAGE_RGB);
    else                mInfoSet(&(dst->info),"image_type",MORN_IMAGE_RGBA);
}


/*
void mColorDiff(MImage *src,MImage *dst,unsigned char *color)
{
    mException(INVALID_IMAGE(src),EXIT,"invalid input");
    int height = src->height;
    int width = src->width;
    
    unsigned char ***data = src->data;
    
    if(src->info.image_type==MORN_IMAGE_RGB)
    {
        mException((src->channel!=3),EXIT,"invalid input");
        float r0=color[2];float g0=color[1];float b0=color[0];
        printf("r0 is %f,g0 is %f,b0 is %f\n",r0,g0,b0);
        for(int j=0;j<height;j++)
            for(int i=0;i<width;i++)
            {
                float r = data[2][j][i];float g = data[1][j][i];float b = data[0][j][i];
                // float diff = (ABS(r*g0-r0*g)/(r*g)+ABS(g*b0-g0*b)/(g*b)+ABS(b*r0-b0*g))/(b*r);
                // diff = diff*1024;
                // float diff = sqrt((r-r0)*(r-r0)+(g-g0)*(g-g0)+(b-b0)*(b-b0));
                
                float diff = MAX(MAX(ABS(r-r0),ABS(b-b0)),ABS(g-g0));
                
                dst->data[0][j][i] = (diff>255)?255:diff;
                
            }
    }
    else
        mException(1,EXIT,"invalid input");
}
*/

    
    