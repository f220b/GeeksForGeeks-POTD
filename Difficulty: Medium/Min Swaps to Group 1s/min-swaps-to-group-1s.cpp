class Solution {
  public:
    int minSwaps(vector<int>& arr) {
        // code here
        int total = 0;
        for(int ar : arr)
            if(ar == 1)
                total++;
        if(total == 0)
            return -1;
        
        int left = 0, right = 0, n = arr.size(), countOnes = 0, minSwaps = INT_MAX;
        while(right < n) {
            if(arr[right] == 1)
                countOnes++;
            while(left < right && right-left+1 > total) {
                if(arr[left] == 1)
                    countOnes--;
                left++;
            }
            if(right-left+1 == total)
                minSwaps = min(minSwaps, total-countOnes);
            right++;
        }
        return minSwaps;
    }
};