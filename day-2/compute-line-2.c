#define _GNU_SOURCE
#include "../compute-line.h"
#include <ctype.h>
#include <string.h>

int strStartWith(const char *str, size_t i, const char *sub_str) {
  size_t j = 0;
  for (; sub_str[j] != '\0' && str[i + j] != '\0'; j++) {
    if (sub_str[j] != str[i + j]) {
      return FALSE;
    }
  }
  return sub_str[j] == '\0';
}

int numberOfCubes(char **cube_ptr) {
  int res = 0;
  char *cube = *cube_ptr;
  while (isspace(*cube) || (*cube >= '0' && *cube <= '9')) {
    if (*cube >= '0' && *cube <= '9') {
      res *= 10;
      res += *cube - '0';
    }
    cube++;
  }

  *cube_ptr = cube;
  return res;
}

int gameValue(char *game) {
  char *save_ptr;
  char *draw = strtok_r(game, ";", &save_ptr);
  int red_cubes = 0;
  int blue_cubes = 0;
  int green_cubes = 0;

  while (draw != NULL) {
    char *save_ptr2;
    char *cube = strtok_r(draw, ",", &save_ptr2);
    while (cube != NULL) {
      int num = numberOfCubes(&cube);

      if (strStartWith(cube, 0, "red")) {
        red_cubes = num > red_cubes ? num : red_cubes;
      } else if (strStartWith(cube, 0, "blue")) {
        blue_cubes = num > blue_cubes ? num : blue_cubes;
      } else {
        green_cubes = num > green_cubes ? num : green_cubes;
      }

      cube = strtok_r(NULL, ",", &save_ptr2);
    }

    draw = strtok_r(NULL, ";", &save_ptr);
  }

  return red_cubes * blue_cubes * green_cubes;
}

int getLineCode(char *line) {
  char *save_ptr;
  strtok_r(line, ":", &save_ptr);

  char *list = strtok_r(NULL, ":", &save_ptr);

  return gameValue(list);
}
