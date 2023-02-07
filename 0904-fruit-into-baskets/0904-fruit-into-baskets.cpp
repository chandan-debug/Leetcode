class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> mp;
        
        int i=0,j=0, counter = 0;
        
        while(j<fruits.size()){
            mp[fruits[j]]++;
            
            while(mp.size() > 2){
                if(mp[fruits[i]] == 1){
                    mp.erase(fruits[i]);
                }
                else{
                    mp[fruits[i]]--;
                }
                i++;
            }
            counter = max(counter, j-i+1);
            j++;
        }
        return counter;
    }
};