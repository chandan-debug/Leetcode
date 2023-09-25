class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            // Sort the stones in descending order.
            sort(stones.begin(), stones.end(), greater<int>());

            // Take the two heaviest stones.
            int y = stones[0];
            int x = stones[1];

            // Remove the two heaviest stones.
            stones.erase(stones.begin());
            stones.erase(stones.begin());

            // Calculate the remaining stone's weight.
            int remainingWeight = abs(y - x);

            // If there's still a stone left, insert it back into the vector.
            if (remainingWeight != 0) {
                stones.push_back(remainingWeight);
            }
        }

        // If there's a stone left, return its weight; otherwise, return 0.
        return (stones.empty() ? 0 : stones[0]);
    }
};
