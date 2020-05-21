#include <string>
#include <iostream>
#include <queue>
using namespace std;

struct Item
{
    int x;
    int y;
    char c;
    bool operator<(const Item& other) const
    {
        if (x > other.x) return true;
        if (x == other.x && y > other.y) return true;
        return false;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        priority_queue<Item> pqueue;
        const bool Zig = true;
        const bool Zag = false;
        bool state = Zig;
        int i = -1, j = 0;
        for (auto& c : s)
        {
            if (state == Zig)
            {
                i++;
            }
            else
            {
                i--;
                j++;
            }
            pqueue.push({i, j, c});
            if (state == Zig && i == numRows-1)
                state = Zag;
            else if (state == Zag && i == 0)
                state = Zig;
        }
        for (int i=0; i<s.size(); i++)
        {
            s[i] = pqueue.top().c;
            pqueue.pop();
        }
        return s;
    }
};


int main()
{
    string s1 = "PAYPALISHIRING"; //"PAHNAPLSIIGYIR"
    int n1 = 3;
    string s2 = "PAYPALISHIRING"; //"PINALSIGYAHRPI"
    int n2 = 4;
    string s3 = "AB";
    int n3 = 1;
    /*
     * P     I    N
     * A   L S  I G
     * Y A   H R
     * P     I
     */
    Solution s;
    std::cout << s1 << ":PAHNAPLSIIGYIR:" << s.convert(s1, n1) << std::endl;;
    std::cout << s2 << ":PINALSIGYAHRPI:" << s.convert(s2, n2) << std::endl;;
    std::cout << s3 << ":AB:" << s.convert(s3, n3) << std::endl;
    return 0;
}
