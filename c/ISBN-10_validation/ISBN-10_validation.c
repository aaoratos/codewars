#include <stdbool.h>

bool is_valid_ISBN_10 (const char *ISBN) {
  unsigned i;
  int checksum = 0;
  for (i = 0; ISBN[i] != '\0'; i++) {
      switch(ISBN[i]) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            checksum += (ISBN[i] - '0') * (i + 1);
            break;
        case 'X':
            if (i == 9) checksum += 100;
            else return false;
            break;
        default:
            return false;
      }
  }
  return (checksum % 11 == 0) && (i == 10);
}