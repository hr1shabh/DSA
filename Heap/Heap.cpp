#include<bits/stdc++.h>
using namespace std;

/* sorting -> nlog(n)
Heap
insert -> O(log(n))
pop -> O(log(n))
get -> O(1)

Heap is a complete binary tree (but must be filled from left to right order)
max heap = every parent node > children
min heap = every parent node < children
*/

class heap{
vector<int> v;
bool minheap;

void heapify(int idx){
int left = 2*idx;
int right = left+1;
int last = v.size()-1;
int min = idx;
if(minheap){
    if(left<=last and v[min]>v[left]) min = left; //for minheap , In case of maxheap v[min]<v[left]
    if(right<=last and v[min]>v[right]) min = right;
}
else{
    if(left<=last and v[min]<v[left]) min = left; 
    if(right<=last and v[min]<v[right]) min = right;
}
if(min != idx){
    swap(v[min],v[idx]);
    heapify(min);
}
}

public:
heap(bool minheap){
    v.push_back(-1); //we don't need 0th idx
    this->minheap = minheap; 
}

void push(int data){
    v.push_back(data);
    int i = v.size()-1;
    int parent = i/2;
    if(minheap){
    while(i>1 and v[parent] > v[i]){
        swap(v[parent],v[i]);
        i = parent;
        parent/=2;
    }}
    else{
    while(i>1 and v[parent] < v[i]){
        swap(v[parent],v[i]);
        i = parent;
        parent/=2;
    }
    }
}

int top(){
    return v[1];
}

void pop(){
    swap(v[1],v[v.size()-1]);
    v.pop_back();
    heapify(1);
}

bool empty(){
    return v.size() == 1;
}

};

int main(){
    int n;
    cin>>n;
    heap h(0);
    while(n--){
        int x;
        cin>>x;
        h.push(x);
        // cout << h.top() << " ";
    }
    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }

}
