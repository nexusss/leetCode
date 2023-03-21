class MyLinkedList {

    struct Node{
        int val = 0;
        Node *next = nullptr;
        Node(int val):val(val){};
    };

    Node *head = nullptr;

    size_t size = 0;

    void deleteHead(){
        if (size >= 0) {
            if (size == 0) {
                delete head;
                head = nullptr;
            } else {
                auto tmp = head;
                head = head->next;
                delete tmp;

            }
            size--;
        }
    }


public:
    MyLinkedList() {

    }

    int get(int index) {
        auto cur = head;

        if (size <= index){
            return -1;
        }

        for(size_t i = 0; i < index and cur != nullptr; ++i){
            cur = cur->next;
        }

        return cur != nullptr ? cur->val : -1;
    }

    void addAtHead(int val) {
        if (head == nullptr){
            head = new Node(val);
        }
        else{
            auto newNode = new Node(val);
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void addAtTail(int val) {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val) {
        if (size < index){
            return;
        }

        if (index == 0) {
            addAtHead(val);
        }
        else {
            auto cur = head;

            for (size_t i = 0; i < index - 1 and cur != nullptr; ++i) {
                cur = cur->next;
            }
            if( cur != nullptr) {
                auto next = cur->next;
                cur->next = new Node(val);
                if (next) {
                    cur->next->next = next;
                }

                size++;
            }
        }

    }

    void deleteAtIndex(int index) {
        if(size <= index){
            return;
        }

        if (index == 0){
            deleteHead();
        }
        else {
            auto cur = head;

            for (size_t i = 0; i < index - 1 and cur->next != nullptr; ++i) {
                cur = cur->next;
            }
            if (cur->next != nullptr) {

                auto tmp = cur->next;
                if (cur->next) {
                    cur->next = cur->next->next;
                }
                delete tmp;

            }
            size--;
        }

    }
};