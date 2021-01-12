struct FamilyTree {
    string name;
    bool isLive = true;
    vector<FamilyTree*> child;
    
    FamilyTree(string _name): name(_name) {};
};

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) {
        root = new FamilyTree(kingName);
        m[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        FamilyTree* node = new FamilyTree(childName);
        m[parentName]->child.push_back(node);
        m[childName] = node;
    }
    
    void death(string name) {
        m[name]->isLive = false;
        m.erase(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> res;
        helper(res, root);
        return res;
    }
private:
    FamilyTree* root;
    unordered_map<string, FamilyTree*> m;
    
    void helper(vector<string>& res, FamilyTree* cur) {
        if (cur->isLive) res.push_back(cur->name);
        for (FamilyTree*& c : cur->child) {
            helper(res, c);
        }
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */