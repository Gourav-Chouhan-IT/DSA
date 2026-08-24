class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: count frequencies
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: min-heap of size k, ordered by frequency
        // pair = {frequency, number} so heap compares by frequency first
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (auto& [num, count] : freq) {
            if (pq.size() < k) {
                pq.push({count, num});
            } else if (count > pq.top().first) {
                pq.pop();
                pq.push({count, num});
            }
        }

        // Step 3: extract the numbers from the heap
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};