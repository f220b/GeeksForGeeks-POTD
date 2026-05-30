class Solution {
public:
    void replaceElements(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return;

        int prev = arr[0];
        arr[0] = arr[0] ^ arr[1];

        for (int i = 1; i < n - 1; ++i) {
            int temp = arr[i];
            arr[i] = prev ^ arr[i + 1];
            prev = temp;
        }

        arr[n - 1] = prev ^ arr[n - 1];
    }
};