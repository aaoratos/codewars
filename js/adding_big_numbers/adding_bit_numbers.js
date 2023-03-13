function add(a, b) {;
  let carry = 0;
  let tmpSum = 0;
  let shorter = [], longer = [];
  let sum = [];
  let i;

  if (a.length >= b.length) {
    shorter = b.split('').reverse();
    longer = a.split('').reverse();
  } else {
    shorter = a.split('').reverse();
    longer = b.split('').reverse();
  }

  for (i = 0; i < shorter.length; i++) {
    tmpSum = carry + Number(shorter[i]) + Number(longer[i]);
    carry = Math.floor(tmpSum / 10);
    if (carry) {
      sum.push(tmpSum % 10);
    } else {
      sum.push(tmpSum);
    }
  }

  for (i; i < longer.length; i++) {
    tmpSum = carry + Number(longer[i]);
    carry = Math.floor(tmpSum / 10);
    if (carry) {
      sum.push(tmpSum % 10);
    } else {
      sum.push(tmpSum);
    }
  }

  if (carry)
    sum.push(carry);
  return sum.reverse().join('');
}