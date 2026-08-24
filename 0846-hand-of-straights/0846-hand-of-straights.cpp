#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        if (groupSize == 1) return true;

        unordered_map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (int card : hand) {
            if (count[card] == 0) continue;

            // Walk backward to find the start of this contiguous sequence
            int start = card;
            while (count.count(start - 1) && count[start - 1] > 0) {
                start--;
            }

            // Process groups sequentially starting from 'start'
            while (start <= card) {
                int freq = count[start];
                if (freq > 0) {
                    for (int i = 0; i < groupSize; ++i) {
                        if (count[start + i] < freq) {
                            return false;
                        }
                        count[start + i] -= freq;
                    }
                }
                start++;
            }
        }

        return true;
    }
};