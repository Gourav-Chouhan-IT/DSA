class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    int atMost(vector<int>& nums, int k) {
        int l = 0, r = 0, ans = 0;
        int count = 0;
        
        vector<int> hash(nums.size() + 1, 0);
        
        while (r < nums.size()) {
            if (hash[nums[r]] == 0) {
                count++;
            }
            hash[nums[r]]++; 
            
            while (count > k) {
                hash[nums[l]]--; 
                
                if (hash[nums[l]] == 0) {
                    count--;
                }
                l++; 
            }
           
            ans += (r - l + 1);
            r++;
        }
        
        return ans;
    }
};