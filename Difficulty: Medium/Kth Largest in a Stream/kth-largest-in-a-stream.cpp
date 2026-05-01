class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> min_heap;
        
        for (int i = 0; i < arr.size(); i++) {
            min_heap.push(arr[i]);
            
            if (min_heap.size() > k) 
                min_heap.pop();
            
            if (min_heap.size() < k) 
                result.push_back(-1);
            else
                result.push_back(min_heap.top());
        }
        
        return result;
    }
};