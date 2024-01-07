#include<bits/stdc++.h>


//  problem link  https://leetcode.com/problems/high-access-employees/

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string , vector<int>>mp;
        vector<string>ans;
        for(int i=0;i<access_times.size();i++){
            mp[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        for(auto it:mp){
            vector<int>v = it.second;
            string s = it.first;
            sort(v.begin(),v.end());
            if(v.size()>=3){
                for(int i=2;i<v.size();i++){
                    if(v[i]-v[i-2]<=99&&v[i]-v[i-1]<=99){
                        ans.push_back(s);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};