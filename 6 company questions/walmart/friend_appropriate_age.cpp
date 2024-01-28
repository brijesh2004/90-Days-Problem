//https://leetcode.com/problems/friends-of-appropriate-ages/


class Solution {
public:
int binarySearch(int idx, int &val,vector<int> &ages){
        int start = 0, mid,ans = -1,end = idx;
        while(start <= end){
            mid = (start + end) / 2;
            if(ages[mid] > val){
                ans = mid;
                end = mid - 1;
            }else start = mid + 1;
        }
        return ans;
    }

int numFriendRequests(vector<int>& ages) {
     sort(ages.begin(),ages.end());
     int ans = 0, frIdx;

        for(int  i = 0; i < ages.size(); i++){
            int val = (ages[i] * 0.5) + 7;
            frIdx = binarySearch(i-1,val,ages);
            if(frIdx != -1) ans+=i-frIdx;
            int index = i-1;
            int value = ages[i];
            while(index>=0&&ages[index]==value&&ages[index]>val){
                ans++;
                index--;
            }
        }
        
        return ans;
}

};