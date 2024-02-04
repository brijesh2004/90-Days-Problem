// https://leetcode.com/problems/count-collisions-on-a-road/

class Solution {
public:
    int countCollisions(string dir) {
        int ans = 0;
        stack<char>s;
        for(int i=0;i<dir.size();i++){
           if(s.empty())
            s.push(dir[i]);
        else if( (s.top() == 'S') && (dir[i] == 'L'))
         ans++;
        else if(s.top() == 'R' && (dir[i] == 'L')) {
            s.pop();
            dir[i] = 'S';
            i--;
            ans += 2;
        }
        else if( (s.top() == 'R') && (dir[i] == 'S')){
            s.pop();
            dir[i] = 'S';
            i--;
            ans++;
        }
        else{
            s.push(dir[i]);
        }
        }
        return ans;
    }
};