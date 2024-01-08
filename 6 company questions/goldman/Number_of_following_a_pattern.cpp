// https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
       string ans = "";
       stack<int>st;
       int i = 0;
       int n = S.size();
       while(i<=n){
           st.push(i+1);
           if(i==n||S[i]=='I'){
               while(!st.empty()){
                   ans+=to_string(st.top());
                   st.pop();
               }
           }
           i++;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends