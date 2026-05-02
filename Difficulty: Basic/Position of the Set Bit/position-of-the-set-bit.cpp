class Solution {
  public:
    int findPosition(int n) {
        if (n <= 0 || (n & (n - 1)) != 0) {
            return -1;
        }

        int pos = 0;
        while (n > 0) {
            n >>= 1;
            pos++;
        }

        return pos;
    }
};