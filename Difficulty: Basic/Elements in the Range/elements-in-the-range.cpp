class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        set<int> st;
        for(int a : arr) {
            if(a >= start && a <= end)
                st.insert(a);
        }
        return st.size() == (end-start+1);
    }
};
