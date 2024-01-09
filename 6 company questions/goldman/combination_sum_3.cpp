// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void solve(int k, int index, int sum, vector<int>& v, vector<int>& output, vector<std::vector<int>>& ans) {
    if (sum == 0 && output.size() == k) {
        ans.push_back(output);
        return;
    }

    for (int i = index; i < v.size(); ++i) {
        if (sum - v[i] >= 0) {
            output.push_back(v[i]);
            solve(k, i + 1, sum - v[i], v, output, ans);
            output.pop_back();
        }
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<std::vector<int>> ans;
    std::vector<int> output;
    solve(k, 0, n, v, output, ans);
    return ans;
    }
};