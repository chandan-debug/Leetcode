class Solution {
public:
    int calPoints(vector<string>& operations) {
        int score = 0;
        vector<int> nums;  

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                if (nums.size() >= 2) {
                    int prev1 = nums[nums.size() - 1];
                    int prev2 = nums[nums.size() - 2];
                    int currentScore = prev1 + prev2;
                    score += currentScore;
                    nums.push_back(currentScore);
                }
            } else if (operations[i] == "D") {
                if (!nums.empty()) {
                    int prev = nums[nums.size() - 1];
                    int currentScore = 2 * prev;
                    score += currentScore;
                    nums.push_back(currentScore);
                }
            } else if (operations[i] == "C") {
                if (!nums.empty()) {
                    int removedScore = nums.back();
                    score -= removedScore;
                    nums.pop_back();
                }
            } else {
                int currentScore = stoi(operations[i]); 
                score += currentScore;
                nums.push_back(currentScore);
            }
        }
        return score;
    }
};
