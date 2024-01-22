//https://leetcode.com/problems/top-k-frequent-words/submissions/1153287162/


bool cmp(pair<string, int>& a, 
        pair<string, int>& b) 
{ 
    if(a.second==b.second)
     return a.first<b.first;
    return a.second > b.second; 
} 
struct compare {
    bool operator()(pair<string,int> &a,pair<string,int> &b) {
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        // first method 
    //     unordered_map<string , int>mp;
    //     for(auto  it: words){
    //         mp[it]++;
    //     }
    //    vector<pair<string , int>>v(mp.begin(), mp.end());
    //    sort(v.begin(),v.end(), cmp);
    // vector<string>ans;
    //   for(auto it:v){
    // ans.push_back(it.first);
    // if(ans.size()==k)
    //  break;
    //   }
    //   return ans;

   // second method




    //    unordered_map<string,int> hm;
    //     for(auto w:words){
    //         hm[w]++;
    //     }
    //     priority_queue<pair<string,int>,vector<pair<string,int>>, compare> pq;
    //     for(auto i: hm){
    //         pq.push({i.first, i.second});
    //         if(pq.size()>k){
    //             pq.pop();
    //         }
    //     }
        
    //     vector<string> res(k);
    //     int n=res.size()-1;
    //     while(!pq.empty()){
    //         auto top=pq.top();
    //         res[n]=top.first;
    //         n--;
    //         pq.pop();
    //     }
    //     return res;




// third method 
         unordered_map<string,int>mp;
        vector<string>ans;
        for(int  i=0 ; i<words.size()  ; i++){
            mp[words[i]]++;
        }
        vector<pair<string,int>>vt;
        for(auto a: mp){
            vt.push_back(a);
        }
        auto cmp = [&](auto &a , auto &b){
            if(a.second==b.second){
                return a.first < b.first;
            }
            return a.second> b.second;
        };
        sort(vt.begin() ,  vt.end() , cmp);

        for(auto a: vt){
            ans.push_back(a.first);
            k--;
            if(k==0){
                break;
            }
        }
        return ans;
    }
};