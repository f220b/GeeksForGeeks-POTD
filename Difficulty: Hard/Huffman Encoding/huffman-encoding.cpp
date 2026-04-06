class Solution {
public:
    struct Node {
        int freq;
        int order;
        char ch;
        Node* left;
        Node* right;
        
        Node(int f, int ord, char c = '\0')
            : freq(f), order(ord), ch(c), left(nullptr), right(nullptr) {}
    };

    struct Cmp {
        bool operator()(Node* a, Node* b) {
            if (a->freq != b->freq) return a->freq > b->freq;
            return a->order > b->order;
        }
    };

    void dfs(Node* node, string code, vector<string>& result) {
        if (!node) return;
        if (node->ch != '\0') {
            result.push_back(code);
            return;
        }
        dfs(node->left,  code + '0', result);
        dfs(node->right, code + '1', result);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        priority_queue<Node*, vector<Node*>, Cmp> pq;

        for (int i = 0; i < (int)s.size(); i++) {
            pq.push(new Node(f[i], i, s[i]));
        }

        if (pq.size() == 1) return {"0"};

        while (pq.size() > 1) {
            Node* left  = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            // KEY FIX: merged node inherits the EARLIER of the two orders
            int mergedOrder = min(left->order, right->order);

            Node* merged = new Node(left->freq + right->freq, mergedOrder);
            merged->left  = left;
            merged->right = right;
            pq.push(merged);
        }

        Node* root = pq.top();
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};