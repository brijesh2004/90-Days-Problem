//{ Driver Code Starts
#include <bits/stdc++.h>



//   problem link https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        vector<int>ans(2);
       sort(arr.begin(),arr.end());
       if(arr[n-1]!=n){
           ans[1]=n;
       }
       else ans[1]=1;
       for(int i=1;i<n;i++){
           if(arr[i]-arr[i-1]<1){
               ans[0]=arr[i];
           }
           if(arr[i]-arr[i-1]>1){
               ans[1]=(arr[i]-1);
           }
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends