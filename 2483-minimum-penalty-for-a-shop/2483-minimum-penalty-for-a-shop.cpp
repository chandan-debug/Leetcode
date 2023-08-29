class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        int penalty=0;
        
        // no customer shop is open
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                penalty++;
            }
        }
        int ans=n;
        int mini=penalty;
        // customer coming but shop close before
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                penalty++;
            }
            else{
                penalty--;
            }
            if(penalty<=mini){
                mini=penalty;
                ans=i;
            }
        }
        return ans;
    }
};