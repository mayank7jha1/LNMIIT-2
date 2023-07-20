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
    int numComponents(ListNode* head, vector<int>& nums) {
        int n = nums.size();
        int freq[10001] = {0};

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            freq[x]++;
        }

        int ans = 0;
        while (head != NULL) {

            if ((freq[head->val] > 0) and ((head->next == NULL) or
                                           freq[head->next->val] == 0)) {
                ans++;
            }
            head = head->next;
        }
        return ans;
    }
};