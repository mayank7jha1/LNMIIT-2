
#include<iostream>
using  namespace std;

// struct ListNode {
// 	int val;
// 	ListNode *next;
// 	ListNode() : val(0), next(nullptr) {}
// 	ListNode(int x) : val(x), next(nullptr) {}
// 	ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

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

	bool isPalindrome(ListNode* head) {
		ListNode* m = midPoint3(head);

		ListNode* h1 = head;
		ListNode* h2 = m->next;

		ReverseLL(h2);
		m->next = NULL;

		while (h1 != NULL and h2 != NULL) {
			if (h1->val != h2->val) {
				return false;
			}
			h1 = h1->next;
			h2 = h2->next;
		}
		return true;
	}
};




