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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        // int length = 0;

        // ListNode *temp = head;
        // while(temp != nullptr)
        // {
        //     length++;
        //     temp = temp->next;
        // }

        // if(length == 1)
        // {   
        //     return nullptr;
        // }
        // int delete_index = length -n+1;

        // if(delete_index == 1)   //first node
        // {   
        //     head = head->next;
        //     return head;
        // }

        // length = 1;
        // ListNode *prev = nullptr;
        // ListNode *curr = head;

        // while(delete_index != length)
        // {
        //     length++;
        //     prev = curr;
        //     curr = curr->next;
        // }

        // prev->next = curr->next;
    
        // return head;


        //Optimal: fast & slow pointers

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *nextNode;

        if(head->next == nullptr)
        {
            return nullptr;
        }

        for (int i=0; i<n ;i++)
        {
            fast = fast->next;
        }

        //if fast becomes nullptr exactly after n moves, delete first node
        if(fast == nullptr)
        {
            head = head->next;
            return head;
        }

        // move both slow and fast (fast reaches end, slow reaches before node to delete)
        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    
    }
};
