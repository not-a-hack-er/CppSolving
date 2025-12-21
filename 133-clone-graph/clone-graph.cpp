/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*>& mp) {
        if (mp.find(curr) != mp.end())
            return mp[curr];

        Node* clone = new Node(curr->val);
        mp[curr] = clone;

        for (auto it : curr->neighbors) {
            clone->neighbors.push_back(dfs(it, mp));
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};
