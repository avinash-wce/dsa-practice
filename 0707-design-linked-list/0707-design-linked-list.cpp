class node {
public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = nullptr;
    }
};
class MyLinkedList {
    node* head;
    node* tail;
public:
    MyLinkedList() {
        head = tail = nullptr;
    }
    
    int get(int index) {
        node* temp = head;
        int count = 0;
        while(temp!=nullptr){
            if(count == index){
                return temp->data;
            }
            temp = temp->next;
            count++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        node* newNode = new node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }
    
    void addAtTail(int val) {
        node* newNode = new node(val);
        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr) return;

        node* newNode = new node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr) {
            tail = newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) return;
        if (index == 0) {
            node* toDelete = head;
            head = head->next;
            if (head == nullptr) {
                tail = nullptr;
            }
            delete toDelete;
            return;
        }
        node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        node* toDelete = temp->next;
        temp->next = temp->next->next;

        if (temp->next == nullptr) {
            tail = temp;
        }

        delete toDelete;

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */