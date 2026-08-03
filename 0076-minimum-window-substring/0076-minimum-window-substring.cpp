class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) return "";

        vector<int> t_freq(128, 0);
        int required = 0; 

        for (char c : t) {
            if (t_freq[c] == 0) required++; 
            t_freq[c]++;
        }

        vector<int> window_freq(128, 0);
        int formed = 0; 

        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_idx = 0; 

        while (r < s.length()) {
            char c = s[r];
            window_freq[c]++;

            if (t_freq[c] > 0 && window_freq[c] == t_freq[c]) {
                formed++;
            }

            while (formed == required) {
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                char left_char = s[l];
                window_freq[left_char]--;

                if (t_freq[left_char] > 0 && window_freq[left_char] < t_freq[left_char]) {
                    formed--;
                }

                l++; 
            }

            r++; 
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};