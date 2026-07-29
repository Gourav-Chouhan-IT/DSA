class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> counts;
        int l = 0, r = 0, ans = 0;
        int n = s.length();
        
        while (r < n) {
            counts[s[r]]++; 
            
            while (counts.size() == 3) {
                ans += (n - r); 
                
                counts[s[l]]--;
                
                if (counts[s[l]] == 0) {
                    counts.erase(s[l]); 
                }
                l++;
            }   
            r++;
        }
        return ans;
    }
};