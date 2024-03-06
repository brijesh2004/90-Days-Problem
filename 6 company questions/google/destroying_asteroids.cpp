//https://leetcode.com/problems/destroying-asteroids/

class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& a) {
        long long mass = m;
        sort(a.begin(), a.end());
        for(int i=0;i<a.size();i++){
            if(mass>=a[i]){
                mass+=a[i];
                continue;
            }
            return false;
        }
        return true;
    }
};