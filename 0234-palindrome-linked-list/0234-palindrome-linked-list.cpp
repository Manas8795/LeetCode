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
    bool isPalindrome(ListNode* head) {
        ListNode* f1 = head;
        ListNode* f2 = head;
        while(f1!=NULL && f1->next!=NULL)
        {
            f1=f1->next->next;
            f2 = f2->next;
        }
        ListNode* temp = head;
        ListNode* curr = f2;
        ListNode* prev = NULL;
        while(curr!=NULL)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        f2 = prev;
        while(f2!=NULL)
        {
            if(f2->val!=temp->val)
            {
                return false;
            }
            f2 = f2->next;
            temp = temp->next;
        }
        
        return true;
    }
};