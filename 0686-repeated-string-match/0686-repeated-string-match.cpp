class Solution {
public:
    int repeatedStringMatch(string s, string b) {
          
          if(s==b) return 1;  
         
          
         int count =0;  
         string str=s;
         while(s.length()<=10000) 
         { 
              count++; 
              int q=s.find(b);
         if(q!=-1) 
         { 
             return count ;
         } 
              s+=str;
         } 
        return -1;

    }
};