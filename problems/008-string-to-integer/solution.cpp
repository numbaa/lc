#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int64_t result = 0;
        int i = 0;
        int sign = 1;
        const auto max = std::numeric_limits<int>::max();
        const auto min = std::numeric_limits<int>::min();
        while (i<str.size() && str[i] == ' ') i++;
        if (i<str.size())
        {
            if (str[i] == '-') { sign = -1; i++; }
            else if (str[i] == '+') { i++; }
        }
        while (i<str.size() &&  std::isdigit(str[i]))
        {
            result = result * 10 + str[i] - '0';
            if (result > max && sign == 1) return max;
            if (-result < min && sign == -1) return min;
            i++;
        }
        return result * sign;
    }
};


int main()
{
    vector<string> vstr{"", "123abc", "123", "   4", "   -42", "-91283472332"};
    Solution s;
    for (auto& str : vstr)
    {
        std::cout << str << ':' << s.myAtoi(str) << std::endl;
    }
    return 0;
}
