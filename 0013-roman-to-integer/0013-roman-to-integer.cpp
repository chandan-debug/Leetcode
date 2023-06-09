class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I']=1;
         m['V']=5;
         m['X']=10;
         m['L']=50;
         m['C']=100;
         m['D']=500;
         m['M']=1000;
        
        int res=m[s.back()];
        
        for(int i=s.size()-2;i>=0;i--){
            if(m[s[i]]<m[s[i+1]]){
                res-=m[s[i]];
            }
            else{
                   res+=m[s[i]];
            }
        }
        return res;
        
        
    }
};