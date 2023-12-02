#include <stdio.h>

#include "../compute-line.h"

int getLineCode(char *line) {
  int firstFound = FALSE;
  int first = 0;
  int last = 0;

  for (size_t i = 0; line[i] != '\0'; i++) {
    char c = line[i];
    if (c >= '0' && c <= '9') {
      last = c - '0';
      if (!firstFound) {
        firstFound = TRUE;
        first = last;
      }
    }
  }

  return first * 10 + last;
}
