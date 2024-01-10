// https://leetcode.com/problems/russian-doll-envelopes/

// recursive methof gives tle
class Solution {
public:
    int solve(vector<vector<int>>&env , int ind , int n , int prev_width , int prev_height){
        if(ind >=n){
            return 0;
        }

        // include 
        int a = 0;
        if(env[ind][0]>prev_width&&env[ind][1]>prev_height){
            a = 1+solve(env , ind+1 , n,env[ind][0],env[ind][1] );
        }

        // exclude 
        int b =0+ solve(env , ind+1 , n , prev_width , prev_height);
        return max(a,b);
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
         int n = envelopes.size();
        return solve(envelopes , 0 , n , -1 ,-1);
    }
};



// second approach using the memorization it is also gives the tle

class Solution {
public:
    int solve(vector<vector<int>>&env , int ind , int n , int prev_width , int prev_height ,unordered_map<string , int>&dp){
        if(ind >=n){
            return 0;
        }
       string key = to_string(ind)+"_"+to_string(prev_width)+"_"+to_string(prev_height);
       if(dp.find(key)!=dp.end()){
           return dp[key];
       }
        // include 
        int a = 0;
        if(env[ind][0]>prev_width&&env[ind][1]>prev_height){
            a = 1+solve(env , ind+1 , n,env[ind][0],env[ind][1] ,dp);
        }

        // exclude 
        int b =0+ solve(env , ind+1 , n , prev_width , prev_height,dp);
        dp[key] = max(a,b);

        return dp[key];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
         int n = envelopes.size();
         unordered_map<string , int>dp;
        return solve(envelopes , 0 , n , -1 ,-1 ,dp);
    }
};


// third approach using the bottom up approach but still tle 

class Solution {
public:
   int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n <= 1) {
            return n;
        }

        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};


// last the final submitted answer 

class Solution {
public:
   int maxEnvelopes(vector<vector<int>>& envelopes) {
          int n = envelopes.size();
        if (n <= 1) {
            return n;
        }

        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        vector<int> tails;
        for (const auto& envelope : envelopes) {
            auto it = lower_bound(tails.begin(), tails.end(), envelope[1]);
            if (it == tails.end()) {
                tails.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }

        return tails.size();
    }
};