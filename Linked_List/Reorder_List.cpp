/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* midPoint3(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL and fast->next != NULL) {
            // fast = fast->next;
            // fast = fast->next;
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    void ReverseLL(ListNode* &head) {
        ListNode* current = head;
        ListNode* prev = NULL;
        ListNode* n;

        while (current != NULL) {
            n = current->next;
            current->next = prev;
            prev = current;
            current = n;
        }
        //current==NULL
        //prev=last node or the first node of the reverse ll.
        head = prev;
    }
    void reorderList(ListNode* head) {
        if (head == NULL or head->next == NULL) {
            return;
        }

        ListNode* m = midPoint3(head);
        ListNode* h1 = head;
        ListNode* h2 = m->next;
        m->next = NULL;

        ReverseLL(h2);

        ListNode *x, *y;

        while (h2) {
            x = h1->next;
            y = h2->next;

            h1->next = h2;
            h1 = x;
            h2->next = h1;
            h2 = y;
        }
    }
};