class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        set<int> s;

        for(auto it : nums)
        s.insert(it);

        vector<int> temp;
        for(auto it : s)
        temp.push_back(it);
        int ans = n-1;

        for(int i = 0; i < temp.size(); i++)
        {
            int a = temp[i];
            int ind = upper_bound(temp.begin(),temp.end(),a+n-1) - temp.begin();

            // if(ind == temp.size()) ind = temp.size() -1;

            // if(temp[ind] != a + n - 1) ind--;

            // if(ind < 0) ind = 0;

            cout << ind << endl; 

            int elements = ind - i;

            ans = min(ans,n - elements);
        }

        return ans;
    }
};