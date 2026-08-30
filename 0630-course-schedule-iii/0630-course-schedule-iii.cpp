class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        priority_queue<int> pq;
        int totalTime = 0;

        for(int i = 0 ; i < courses.size() ; i++){
            totalTime += courses[i][0];
            pq.push(courses[i][0]);

            if(totalTime > courses[i][1]){
                totalTime -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};