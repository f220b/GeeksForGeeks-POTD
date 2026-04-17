class Solution {
  public:
    bool canFormPalindrome(string &s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        int oddCount = 0;
        for (int count : freq) {
            if (count & 1) {
                oddCount++;
            }
        }

        return oddCount <= 1;
    }
};