class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
    
private:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        
        // n = no. of odd numbers
        int l = 0, r = 0, sum = 0, ans = 0;
        
        while (r < nums.size()) {
            sum += (nums[r]%2);

            while (sum > goal) {
                sum -= (nums[l] % 2); 
                l++; 
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }
};