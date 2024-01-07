// https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/

class Solution {
public:
int mod = 1e9 + 7;
int solve(int present , int end , int step , int k , vector<vector<int>>&dp){
    if(step>k){
        return 0;
    }
    if(step==k&&present==end){
        return 1;
    }

   if(dp[999+present][step]!=-1){
       return dp[999+present][step]%mod;
   }
    
    // 1 step ahed
    int a = solve(present+1 , end , step+1 , k , dp);
    // 1 step backward
    int b =solve(present-1 , end , step+1 , k , dp);
    return dp[999+present][step] = (a+b)%mod;
}

  int solveTab(int startPos, int endPos, int k){

      vector<vector<int>>dp(3002 , vector<int>(k+1 ,0));
        // initialization
        dp[startPos+1000][k] = 1;
        // dp for different remaining steps
        for(int j = k - 1; j >= 0; j--){
            // iterate different idx
            for(int idx = 1; idx <= 3000; idx++){
                // reach from previous idx or next idx
                dp[idx][j] = ((dp[idx][j] + dp[idx - 1][j + 1]) % mod + dp[idx + 1][j + 1]) % mod;
            }
        }
        return dp[endPos + 1000][0];

  }
    int numberOfWays(int startPos, int endPos, int k) {
        // vector<vector<int>>dp(3000 , vector<int>(k+1,-1));
        // return solve(startPos , endPos , 0 , k , dp)%mod;
        return solveTab(startPos , endPos , k)%mod;
    }
};