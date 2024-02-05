// https://leetcode.com/problems/assign-cookies/submissions/1166527571/
 class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin() , g.end());
        sort(s.begin() , s.end());
        int n  = g.size();
        int m = s.size();
        int i=0,j=0;
        int ans = 0;
        while(i<n&&j<m){
           if(s[j]>=g[i]){
               ans++;
               i++;
               j++;
           }
           else if(g[i]>s[j]){
               j++;
           }
           else{
               i++;
           }
        }
        return ans;
    }
};