class Solution {
public:
    bool isIncreasing(vector<int>&v ){
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]>=1);
            else return false;
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {

        //****************************first method *******************************************//
        // int ans = 0;
        // int n = nums.size();
        // for(int i=0;i<n;i++){
        //     vector<int>v=nums;
        //     for(int j  = i;j<n;j++){
        //       v.erase(v.begin()+i , v.begin()+i+1);
        //       if(isIncreasing(v)){
        //           ans++;
        //       }
        //     }
        // }
        // return ans;


        //*****************************second method using two pointer ***********************//

        int n = nums.size();
        vector<int>start , end;
        // start for the suffix increasing ans the end for the end increasing sequence
        for(int i=0;i<n;i++){
            if(start.empty()||start.back()<nums[i])
             start.push_back(nums[i]);
            else
             break;
        }
        for (int i = n - 1; i >= 0; --i) {
            if (end.empty() || end.back() > nums[i]) {
                end.push_back(nums[i]);
            } else 
                break;
        }

        if(start.size()+end.size()>n)
         return n*(n+1)/2;

        int ans = start.size() + end.size();
        int i = 0, j = 0;
        
        reverse(end.begin(), end.end());

        while (i<start.size()&&j<end.size()){
            if (start[i] < end[j]) {
                ans += end.size() - j;
                ++i;
            } else {
                ++j;
            }
        }
        // plus one for the empty array 
        return ans + 1;
        
    }
};