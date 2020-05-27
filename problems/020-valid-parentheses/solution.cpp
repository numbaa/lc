#include <stack>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto c : s)
        {
            if (c == '[' || c == '(' || c == '{')
                st.push(c);
            else if (st.empty())
                return false;
            else if ((st.top() == '[' && c == ']')
                    || st.top() == '(' && c == ')'
                    || st.top() == '{' && c == '}')
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};


int main()
{
    vector<string> ss { "({}[])", "{{)", "())" };
    Solution s;
    for (auto& str : ss)
        std::cout << str << ':' << s.isValid(str) << std::endl;
}
