#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        for (int i=0; i<haystack.size(); i++)
        {
            if (needle.size() > haystack.size()-i)
                return -1;
            if (needle[0] == haystack[i] && 0 == ::strncmp(needle.c_str(), haystack.c_str()+i, needle.size()))
                return i;
        }
        return -1;
    }
};