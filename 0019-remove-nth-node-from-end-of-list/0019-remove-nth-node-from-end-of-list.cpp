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
        // Read the answer: 
        // https://leetcode.com/problems/remove-nth-node-from-end-of-list/solutions/589304/clear-java-solution-with-detailed-explanation/

        // Trick: In any question where we need to delete a node always use a dummy node.
        // In case first node is getting deleted it will help.

        // Solution: We need to do it in 1 pass. Say length is L. We need to delete n-th node from last. 
        // So, it is L-n+1 th node from start. Ex. L = 7, List is 10-20-30-40-50-60-70, n = 3. So, we need to delete node# L-n+1 i.e., 5th node i.e., 50. But the thing is we do not know L.

        // So, what we will do is, first make a dummy node 0. So LL is 0-10-20-30-40-50-60-70.
        // Now, Use pointers start, slow and fast all point to 0 first.
        // WKT our answer will be start->next at last. (Can be NULL too).
        // Now, Move fast to (n+1)th node. Slow is at previous to 1st node.
        // Now, see total length is L. So, after this if we move slow and fast both 1 step at a time,
        // fast will hit NULL after L-n steps. And in the meantime slow will move to Node# L-n only,
        // which is nothing but previous to our desired node which we want to delete. (Draw to understand it more clearly).
        ListNode* dummy = new ListNode(-1);
        ListNode* start = dummy;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        dummy->next = head;

        while(fast != NULL){
            int i = 0;
            while(i <= n){
                fast = fast->next;
                i++;
            }

            while(fast != NULL){
                slow = slow->next;
                fast = fast->next;
            }

            ListNode* nodeToDelete = slow->next;
            slow->next = nodeToDelete->next;

            delete nodeToDelete;
        }

        // Before returning start, delete dummy too.
        start = start->next;
        delete dummy;
        return start;
    }
};