//https://leetcode.com/problems/get-equal-substrings-within-budget/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans  = 0;
        int i =0;
        int j =0;
        int n = s.length();
        int sum = 0;
        while(i<n){
            sum+=abs(s[i]-t[i]);
            if(sum<=maxCost){
                ans = max(ans , i-j+1);
            }
            else{
             while(sum>maxCost){
                 sum-=abs(s[j]-t[j]);
                 j++;
             }
            }
            i++;
        }
        return ans;

    }
};