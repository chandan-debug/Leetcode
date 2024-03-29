/*Just see the pattern of how partition is made. We don't care about the middle elements of the Subarray, We just care about the boundaries of the Partition.

Let say arr= [a,b,c,d,e,f,g,h,i,j] and k=4
if i do partition like this:
a | b c d | e f g | h i j
sum= a+a + b+d + e+g + h+j
sum = a+ (a+b) + (d+e) + (g+h) + j;
........................|__________________|
So we need maximize and minimize this part to get the answer.

So, We store sum of pair of consecutive elements in a vector and then sort it.
After that we just give the Difference between maxi and mini.

ex: arr=[1 , 3 , 5 , 1] k=2;

1 | 3 5 1 , sum is 1+1 + 3+1 => 1+ (1+3) +1
1 3 | 5 1 , sum is 1+3 + 5+1 => 1+ (3+5) +1
1 3 5 | 1 , sum is 1+5 + 1+1 => 1+ (5+1) +1
Complexity
Time complexity: O(NlogN), We sort the store vector.

Space complexity: O(N), we made a store vector
*/
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> store;
        for(int i=1;i<weights.size();i++){
            store.push_back(weights[i]+weights[i-1]);
        }
        sort(store.begin(),store.end());
        int n=store.size();
        long long mini=0;
        for(int i=0;i<k-1;i++){
            mini+= store[i];
        }

        long long maxi=0;
        for(int i=0;i<k-1;i++){
            maxi+= store[n-1-i];
        }
        return maxi - mini;
    }
};