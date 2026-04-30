class Solution {
  public:
    bool isMaxHeap(vector<int> &arr) {
        int n = arr.size();
        
        // Iterate through all internal nodes (parents)
        for (int i = 0; i < n / 2; ++i) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            
            // If left child exists and is greater than the parent, it's not a max-heap.
            if (leftChild < n && arr[leftChild] > arr[i]) {
                return false;
            }
            
            // If right child exists and is greater than the parent, it's not a max-heap.
            if (rightChild < n && arr[rightChild] > arr[i]) {
                return false;
            }
        }
        
        return true;
    }
};