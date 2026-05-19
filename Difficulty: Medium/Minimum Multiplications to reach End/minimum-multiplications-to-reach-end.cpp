class Solution {
	public:
	int minSteps(vector<int>& arr, int start, int end) {
		// code here
		set<int> seen;
		queue<int> q;
		q.push(start);
		seen.insert(start);
		int steps = 0;
		
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				int n = q.front();
				q.pop();
				
				if (n == end)
					return steps;
				
				for (int num : arr) {
					int newNum = (n*num)%1000;
					if(!seen.count(newNum)) {
					    q.push(newNum);
					    seen.insert(newNum);
					}
				}
			}
			steps++;
		}
		return -1;
	}
};
