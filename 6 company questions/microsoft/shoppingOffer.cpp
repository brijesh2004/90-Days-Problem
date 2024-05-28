class Solution {
public:

 unordered_map<string, int> memo;
    
    string hashKey(const vector<int>& needs) {
        string key;
        for (int need : needs) {
            key += to_string(need) + ",";
        }
        return key;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
    string key = hashKey(needs);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        int ans = 0;
        for (int i = 0; i < price.size(); ++i) {
            ans += price[i] * needs[i];
        }
        
        for (const auto& offer : special) {
            vector<int> tempNeeds(needs);
            bool validOffer = true;
            for (int j = 0; j < needs.size(); ++j) {
                tempNeeds[j] -= offer[j];
                if (tempNeeds[j] < 0) {
                    validOffer = false;
                    break;
                }
            }
            if (validOffer) {
                ans = min(ans, offer.back() + shoppingOffers(price, special, tempNeeds));
            }
        }
        
        memo[key] = ans;
        return ans;
    }
};