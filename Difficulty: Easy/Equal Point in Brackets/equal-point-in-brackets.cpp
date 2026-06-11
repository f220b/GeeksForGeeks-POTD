class Solution {
public:
    int findIndex(string &s) {
        int countClose = 0;
        for (char ch : s) {
            if (ch == ')') {
                countClose++;
            }
        }
        return countClose;
    }
};