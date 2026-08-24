class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Count frequencies
        unordered_map<char, int> hash;

        for (char ch : tasks) {
            hash[ch]++;
        }

        // Max heap: {frequency, character}
        priority_queue<pair<int, char>> pq;

        for (auto it : hash) {
            pq.push({it.second, it.first});
        }

        int time = 0;

        while (!pq.empty()) {

            vector<pair<int, char>> used;

            // Number of tasks executed in this cycle
            int executed = 0;

            // Cycle size = n + 1
            for (int i = 0; i <= n; i++) {

                if (pq.empty()) {
                    break;
                }

                auto current = pq.top();
                pq.pop();

                // Execute task
                time++;
                executed++;

                // Decrease frequency
                current.first--;

                // Save if it still has occurrences
                if (current.first > 0) {
                    used.push_back(current);
                }
            }

            // Put remaining tasks back
            for (auto x : used) {
                pq.push(x);
            }

            // If tasks are still remaining,
            // unused positions in this cycle are idle
            if (!pq.empty()) {
                time += (n + 1) - executed;
            }
        }

        return time;
    }
};