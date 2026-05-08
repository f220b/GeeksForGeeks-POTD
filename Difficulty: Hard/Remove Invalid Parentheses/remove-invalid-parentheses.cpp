class Solution {
  public:
    set<string> st;
    void helper(string &s, int i, int open, int remOpen, int remClose, string curr) {
        if(i == s.length()) {
            if(open == 0 && remOpen == 0 && remClose == 0)
                st.insert(curr);
            return;
        }
        
        char ch = s[i];
        if(ch == '(') {
            if(remOpen > 0)
                helper(s, i+1, open, remOpen-1, remClose, curr);
                
            helper(s, i+1, open+1, remOpen, remClose, curr+ch);
        } else if(ch == ')') {
            if(remClose > 0)
                helper(s, i+1, open, remOpen, remClose-1, curr);
                
            if(open > 0)
                helper(s, i+1, open-1, remOpen, remClose, curr+ch);
        } else {
            helper(s, i+1, open, remOpen, remClose, curr+ch);
        }
    }
    vector<string> validParenthesis(string &s) {
        // code here
        int open = 0, close = 0;
        for(char ch : s) {
            if(ch == '(')
                open++;
            else if(ch == ')') {
                if(open > 0)
                    open--;
                else
                    close++;
            }
        }
        helper(s, 0, 0, open, close, "");
        vector<string> result(st.begin(), st.end());
        return result;
    }
};
