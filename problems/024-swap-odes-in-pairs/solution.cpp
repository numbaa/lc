#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* hhead = new ListNode;
        hhead->next = head;
        ListNode* curr = hhead;
        while (curr->next != nullptr && curr->next->next != nullptr)
        {
            ListNode* first = curr->next;
            ListNode* second = first->next;
            ListNode* third = second->next;
            curr->next = second;
            second->next = first;
            first->next = third;
            curr = first;
        }
        ListNode* to_return = hhead->next;
        delete hhead;
        return to_return;
    }
};
