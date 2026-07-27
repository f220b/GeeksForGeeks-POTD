/* Structure of Binary Tree Node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(int val) {
		data = val;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	Node* buildTree(vector<int>& pre, vector<int>& preMirror, int& preIdx, int l, int h, int n) {
		if (preIdx >= n || l > h)
			return nullptr;
		
		Node* root = new Node(pre[preIdx++]);
		
		if (l == h || preIdx >= n)
			return root;
		
		int i = l;
		while (i <= h) {
			if (preMirror[i] == pre[preIdx])
				break;
			i++;
		}
		
		if (i <= h) {
			root->left = buildTree(pre, preMirror, preIdx, i, h, n);
			root->right = buildTree(pre, preMirror, preIdx, l + 1, i - 1, n);
		}
		
		return root;
	}
	Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
		int preIdx = 0;
		int n = pre.size();
		return buildTree(pre, preMirror, preIdx, 0, n - 1, n);
	}
};
