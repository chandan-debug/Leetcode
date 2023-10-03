class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
       
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        
        int count = 0;
       
        for(auto i = mp.begin(); i != mp.end(); i++)
        {
            if(i->second >1)
            {
                count += i->second * (i->second-1)/2;
            }
        }

        return count;
    }
};