class Solution {
public:
    int minToggle(vector<int>& arr) {
        int n = arr.size();
        
        int zeros_on_right = 0;
        for (int num : arr) {
            if (num == 0) zeros_on_right++;
        }
        
        int min_toggles = zeros_on_right; 
        int ones_so_far = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                ones_so_far++;
            } else {
                zeros_on_right--;
            }
            
            int current_toggles = ones_so_far + zeros_on_right;
            min_toggles = min(min_toggles, current_toggles);
        }
        
        return min_toggles;
    }
};