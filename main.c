#define _POSIX_C_SOURCE 200809L
#include "compute-line.h"
#include <stdio.h>
#include <stdlib.h>

int getAnswer(const char *fileName) {
  FILE *f = fopen(fileName, "r");
  if (f == NULL) {
    return -1;
  }

  char *line = NULL;
  size_t n = 0;
  ssize_t length = getline(&line, &n, f);
  int res = 0;

  while (length > 0) {
    int code = getLineCode(line);
    res += code;
    length = getline(&line, &n, f);
  }
  free(line);
  return res;
}

int main(int argc, char *argv[]) {
  if (argc > 1) {
    int answer = getAnswer(argv[1]);
    if (answer != -1) {
      printf("Answer: %d\n", answer);
      return EXIT_SUCCESS;
    }
  }
  return EXIT_FAILURE;
}
