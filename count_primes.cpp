/**
 * Count the number of prime numbers less than a non-negative number, n.
 */

class Solution {
public:
  int countPrimes(int n) {
    vector<bool> primes(n, true);
    int count = 0;
    for (int i = 2; i < n; i++) {
      if (primes[i]) {
        ++count;
        for (int j = 2; j * i < n; j++)  primes[j * i] = false;
      }
    }
    return count;
  }
};
