// https://leetcode.com/problems/bulls-and-cows/



class Solution {
public:
    string getHint(string s, string g) {
        int a = 0;
        int b = 0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            if(s[i]==g[i]){
                a++;
            }
            else{
              mp[s[i]]++;
            }
        }

        for(int i=0;i<s.size();i++){
           if(s[i]!=g[i]){
               if(mp[g[i]]){
                   b++;
                   mp[g[i]]--;
               }
           }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};