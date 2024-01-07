
// https://leetcode.com/problems/k-divisible-elements-subarrays/

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>st;
        for(int i=0;i<nums.size();i++){
            int divcnt = 0;
            vector<int>v;
            for(int j=i;j<nums.size();j++){
                 if(nums[j]%p==0){
                     divcnt++;
                 }
                 if(divcnt>k){
                     break;
                 }
                 v.push_back(nums[j]);
                 st.insert(v);
            }
        }
        return st.size();
    }
};