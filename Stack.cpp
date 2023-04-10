/*
 * Author: Aya Osama Mohamed.
 * YEAR: 2022/2023.
 * version: 2.
 * Description: this code explain all codes that related to stack with a simple explanation using comments.
 */
#include <iostream>
#include<stack>
using namespace std;
const int MAX = 100;
template<class T>
class fixedStack{
    int top;
    T items[MAX];
public:
    fixedStack(): top(-1) , items{0}{}
    bool isEmpty(){
        if(top == -1){
            return true;
        }else
            return false;
    }

    void push_back(T ele){
        if(top <= MAX){
            top++;
            items[top] = ele;
        }else{
            cout << "Stack is full" << endl;
        }

    }

    void pop(){
        if(!isEmpty()){
            top--;
        }else{
            cout << "Stack is Empty" << endl;
        }
    }

    void getTop(int&stackTop){//& -> changing on the original value of stackTop.
        if(!isEmpty()){
            items[top] = stackTop;
            cout << stackTop << endl;// store top v at stackTop not a copy from it.
            top++;
        }
    }

    void print(){
        cout << "{ ";
        int i = top;
        while(i != -1){
            cout << items[i] << " ";
            i--;
        }
        cout << "}";
    }

};

//Problem of balanced practices
bool isPaired(char start, char end){ //this function to ensure that the start and the end of the practices have the same shape.
    if(start == '[' && end == ']'){
        cout << "Enter3" << endl;

        return true;
    }else if(start == '{' && end == '}'){
        cout << "Enter4" << endl;

        return true;
    }else if(start == '(' && end == ')'){
        cout << "Enter5" << endl;

        return true;
    }

    return false;
}
bool isBalanced(string word){ //to push each start of practices and pop it when the function found his original end.
    stack<char>s;
    for(int i = 0 ; i <= word.length(); i++){
        if(word[i] == '[' || word[i] == '{' || word[i] == '('){
            s.push(word[i]);
        }else if(word[i] == ']' || word[i] == '}' || word[i] == ')'){
            if(s.empty() || !isPaired(s.top(), word[i])){
                return false;
            }else{
                s.pop();
            }
        }
    }
    if(s.empty()){
        return true;
    }else {
        cout << s.size() << " " << s.top();
        return false;
    }
}

class DynamicStack{
    struct node{
        int item = 0;
        node* next = nullptr;
        node() = default;
    };
    node* top = nullptr;

public:
    DynamicStack() = default;

    void push(int newItem){
        node *newNode = new node();
        newNode->item = newItem;
        newNode->next = top;
        top = newNode;
        //cout << top << " " << &top << endl; /* Ensure about the changes done.*/
    }

    bool isEmpty(){
        if(top == nullptr){
            return true;
        }
        return false;
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack is Empty" << endl;
        }else{
            node* temp = top;
            top = temp ->next;
            temp-> next = nullptr;
            temp = nullptr;
            delete temp;
        }
    }

    void getTop(int& topValue){
        if(isEmpty()){
            cout << "Stack is empty" << endl;
        }else{
            topValue = top->item;
        }
    }

    void display(){
        node *cur = top;
        cout << "{ ";
        while(cur != nullptr){
            cout << cur->item << " ";
            cur = cur->next;
        }
        cout << "}" << endl;
    }

};

int main() {
     fixedStack<int>s;
     s.push_back(12);
     s.push_back(15);
     s.push_back(20);
     s.push_back(22);
     s.push_back(11);
     s.print();
     s.pop();
     s.print();
    DynamicStack Stack1;
    Stack1.push(12);
    Stack1.push(14);
    Stack1.push(15);
    Stack1.push(11);
    Stack1.display();
    Stack1.pop();
    cout << " " << endl;
    Stack1.display();
    int n = 0;
    Stack1.getTop(n);
    Stack1.pop();
    Stack1.pop();
    Stack1.pop();
    Stack1.display();
    return 0;
}
