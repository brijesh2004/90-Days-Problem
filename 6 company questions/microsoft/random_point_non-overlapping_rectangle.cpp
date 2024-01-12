//https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/


class Solution {
public:
    vector<vector<int>>v;
    int i,j ,select;
   
    Solution(vector<vector<int>>& rects) {
        v = rects;
        i = rects[0][0];
        j = rects[0][1];
        select=0;
    }
    
    vector<int> pick() {

        if(i!=v[select][2]){
         i++;
        }
        else if(i==v[select][2]&&j!=v[select][3]){
           j++;
           i = v[select][0];
        }
        else if(i==v[select][2]&&j==v[select][3]){
            select = (select < v.size() - 1) ? select + 1 : 0;
            i = v[select][0];
            j = v[select][1];
        }

        return {i,j};
         
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */