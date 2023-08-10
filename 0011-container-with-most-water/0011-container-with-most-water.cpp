class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int t1=0,t2=0,cnt=0;
        int rt=n-1,lt=0;
        while(lt<rt){
            if(height[lt]>height[rt]){
                t1=min(height[rt],height[lt])*(abs(rt-lt));
                cnt=max(t1,cnt);
                rt--;
            }
            else{
                t2=min(height[rt],height[lt])*(abs(rt-lt));
                cnt=max(cnt,t2);
                lt++;
            }
        }
        return cnt;
    }
};