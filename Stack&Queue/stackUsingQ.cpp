#include<bits/stdc++.h>
using namespace std;
int main(){
//using 2 queues
/*
queue<int> q1,q2;
int n;
cin>>n;
for(int i = 0; i<n ;i++){
int x;
cin>>x;
q2.push(x);
while(!q1.empty()){
    q2.push(q1.front());
    q1.pop();
}
swap(q1,q2);
}

while(!q1.empty()){
    cout<<q1.front()<<endl;
    q1.pop();
}
*/

//using 1 queue
queue<int> q;
int n;
cin>>n;
for(int i = 0; i<n ;i++){
int x;
cin>>x;
q.push(x);
for(int j = 1;j<q.size();j++){
int temp = q.front();
q.pop();
q.push(temp);
}
}

while(!q.empty()){
    cout<<q.front()<<endl;
    q.pop();
}



}