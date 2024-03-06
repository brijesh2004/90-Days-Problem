// https://leetcode.com/problems/maximum-product-after-k-increments/


class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        long long mod = 1000000007;
        priority_queue<int ,  vector<int>, greater<int>> pq;
        for(auto it:nums){
            pq.push(it);
        }
      
        while(k>0){
            int t = pq.top();
            t++;
            pq.pop();
            pq.push(t);
            k--;
        }
        
        long long ans = 1;
        while(!pq.empty()){
           ans = ((ans)%mod*(pq.top())%mod)%mod;
           pq.pop();
        }
        
        return ans;
    }
};