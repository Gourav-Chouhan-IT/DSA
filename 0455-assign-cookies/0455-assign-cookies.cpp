#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both vectors in ascending order
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int gp = 0; // Pointer for children
        int sp = 0; // Pointer for cookies
        
        while (gp < g.size() && sp < s.size()) {
            if (s[sp] >= g[gp]) {
                gp++; // Child satisfied, move to next child
            }
            sp++;     // Move to next cookie
        }
        
        return gp;
    }
};