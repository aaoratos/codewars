#include <stdio.h>

char *printer_error(char *str) {
  int len = 0, errors = 0;
  char *result;
  for (char *cp = str; *cp; cp++, len++)
    if (*cp < 'a' || *cp > 'm') errors++;
  asprintf(&result, "%d/%d", errors, len);
  return result;
}