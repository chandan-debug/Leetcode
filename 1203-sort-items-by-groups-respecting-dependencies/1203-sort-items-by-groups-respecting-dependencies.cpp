class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = i + m;
            }
        }

        unordered_map<int, vector<int>> graph0;
        vector<int> seen0(m + n, 0);
        unordered_map<int, vector<int>> graph1;
        vector<int> seen1(n, 0);

        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                if (group[j] != group[i]) {
                    graph0[group[j]].push_back(group[i]);
                    seen0[group[i]]++;
                }

                graph1[j].push_back(i);
                seen1[i]++;
            }
        }

        vector<int> top0 = fn(graph0, seen0);
        int a = top0.size();
        int b = seen0.size();
        if (a != b) {
            return {};
        }

        vector<int> top1 = fn(graph1, seen1);
        int c = top1.size();
        int d = seen1.size();
        if (c != d) {
            return {};
        }

        unordered_map<int, int> map0;
        for (int i = 0; i < a; ++i) {
            map0[top0[i]] = i;
        }
        unordered_map<int, int> map1;
        for (int i = 0; i < c; ++i) {
            map1[top1[i]] = i;
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = i;
        }
        sort(result.begin(), result.end(), [&](int x, int y) {
            return make_pair(map0[group[x]], map1[x]) < make_pair(map0[group[y]], map1[y]);
        });

        return result;
    }

private:
    vector<int> fn(unordered_map<int, vector<int>>& graph, vector<int>& seen) {
        vector<int> ans;
        vector<int> stack;
        for (int k = 0; k < seen.size(); ++k) {
            if (seen[k] == 0) {
                stack.push_back(k);
            }
        }
        while (!stack.empty()) {
            int n = stack.back();
            stack.pop_back();
            ans.push_back(n);
            for (int s : graph[n]) {
                seen[s]--;
                if (seen[s] == 0) {
                    stack.push_back(s);
                }
            }
        }
        return ans;
    }
};