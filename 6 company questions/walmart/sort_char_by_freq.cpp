// 
// https://leetcode.com/problems/sort-characters-by-frequency/

bool cmp(pair<char, int>& a, pair<char, int>& b) {
    return a.second > b.second; // Use '>' for descending order
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto it : s) {
            mp[it]++;
        }

        vector<pair<char, int>> sortedFreq(mp.begin(), mp.end());
        sort(sortedFreq.begin(), sortedFreq.end(), cmp);

        string ans = "";
        for (auto it : sortedFreq) {
            char a = it.first;
            int b = it.second;
            while (b--) {
                ans += a;
            }
        }

        return ans;
    }
};