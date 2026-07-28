class Solution {
public:
    int characterReplacement(string s, int k) {
        int c[26] = {0};
        int a = 0;
        int l = 0;
        int m = 0;
        
        for (int r = 0; r < s.length(); r++) {
            c[s[r] - 'A']++;
            m = max(m, c[s[r] - 'A']);
            
            if ((r - l + 1) - m > k) {
                c[s[l] - 'A']--;
                l++;
            }
            
            a = max(a, r - l + 1);
        }
        
        return a;
    }
};