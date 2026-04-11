class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int n = arr.size();
        int curr = 1, total = 0;
        for(int i = 1; i < n; i++) {
            if(arr[i] <= arr[i-1]) {
                total += (curr*(curr-1)) >> 1;
                curr = 1;
            } else {
                curr++;
            }
        }
        if(curr != 1) 
            total += (curr*(curr-1)) >> 1;
        
        return total;
    }
};
