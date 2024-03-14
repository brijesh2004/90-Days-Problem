// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int preSum = 0;
        unordered_map<int , int>mp;
        mp[0] = 1;
        int ans = 0;
        for(int i=0;i<n;i++){
            preSum +=nums[i];
            ans+=mp[preSum-goal];
            mp[preSum]++;
        }
        return ans;
    }
};