int isPrime(int n) {
  int output = 1;
  if (n == 0 || n == 1) output = 0;
  for (int i = 2; i < n; ++i) {
    if (n % i == 0) output = 0;
  }

  return output;
}