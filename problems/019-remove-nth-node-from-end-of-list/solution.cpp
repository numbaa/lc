struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hhead = new ListNode;
        hhead->next = head;
        ListNode* front = hhead;
        ListNode* end = hhead;
        int distance = 0;
        while (end->next != nullptr)
        {
            end = end->next;
            if (distance != n)
                distance++;
            else
                front = front->next;
        }
        ListNode* to_delete = front->next;
        front->next = to_delete->next;
        if (head == to_delete)
        {
            delete head;
            ListNode* to_return = front->next;
            delete front;
            return to_return;
        }
        delete to_delete;
        delete hhead;
        return head;
    }
};


int main()
{
}


/*
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 */
