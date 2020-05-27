
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* curr = head;
        while (l1 != nullptr || l2 != nullptr)
        {
            if (l1 == nullptr)
            {
                curr->next = l2;
                l2 = l2->next;
            }
            else if (l2 == nullptr)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else if (l1->val < l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            if (head->next == nullptr)
                head->next = curr;
            curr = curr->next;
        }
        ListNode* result = head->next;
        delete head;
        return result;
    }
};

int main()
{
}

/*
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/
