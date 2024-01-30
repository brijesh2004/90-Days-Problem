// https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/

class Solution {
public:

// time limit exceeds
 int lcs(string X, string Y)
{
 
    int m = X.size();
    int n = Y.size();

    int L[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
 
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}


// using two loops
  
bool check(string s , string X){
    int n = s.size();
    int m = X.size();
    int j = 0;
    int i = 0;
    for(i=0;i<m;i++){
       bool flag = false;
        while(j<n){
            if(s[j]==X[i]){
                flag = true;
                j++;
                break;
            }
            j++;
        }
        if(flag==false){
            return false;
        }
    }
    return true;
}
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin() , d.end());
         string ans = "";
         for(auto it: d){
             if(it.length()>ans.length()){
                 bool t = check(s , it);
                //  cout<<"t"<<t<<endl;
                 if(t){
                     ans = it;
                 }
             }
         }
         return ans;
    }
};