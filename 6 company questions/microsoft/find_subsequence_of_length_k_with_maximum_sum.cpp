// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/

#include<bits/stdc++.h>
using namespace std;
 vector<int> maxSubsequence(vector<int>& nums, int k) {
        int p = k;
        vector<pair<int,int>>v;
        int n = nums.size();
        for(int i=0;i<n;i++){
          v.push_back({nums[i] , i});
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        int i = nums.size()-1;
        while(i>=0&&k--){
          ans.push_back(v[i].second);
          i--;
        }
        sort(ans.begin(),ans.end());
        
        vector<int>t;
        for(int i=0;i<p;i++){
            t.push_back(nums[ans[i]]);
        }
       return t;

    }