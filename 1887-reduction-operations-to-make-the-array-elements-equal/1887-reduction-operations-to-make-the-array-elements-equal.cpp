class Solution {
public:
    int reductionOperations(vector<int>& nums) 
{
   priority_queue<pair<int,int>>pq;
   unordered_map<int,int>mp;
   for(int i=0;i<nums.size();i++)
   {
   	  mp[nums[i]]++;
   }
   for(auto it=mp.begin();it!=mp.end();it++)
   {
   	  pq.push(make_pair(it->first,it->second));   //element , frequency
   }
   int ans=0;
   pair<int,int>p;
   pair<int,int>temp;
   while(true)
   {
   	  p =pq.top();
   	  pq.pop();
   	  
   	  if(pq.size()==0)
   	  {
   	      return ans;	
      }
      else if(pq.size()>0)
      {
      	  ans=ans+p.second;
          temp=pq.top();
          pq.pop();
          temp.second=temp.second+p.second;
          pq.push(temp);
      	  //pq.top().second=pq.top().second+p.second;
	  }
   }
   return -1;
}
};