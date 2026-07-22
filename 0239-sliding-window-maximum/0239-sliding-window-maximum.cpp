#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices of elements
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            // 1. Remove elements out of the current window boundary
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // 2. Maintain monotonic property (decreasing order in deque)
            // Remove all indices whose values are smaller than the current element
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            
            // 3. Add current element's index
            dq.push_back(i);
            
            // 4. Record the maximum (front of deque) once the first window is formed
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};