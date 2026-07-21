#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
private:
    // Helper function: Solves LeetCode 84 (Largest Rectangle in Histogram)
    int largestRectangleArea(const vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; ++i) {
            int current_height = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && current_height < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                int width = st.empty() ? i : (i - st.top() - 1);
                max_area = max(max_area, height * width);
            }
            
            st.push(i);
        }
        
        return max_area;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<int> heights(cols, 0);
        int max_rectangle_area = 0;
        
        for (int r = 0; r < rows; ++r) {
            // Update the histogram height array for current row
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0; // Reset height if zero encountered
                }
            }
            
            // Calculate max rectangle using the histogram for row 'r'
            max_rectangle_area = max(max_rectangle_area, largestRectangleArea(heights));
        }
        
        return max_rectangle_area;
    }
};