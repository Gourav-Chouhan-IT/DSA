class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        
        for(int i = 0 ; i < k ; i ++){
            sum += cardPoints[i];
        }

        int max_score = sum ; 
         
         for (int i = 0 ; i < k ; i++){
            sum -= cardPoints[k-1-i];
            sum += cardPoints[n-1-i];
            max_score = max(max_score , sum);
        }

        return max_score;
    }
};