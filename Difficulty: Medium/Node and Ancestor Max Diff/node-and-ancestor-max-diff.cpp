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
};*/

class Solution {
public:
    void helper(Node* root, int maxAncestor, int& maxD) {
        if (!root)
            return;

        maxD = max(maxD, maxAncestor - root->data);
        int newMax = max(maxAncestor, root->data);

        helper(root->left, newMax, maxD);
        helper(root->right, newMax, maxD);
    }

    int maxDiff(Node* root) {
        if (!root)
            return 0;

        int maxD = INT_MIN;
        helper(root->left, root->data, maxD);
        helper(root->right, root->data, maxD);

        return maxD;
    }
};