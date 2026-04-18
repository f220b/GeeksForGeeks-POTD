class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int totalOnes = 0;
        int maxGain = 0;
        int currentGain = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 1)
                totalOnes++;

            int val = (arr[i] == 0) ? 1 : -1;
            currentGain += val;

            if (currentGain < 0)
                currentGain = 0;
            if (currentGain > maxGain)
                maxGain = currentGain;
        }

        return totalOnes + maxGain;
    }
};