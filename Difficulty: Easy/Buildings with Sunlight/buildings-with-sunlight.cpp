class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        if (arr.empty()) return 0;

        int count = 0;
        int maxH = 0;

        for (int h : arr) {
            if (h >= maxH) {
                count++;
                maxH = h;
            }
        }

        return count;
    }
};