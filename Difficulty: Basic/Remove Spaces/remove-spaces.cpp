class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        string ans = "";
        for(char ch : s) 
            if(ch != ' ')
                ans += ch;
        
        return ans;
    }
};