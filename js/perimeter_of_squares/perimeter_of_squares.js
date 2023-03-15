const memoize = (fn) => {
  let cache = {};
  return (x) => cache[x] || (cache[x] = fn(x));
}

const fib = memoize( (n) => {
  if (n === 0 || n === 1) return n;
  return (fib(n - 2) + fib(n - 1))
});

function perimeter(n) {
  let result = 0;
  if (n === 0 || n === 1) return (n + 1) * 4;
  for (let i = 0; i <= n + 1; i++)
    result += fib(i);
  return result * 4;
}