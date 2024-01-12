class Solution {
public:
    bool halvesAreAlike(string s) {
        int count1=0,count2=0;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        for(int i=0;i<s.length();i++){
            if(i<s.length()/2){
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                count1++;
            }else{
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
                count2++;
            }
        }
        if(count1==count2) return true;
        return false;
    }
};