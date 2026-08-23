class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        int n = matrix.size();

        priority_queue<
            pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>,
            greater<pair<int, pair<int, int>>>
        > pq;

        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        while (k > 1) {

            auto current = pq.top();
            pq.pop();

            int row = current.second.first;
            int col = current.second.second;

            if (col + 1 < n) {
                pq.push({matrix[row][col + 1], {row, col + 1}});
            }

            k--;
        }

        return pq.top().first;
    }
};