class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if((double) dist.size()-1>=hour)
            return -1;
        int left=1;
        int right=(int)10e7;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(condition(mid,dist,hour)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
        
    }
    public : bool condition(int s,vector<int>&dist,double hour){
        double time=0;
        for(int i=0;i<dist.size()-1;i++){
            time+=dist[i]/s;
            time+=(dist[i]%s==0)?0:1;
        }
        time+=dist[dist.size()-1]*1.0/s;
        return time<=hour;
    }
};

// TC=O(N*log(M))
//     SC=O(1)