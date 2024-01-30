// https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
       

        unordered_map<int , int>second;
        for(auto it: matches){
            if(!second[it[0]]){
                second[it[0]] = 0;
            }
          second[it[1]]++;
        }
        vector<int>f , s;
        for(auto it: second){
           if(it.second==0){
               f.push_back(it.first);
           }
           if(it.second==1){
               s.push_back(it.first);
           }
        }
        sort(f.begin() , f.end());
         sort(s.begin() , s.end());
         return {f , s};
    }