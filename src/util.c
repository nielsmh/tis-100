#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "util.h"
#include <ncurses.h>

void raise_error(const char *msg, ...) {
  va_list(args);
  va_start(args, msg);
#ifdef RICH_OUTPUT
  endwin();
#endif
  vfprintf(stderr, msg, args);
  fprintf(stderr, "\n");
  exit(0);
}

void custom_log(const char *msg, ...) {
  va_list(args);
  va_start(args, msg);

  FILE *fp = fopen("tis.log", "a");
  vfprintf(fp, msg, args);
  fprintf(fp, "\n");
  fclose(fp);
}

char *trim_whitespace(char *str)
{
  char *end;

  // Trim leading space
  while(isspace(*str)) str++;

  if(*str == 0)  // All spaces?
    return str;

  // Trim trailing space
  end = str + strlen(str) - 1;
  while(end > str && isspace(*end)) end--;

  // Write new null terminator
  *(end+1) = 0;

  return str;
}

