class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int min1=1e9, min2=1e9;
        int n=prices.size();
        for(int i=0; i<n; i++){
            int c=prices[i];
            if(c<=min1){
                min2=min1;
                min1=c;
            }else if(c<min2){
                min2=c;
            }
        }
        int diff=money-min1-min2;
        return diff>=0?diff:money;
    }
};