class Solution {
public:
    void solve(int n, int k, int i, vector<int>& combination, vector<vector<int>>& result) {
        if (k == 0) {
            result.push_back(combination);
            return;
        }

        for (int j = i; j <= n; j++) {
            combination.push_back(j);
            solve(n, k - 1, j + 1, combination, result);
            combination.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        solve(n, k, 1, combination, result);
        return result;
    }
};
