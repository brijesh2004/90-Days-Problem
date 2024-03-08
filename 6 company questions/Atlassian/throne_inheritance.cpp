//https://leetcode.com/problems/throne-inheritance/

class ThroneInheritance {
public:
    unordered_map<string , vector<string>>adj;
    unordered_map<string , int>dth;
    string king;
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    void birth(string parentName, string childName) {
        adj[parentName].push_back(childName);
    }
    
    void death(string name) {
        dth[name]++;
    }
    
    void dfs(string node , vector<string>&ans){
         if(!dth[node]){
               ans.push_back(node);
           }
        for(auto it:adj[node]){
           dfs(it , ans);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string>ans;
        dfs(king , ans);
        return ans;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */