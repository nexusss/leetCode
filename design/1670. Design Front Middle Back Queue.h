struct Node{

    int val;
    Node * next;
    Node * prev;
    
    Node(int x)
    {
        val = x;
        next = prev = NULL;
    }
};

    Node* createNode(int x)
    {
        return new Node(x);
    }

class FrontMiddleBackQueue {
public:
    Node * head = NULL;
    Node * tail = NULL;
    Node * mid = NULL;
    int size = 0;

    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {

        Node * newNode = createNode(val);

        if(size==0)
            head = tail = mid = newNode;
        else
        {
            newNode->next = head;
            newNode->prev = NULL;
            head->prev = newNode;
            head = head->prev;
        }

        size++;
        if(size%2==0)
            mid = mid->prev;
    }
    
    void pushMiddle(int val) {
        Node * newNode = createNode(val);
        if(size==0)
            head = tail = mid = newNode;
        else
        {
            if(size%2==0)//even no of elements
            {
                newNode->next = mid->next;
                newNode->prev = mid;
                mid->next->prev = newNode;
                mid->next = newNode;
                mid = mid->next;
            }
            else //odd no of elements
            {
                newNode->next = mid;
                newNode->prev = mid->prev;
                if(mid->prev)
                    mid->prev->next = newNode;
                mid->prev = newNode;
                mid = mid->prev;
                if(size==1)
                    head = mid;
            }
        }
        size++;
    }
    
    void pushBack(int val) {
        Node * newNode = createNode(val);
        if(size==0)
            head = tail = mid = newNode;
        
        else
        {
            newNode->prev = tail;
            newNode->next = NULL;
            tail->next = newNode;
            tail = tail->next;
        }
        size++;
        if(size%2!=0 && size!=1)
            mid = mid->next;
    }
    
    int popFront() {

        if(size==0) return -1;

        int ans = head->val;
        Node * toDel = head;;
        if(size==1)
        {
            head = mid = tail = NULL;
        }
        else
        {
            head->next->prev = NULL;
            head = head->next;
            if(size%2==0)
                mid = mid->next;
        }
        delete toDel;
        size--;
        return ans;
    }
    
    int popMiddle() {
        if(size==0) return -1;

        int ans = mid->val;
        Node * toDel = mid;
        if(size==1)
        {
            head = mid = tail = NULL;
        }
        else
        {
            mid->next->prev = mid->prev;
            if(mid->prev)
                mid->prev->next = mid->next;

            if(size%2!=0) //odd no of elements
                mid = mid->prev;
            else
                mid = mid->next;

            if(size==2)
                head = mid;

        }
        delete toDel;
        size--;
        return ans;
    }
    
    int popBack() {

        if(size==0) return -1;

        int ans = tail->val;
        Node *toDel = tail;
        
        if(size==1)
            head = mid = tail = NULL;
        else
        {
            tail->prev->next = NULL;
            tail = tail->prev;
            if(size%2!=0)
                mid = mid->prev;
            
        }
        delete toDel;
        size--;
        return ans;
    }
};