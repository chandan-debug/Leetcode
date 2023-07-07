class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
     int extra=0,mx=0;
        int i=0,j=0;
        while(j<answerKey.size()){ //For consecutive TRUE
            if(answerKey[j]=='F'){
                extra++;
                while(extra>k){
                    if(answerKey[i]=='F')extra--;
                    i++;
                }
            }
            mx = max(mx,j-i+1);
            j++;
        }
        i=0;j=0;
        extra=0;
        while(j<answerKey.size()){ //For consecutive FALSE
            if(answerKey[j]=='T'){
                extra++;
                while(extra>k){
                    if(answerKey[i]=='T')extra--;
                    i++;
                }
            }
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};