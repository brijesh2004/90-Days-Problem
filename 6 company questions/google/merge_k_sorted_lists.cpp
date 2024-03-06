// https://leetcode.com/problems/merge-k-sorted-lists/

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
        vector<int>v;
        for(auto it:lists){
            ListNode*head = it;
            while(head!=NULL){
                v.push_back(head->val);
                head=head->next;
            }
        }
        sort(v.begin() , v.end());
        ListNode * temp = new ListNode(-1);
        ListNode* ans = temp;

        for(auto it:v){
            ListNode*t = new ListNode(it);
            temp->next = t;
            temp = temp->next;
        }
        return ans->next;
    }
};