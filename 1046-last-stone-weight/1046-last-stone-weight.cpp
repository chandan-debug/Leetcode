class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;

        for (int i = 0 ; i < n ; i ++)
        {
            pq.push(stones[i]);
        }

        int x , y;
        while (n != 1)
        {
            y = pq.top();
            pq.pop();

            x = pq.top();
            pq.pop();

            if (x == y)
            {    
                n = n-2;
                if (n == 0)
            return 0;
                continue;
            }
            else
            {
                y = y-x;
                pq.push(y);
            }
            n--;

            if (n == 0)
            return 0;
        }

        int lastWeight = pq.top();
        return lastWeight;
    }
};