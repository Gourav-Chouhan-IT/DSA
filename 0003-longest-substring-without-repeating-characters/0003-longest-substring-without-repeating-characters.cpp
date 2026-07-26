#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);
        
        int max_length = 0;
        int l = 0;
        
        for (int r = 0; r < s.length(); ++r) {
            char current = s[r];
            
            if (last[current] >= l) {
                l = last[current] + 1;
            }
            
            last[current] = r;
            
            max_length = max(max_length, r - l + 1);
        }
        
        return max_length;
    }
};