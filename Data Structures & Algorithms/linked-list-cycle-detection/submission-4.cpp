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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited_nodes;

        ListNode* node = head;

        while (node) {
            if (visited_nodes.find(node) != visited_nodes.end()) {
                return true;
            }
            visited_nodes.insert(node);
            node = node->next;
        }
        return false;
    }
};
