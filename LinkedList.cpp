/*
 * Author:Aya Osama Mohamed
 * Version: 3.00
 * Year: 2022/2023
 * Description: an implementation for linked list with a detailed steps and provided comments(in need)
 */

#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

struct node{
    int item;
    node * next = nullptr;
    node() = default;
};
class linkedList{

    node *first = nullptr;
    node * last = nullptr;
    int length = 0;
public:
    linkedList() = default;

    bool isEmpty(){
        if(first == nullptr){
            return true;
        }else
            return false;
    }

   void pushFront(int ele){
        node *newNode = new node;
        newNode -> item = ele;//store at newNode item element value;
        if(length == 0){
            first = last = newNode;
            length++;
        }else{
            newNode ->next = first;
            first = newNode;
            length++;
        }
    }
    void pushBack(int ele){
        node* newNode = new node;
        newNode -> item = ele;
        if(length == 0){
            first = last = newNode;
        }else {
            last->next = newNode;
            newNode->next = nullptr;
            last = newNode;
        }
        length++;
    }

    void insert(int ele, int pos){
        node* newNode = new node;
        newNode-> item = ele;
        if(pos == 0){
            pushFront(ele);
        }else if(pos == length){
            pushBack(ele);
        }else
        {
            node*current = first;
            for(int i = 1 ; i < pos - 1; i++){
                current = current->next;
            }
            newNode ->next = current->next;
            current ->next = newNode;
            length++;
        }
    }
    
    bool isExist(T element) {
        node *current = first;
        int loc = 0;
        while (current != NULL) {
            if (current->item == element)
                return true;
            current = current->next;
            loc++;
        }
        return false;
    }

    
    void print(){
        node* current = first;
        for(int i = 0; i < length; i++){
            cout << current->item<< " ";
            current = static_cast<node *>(current->next);
        }
        //cout << last ->item;
    }

    void removeFront(){
        node *current = new node;
        if(length == 0 ){
            return;
        }else if(length == 1){
            delete first;
            last = first = nullptr;
            length--;
        }else{
            current = first;
            first = first-> next;
            delete current;
            length--;
        }
    }

    void popBack(){
        if(length == 0){
            return;
        }else if(length == 1){
            delete last;
            first = last = nullptr;
            length--;
        }else{
            node* current = new node;
            current = first;
            for(int i = 0 ; i < length - 1; i++){
                current = current-> next;
            }
            last = current;
            delete current ->next;
            current->next = nullptr;
            length--;

        }
    }

    void remove(int ele){
        node*cur = nullptr;
        node*pre = nullptr;
        pre = first;
        cur = first->next;
        if(first-> item == ele){
            removeFront();
        }else if(last->item == ele){
            popBack();
        }else{
            for(int i = 0 ; i < length; i++){
                if(cur->item == ele){
                    pre->next = cur->next;
                    cout << pre->item << "--" << cur->item << "--" << (pre->next)->item << endl;
                    delete cur;
                    cur = pre;
                }else{
                    pre = pre-> next;
                    cur = cur->next;
                }
            }
            length--;
        }
    }

    int searchByEle(int ele){
        node* cur = first;
        for(int i = 0; i < length; i++){
            if(cur->item == ele){
                return i + 1;

            }else{
                cur = cur->next;
            }
        }
    }

    int searchByPos(int pos){
        node* cur = first;
        for(int i = 0; i < length; i++){
            if(i == pos){
                return cur->item;
            }
            cur = cur->next;
        }
    }

    void reverse(){
        node*cur = first;
        node*pre = nullptr;
        node*next = cur->next;
        while(next != nullptr){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        first = pre;
    }
};


template<typename T>
linkedList<T> merge(linkedList<T>l1, linkedList<T>l2){
    linkedList<T>l;
    node* cur1 = l1.pointToFirst();
    node* cur2 = l2.pointToFirst();
    while((cur1->next != nullptr) && (cur2->next != nullptr)) {
        if (cur1->item < cur2->item) {
            l.insertAtTail(cur1->item);
            cur1 = cur1->next;
        }else {
            l.insertAtTail(cur2->item);
            cur2 = cur2->next;
        }
    }
    static bool t1 = true;
    while((cur1->next == nullptr) && (cur2->next != nullptr)) {
        if (cur1->item < cur2->item && t1) {
            l.insertAtTail(cur1->item);
            t1 = false;
        }
        l.insertAtTail(cur2->item);
        cur2 = cur2->next;
    }
    static bool t = true;
    while((cur1->next != nullptr) && (cur2->next == nullptr)) {
        if (cur1->item > cur2->item && t) {
            l.insertAtTail(cur2->item);
            t = false;

            cout << "enter" << cur1->item << " " << cur2->item << endl;
        }
        l.insertAtTail(cur1->item);
        cur1 = cur1->next;
    }

    if((cur1->next == nullptr) && (cur2->next == nullptr)) {
        if(!l.isExist(cur1->item) && !l.isExist(cur2->item)){
            if (cur1->item > cur2->item) {

                l.insertAtTail(cur2->item);
                l.insertAtTail(cur1->item);

            }else{
                l.insertAtTail(cur1->item);
                l.insertAtTail(cur2->item);
            }
        }else if(l.isExist(cur1->item) && !l.isExist(cur2->item)){
            l.insertAtTail(cur2->item);

        }else if(l.isExist(cur2->item) && !l.isExist(cur1->item)){
            l.insertAtTail(cur1->item);
        }

    }
    return l;
}

template<typename T, typename ...Ts>
linkedList<T> merge(linkedList<T>l1, linkedList<Ts>...rest){
    linkedList<int> l = merge(l1, merge(rest...));
    return l;

}

int main(){
    linkedList l1;
    l1.pushBack(7);
    l1.pushBack(8);
    l1.pushBack(9);
    l1.pushBack(10);
    l1.pushBack(11);
    l1.pushBack(12);
    cout << l1.searchByEle(11) << endl;
    cout << l1.searchByPos(2) << endl;
    l1.reverse();
    l1.print();
}
