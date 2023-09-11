class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < groupSizes.size(); i++){
            mp[groupSizes[i]].push_back(i);
        }

       
        for(auto m: mp){
            vector<int> vec;
            for(auto mm: m.second){
                if(vec.size() == m.first){
                    ans.push_back(vec);
                    vec.clear();
                }
                vec.push_back(mm);       
            }
            ans.push_back(vec);
        }

        return ans;
    }
};