class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int maxElement = *max_element(arr.begin(), arr.end());
        if(k >= n)  return maxElement;
        int winner = arr[0];
        int streak = 0;
        for(int i=1; i<n; i++){
            if(arr[i] > winner){
                winner = arr[i];
                streak = 1;
            }
            else{
                streak++;
            }
            if(streak == k || winner == maxElement)
                return winner;
        }
        return winner;
    }
};