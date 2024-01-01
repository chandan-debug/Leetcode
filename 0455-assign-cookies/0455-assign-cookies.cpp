class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)
        return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,c=0,i=0;
        while(i<g.size() and j<s.size()){
            if(g[i]<=s[j]){
                i++,j++,c++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};