class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        int count = 1; 
        vector<bool> isPrime(n / 2, true);
        for (int i = 1; 2 * i * i + 2 * i < n; i++) {
            if (isPrime[i]) {
                int p = 2 * i + 1;
                for (int j = 2 * i * i + 2 * i; j < n / 2; j += p) {
                    isPrime[j] = false;
                }
            }
        }
        
        for (int i = 1; i < n / 2; i++) {
            if (isPrime[i]) {
                count++;
            }
        }
        
        return count;
    }
};
