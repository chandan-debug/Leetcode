class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Create an unordered map to store the next greater elements
        unordered_map<int, int> nextgreater;
        // Create a stack to help find the next greater elements
        stack<int> st;
        
        // Iterate through nums2 in reverse order
        for(int i = nums2.size() - 1; i >= 0; i--) {
            // While the stack is not empty and the current element is greater than
            // the element at the top of the stack, pop elements from the stack
            while (!st.empty() && nums2[i] > st.top()) {
                st.pop();
            }
            // If the stack is empty, there's no greater element, so assign -1
            if (st.empty()) {
                nextgreater[nums2[i]] = -1;
            } else {
                // Otherwise, assign the element at the top of the stack as the next greater element
                nextgreater[nums2[i]] = st.top();
            }
            // Push the current element onto the stack
            st.push(nums2[i]);
        }
        
        // Create a vector to store the final results
        vector<int> result;
        // Iterate through nums1
        for (int i = 0; i < nums1.size(); i++) {
            // Push the next greater element (from the map) corresponding to the current element of nums1
            result.push_back(nextgreater[nums1[i]]);
        }
        
        // Return the final results
        return result;
    }
};
