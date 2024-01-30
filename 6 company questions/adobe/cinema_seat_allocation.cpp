// https://leetcode.com/problems/cinema-seat-allocation/


class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
         unordered_map<int , vector<int>>mp;
        for(auto it : reservedSeats){
            mp[it[0]].push_back(it[1]);
        }
        int ans = 0;
        ans = (n-mp.size())*2 ;  // for no allocation row
        for(auto it : mp){
            vector<int>vis(11 , 0);
            for(auto it1 : it.second){
                vis[it1] = 1;
            }
          if(vis[2]!=1&&vis[3]!=1&&vis[4]!=1&&vis[5]!=1){
              ans++;
              if(vis[6]!=1&&vis[7]!=1&&vis[8]!=1&&vis[9]!=1)
               ans++;
          }
          else if(vis[6]!=1&&vis[7]!=1&&vis[8]!=1&&vis[9]!=1)
               ans++;
          else if(vis[4]!=1&&vis[5]!=1&&vis[6]!=1&&vis[7]!=1)
           ans++;

        }
        return ans;
    }
};