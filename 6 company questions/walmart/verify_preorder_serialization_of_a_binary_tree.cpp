 //https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/


 class Solution {
public:
    bool isValidSerialization(string preorder) {
    //     vector<string>v;
    //     string s = "";
    //     for(auto it:preorder){
    //         if(it==','){
    //               v.push_back(s);
    //               s="";
    //         }   
    //         else{
    //          s+=it;
    //         }
    //     }
    //     v.push_back(s);

    //     // for(auto it: v){
    //     //     cout<<it<<":";
    //     // }
    //     int size = v.size()-1;
    //     stack<string>st;
    //     while(size>=0){
    //      if(v[size]!="#"){
    //         if(st.size()>=2){
    //            string top1 = st.top();
    //             st.pop();
    //            string top2 = st.top();
    //            st.pop();
    //            if(top1=="#"&&top2=="#"){
    //                st.push("#");
    //            }
    //            else{
    //                return false;
    //            }
    //         }
    //         else{
    //             return false;
    //         }
    //      }
    //      else{
    //         st.push(v[size]);
    //      }
    //      size--;
    //     }
    //     if(st.size()==1&&st.top()=="#"){
    //         return true;
    //     }
    //     return false;



     int nodes = 1;
        preorder += ',';
        for(int i=0;i<preorder.size();i++){
          if(preorder[i]!=',')continue;
          nodes--;
          if(nodes<0)return false;
          if(preorder[i-1]!='#')nodes+=2;  
        }
    return nodes==0;
    }
};