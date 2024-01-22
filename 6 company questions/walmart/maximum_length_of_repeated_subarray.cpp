//https://leetcode.com/problems/maximum-length-of-repeated-subarray/

class Solution {
public:
 int ans = 0;
 int solve(vector<int>&nums1 , vector<int>&nums2 , int i , int j , vector<vector<int>>&dp , int n , int m){
     if(i>=n || j>=m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int res = 0;
    if(nums1[i]==nums2[j]){
       res = 1+solve(nums1,nums2,i+1,j+1 , dp , n ,m);
       ans = max(ans , res);
    }
    solve(nums1 , nums2 , i+1 , j ,dp, n ,m);
    solve(nums1 , nums2 , i , j+1 ,dp,  n,m);
    return dp[i][j] = res;
 }


    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // int ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //          if(nums1[i]==nums2[j]){
        //             int x = i;
        //             int y = j;
        //             int cnt = 0;
        //             while(x<n&&y<m){
        //                 if(nums1[x]==nums2[y]){
        //                     // cout<<i<<"->"<<x<<" "<<y<<" ";
        //                     x++;
        //                     y++;
        //                     cnt++;
        //                     // cout<<cnt<<endl;
        //                 }
        //                 else{
                            
        //                     break;
        //                 }
        //             }
        //             ans = max(cnt , ans);
        //          }
        //     }
        // }
        // return ans;


        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // solve(nums1 , nums2 , 0 , 0 , dp , n ,m);
        // return ans;




 int dp[1021][1002];

         int ans = 0 ;
        for (int i = 1 ; i <= n ; i++) {
            for (int j = 1 ; j <= m ; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }

        return ans  ;
    }
};