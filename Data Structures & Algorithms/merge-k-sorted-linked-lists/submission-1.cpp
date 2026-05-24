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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Brute Force

        // vector <int> ans;
        // for(int i=0; i<lists.size(); i++)
        // {
        //     ListNode *temp = lists[i];

        //     while(temp!= nullptr)
        //     {
        //         ans.push_back(temp->val);
        //         temp = temp->next;
        //     }
        // }

        // sort(ans.begin(),ans.end());

        // //recreating the LL
        // ListNode *newHead = nullptr;
        // ListNode *tail = nullptr;

        // for(int i=0; i<ans.size(); i++)
        // {
        //     ListNode *curr = new ListNode(ans[i]);    

        //     if(newHead == nullptr)
        //     {
        //         newHead = curr;
        //         tail = curr;
        //     }

        //     else
        //     {
        //         tail->next = curr;
        //         tail = tail->next;
        //     }

        // }

        // return newHead;


        //Optimal: Merge Lists n times

        if(lists.empty())
        {
            return nullptr;
        }

        for(int i=1; i<lists.size(); i++)
        {
            lists[i] = merge(lists[i], lists[i-1]);
        }
        return lists.back();  //the last one

        
    }

    private:
        ListNode *merge(ListNode *l1, ListNode *l2){
            ListNode *dummy = new ListNode(0);
            ListNode *curr = dummy;

            while(l1!= nullptr && l2!=nullptr)
            {
                if(l1->val <= l2->val)
                {
                    curr->next = l1;
                    l1= l1->next;
                }
                else
                {
                    curr->next = l2;
                    l2= l2->next;
                }
                curr= curr->next;
            }

            if(l1!= nullptr){
                curr->next = l1;
            }
            else
            {
                curr->next = l2;
            }

            return dummy->next;
        }
};
