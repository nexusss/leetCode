#include <iostream>

using namespace std;

class FrontMiddleBackQueue {

    struct Node{
        int val = 0;
        Node *next = nullptr;
        Node *prev = nullptr;
    };

    Node *front = nullptr;
    Node *middle = nullptr;
    Node *back = nullptr;
    size_t size = 0;

public:
    FrontMiddleBackQueue() {

    }

    void pushFront(int val) {
        size++;
        auto tmp = new Node();
        tmp->val = val;
        tmp->next = front;

        if (front != nullptr){
            front->prev = tmp;
        }
        front = tmp;
        if(back == nullptr){
            back = front;
        }
        if(middle == nullptr){
            middle = front;
        }
        else{
            if(size%2 == 0){
                middle = middle->prev;
            }
        }
    }

    void pushMiddle(int val) {
        if (middle == nullptr or size == 1){
            pushFront(val);
        }
        else{
            size++;

            auto tmp = new Node();
            tmp->val = val;

            if(size % 2 == 1){
                auto next = middle->next;
                tmp->next = next;

                if(next != nullptr){
                    next->prev = tmp;
                }

                middle->next = tmp;
                tmp->prev = middle;
                middle = tmp;
            }
            else{
                auto prev = middle->prev;
                tmp->prev = prev;

                if(prev != nullptr){
                    prev->next = tmp;
                }

                tmp->next = middle;
                middle->prev = tmp;
                middle = tmp;
            }


/*    q.pushMiddle(3);  [1, 2]// [1, 3, 2]
    q.pushMiddle(4);  // [1, 4, 3, 2]
*/
        }
    }

    void pushBack(int val) {

        auto tmp = new Node();
        tmp->val = val;
        if (back != nullptr){
            back->next = tmp;
        }

        tmp->prev = back;
        back = tmp;
        if(front == nullptr){
            front = back;
        }
        if(middle == nullptr){
            middle = back;
        }
        else{
            if(size %2 == 0 && size!=1){
                middle = middle->next;
            }
        }
        size++;
    }

    int popFront() {
        cout << "f\n";
        if(size == 0){
            return -1;
        }
        size--;
        auto val = front->val;
        auto tmp = front;

        front = front->next;
        if(front){
            front->prev = nullptr;
        }
        if(size %2 == 1){
            middle = middle->next;
        }


        delete tmp;
        return val;
    }

    int popMiddle() {
        cout << "m\n";
        if(size == 0){
            return -1;
        }
        size--;
        //cout << "0\n";
        auto val = middle->val;
        auto tmp = middle;

        auto prev = middle->prev;
        auto next = middle->next;

        //cout <<"1\n";

        if (size == 1){

             middle = middle->next;
            middle->prev = nullptr;
            middle->next = nullptr;
        }
        else if(size == 0){
            middle = nullptr;
        }
        else{
            //cout <<"4\n";
            if (prev != nullptr){
                prev->next = next;
            }
            //cout <<"2\n";
            if(next != nullptr){
                next->prev = prev;
            }
        //cout <<"3\n";
            if (size %2 == 0){
                middle = prev;
            }
            else{
                middle = next;
            }
        }

        delete tmp;
        //cout <<"5\n";

        return val;
    }

    int popBack() {
        cout << "b\n";
        if(size == 0){
            return -1;
        }
        size--;
        auto val = back->val;
        auto tmp = back;
        back = back->prev;
        if (back){
            back->next = nullptr;
        }
        if(size%2 == 1){
            middle = middle->prev;
        }


        delete tmp;
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

int main()
{

    FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
    /*obj->pushFront(1);
    obj->pushFront(2);
    obj->pushFront(3);
    obj->pushFront(4);
    obj->pushBack(5);
    obj->pushBack(6);
    obj->pushMiddle(0);*/

        auto q =*obj;
    q.pushMiddle(1);   // [1]
    //q.pushMiddle(2);    // [1, 2]
    //q.pushMiddle(3);  // [1, 3, 2]
    //q.pushMiddle(4);  // [1, 4, 3, 2]
    cout << "p\n";
    cout << "1 " << q.popMiddle() << endl;     // return 1 -> [4, 3, 2]
    cout << "2 "<< q.popBack() << endl;    // return 3 -> [4, 2]
    cout << "3 "<< q.popFront() << endl;
    cout << "3 "<< q.popMiddle() << endl;// return 4 -> [2]
    //cout << q.popBack() << endl;      // return 2 -> []
    //cout << q.popFront() << endl;     // return -1 -> [] (The queue is empty)

    cout << "Hello World!" << endl;
    return 0;
}
