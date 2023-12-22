class Solution {
public:
    int maxScore(string s) {
        int one=0;
       if(s.size()==2){
            if(s=="00") return 1;
            if(s=="10") return 0;
            if(s=="01") return 2;
            if(s=="11") return 1;   
        }
        vector<int> temp1(s.size(),0);
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1'){
                one++;
            }
            temp1[i]=one;
        }
        int zero=0;
        int maxi=INT_MIN;
        vector<int> temp0(s.size(),0);
       for(int i=0;i<s.size();i++){
           if(s[i]=='0'){
               zero++;
           }
           temp0[i]=zero;
       }
        for(int i=1;i<s.size()-1;i++){
            maxi=max(maxi,temp1[i]+temp0[i]);
        }
        return maxi;
    }
};