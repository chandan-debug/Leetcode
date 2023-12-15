class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n=paths.size();
        int m=paths[0].size();
        unordered_set<string> out;
        unordered_set<string> in;
        for(auto& way:paths){
            out.insert(way[0]);
            in.insert(way[1]);
        }
        for(auto& des:in){
            if(out.find(des)==out.end()){
                return des;
            }
        }
        return paths[n-1][m-1];
    }
};