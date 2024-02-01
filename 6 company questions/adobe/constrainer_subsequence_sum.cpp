// https://leetcode.com/problems/constrained-subsequence-sum/


class Solution {
public:
   int solve(int currInd, int prevInd, vector<int>& nums, int k) {
    if(currInd >= nums.size()) {
        return 0;
    }
    
    int take = INT_MIN, notTake;
    // You can include this element if it's the first element or within k distance from the last included element
    if(prevInd == -1 || currInd - prevInd <= k) {
        take = nums[currInd] + solve(currInd + 1, currInd, nums, k);
    }
    // Exclude the current element, do not update prevInd
    notTake = solve(currInd + 1, prevInd, nums, k);
    
    return max(take, notTake);
}

 int solveMem(int currInd, int prevInd, vector<int>& nums, int k, vector<vector<int>>& memo) {
    if(currInd >= nums.size()) {
        return 0;
    }
    if(memo[currInd][prevInd+1] != INT_MIN) { // Using prevInd+1 to handle -1 case
        return memo[currInd][prevInd+1];
    }
    int take = INT_MIN, notTake;
    // You can include this element if it's the first element or within k distance from the last included element
    if(prevInd == -1 || currInd - prevInd <= k) {
        take = nums[currInd] + solveMem(currInd + 1, currInd, nums, k, memo);
    }
    // Exclude the current element, do not update prevInd
    notTake = solveMem(currInd + 1, prevInd, nums, k, memo);
    
    memo[currInd][prevInd+1] = max(take, notTake);
    return memo[currInd][prevInd+1];
}


    int solveTab(vector<int>&nums , int k ){
         int n = nums.size();
    if (n == 0) return 0;
    vector<int> dp(n, 0); // dp[i] is the max sum up to and including nums[i]
    dp[0] = nums[0];
    int maxSum = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = nums[i]; // Start with taking only the current element
        // Check previous k elements for max sum we can extend
        for (int j = max(i - k, 0); j < i; j++) {
            dp[i] = max(dp[i], dp[j] + nums[i]);
        }
        // Update maxSum if dp[i] is the new max
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
      }

   
    int constrainedSubsetSum(vector<int>& nums, int k) {
        // if(k==1)
        //  return -1;
    //     int maxi = *max_element(nums.begin() , nums.end());
    //     if(maxi<=0){
    //         return maxi;
    //     }
    //     // int n = nums.size();
    //     // vector<vector<int>>dp(n+1 , vector<int>(n+1 , INT_MIN));
    //     // return solveMem(0 , -1 , nums ,k , dp);

    // //         int n = nums.size();
    // // vector<vector<int>> memo(n, vector<int>(n+1, INT_MIN)); // +1 to handle prevInd = -1 case
    // // return solveMem(0, -1, nums, k, memo); 

    //  return solveTab(nums , k);


  int n = nums.size();
  vector<int>dp(n);
  deque<int>dq;
  int ans = INT_MIN;
  dp[0] = nums[0];
  ans = max(ans , dp[0]);
  dq.push_back(0);

  for(int i=1;i<n;i++){
      dp[i] = max(0 , dp[dq.front()])+nums[i];
      ans = max(ans , dp[i]);

      while(!dq.empty() && dp[dq.back()] <= dp[i]){
          dq.pop_back();
      }
      dq.push_back(i);
      if(dq.front() == i-k){
          dq.pop_front();
      }
  
  }
    return ans;
    }
};

