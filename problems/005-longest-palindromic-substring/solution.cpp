#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string pstr;
        for (int i=0; i<s.size(); i++)
        {
            for (int j=i,k=i+1; j>=0 && k<size && s[j]==s[k]; j--,k++)
            {
                if (k-j+1>pstr.size())
                {
                    pstr = s.substr(j, k-j+1);
                    //std::cout << pstr << i << ',' << j << ',' << k << std::endl;
                }
            }
            for (int j=i,k=i; j>=0 && k<size && s[j]==s[k]; j--,k++)
            {
                if (k-j+1>pstr.size())
                {
                    pstr = s.substr(j, k-j+1);
                    //std::cout << pstr << i << ',' << j << ',' << k << std::endl;
                }
            }
        }
        return pstr;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {
        "aabc",
        "xxxx",
        "4x5dsasdx",
        "a",
        "ac",
        ""
    };
    for (auto& str : strs)
    {
        std::cout << str << ':' << s.longestPalindrome(str) << '\n';
    }
    return 0;
}
