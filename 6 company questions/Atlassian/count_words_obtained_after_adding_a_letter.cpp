//  https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/


class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_map<string , int>mp;
        int ans = 0;
        for(int i=0;i<startWords.size();i++){
             string s = startWords[i];
             sort(s.begin(),s.end());
             mp[s]=1;
        }

        for(int i=0;i<targetWords.size();i++){
            string s = targetWords[i];
            sort(s.begin(), s.end()); 

            for(int j=0;j<s.size();j++){
                string k = s;
                k.erase(j , 1);
               // cout<<k<<endl;
                if(mp[k]){
                    ans++;
                    break;
                }
            }


        }

   return ans;
    }
};