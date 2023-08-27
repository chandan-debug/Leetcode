class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        
        // Create a dictionary to store jump distances for each stone
        unordered_map<int, unordered_set<int>> stone_jumps;
        
        // Initialize the first stone (position 0) with jump distance 0
        stone_jumps[0].insert(0);
        
        // Iterate through stones
        for (int i = 0; i < n; i++) {
            int stone = stones[i];
            
            // Iterate through possible jump distances for the current stone
            for (int jump : stone_jumps[stone]) {
                // Try jumps of k-1, k, and k+1 units
                for (int next_jump = jump - 1; next_jump <= jump + 1; next_jump++) {
                    if (next_jump > 0) {
                        int next_stone = stone + next_jump;
                        if (next_stone == stones.back()) {
                            return true; // Frog can reach the last stone
                        }
                        if (find(stones.begin(), stones.end(), next_stone) != stones.end()) {
                            // Add the new jump distance to the set of jump distances for the next stone
                            stone_jumps[next_stone].insert(next_jump);
                        }
                    }
                }
            }
        }
        
        return false; // Frog cannot reach the last stone
    }
};