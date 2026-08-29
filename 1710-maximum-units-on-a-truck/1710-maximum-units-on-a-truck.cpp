class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort boxTypes in descending order based on units per box (index 1)
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        int totalUnits = 0;
        
        for (const auto& box : boxTypes) {
            int numBoxes = box[0];
            int unitsPerBox = box[1];
            
            int boxesToTake = min(numBoxes, truckSize);
            
            totalUnits += boxesToTake * unitsPerBox;
            truckSize -= boxesToTake;
            
            // Early exit if the truck is completely full
            if (truckSize == 0) {
                break;
            }
        }
        
        return totalUnits;
    }
};