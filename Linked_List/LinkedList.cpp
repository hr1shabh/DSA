#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int data){
		this -> data = data;
		next = NULL;
	}
};
//================================================================================================================//
// We take input to the linked list until we found -1
node* takeInput(){
int data;
cin>>data;
node* head = NULL;
node* tail = head;
while(data != -1){
node* temp = new node(data);
if(head == NULL){
	head = temp;
	tail = head;
}else{
tail -> next = temp;
tail = tail->next;}
cin>>data;
}
return head;
}

//================================================================================================================//
// for printing all elements in linked list
void print(node* head){
while(head != NULL){
	cout<<head->data<<" ";
	head = head->next;
}
cout<<endl;
}

//================================================================================================================//

// A function to insert at kth position
node* inserAtK(node* head, int i,int no){
node* temp = new node(no);
if(i == 0){
temp->next = head;
head = temp;
return head;
}
int cnt = 0;
node* t=head;
while(t!=NULL and cnt < i-1){
t = t->next;
cnt++;
}
if(t == NULL) return head;
temp->next = t->next;
t->next = temp;
return head;
 }


//================================================================================================================//
//Recursive code
node* insertAtK_R(node* head,int i, int no){
if(head == NULL) return NULL;

if(i == 0){
node* t = new node(no);
t->next = head;
head = t;
return head;
}
head->next = insertAtK_R(head->next,i-1,no);
return head;
}

//================================================================================================================//
// delete Recusively
node* DeleteAtKR(node* head, int i){
if(head == NULL) return NULL;

if(i == 0){
node* t = head;
head = head->next;
delete t;
return head;
}
head->next = DeleteAtKR(head->next,i-1);
return head;
}


//================================================================================================================//
// delete element at i th position
node* DeleteAtK(node* head,int i){
if(i == 0){
node* t = head;
head = head->next;
delete t;
return head;
}
int cnt = 0;
node* a = head;
while(a!=NULL and cnt < i-1){
	cnt++;
	a=a->next;
}
if(a == NULL) return head;
node* b = a->next;
a->next = b->next;
delete b;
return head;
}

//================================================================================================================//
// we use dynamic allocation due to scope issue
int main(){
node* head = takeInput(); //head is the pointer to the head node of linked list
print(head);
head = insertAtK_R(head,3,4);
print(head);
head = DeleteAtKR(head,2);
print(head);
return 0;}