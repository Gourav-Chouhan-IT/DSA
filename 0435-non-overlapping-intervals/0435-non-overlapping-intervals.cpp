class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        // Sort intervals by their END time ascending
        // Greedily choosing intervals that end earliest leaves maximum room for future intervals
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int removed = 0;
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            // If current start time is >= previous end time, there is no overlap
            if (intervals[i][0] >= prevEnd) {
                prevEnd = intervals[i][1]; // Keep interval & update prevEnd
            } else {
                // Overlap detected: greedily remove current interval
                removed++;
            }
        }

        return removed;
    }
};