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
    int length(ListNode* head) {
        int ans = 0;
        while (head != NULL) {
            ans++;
            head = head->next;
        }
        return ans;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = length(root);
        ListNode* head = root;

        int Min_Element_In_Every_Part = n / k;
        int ElementsRemaining = n % k;


        vector<ListNode*>ans;

        if (Min_Element_In_Every_Part == 0) {
            //K>n;

            for (int i = 0; i < k; i++) {

                if (head != NULL) {
                    ListNode* n = head->next;
                    head->next = NULL;
                    ans.push_back(head);
                    head = n;
                } else {
                    ans.push_back(NULL);
                }
            }
        } else {
            int count = 1;

            while (head != NULL) {
                ans.push_back(head);
                int x;
                if (ElementsRemaining > 0) {
                    x = 1;
                } else {
                    x = 0;
                }

                ElementsRemaining--;
                for (int i = 1; i < Min_Element_In_Every_Part + x; i++) {
                    head = head->next;
                }

                ListNode* n = head->next;
                head->next = NULL;
                head = n;
                count++;
                if (count == k) {
                    ans.push_back(head);
                    break;
                }

            }

        }
        return ans;

    }
};


1->2->3->4->5->6->7->8->9->10->11->NULL;
k = 3;

min = 3;
first part = min + x; = 4;

1->2->3->4->NULL;

5->6->7->8->NULL;

9->10->11->NULL;

