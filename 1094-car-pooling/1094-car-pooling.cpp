class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];   // sort by pickup location, index 1
        });

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // pair = {dropLocation, passengers}, min-heap by dropLocation

        int cap = capacity;
        int n = trips.size();

        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= trips[i][1]) {
                cap += pq.top().second;
                pq.pop();
            }

            cap -= trips[i][0];
            if (cap < 0) {
                return false;
            }

            pq.push({trips[i][2], trips[i][0]});   // {dropLocation, passengers}
        }

        return true;
    }
};