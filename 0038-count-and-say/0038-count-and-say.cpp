class Solution {
public:
    string countAndSay(int n) {
      if(n==1) return "1";                       //if n==1, return "1"
    if(n==2) return "11";                      //if n==2, return "11"
    
    string s="11";                             //initialise s = "11"
    
    for(int i=3;i<=n;i++){
        
        string temp="";                        //empty string, temp
        s+= '$';                               //append a random character, therefore, s = "11$"
        int count=1;                           //initially count = 1
        
        for(int j=1;j<s.size();j++){           //traverse string s from idx 1 to s.size()
            
            if(s[j]!=s[j-1]){                  //if curr_character and prev_character doesn't match
                
                temp+= to_string(count);       //First,  add count to temp string
                temp+= s[j-1];                 //Second, add the character (prev_character)
                count=1;                       //Third,  reset the count
            }
            else count++;                      //if curr_character and prev_character match, increment count
            
        }
        
        s=temp;                                //Update string s wuth temp
    }
    
    return s;                                  //return s
}
};