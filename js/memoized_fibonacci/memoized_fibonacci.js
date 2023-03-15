const memoize = (fn) => {
  let cache = {};
  return (x) => cache[x] || (cache[x] = fn(x));
}

const fibonacci = memoize( (n) => {
  if (n === 0 || n === 1) return n;
  return (fibonacci(n - 2) + fibonacci(n - 1))
});