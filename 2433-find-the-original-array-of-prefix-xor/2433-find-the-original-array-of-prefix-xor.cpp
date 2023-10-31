class Solution {
public:
    vector<int> findArray(vector<int>& pref) 
    {
        vector<int>ans(pref.size());
        int l=pref.size()-1;
        for(l;l>0;l--)
        {
            ans[l] = (pref[l]^pref[l-1]);
        }
        ans[0] = pref[0];
        return ans;
    }
};