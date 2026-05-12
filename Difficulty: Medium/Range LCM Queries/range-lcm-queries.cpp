#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<long long> tree;
    int n;
    
    // Compute LCM using GCD
    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }
    
    // Build segment tree bottom-up
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(arr, 2*node,   start, mid);
        build(arr, 2*node+1, mid+1, end);
        tree[node] = lcm(tree[2*node], tree[2*node+1]);
    }
    
    // Point update: set arr[idx] = val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2*node,   start, mid,   idx, val);
        else
            update(2*node+1, mid+1, end,   idx, val);
        tree[node] = lcm(tree[2*node], tree[2*node+1]);
    }
    
    // Range LCM query [l, r]
    long long query(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || end < l)
            return 1LL;  // LCM identity element
        // Total overlap
        if (l <= start && end <= r)
            return tree[node];
        // Partial overlap
        int mid = (start + end) / 2;
        long long leftLCM  = query(2*node,   start, mid,   l, r);
        long long rightLCM = query(2*node+1, mid+1, end,   l, r);
        return lcm(leftLCM, rightLCM);
    }

public:
    vector<long long> RangeLCMQuery(vector<int>& arr, vector<vector<int>>& queries) {
        n = arr.size();
        tree.assign(4 * n, 1LL);     // 4*n is safe upper bound for segment tree
        
        build(arr, 1, 0, n-1);
        
        vector<long long> result;
        
        for (auto& q : queries) {
            if (q[0] == 1) {
                // Update: set arr[index] = value
                update(1, 0, n-1, q[1], q[2]);
            } else {
                // Range LCM query [L, R]
                result.push_back(query(1, 0, n-1, q[1], q[2]));
            }
        }
        return result;
    }
};