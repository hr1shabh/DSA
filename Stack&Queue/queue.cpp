#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Queue{
vector<t> v;
int size;
int f;
int back;
public:
Queue(){
 size = 0;
 f = -1;
 back = 0;
}
void enqueue(t data){
v.push_back(data);
size++;
if(f == -1) f = 0;
back++;
}

int getsize(){
    return size;
}

t front(){
if(!isempty())
return v[f];
return 0;
}

bool isempty(){
    return size == 0;
}
void dequeue(){
if(!isempty()){
f++;
size--;
}
}

};

int main(){
Queue<int> q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
cout<<q.front()<<endl;
while(!q.isempty()){
    cout<<q.front()<<" ";
    q.dequeue();
}

}