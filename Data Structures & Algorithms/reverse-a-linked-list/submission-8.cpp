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
        std::stack<ListNode*> nodes;

        ListNode* curr = head;
        while (curr != nullptr) {
            nodes.push(curr);
            curr = curr->next;
        }

        if (nodes.empty()) {
            return nullptr;
        }

        ListNode* new_head = nodes.top();
        nodes.pop();

        curr = new_head;

        while (!nodes.empty()) {
            curr->next = nodes.top();
            nodes.pop();
            curr = curr->next;
        }

        curr->next = nullptr;

        return new_head;
    }
};
