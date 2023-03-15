function arrayDiff(a, b) {
  if (a.length == 0) return [];
  if (b.length == 0) return a;

  for (let i = 0; i < a.length; i++)
    if (b.includes(a[i])) a.splice(i--, 1);
  return a;
}