
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

template<class T>
class DoublyLinkedList{
private:
    struct node{
        node*prev = NULL;
        node*next = NULL;
        T item = 0;
    };
    node*first = nullptr;
    node*last = nullptr;
    int length = 0;
public:
    DoublyLinkedList() = default;

    bool isEmpty(){
        return length == 0;
    }

    int DoublyLinkedList_size(){
        return length;
    }

    void pushFront(T ele){
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

    void pushBack(T ele){
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

    void insertAfter(T ele, int pos){
        node*cur = first;
        node*prevNode = NULL;
        node* newNode = new node;
        newNode->item = ele;
        if(isEmpty()){
            pushFront(ele);
        }else{
            for(int i = 0; i < pos ; i++){/* Subtract one to get the previous element from position &
                                              *Another one for 1 based count;*/
                cur = cur->next;
            }
            prevNode = cur;
            cur = cur->next;
            newNode->next = cur;
            prevNode->next = newNode;
            newNode->prev = prevNode;
            cur->prev = newNode;
            length++;
        }
    }

    void insertAt(T ele, int pos){
        node*cur = first;
        node*prevNode = NULL;
        node* newNode = new node;
        newNode->item = ele;
        if(isEmpty()){
            pushFront(ele);
        }else{
            for(int i = 0; i < pos; i++){/* Subtract one to get the previous element from position &
                                              *Another one for 1 based count;*/
                cur = cur->next;
            }
            prevNode = cur->prev;
            newNode->next = cur;
            prevNode->next = newNode;
            newNode->prev = prevNode;
            cur->prev = newNode;
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

    void removeAt(int pos) {//Remove element by counting from 1 --> n
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

    void removeElement(T ele){
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

    void swap(int firstIndex, int secondIndex){
        node* cur = first;
        node* second = first;
        node* temp = nullptr;
        node* temp1 = nullptr;
        if(firstIndex != 0 && secondIndex != length - 1) {
            for(int i = 0; i < firstIndex; i++){
                cur = cur->next;
            }

            for(int j = 0; j < secondIndex; j++){
                second = second->next;
            }
            node *nextCurNode = cur->next;
            node *nextSecondNode = second->next;

            (cur->prev)->next = second;
            (second->prev)->next = cur;

            cout << second->prev->item << " " << cur->prev->item << endl;

            temp = second->prev;
            second->prev = cur->prev;
            cur->prev = temp;
            cout << second->next->item << " " << cur->next->item << endl;

            temp = second->next;
            second->next = cur->next;
            cur->next = temp;

            nextCurNode->prev = second;
            nextSecondNode->prev = cur;


        } else if(firstIndex == 0 && secondIndex == length - 1){
            cout << "enter" << endl;
            for(int j = 0; j < secondIndex; j++){
                second = second->next;
            }

            (cur->next)->prev = second;
            (second->prev)->next = cur;
            temp = cur->next;
            temp1 = second->prev;
            cur->prev = second->prev;
            second->next = cur->next;
            second->prev = nullptr;
            cur->next = nullptr;
            first = second;
            last = cur;

        }else if(firstIndex == 0 && secondIndex != length - 1){
            for(int j = 0; j < secondIndex; j++){
                second = second->next;
            }

            (cur->next)->prev = second;
            temp = cur->next;
            cur->next = second->next;

            second->next->prev = cur;
            second->next = temp;
            second->prev->next = cur;
            second->prev = nullptr;

            first = second;

        }else if(firstIndex != 0 && secondIndex == length - 1){

            for(int i = 0; i < firstIndex; i++){
                cur = cur->next;
            }

            for(int j = 0; j < secondIndex; j++){
                second = second->next;
            }
            cur->prev->next = second;
            second->prev->next = cur;
            cur->prev = second->prev;
            second->next = cur->next;

            cur->next = nullptr;
            last = cur;
        }
    }

    void reverse(){
        if(isEmpty()){
            cout << "The List is Empty please push element" << endl;
        }else {
            node *begin = first;
            node *end = last;

            for (int i = 0; i < length / 2; i++) {
                T temp = begin->item;
                begin->item = end->item;
                end->item = temp;
                end = end->prev;
                begin = begin->next;
            }
        }
    };

    void replace(T ele, int indx) {
        if (isEmpty()) {
            cout << "The List is Empty please push element" << endl;
        }else if(indx >= length){
            cout << "OUT OF SCOPE INDEX, TRY AGAIN" << endl;
        }else{
            node*cur = first;
            for(int i = 0 ; i < indx; i++){
                cur = cur->next;
            }
            cur->item = ele;
        }
    }

    T retrieveAt(T indx){
        node* cur = first;
        if(indx > length){
            cout << "OUT OF SCOPE INDEX" << endl;
        }else{
            for (int i = 0; i < indx; i++) {
                cur = cur->next;
            }
            return cur->item;
        }
        return "";
    }

    bool isExist(T ele){
        if(isEmpty()){
            cout << "List is Empty" << endl;
        }else {
            node *cur = first;
            while (cur->next != nullptr) {
                if (cur->item == ele) {
                    return true;
                    break;
                }
                cur = cur->next;
            }
        }
        return false;
    }

    bool isItemAtEqual(T ele, int indx){
        if(isEmpty()){
            cout << "List is empty" << endl;
        }else{
            node* cur = first;
            for(int i = 0; i < indx; i++){
                cur = cur->next;
            }
            if(cur->item == ele){
                return true;
            }
            return false;
        }
    }

    void clear(){
        if(isEmpty()){
            cout << "Stack is already empty" << endl;
        }else{
            node *cur = first;
            while(cur != nullptr){
                node*newNode = cur;
                cur = cur->next;
                newNode->next = nullptr;
                delete newNode;
                newNode = nullptr;
            }
            first= nullptr;
        }
    }

    void forwardTraversal(){
        node* curr = first;
        cout <<"{ ";
        for(int i = 0; i < length; i++){
            cout << curr->item << " ";
            curr = curr->next;
        }
        cout << "}" << endl;
    }

    void backwardTraversal(){
        node* curr = last;
        cout <<"{ ";
        for(int i = 0; i < length ; i++){
            cout << curr->item << " ";
            curr = curr->prev;
        }
        cout << "}" << endl;
    }
};

int main(){
    DoublyLinkedList<int> l1;
    l1.pushBack(10);
    l1.pushBack(12);
    l1.pushBack(13);
    l1.pushBack(14);
    l1.insertAfter(0, 2);
    l1.replace(19,3);
    l1.pushBack(16);
    l1.pushBack(85);
    l1.pushBack(6);
    l1.forwardTraversal();
   l1.swap(4, 7);
   l1.forwardTraversal();
}
