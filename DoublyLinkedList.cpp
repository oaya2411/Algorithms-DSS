
/*
 *                      بـسـمـ اللَّه الرحمن الرحيم
 * Author:Aya Osama Mohamed
 * Version: 1.01
 * Year: 2022/2023
 * Description: an implementation for doubly linked list with a detailed steps and provided comments(in need)
 */

/*
 *                        The difference between linkedList & DoublyLinkedList
 *
 *  *Linked List: contains of nodes which linked together with a pointer.
 *               each node has a pointer which points to next node and the last node point to NULL.
 *               -------------------------------------------------------------
 *  *Doubly Linked List: contains of nodes also linked together with a pointer.
 *                     But here each node has a pointer which refers to previous and another one which refers to next.
 */

/**********************************************************************************************************************/

#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

class DoublyLinkedList{
private:
    struct node{
        node*prev = NULL;
        node*next = NULL;
        int item = 0;
    };
    node*first = nullptr;
    node*last = nullptr;
    int length = 0;
public:
    DoublyLinkedList() = default;

    bool isEmpty(){
        return length == 0;
    }

    void pushFront(int ele){
        node* newNode = new node;
        newNode->item = ele;
        if(!isEmpty()){
            first->prev = newNode;
            newNode->next = first;
            newNode->prev = nullptr;
            first = newNode;
        }else{
            first = newNode;
            last = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        length++;
    }

    void pushBack(int ele){
        node* newNode = new node;
        newNode->item = ele;
        if(!isEmpty()){
            newNode->prev = last;
            newNode->next = nullptr;
            last->next = newNode;
            last = newNode;

        }else{
            first = newNode;
            last = newNode;
            newNode->prev = nullptr;
            newNode->next = nullptr;
        }
        length++;
    }

    void insert(int ele, int pos){
        node*cur = first;
        node*next = nullptr;
        node* newNode = new node;
        if(isEmpty()){
            pushFront(ele);
        }else{
            for(int i = 0; i < pos - 2; i++){//Subtract one to get the previous element from position &
                //Another one for 1 based count;
                cur = cur->next;
            }
            next = cur->next;
            next->prev = newNode;
            newNode->next = next;
            newNode->prev = cur;
            cur->next = newNode;
            length++;
        }
    }

    void popFront(){
        if(!isEmpty()) {
            node *newNode = first;
            first = newNode->next;
            first->prev = nullptr;
            delete newNode;
            newNode->prev = newNode->next = NULL;
        }else{
            delete first;
            delete last;
            first = last = nullptr;
        }
        length--;
    }

    void popBack(){
        if(!isEmpty()) {
            node* newNode = last;
            last = last->prev;
            last->next = nullptr;
            delete newNode;
        }else{
            delete first;
            delete last;
            first = last = nullptr;
        }
        length--;
    }

    void removePos(int pos) {//Remove element by counting from 1 --> n
        if (pos > length) {
            cout << "OUT OF SCOPE POSITION." << endl;
        }else if(pos == 0){
            popFront();
        }else{
            node *cur = first;
            node *newNode = NULL;
            for (int i = 0; i < pos - 1; i++) {
                cur = cur->next;
            }
            newNode = cur->prev;
            newNode->next = cur->next;
            (cur->next)->prev = newNode;
            cur->next = cur->prev = nullptr;
            delete cur;
        }
        length--;
    }

    void removeElement(int ele){
        node* curr = first;
        for(int i = 0; i < length; i++){
            if(curr->item == ele){
                if(curr->next == nullptr){
                    (curr->prev)->next = nullptr;
                    delete curr;
                }else {
                    (curr->prev)->next = curr->next;
                    (curr->next)->prev = curr->prev;
                    delete curr;
                    break;
                }
            }
            curr = curr-> next;
        }
        length--;
    }

    void print(){
        node* curr = first;
        cout <<"{ ";
        for(int i = 0; i < length; i++){
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << "}" << endl;
    }
};

int main(){
    DoublyLinkedList l1;
    l1.pushBack(10);
    l1.pushBack(12);
    l1.pushBack(13);
    l1.pushBack(14);
    l1.removeElement(14);
    l1.print();
}