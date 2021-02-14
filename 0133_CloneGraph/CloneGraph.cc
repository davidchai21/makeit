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
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> m;
        build(node, m);
        addConnection(m);
        return m[node];
    }
private:
    void build(Node* node, unordered_map<Node*, Node*>& m) {
        if (!node || m.find(node) != m.end()) return;
        m[node] = new Node(node->val);
        for (Node*& c : node->neighbors) {
            build(c, m);
        }
    }
    
    void addConnection(unordered_map<Node*, Node*>& m) {
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (Node*& c : it->first->neighbors) {
                it->second->neighbors.push_back(m[c]);
            }
        }
    }
};