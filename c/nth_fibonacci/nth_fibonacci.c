typedef unsigned long long ull;

ull nth_fib (int n) {
  ull n1 = 1, n2 = 2, tmp = 0;

  if (n == 1) return 0;
  else if (n == 2 || n == 3) return 1;

  do {
    tmp = n2;
    n2 = n2 + n1;
    n1 = tmp;
  } while (--n > 3);

  return n1;
}