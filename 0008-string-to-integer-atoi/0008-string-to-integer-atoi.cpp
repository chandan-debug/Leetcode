class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0)
            return 0;
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        string str = s.substr(i);

        int sign = 1;
        long ans = 0;
        int max = INT_MAX, min = INT_MIN;
        if (str[0] == '+') {
    sign = 1;
    i = 1;
} else if (str[0] == '-') {
    sign = -1;
    i = 1;
} else {
    sign = 1;
    i = 0;
}

        while (i < str.size() && isdigit(str[i])) {
            ans = ans * 10 + (str[i] - '0');
            if (sign == -1 && -1 * ans < min)
                return min;
            if (sign == 1 && ans > max)
                return max;
            i++;
        }
        return sign * ans;
    }
};
