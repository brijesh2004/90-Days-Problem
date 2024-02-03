//https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/description/


class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int , int>mp;
        int ans = 0;
        int cnt = 0;
        int n = nums.size();
        int i=0;
        int j=0;
        while(i<n){
            if(mp[nums[i]]==k){
                while(nums[j]!=nums[i]){
                    mp[nums[j]]--;
                    j++;
                    cnt--;
                }
                mp[nums[j]]--;
                j++;
                cnt--;
            }
            mp[nums[i]]++;
            cnt++;
            ans = max(cnt , ans);
            i++;
        }
        return ans;
    }
};