#include <vector>

using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int num : nums) {
            int count = 0;
            int currentSum = 0;
            
            for (int d = 1; d * d <= num; ++d) {
                if (num % d == 0) {
                    if (d * d == num) {
                        count += 1;
                        currentSum += d;
                    } else {
                        count += 2;
                        currentSum += d + (num / d);
                    }
                }
                if (count > 4) break;
            }
            
            if (count == 4) {
                totalSum += currentSum;
            }
        }
        
        return totalSum;
    }
};