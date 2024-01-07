
//  https://www.geeksforgeeks.org/problems/run-length-encoding/1
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  string ans = "";
  int t=1;
  for(int i=1;i<src.length();i++){
      if(src[i]!=src[i-1]){
          ans+=src[i-1];
          ans+=to_string(t);
          t=1;
      }
      else{
          t++;
      }
      
  }
  ans+=src[src.length()-1];
   ans+=to_string(t);
   return ans;
          
}     
 
