class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int a = abs(fy-sy);
        int b = abs(fx -sx);
        if(a==0 && b==0 && t==1) return false;
        if(a==0 && b==0) return true;
        int ans = a+b;
        int f = min(a,b);
        int offset = 0;
        if(a<=b){
            offset = f + fx-sx-a;
        }else{
            offset = f+fy-sy-b;
        }
        ans = min(offset,ans);
        return abs(ans)<=t;
    }
};