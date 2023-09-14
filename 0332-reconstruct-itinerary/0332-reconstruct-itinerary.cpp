class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> outdegree;

    void recursion(vector<string>& res, string departure) {
        while (!outdegree[departure].empty()) {
            string top = outdegree[departure].top();
            outdegree[departure].pop();
            recursion(res, top);
        }
        res.push_back(departure);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            outdegree[tickets[i][0]].push(tickets[i][1]);
        }
        vector<string> res; 
        recursion(res, "JFK");
        reverse(res.begin(),  res.end());
        return res;
    }
};
