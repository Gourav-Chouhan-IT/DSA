class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        stack<int> st1; // for 5
        stack<int> st2; // for 10
        int n = bills.size();
        for (int i=0 ; i<n ; i++){
            if (bills[i] == 5){
                st1.push(5);
            }
            else if (bills[i] == 10){
                if (st1.empty()) return false;
                st1.pop();
                st2.push(10);
            }
            else {
                if (!st2.empty() && !st1.empty()){
                    st2.pop();
                    st1.pop();
                }
                else if (st1.empty()){
                    return false;
                }
                else if (st2.empty()){
                    if (st1.size()>=3){
                        st1.pop();
                        st1.pop();
                        st1.pop();
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};