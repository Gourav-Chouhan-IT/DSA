class Solution {
public:
    int numberOfSubstrings(string s) {
        int hash[3] = {0}; 
        int l = 0, r = 0, ans = 0;
        int n = s.length();
        
        while (r < n) {
            hash[s[r] - 'a']++; 
            
            while (hash[0] > 0 && hash[1] > 0 && hash[2] > 0) {
                ans += (n - r); 
                
                hash[s[l] - 'a']--;
                l++;
            }
            
            r++;
        }
        
        return ans;
    }
};