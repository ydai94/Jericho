/*
Copyright (C) 2018 Microsoft Corporation

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <string.h>
#include "frotz.h"
#include "games.h"
#include "frotz_interface.h"

// The Lurking Horror: http://ifdb.tads.org/viewgame?id=jhbd0kja1t57uop

const char *lurking_intro[] = { "sit on chair\n",
                                "turn pc on\n",
                                "login 872325412\n",
                                "password uhlersoth\n" };

zword* lurking_ram_addrs(int *n) {
    *n = 0;
    return NULL;
}

char** lurking_intro_actions(int *n) {
  *n = 4;
  return lurking_intro;
}

char* lurking_clean_observation(char* obs) {
  char* pch;
  pch = strchr(obs, '\n');
  if (pch != NULL) {
    return pch+1;
  }
  return obs;
}

int lurking_victory() {
  char *death_text = "The hacker, mud-covered and weak, staggers to his feet. \"Can I have my key back?\" he asks.";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int lurking_game_over() {
  char *death_text = "****  You have died  ****";
  if (strstr(world, death_text)) {
    return 1;
  }
  return 0;
}

int lurking_get_self_object_num() {
  return 56;
}

int lurking_get_moves() {
  return (((short) zmp[696]) << 8) | zmp[697];
}

short lurking_get_score() {
  return zmp[695];
}

int lurking_max_score() {
  return 100;
}

int lurking_get_num_world_objs() {
  return 252;
}

int lurking_ignore_moved_obj(zword obj_num, zword dest_num) {
  return 0;
}

int lurking_ignore_attr_diff(zword obj_num, zword attr_idx) {
  return 0;
}

int lurking_ignore_attr_clr(zword obj_num, zword attr_idx) {
  return 0;
}

void lurking_clean_world_objs(zobject* objs) {
    int i;
    char mask;
    mask = ~(1 << 1);
    // Clear attr 6
    for (i=1; i<=lurking_get_num_world_objs(); ++i) {
        objs[i].attr[0] &= mask;
    }
}
