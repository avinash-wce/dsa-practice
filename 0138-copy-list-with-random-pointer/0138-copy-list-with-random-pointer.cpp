/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return nullptr;
        }
        unordered_map<Node*, Node*> hs;
        Node* newHead = new Node(head->val);
        Node* oldTemp = head->next;
        Node* newTemp = newHead;
        hs[head] = newHead;

        while(oldTemp != NULL) {
            Node* copy = new Node(oldTemp->val);
            hs[oldTemp] = copy;
            newTemp->next = copy;

            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        oldTemp = head;
        newTemp = newHead;
        while(oldTemp != nullptr) {
            newTemp -> random = hs[oldTemp -> random];
            oldTemp = oldTemp->next;
            newTemp = newTemp->next;
        }
        return newHead;
    }
};