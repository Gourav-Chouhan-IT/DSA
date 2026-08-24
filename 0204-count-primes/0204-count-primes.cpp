#include <vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        // Only track odd numbers >= 3 that are strictly less than n.
        // index i in isComposite represents the number (2*i + 3)
        int size = (n - 2) / 2;
        
        vector<bool> isComposite(size, false);
        int count = 1; // account for the prime 2
        
        for (int i = 0; i < size; i++) {
            if (!isComposite[i]) {
                long num = 2L * i + 3;
                count++;
                for (long j = num * num; j < n; j += 2 * num) {
                    int idx = (j - 3) / 2;
                    isComposite[idx] = true;
                }
            }
        }
        
        return count;
    }
};