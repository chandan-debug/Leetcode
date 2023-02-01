class Solution {
public:
    bool check(string str1,string str2,string str){
        int s1 = str1.size(),s2=str2.size(), s3= str.size();
        int l1 = s1/s3 , l2 = s2/s3;
        string x="",y="";

        while(l1--) x = x + str;
        while(l2--) y = y + str;
        return (x==str1) && (y==str2);
    }
    string gcdOfStrings(string str1, string str2) {
        string ans = "";
        if(str1.size()<str2.size()) swap(str1,str2);

        for(int i=1;i<=str2.size();i++){
            string str = str2.substr(0,i);
            if(check(str1,str2,str)){
                ans = str;
            }
        }

        return ans;
    }
};