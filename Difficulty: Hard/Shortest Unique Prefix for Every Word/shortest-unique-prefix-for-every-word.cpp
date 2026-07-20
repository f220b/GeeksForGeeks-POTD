struct Node {
    Node* next[26];
    int count;
    
    Node() {
        count = 0;
        for (int i = 0; i < 26; i++) 
            next[i] = nullptr;
    }
};

class Solution {
public:
    vector<string> findPrefixes(vector<string>& arr) {
        Node* root = new Node();
        
        for (const string& s : arr) {
            Node* curr = root;
            for (char c : s) {
                int id = c - 'a';
                if (!curr->next[id]) 
                    curr->next[id] = new Node();
                curr = curr->next[id];
                curr->count++;
            }
        }
        
        vector<string> res;
        for (const string& s : arr) {
            Node* curr = root;
            string pre = "";
            for (char c : s) {
                pre += c;
                curr = curr->next[c - 'a'];
                if (curr->count == 1) 
                    break;
            }
            res.push_back(pre);
        }
        
        return res;
    }
};