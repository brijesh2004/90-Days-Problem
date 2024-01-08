//  https://leetcode.com/problems/random-flip-matrix/

class Solution {
public:
    int m,n;
     int i = 0,j=0;
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
    }
    
    vector<int> flip() {
        int I = i, J = j; 
        if(j + 1 < n) j++; 
        else if(i + 1 < m){ 
            i++;
            j = 0;
        }
        else i = 0,j = 0; 
        return {I,J};
    }
    
    
    void reset() {
      
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */