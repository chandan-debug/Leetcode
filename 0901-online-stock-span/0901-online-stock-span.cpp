class StockSpanner {
public:
    stack<pair<int, int>> st;  // Stack to store pairs of (day index, stock price)
    int index;  // Current day index
    
    StockSpanner() {
        index = -1;  // Initialize the current day index
    }
    
    int next(int price) {
        index += 1;  // Move to the next day
        
        // Pop elements from stack while the current price is greater than or equal to the price on the stack top
        while (!st.empty() && price >= st.top().second) {
            st.pop();
        }
        
        if (st.empty()) {
            // If stack is empty, the current day's price is the highest encountered so far
            st.push({index, price});
            return index + 1;  // Span is the current index + 1
        }
        
        int curr = st.top().first;  // Get the index of the most recent day with a smaller price
        st.push({index, price});    // Push the current day's index and price onto the stack
        
        // Span is the difference between the current index and the index of the most recent smaller price day
        return index - curr;
    }
};
