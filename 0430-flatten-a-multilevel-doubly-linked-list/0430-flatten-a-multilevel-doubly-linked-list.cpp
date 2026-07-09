/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return nullptr;

        Node* curr = head;
        while(curr != nullptr) {
            if (curr->child != NULL) {
                Node* nextptr = curr->next;
                Node* childptr = curr->child;

                curr->next = childptr;
                childptr->prev = curr;
                curr->child = nullptr;

                Node* tail = childptr;
                while(tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = nextptr;
                if (nextptr != NULL){
                    nextptr->prev = tail;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};