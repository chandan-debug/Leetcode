class Solution {
public:
    
    string convertToTitle(int columnNumber) {
        string ans = "";
        while(columnNumber)
        {
            columnNumber--;

            //extracting the last character and appending it to the string
            ans += 'A' + columnNumber%26;
            columnNumber /= 26;
        }

        //reversing because we appended characters in reverse order
        reverse(ans.begin(),ans.end());
        return ans;
    }
};