/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        return helper_se(root);
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream ss(data);
        return helper_de(ss);
    }
private:
    string helper_se(Node* root) {
        if (!root) return "#";
        string res = to_string(root->val) + " ";
        for (Node*& child:root->children) {
            res += helper_se(child) + " ";
        }
        res += "# ";
        return res;
    }
    
    Node* helper_de(istringstream& ss) {
        string word;
        stack<Node*> st;
        Node* res = nullptr;
        while (ss >> word) {
            if (word == "#") {
                res = st.top();
                st.pop();
            } else {
                Node* node = new Node(stoi(word));
                if (!st.empty()) st.top()->children.push_back(node);
                st.push(node);
            }
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));