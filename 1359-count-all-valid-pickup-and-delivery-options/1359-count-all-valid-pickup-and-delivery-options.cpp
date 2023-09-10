class Solution {
public:
    int mod =  1e9+7;
    int countOrders(int n) {
        long long pro = 1;
        for(int i = 0; i< 2 * n; i++){
            if(i%2) pro = (1ll * pro * (i+1)/2)%mod;
            else pro = (1ll * pro * (i+1))%mod;
        }

        // cout<<power<<endl;
        return (pro)%mod;
    }
};