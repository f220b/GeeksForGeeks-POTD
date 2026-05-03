class Solution {
  public:
    static int countBits(int n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1);
            count++;
        }
        return count;
    }

    vector<int> sortBySetBitCount(vector<int>& arr) {
        stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            return countBits(a) > countBits(b);
        });
        return arr;
    }
};