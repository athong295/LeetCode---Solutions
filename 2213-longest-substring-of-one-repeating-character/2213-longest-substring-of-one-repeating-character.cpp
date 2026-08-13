#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    int max_len;
    int prefix_len;
    int suffix_len;
};

class SegmentTree {
private:
    int n;
    string s;
    vector<Node> tree;

    void push_up(int node, int l, int r) {
        int mid = l + (r - l) / 2;
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;

        int len_l = mid - l + 1;
        int len_r = r - mid;

        // Max len ban đầu là max của 2 con
        tree[node].max_len = max(tree[left_child].max_len, tree[right_child].max_len);
        tree[node].prefix_len = tree[left_child].prefix_len;
        tree[node].suffix_len = tree[right_child].suffix_len;

        // Nếu ký tự ở điểm nối giống nhau
        if (s[mid] == s[mid + 1]) {
            tree[node].max_len = max(tree[node].max_len, tree[left_child].suffix_len + tree[right_child].prefix_len);

            // Nếu con trái gồm toàn bộ các ký tự giống nhau
            if (tree[left_child].prefix_len == len_l) {
                tree[node].prefix_len = len_l + tree[right_child].prefix_len;
            }
            // Nếu con phải gồm toàn bộ các ký tự giống nhau
            if (tree[right_child].suffix_len == len_r) {
                tree[node].suffix_len = len_r + tree[left_child].suffix_len;
            }
        }
    }

    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = {1, 1, 1};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node + 1, l, mid);
        build(2 * node + 2, mid + 1, r);
        push_up(node, l, r);
    }

public:
    SegmentTree(string str) : s(str) {
        n = s.length();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int node, int l, int r, int idx, char ch) {
        if (l == r) {
            s[idx] = ch;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * node + 1, l, mid, idx, ch);
        } else {
            update(2 * node + 2, mid + 1, r, idx, ch);
        }
        push_up(node, l, r);
    }

    int getMaxLen() {
        return tree[0].max_len;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        vector<int> ans;
        int k = queryIndices.size();

        for (int i = 0; i < k; i++) {
            st.update(0, 0, s.length() - 1, queryIndices[i], queryCharacters[i]);
            ans.push_back(st.getMaxLen());
        }

        return ans;
    }
};