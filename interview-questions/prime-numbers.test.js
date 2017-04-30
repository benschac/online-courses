const isPrime = require('./prime-numbers');

test('returns true if number is prime', () => {
  expect(isPrime(2)).toBe(true);
  expect(isPrime(3)).toBe(true);
  expect(isPrime(11)).toBe(true);
});

test('returns true if large number is prime', () => {
  expect(isPrime(98563)).toBe(true);
});

test('returns false if number is not prime', () => {
  expect(isPrime(4)).toBe(false);
  expect(isPrime(10)).toBe(false);
  expect(isPrime(98000)).toBe(false);
});

test('returns false if large number is not prime', () => {
  expect(isPrime(98000)).toBe(false);
});

