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

// function to return mid value of linked list without knowing its length 
node* mid(node* head){
if(head == NULL) return head;
node* slow = head;
node* fast = head;
while(fast->next != NULL and fast->next->next != NULL){
	slow = slow->next;
	fast = fast->next->next;
}
return slow;
}

//================================================================================================================//
//merge two sorted linked list
node* merge(node* h1, node* h2){
if(h1 == NULL) return h2;
if(h2 == NULL) return h1;
node* h = NULL;
if((h1->data) < (h2->data)){
h = h1; 
h1=h1->next;
}
else{
	h=h2;  h2=h2->next;
}

node* t = h;
while(h1!=NULL and h2!=NULL){
if((h1->data) > (h2->data)){
	t->next = h2;
	t = t->next;
	h2=h2->next;
}
else{
t->next = h1;
t = t->next;
h1=h1->next;
}
}

while(h1!=NULL){
t->next = h1;
t = h1;
h1=h1->next;
}
while(h2!=NULL){
	t->next = h2;
	t = h2;
	h2=h2->next;	
}
return h;
}
//================================================================================================================//
//***REVERSE A LINKED LIST ***//
node* Reverse(node* head){
if(head == NULL or head->next == NULL) return head;

node* h = Reverse(head->next);
node* temp = head->next;
temp->next = head;
head->next = NULL;
return h;
}
//================================================================================================================//
node* ReverseI(node* head){
if(head == NULL or head->next == NULL) return head;
node* c = head; // c holds the current position
node* p = NULL; // p holds the previous position
node* n = head; // n holds the next position
while(1){
n = n->next;	
c->next = p;  // curr position should point to its prev
p = c;  // pre will movw to curr
if(n == NULL){ //if our next pos is NULL then we are done
	break;
}
c = n;
}
return c;
}
//================================================================================================================//
// we use dynamic allocation due to scope issue
int main(){
// node* head = takeInput(); //head is the pointer to the head node of linked list
// print(head);
// head = insertAtK_R(head,3,4);
// print(head);
// head = DeleteAtKR(head,2);
// print(head);
// cout<<mid(head)->data<<endl;

// node* h1 = takeInput();
// node* h2 = takeInput();
// node* h = merge(h1,h2);
node* h =takeInput();
h = Reverse(h);
print(h);
h = ReverseI(h);
print(h);
return 0;}