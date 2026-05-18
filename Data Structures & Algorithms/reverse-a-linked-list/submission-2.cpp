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
    ListNode* reverseList(ListNode* head) {

        // // Brute Force:
        // vector <int> vec;
        // ListNode *temp = head;

        // while(temp!=nullptr)
        // {
        //     vec.push_back(temp->val);
        //     temp = temp->next;
        // }
        // reverse(vec.begin(), vec.end());

        // ListNode *newHead = nullptr;
        // ListNode *tail = nullptr;
        
        // for(int i=0; i<vec.size(); i++)
        // {
        //     ListNode *curr = new ListNode(vec[i]);

        //     //since the list is empty the tail and newHead point to first node 
        //     if(newHead == nullptr)
        //     {
        //         newHead = curr;
        //         tail = curr;
        //     }

        //     //adding nodes
        //     else
        //     {
        //         tail->next = curr;
        //         tail = tail->next;
        //     }
        // }

        // return newHead;


        // Optimal

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nextNode = NULL;

        //no ele or single ele
        if(head == nullptr || head->next== nullptr)
        {
            return head;
        }

        while(curr != nullptr)
        {
            nextNode = curr->next;   //save the next node so linkage is safe
            curr->next = prev;       // reverse the list
            prev = curr;             //move prev
            curr = nextNode;          //move curr
            
        }

        return prev;
    }
};
