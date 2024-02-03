// https://leetcode.com/problems/partition-array-for-maximum-sum/


class Solution {
public:

   // recursion
    int solve(vector<int> &arr, int k, int ind){
        int n = arr.size();
        if(ind >= n)
         return 0;

        int mx = 0, ans = 0;

        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solve(arr, k, i+1));
        }
        return ans;
    }

    // memorization

     int solveMem(vector<int> &arr, int k, int ind , vector<int>&dp){
        int n = arr.size();
        if(ind >= n)
         return 0;

          if(dp[ind]!=-1)
           return dp[ind];
        int mx = 0, ans = 0;

        for(int i=ind; i<min(ind+k, n); i++){
            mx = max(mx, arr[i]);
            ans = max(ans, (i - ind + 1)*mx + solveMem(arr, k, i+1 ,dp));
        }
        return dp[ind] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // return solve(arr, k, 0);
        vector<int>dp(arr.size()+1 , -1);
        return solveMem(arr ,k , 0,dp);
    }
};