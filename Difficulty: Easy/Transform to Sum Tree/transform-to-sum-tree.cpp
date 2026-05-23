/* Structure for Tree Node
class Node {
	public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val) {
		data = val;
		left = nullptr;
		right = nullptr;
	}
};
*/

class Solution {
	public:
	int helper(Node* root) {
		if (!root)
			return 0;
		
		int leftSum = helper(root->left);
		int rightSum = helper(root->right);
		int subTreeSum = leftSum + root->data + rightSum;
		root->data = leftSum + rightSum;
		
		return subTreeSum;
	}
	void toSumTree(Node *root) {
		// code here
		helper(root);
	}
};
