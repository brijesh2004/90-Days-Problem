//https://leetcode.com/problems/matrix-cells-in-distance-order/



class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {

        // using BFS


    //     vector<vector<int>>ans;
    //     vector<vector<int>>v;
    //    vector<vector<int>>mp(rows , vector<int>(cols , 0));
    //     queue<pair<int , int>>q;

    //     q.push({rCenter , cCenter});
    //       mp[rCenter][cCenter] = 1;
    //     //  v.push_back({0 , rCenter ,cCenter});

    //     while(!q.empty()){
    //         auto [r ,c] = q.front();
    //         // ans.push_back({r,c});
    //        v.push_back({abs(r-rCenter)+abs(c-cCenter) , r,c});
    //       // cout<<" dis "<<abs(r-rCenter)+abs(c-cCenter)<<" r "<< r<<" c "<<c<<endl;

    //         q.pop();

          
    //         //move up
    //         if(r-1>=0&&!mp[r-1][c]){
    //               mp[r-1][c] = 1;
    //           q.push({r-1,c});
    //         }
    //         if(c-1>=0&&!mp[r][c-1]){
    //               mp[r][c-1] = 1;
    //           q.push({r,c-1});
    //         }
    //         //down
    //         if(r+1<rows&&!mp[r+1][c]){
    //               mp[r+1][c] = 1;
    //           q.push({r+1,c});
    //         }
    //         //right 
    //          if(c+1<cols&&!mp[r][c+1]){
    //                mp[r][c+1] = 1;
    //           q.push({r,c+1});
    //         }

    //         // all diagonal
    //         if(r-1>=0&&c-1>=0&&!mp[r-1][c-1]){
    //               mp[r-1][c-1] = 1;
    //           q.push({r-1,c-1});
    //         }
    //         if(r-1>=0&&c+1<cols&&!mp[r-1][c+1]){
    //               mp[r-1][c+1] = 1;
    //           q.push({r-1,c+1});
    //         }
    //         if(r+1<rows&&c-1>=0&&!mp[r+1][c-1]){
    //               mp[r+1][c-1] = 1;
    //           q.push({r+1,c-1});
    //         }
    //         if(r+1<rows&&c+1<cols&&!mp[r+1][c+1]){
    //               mp[r+1][c+1] = 1;
    //           q.push({r+1,c+1});
    //         }
            

    //     }
    //     sort(v.begin() , v.end());
    //     for(auto it:v){
    //         ans.push_back({it[1] , it[2]});
    //     }
    //     return ans;


     

     // second method 
     vector<vector<int>>v;
     vector<vector<int>>ans;
     for(int i=0;i<rows;i++){
         for(int j=0;j<cols;j++){
           v.push_back({abs(i-rCenter)+abs(j-cCenter) , i,j});
         }
     }
     sort(v.begin() , v.end());
     for(auto it:v){
         ans.push_back({it[1],it[2]});
     }
     return ans;
    }
};