// https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/1155364284/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
    //     int i=0,j=0;
    //     int n = nums.size();
    //     sort(nums.begin() , nums.end());
    //     set<pair<int , int>>st;
    //     while(i<n&&j<n){
    //         if(i==j){
    //          j++;
    //         }
    //         else if(i!=j&&nums[j]-nums[i]==k){
    //             st.insert({nums[j] , nums[i]});
    //             i++;
    //         }
    //         else if(nums[j]-nums[i]>k){
    //             i++;
    //         }
    //         else if(nums[j]-nums[i]<k){
    //          j++;
    //         }
    //         // if(j>=n-1){
    //         //     j=n-1;
    //         // }
           
    //     }
    // return st.size();

  sort(nums.begin(),nums.end());
        
        set<pair<int,int>> ans;
        int i=0;
        int j=1;

        while(j<nums.size()){
            int diff = nums[j] - nums[i];
            if(diff == k){
                ans.insert({nums[i],nums[j]});
                i++;
                j++;
            }

            else if(diff > k){
                i++;
            }
            
            else j++;

            if(i == j) j++;

        }

        return ans.size();
    }
};