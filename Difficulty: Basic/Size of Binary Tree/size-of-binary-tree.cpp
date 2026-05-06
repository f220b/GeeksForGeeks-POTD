/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int getSize(Node* root) {
        // code here
        int count = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* node = q.front();
            count++;
            q.pop();
            
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        return count;
    }
};