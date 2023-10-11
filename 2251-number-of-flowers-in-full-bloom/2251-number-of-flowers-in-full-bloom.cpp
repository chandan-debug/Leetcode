class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int,int>mp;
        int n = flowers.size();
        for(auto vec: flowers)
        {
            mp[vec[0]]++;
            mp[vec[1]+1]--;
        }

        int prev=0;
        for(auto &it:mp)
        {
            it.second+=prev;
            prev = it.second;
        }
        
        vector<int>ans;
        for(auto p:people)
        {
            auto it = mp.lower_bound(p);

            if(mp.find(p)!=mp.end())ans.push_back(it->second);
            else if(it==mp.begin())ans.push_back(0);
            else{
                it--;
                ans.push_back(it->second);
            }
        }

        return ans;
    }
};