class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y){
            return (x+y+z)*2;
        }
        if(y>x){
           return 2*x+2*(x+1)+2*z;
        }
        
        return 2*y+2*(y+1)+2*z;
        
    }
};