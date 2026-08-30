#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // 1. Sort events by start day ascending
        sort(events.begin(), events.end());

        // 2. Min-heap storing only end days of active events
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int count = 0;
        int i = 0;
        int n = events.size();
        int day = 1;

        // Loop as long as there are events to process or active events in min-heap
        while (i < n || !minHeap.empty()) {
            // If no active events, jump directly to the next event's start day
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // Add all events that start on or before 'day'
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]); // Store end day
                i++;
            }

            // Remove events that have already expired before 'day'
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // Greedily attend the event that ends earliest
            if (!minHeap.empty()) {
                minHeap.pop();
                count++;
                day++; // Move to the next day
            }
        }

        return count;
    }
};