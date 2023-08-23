class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;

        int n = s.size();
        priority_queue<pair<int, char>> maxHeap;
        for (int i = 0; i < 26; ++i) {
            if (count[i] > (n + 1) / 2) return "";
            if (count[i] > 0) maxHeap.push({count[i], 'a' + i});
        }

        string ans = "";
        while (maxHeap.size() >= 2) {
            auto top1 = maxHeap.top(); maxHeap.pop();
            auto top2 = maxHeap.top(); maxHeap.pop();
            ans += top1.second;
            ans += top2.second;
            if (--top1.first > 0) maxHeap.push(top1);
            if (--top2.first > 0) maxHeap.push(top2);
        }

        if (!maxHeap.empty()) ans += maxHeap.top().second;

        return ans;
    }
};