#include <stdio.h>

#include "../compute-line.h"

const char NUMBERS[9][6] = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
};

int strStartWith(const char *str, size_t i, const char *sub_str) {
  size_t j = 0;
  for (; sub_str[j] != '\0' && str[i + j] != '\0'; j++) {
    if (sub_str[j] != str[i + j]) {
      return FALSE;
    }
  }
  return sub_str[j] == '\0';
}

int getSpelledNumber(const char *line, size_t i) {
  for (int j = 0; j < 9; j++) {
    if (strStartWith(line, i, NUMBERS[j])) {
      return j + 1;
    }
  }
  return -1;
}

int getNumber(const char *line, size_t i) {
  int num = -1;
  char c = line[i];
  if (c >= '0' && c <= '9') {
    num = c - '0';
  } else {
    num = getSpelledNumber(line, i);
  }
  return num;
}

int getLineCode(const char *line) {
  int firstFound = FALSE;
  int first = 0;
  int last = 0;

  for (size_t i = 0; line[i] != '\0'; i++) {
    char c = line[i];
    int num = getNumber(line, i);
    if (num != -1) {
      last = num;
      if (!firstFound) {
        firstFound = TRUE;
        first = last;
      }
    }
  }

  return first * 10 + last;
}
