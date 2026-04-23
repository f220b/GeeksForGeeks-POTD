class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        int leftSum = 0, rightSum = totalSum;
        for(int i = 0; i < arr.size(); i++) {
            if(leftSum == rightSum)
                return true;
            leftSum += arr[i];
            rightSum -= arr[i];
        }
        return leftSum == rightSum;
    }
};
