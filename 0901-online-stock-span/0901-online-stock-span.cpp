class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index;
    StockSpanner() {
        index=-1;
    }
    
    int next(int price) {
        index+=1;
        while(!st.empty() && price>=st.top().second){
            st.pop();
        }
        if(st.empty()){
            st.push({index,price});
            return index+1;
        }
        int curr=st.top().first;
        st.push({index,price});
        return index-curr;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */