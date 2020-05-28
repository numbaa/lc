#include <iostream>
#include <queue>
#include <vector>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode* left, const ListNode* right) {
            return left->val > right->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto node : lists)
        {
            if (node != nullptr)
                pq.push(node);
        }
        ListNode* head = new ListNode;
        ListNode* curr = head;
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            curr->next = top;
            curr = curr->next;
            if (top->next != nullptr)
                pq.push(top->next);
        }
        ListNode* to_return = head->next;
        delete head;
        return to_return;
    }
};

int main()
{
}
