// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/


class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>aind;
        vector<int>bind;
        int n = a.size();
        int m = b.size();
        for(int i=0;i<s.size();i++){
           if(i+n-1<s.size()){
           string t1 = s.substr(i , n);
          // cout<<" t1 "<<t1<<" a "<<a<<endl;
               if(t1==a){
                  // cout<<"true"<<endl;
                   aind.push_back(i);
               }
           }
           if(i+m-1<s.size()){
           string t2 = s.substr(i , m);
            // cout<<" t2 "<<t2<<" b "<<b<<endl;
             if(t2==b){
                 //cout<<"true"<<endl;
                 bind.push_back(i);
             }
           }

 }


   n = aind.size();
   m = bind.size();
  vector<int>ans;
  int i = 0 , j=0;
  while(i<n&&j<m){
     if(abs(aind[i]-bind[j])<=k){
          ans.push_back(aind[i]);
          i++;
     }
     else {
         if(aind[i]>bind[j]){
             j++;
         }
         else
          i++;
     }
  }


       
        return ans;
    }
};