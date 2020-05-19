#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i1 = 0, i2 = 0, i3 = -1;
        int front, end, front_num = 0, end_num = 0;
        int len = nums1.size() + nums2.size();
        if (len % 2 == 0) {
            end = len / 2;
            front = end - 1;
        } else {
            end = len / 2;
            front = end;
        }
        while (i3 < end) {
            i3++;
            int curr;
            if (i1 >= nums1.size()) {
                curr = nums2[i2];
                i2++;
            } else if (i2 >= nums2.size()) {
                curr = nums1[i1];
                i1++;
            } else {
                if (nums1[i1] < nums2[i2]) {
                    curr = nums1[i1];
                    i1++;
                } else {
                    curr = nums2[i2];
                    i2++;
                }
            }
            if (i3 == front)
                front_num = curr;
            if (i3 == end)
                end_num = curr;
        }
        return (front_num + end_num) / 2.0;
    }
};






int main()
{
    Solution s;
    vector<int> a1{1,3};
    vector<int> a2{2};
    vector<int> a3{1,3,6};
    vector<int> a4{1,5};
    vector<int> a5{1,3};
    vector<int> a6;
    std::cout << s.findMedianSortedArrays(a1, a2) << std::endl;
    std::cout << s.findMedianSortedArrays(a3, a4) << std::endl;
    std::cout << s.findMedianSortedArrays(a5, a6) << std::endl;
    return 0;
}
