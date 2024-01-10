// https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int mid = n/2;
        int ans = 0;
        for(int i=0;i<=mid;i++){
        ans += nums[mid]-nums[i];
        }
        for(int i = mid+1;i<n;i++){
            ans+= nums[i]-nums[mid];
        }
        return ans;
    }
};