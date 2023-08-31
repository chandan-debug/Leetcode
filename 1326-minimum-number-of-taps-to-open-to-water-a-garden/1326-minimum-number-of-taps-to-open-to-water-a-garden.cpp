class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int > > arr;
        // int sz = ranges.size();

        for(int i=0;i<n+1;i++){
            arr.push_back({i - ranges[i], ranges[i] + i});
        }

        sort(arr.begin(), arr.end());

        int ans = 0;
        int curr = 0;
        int j = 0;

        while(j < n + 1 && curr < n){
            int nxt = -1;
            while(j < n + 1 && arr[j].first <= curr){
                nxt = max(nxt, arr[j].second);
                j++;
            }
            if(nxt == -1) return -1;
            ans++;
            curr = nxt;
        }
        if(curr < n) return -1;
        return ans;
    }
};