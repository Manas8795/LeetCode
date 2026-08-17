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
    ListNode* middleNode(ListNode* head) {
        ListNode* f1 = head;
        ListNode* f2 = head;
        while(f2!=NULL && f2->next!=NULL)
        {
            f1 = f1->next;
            f2 = f2->next->next;
        }
        return f1;
    }
};