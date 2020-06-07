#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <set>
using namespace std;

struct Pin {
    const std::string& origin;
    std::multiset<char> s;
    Pin(const std::string& _origin)
        : origin(_origin), s(_origin.begin(), _origin.end())
    {}

    bool operator<(const Pin& rhs) const
    {
        return s < rhs.s;
    }
    bool operator==(const Pin& rhs) const
    {
        return origin.size() == rhs.origin.size() &&
            s == rhs.s;
    }
    bool operator!=(const Pin& rhs) const
    {
        return !operator==(rhs);
    }
};

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::multiset<Pin> ms;
        for (auto& str : strs)
        {
            Pin p{str};
            ms.insert(p);
        }
        vector<vector<string>> result;
        string empty{"__invalid_stttttring"}; //估计是leetcode的系统加了什么编译选项，这里必须在堆上创建字符串
        Pin tmp{empty};
        const Pin* prev = &tmp;
        for (auto& p : ms)
        {
            if (*prev != p)
            {
                result.push_back({p.origin});
            }
            else
            {
                result.back().push_back(p.origin);
            }
            prev = &p;
        }
        return result;
	}
};

int main()
{
    Solution s;
    //vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs{""};
    auto result = s.groupAnagrams(strs);
    for (auto& group : result)
    {
        for (auto& item : group)
            cout << item << ", ";
        cout << '\n';
    }
    return 0;
}
