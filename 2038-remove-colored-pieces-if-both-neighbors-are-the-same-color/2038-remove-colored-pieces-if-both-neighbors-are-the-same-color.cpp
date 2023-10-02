class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int aliceCount = 0, bobCount = 0;
        
        for (int i = 1; i < n - 1; i++) {
            if (colors[i] == 'A' && colors[i - 1] == 'A' && colors[i + 1] == 'A') {
                aliceCount++;
            } else if (colors[i] == 'B' && colors[i - 1] == 'B' && colors[i + 1] == 'B') {
                bobCount++;
            }
        }
        
        return aliceCount > bobCount;
    }
};