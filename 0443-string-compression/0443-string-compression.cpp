class Solution {
public:
    void rec(vector<char>&chars, int &j, int count){
        if(count==0)return;
        rec(chars,j,count/10);
        chars[j++]='0'+count%10;
    }
    int compress(vector<char>& chars) {
      int i=0,j=0,count=0,n=chars.size();
      while(i<n){
          chars[j++]=chars[i];
          count=1;
          while(i+1<n && chars[i]==chars[i+1]){
              i++;
              count++;
          }
          if(count>1){
              rec(chars,j,count);
          }
          i++;
      }
      return j;  
    }
};