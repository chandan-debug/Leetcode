class Solution {
public:
    int repeatedStringMatch(std::string a, std::string b) {
        std::string A = a;
        int s = 1;
        int repeat = b.length() / a.length();
        for (int i = 0; i < repeat + 2; i++) {
            if (a.find(b) != string::npos) {
                return s;
            } else {
                a += A;
                s++;
            }
        }
        return -1;
    }
};