class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int first = 0;
        int end = nums.size() - 1;
        while (first <= end)
        {
            int mid = (first+end)/2;
            if (nums[mid]==target)
                return mid;

            if (nums[mid]<target)
                first = mid+1;
            else
                end = mid -1;
        }
        return first;
    }
};
