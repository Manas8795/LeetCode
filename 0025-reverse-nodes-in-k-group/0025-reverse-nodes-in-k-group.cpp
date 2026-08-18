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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == NULL || head->next == NULL) return head;
        int length = 0;
        vector<ListNode*> start;
        vector<ListNode*> end;
        
        ListNode* temp = head;
        while(temp!=NULL)
        {
            temp = temp->next;
            length++;
        }
        // cout<<length;
        length = length - length%k;
        int count = 0;
       
        ListNode* curr = head;
        while(count<length)
        {
            if((count+1)%k ==0) end.push_back(curr);
            if(count%k==0) start.push_back(curr);
            curr=curr->next;
            count++;
        }
        start.push_back(curr);
        
        ListNode* prev = NULL;
        count = 0;
        curr = head;
        ListNode* head1 = NULL;
        ListNode* tail = NULL; 
        while(count!=length)
        {
            ListNode* grpstart = start[count/k];
            prev = NULL;
            for(int i = 0;i<k;i++)
            {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
                count++;
            }
            if(head1 == NULL) head1 = prev;    
        }
        for(int i = 0;i+1<end.size();i++)
        {
            start[i]->next = end[i+1];
        }
        if(start.size()>end.size())
        {
            start[end.size()-1]->next = start[end.size()];
        }
        return head1;
    }
};