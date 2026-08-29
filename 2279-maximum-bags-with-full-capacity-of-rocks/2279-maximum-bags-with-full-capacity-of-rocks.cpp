class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int full = 0;
        int n = capacity.size();
        vector<int> diff;
        for(int i = 0 ; i < n ; i++){
            diff.push_back(capacity[i] - rocks[i]);
        }
        sort(diff.begin() , diff.end());
        for(int i = 0 ; i < n ; i ++){
            if(diff[i] <= additionalRocks || diff[i] == 0){   
                additionalRocks -= diff[i];
                full++;                     
            }
        }
        return full; 
    }
};