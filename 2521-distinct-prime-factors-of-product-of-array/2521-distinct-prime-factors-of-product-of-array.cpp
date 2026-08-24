#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> primes;
        for (int num : nums) {
            for (int d = 2; d * d <= num; ++d) {
                if (num % d == 0) {
                    primes.insert(d);
                    while (num % d == 0) {
                        num /= d;
                    }
                }
            }
            if (num > 1) {
                primes.insert(num);
            }
        }
        return primes.size();
    }
};