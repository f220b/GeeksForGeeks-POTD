class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            if (arr[left] == 1) {
                if (arr[right] == 0) {
                    swap(arr[left], arr[right]);
                    left++;
                    right--;
                } else {
                    right--;
                }
            } else {
                left++;
            }
        }
    }
};