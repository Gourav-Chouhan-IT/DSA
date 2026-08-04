class Solution {
public:
    string minWindow(string s, string t) {
        
        int count = 0;
        vector<int> hash(128,0);
        for( char c : t){
            if(hash[c] == 0) count++;
            hash[c]++;

        }

        int l = 0; int r =0;
        int formed = 0;
        int start_index = 0;
        int min_len = INT_MAX;
        vector<int> window_freq(128,0);

        while(r < s.length()){
            char c = s[r];
            window_freq[c]++;

            if(hash[c] > 0 &&  window_freq[c] == hash[c]){
                formed++;
            }

            while(formed == count){
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_index = l;
                }
                
                char left_char = s[l];
                window_freq[left_char]--;

                if (hash[left_char] > 0 && window_freq[left_char] < hash[left_char]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return min_len == INT_MAX ? "" : s.substr(start_index, min_len);
    }
};