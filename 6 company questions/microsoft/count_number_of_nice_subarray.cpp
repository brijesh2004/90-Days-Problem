//https://leetcode.com/problems/count-number-of-nice-subarrays/ 


  int numberOfSubarrays(vector<int>& nums, int k) {
    //     int n = nums.size();
    //    for(int i=0;i<n;i++){
    //        if(nums[i]%2==0)
    //          nums[i]=0;
    //        else  nums[i]=1;
    //    }
    //   // prefix sum 
    //   int ans = 0;
    //   int currSum = 0;
    //   unordered_map<int , int>Summap;
    //   Summap[0]=1;
    //   for(int i=0;i<n;i++)
    //   {
    //       currSum+=nums[i];
    //       int complement = currSum-k;
    //       if(Summap[complement]){
    //           ans+=Summap[complement];
    //       }

    //       if(Summap[currSum]){
    //           Summap[currSum]++;
    //       }
    //       else{
    //           Summap[currSum] = 1;
    //       }
    //   }
    //   return ans;







     int j = 0, cnt = 0, ans = 0, c = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1){
                c++;
                if(c >= k){
                    cnt = 1;
                    while(nums[j++] % 2 == 0) cnt++;
                    ans = ans + cnt;
                }
            }
            else if(c >= k)
                ans = ans + cnt;
        }
        return ans;
    }