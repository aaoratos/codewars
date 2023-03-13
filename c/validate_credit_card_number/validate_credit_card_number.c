#include <stdbool.h>
#include <stdlib.h>

#define MAX_DIGITS 16

int get_digits(long numb, int *buf) {
  int tmp = 0;
  int len = 0;

  do {
      tmp = numb % 10;
      buf[len++] = tmp;
  } while(numb /= 10);
  buf[len] = numb;
  return len;
};

int get_arr_sum(int *arr, int len) {
  int sum = 0;

  while(--len >= 0)
    sum += arr[len];
  return sum;
}

bool validate(long card_number) {
  int digits[MAX_DIGITS];
  int len = get_digits(card_number, digits);
  int digits_sum = 0;

  for(int step = 1; step < len; step += 2) {
    digits[step] *= 2;
    if (digits[step] > 9)
      digits[step] -= 9;
  }
  digits_sum = get_arr_sum(digits, len);
  if (digits_sum % 10)
    return false;
  return true;
}