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
    ListNode* swapPairs(ListNode* head) {
        // if(head == NULL || head->next == NULL) return head;
        // ListNode* curr = head;
        // // ListNode* temp = curr;
        // ListNode* nextnode = head->next;
        // curr->next = nextnode->next;
        // nextnode->next = curr;
        // swapPairs(curr->next);
        // return head;
        return swap1(head,NULL);
    }
    ListNode* swap1(ListNode* curr,ListNode* prev)
    {
        if(curr == NULL || curr->next == NULL) return curr;
        ListNode* nextnode = curr->next;
        curr->next = nextnode->next;
        nextnode->next = curr;
        if(prev != NULL) prev->next = nextnode;
        swap1(curr->next,curr);
        return nextnode;
    }
};