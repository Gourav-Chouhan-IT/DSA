class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());  // sort by startDay

        priority_queue<int, vector<int>, greater<int>> minHeap;  // min-heap of endDay
        int i = 0;
        int day = 0;
        int count = 0;

        while (i < n || !minHeap.empty()) {
            // if heap is empty, jump straight to the next event's start day
            // (no point looping day-by-day through a gap with nothing available)
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // push every event that has become available by today
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // discard anything already expired
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // attend the soonest-expiring available event
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
            }

            day++;
        }

        return count;
    }
};