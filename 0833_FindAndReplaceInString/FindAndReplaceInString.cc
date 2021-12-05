class Solution {
public:
    string findReplaceString(string s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        vector<Node*> graph = build(s, indexes, sources, targets);
        sort(graph.begin(), graph.end(), [](const Node* lhs, const Node* rhs) {
            return lhs->start < rhs->start;
        });
        
        int index = 0;
        int i = 0;
        string res = "";
        while (index < s.size() && i<graph.size()) {
            if (index == graph[i]->start) {
                res += graph[i]->target;
                index += graph[i]->len;
                ++i;
            } else {
                res.push_back(s[index++]);
            }
        }
        if (index < s.size()) res += s.substr(index);
        return res;
    }
private:
    struct Node {
        int start, len;
        string target;
        
        Node(int s, int l, string t): start(s), len(l), target(t) {}
    };
    
    vector<Node*> build(string& s, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        int n = indexes.size();
        vector<Node*> res;
        for (int i=0;i<n;++i) {
            if (indexes[i]+sources[i].size() <= s.size() && s.substr(indexes[i], sources[i].size()) == sources[i]) {
                res.push_back(new Node(indexes[i], sources[i].size(), targets[i]));
            }
        }
        return res;
    }
};