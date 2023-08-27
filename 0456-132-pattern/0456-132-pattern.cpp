class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> st;         // Initialize a stack to store elements
        int s = INT_MIN;       // Initialize a variable to track the potential third element
        int n = nums.size();   // Get the size of the input array
        
        // Traverse the array in reverse
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] < s) {
                return true;   // Check if current element is smaller than potential third element, return true
            }
            
            while (!st.empty() && nums[i] > st.top()) { // ex 35034 -> 354
                                // The while loop is used to update s to the maximum potential third element
                s = st.top();    // Update s with the value of the top element from the stack
                st.pop();        // Pop the element from the stack
            }
            
            st.push(nums[i]);   // Push the current element onto the stack for potential comparisons
        }
        
        return false;          // If no pattern is found, return false
    }
};