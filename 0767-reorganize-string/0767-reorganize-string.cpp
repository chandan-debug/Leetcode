class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26, 0);  // Initialize an array to store the count of each character.
        for (char c : s) count[c - 'a']++;  // Count the frequency of each character in the string.

        int n = s.size();  // Get the length of the input string.
        priority_queue<pair<int, char>> maxHeap;  // Create a max heap to store characters and their counts.
        
        // Populate the max heap with characters and their counts.
        for (int i = 0; i < 26; ++i) {
            if (count[i] > (n + 1) / 2) return "";  // If a character's count is too high, a valid arrangement isn't possible.
            if (count[i] > 0) maxHeap.push({count[i], 'a' + i});
        }

        string ans = "";  // Initialize the result string.
        
        // Construct the reorganized string by extracting characters from the max heap.
        while (maxHeap.size() >= 2) {
            auto top1 = maxHeap.top(); maxHeap.pop();  // Extract the character with the highest count.
            auto top2 = maxHeap.top(); maxHeap.pop();  // Extract the character with the second highest count.
            ans += top1.second;  // Append the characters to the result string.
            ans += top2.second;
            if (--top1.first > 0) maxHeap.push(top1);  // Decrement the count of extracted characters and push them back if count > 0.
            if (--top2.first > 0) maxHeap.push(top2);
        }

        // If there's a character left in the heap (odd frequency), append it to the result.
        if (!maxHeap.empty()) ans += maxHeap.top().second;

        return ans;  // Return the reorganized string.
    }
};
