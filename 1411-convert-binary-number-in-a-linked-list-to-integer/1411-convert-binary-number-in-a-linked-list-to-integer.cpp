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
    int getDecimalValue(ListNode* head) {
        int ans = 0;

        while(head){
            if(head->val == 0){
                ans = 2*ans;
            }else{
                ans = 2*ans + 1;
            }
            head = head->next;
        }
        return ans;
    }
};