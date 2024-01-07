
// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution {
    #define mod 1000000007
public:
   int solve(int index , int delay , int forget , int n , vector<int>&dp){
       if(index+delay>n) return 1;
          if(dp[index]!=-1){
              return dp[index];
          }
       int ans = 1;
       for(int i= index + delay ;i<=min(n , index+forget);i++){
           if(i==index+forget){
               ans-=1;
               break;
           }
           ans = (ans%mod + solve(i , delay , forget , n,dp)%mod)%mod;
       }
       return dp[index] = ans;
   }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(1002,-1);
        return solve(1 , delay , forget ,n , dp);
    }
};