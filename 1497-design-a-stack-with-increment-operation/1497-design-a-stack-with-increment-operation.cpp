class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

class CustomStack {
public:
    Node *head;
    Node *tail;

    int cap;
    int size;

    CustomStack(int maxSize) {
        cap = maxSize;
        size = 0;
        head = NULL;
        tail = head;
    }
    
    void push(int x) {
        if(size == cap) return;
        Node *newNode = new Node(x);

        if(size == 0){
            head = newNode;
            tail = head;
        }else{
            // Insert should be at tail.
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        return;
    }
    
    int pop() {
        // Pop should be from tail.
        if(size == 0) return -1;
        Node *nodeToDelete = tail;
        int x = tail->data;

        if(tail == head){
            head = NULL;
            tail = NULL;
        }else{
            tail = tail->prev;
            tail->next = NULL;
        }
        size--;
        delete nodeToDelete;
        return x;
    }
    
    void increment(int k, int val) {
        int i = 0;
        Node *t = head;
        while(t != NULL && i < k){
            t->data = t->data + val;
            t = t->next;
            i++;
        }
        return;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */