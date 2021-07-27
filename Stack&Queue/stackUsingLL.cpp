#include<bits/stdc++.h>
using namespace std;
template<typename t>
class node{
public:
t data;
node<t> *next;
node(t data){
    this->data = data;
    next = NULL;
}
};
template<typename t> // for every class we have to specify the typename
class Stack{
node<t>* head;
int size;
public:
Stack(){
head = NULL;
size = 0;
}
int getsize(){
    return size;
}
bool isempty(){
    return size == 0;
}
void push(t data){
    node<t>* temp = new node<t>(data);
    temp->next = head;
    head = temp;
    size++;
}
void pop(){
node<t>* temp = head;
head = head->next;
delete temp;
size--;
}
t top(){
    return head->data;
}

};

int main(){
Stack<int> s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
while(!s.isempty()){
    cout<<s.top()<<" ";
    s.pop();
}


}