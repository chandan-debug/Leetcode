class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l=0, r=n;
        for(auto &e : left) l = max(l,e);
        for(auto &e : right) r = min(r,e);
        return max(l,n-r);
    }
};
