#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

inline void aux(int& val, int& count)
{
    if (val >= 10)
    {
        val -= 10;
        count = 1;
    }
    else
    {
        count = 0;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* current = result;
        ListNode* prev = nullptr;
        int count = 0;
        while (true)
        {
            int val;
            if (l1 && l2)
            {
                val = l1->val + l2->val + count;
                aux(val, count);
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 && !l2)
            {
                val = l1->val + count;
                aux(val, count);
                l1 = l1->next;
            }
            else if (!l1 && l2)
            {
                val = l2->val + count;
                aux(val, count);
                l2 = l2->next;
            }
            else
            {
                if (count == 1)
                {
                    current->val = 1;
                }
                else
                {
                    if (!(prev->next)) delete prev->next;
                    prev->next = nullptr;
                }
                return result;
            }
            current->val = val;
            prev = current;
            current->next = new ListNode();
            current = current->next;
        }
        return nullptr;
    }
};

//NOTES: 对于这种使用链表的方式，可以提前生成Node，方便使用。后面判断不需要这个Node，再把这个Node删除。