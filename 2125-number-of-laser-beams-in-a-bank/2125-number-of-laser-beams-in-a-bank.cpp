class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();//number of floors
        int prevDeviceCount=0;
        int result=0;
        for(int i=0;i<n;i++)
        {
            int currentDeviceCount=0;
            for(char ch:bank[i])
            {
                if(ch=='1')
                {
                    currentDeviceCount++;
                }
            }
            result+=(currentDeviceCount*prevDeviceCount);
            if(currentDeviceCount!=0)
            {
                prevDeviceCount=currentDeviceCount;
            }
        }
        return result;
        
    }
};