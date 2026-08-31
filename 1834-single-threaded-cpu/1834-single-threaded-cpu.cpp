class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        vector<array<int,3>> sortedTasks(n);  // {enqueueTime, processingTime, originalIndex}

        for (int i = 0; i < n; i++) {
            sortedTasks[i] = {tasks[i][0], tasks[i][1], i};
        }

        sort(sortedTasks.begin(), sortedTasks.end());  // sort by enqueueTime

        // min-heap of {processingTime, originalIndex}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        vector<int> result;
        result.reserve(n);

        long long currentTime = 0;
        int i = 0;  // pointer into sortedTasks

        while (i < n || !pq.empty()) {
            // if nothing is available yet, jump time forward to the next task's arrival
            if (pq.empty() && currentTime < sortedTasks[i][0]) {
                currentTime = sortedTasks[i][0];
            }

            // push every task that has arrived by currentTime
            while (i < n && sortedTasks[i][0] <= currentTime) {
                pq.push({sortedTasks[i][1], sortedTasks[i][2]});
                i++;
            }

            auto [processingTime, originalIndex] = pq.top();
            pq.pop();

            currentTime += processingTime;
            result.push_back(originalIndex);
        }

        return result;
    }
};