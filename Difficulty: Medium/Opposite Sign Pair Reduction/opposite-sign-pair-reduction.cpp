#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> reducePairs(vector<int>& arr) {
        vector<int> st;

        for (int x : arr) {
            bool destroyed = false;
            while (!st.empty() && ((st.back() > 0 && x < 0) || (st.back() < 0 && x > 0))) {
                int topVal = st.back();
                int absTop = abs(topVal);
                int absCurr = abs(x);

                if (absTop < absCurr) {
                    st.pop_back();
                    continue; 
                } else if (absTop == absCurr) {
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push_back(x);
            }
        }

        return st;
    }
};