class Solution {
public:
    bool isAnagram(vector<int> &u,vector<int> &v){
        for(int i=0;i<26;i++){
            if(u[i]!=v[i])
            return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
    vector<int> v(26,0);
    vector<int> ans;
    int l=p.length();
    for(auto i:p) v[i-'a']++;
    vector<int> u(26,0);
    int i=0,j=0;
    while(j<s.length()){
        u[s[j]-'a']++;
        if(j-i+1==l){
            if(isAnagram(u,v)){
            ans.push_back(i);
            }
        }
        if(j-i+1<l){
            j++;
        }
        else{
            u[s[i]-'a']--;
            i++;
            j++;
        }
    }

    return ans;

    }

};