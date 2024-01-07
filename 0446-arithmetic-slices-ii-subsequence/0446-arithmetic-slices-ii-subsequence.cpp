class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n = a.size();
        int res = 0;
        unordered_map<long, int> mp[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                long d = (long)a[i]-a[j];
                int t = mp[j].find(d) == mp[j].end() ? 0 : mp[j][d];
                mp[i][d] += t+1;
                res+=t ;
                
            }
        }
        return res;
    }
};