//  https://leetcode.com/problems/rotate-function/


// first method iterative time limit exceeds

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int k = i;
            int sum = 0;
            bool flag = false;
            for(int j=0;j<n;j++){
             if(flag==false && k>0){
                sum+=((n-k)*nums[j]);
                k--;
             }
             else{
                 flag=true;
                 sum+=(k*nums[j]);
                 k++;
             }
            }
            ans = max(ans , sum);
        }
        return ans;
    }
};


// second method sliding window


class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
         int n=nums.size();
        int product=0;
        int sum = 0;
        for(int i=0;i<n;i++){
            product += nums[i]*i;
            sum += nums[i];
        }

        int maxi = product;

        for(int i=1;i<n;i++){
            int temp = product + sum - nums[n-i] * n;
            product = temp;
            maxi = max(maxi,product);
        }
        return maxi;

    }
};