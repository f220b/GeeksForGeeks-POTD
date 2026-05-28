/* Structure of binary tree node
class Node {
	public:
	int data;
	Node* left, right;
	Node(int item)
	{
		data = item;
		left = nullptr;
		right = nullptr;
	}
}
*/
class Solution {
	public:
	vector<int> verticalSum(Node* root) {
		// code here
		map<int, int> mpp;
		
		queue<pair<Node*, int>> q;
		q.push({root, 0});
		
		while (!q.empty()) {
			auto itr = q.front();
			q.pop();
			mpp[itr.second] += itr.first->data;
			
			if (itr.first->left)
				q.push({itr.first->left, itr.second - 1});
			if (itr.first->right)
				q.push({itr.first->right, itr.second + 1});
		}
		
		vector<int> vertSum;
		for (auto itr : mpp)
			vertSum.push_back(itr.second);
		
		return vertSum;
	}
};
