#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            // Treat the index past the end of the array as a bar of height 0
            int current_height = (i == n) ? 0 : heights[i];
            
            // While the current bar is shorter than the bar at the top of the stack
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // If the stack is empty, the popped bar was the shortest so far, 
                // meaning its width extends all the way to the beginning of the histogram.
                int width = st.empty() ? i : (i - st.top() - 1);
                
                max_area = std::max(max_area, height * width);
            }
            
            st.push(i);
        }
        
        return max_area;
    }
};