// https://leetcode.com/problems/repeated-dna-sequences/description/


class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length()<10){
            return {};
        }
        unordered_map<string , int>mp;
        vector<string>ans;
        string t = "";
        for(int i=0;i<10;i++){
          t+=s[i];
        }
        mp[t]++;
        for(int i=10;i<s.length();i++){
            t.erase(t.begin());
            t+=s[i];
            if(mp[t]==1){
                ans.push_back(t);
            }
            mp[t]++;
        }
        return ans;
    }
};