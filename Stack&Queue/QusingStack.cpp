#include<bits/stdc++.h>
using namespace std;
class Q{
stack<int> in;
stack<int> out;
public:
void push(int d){
    in.push(d);
}
int top(){
if(out.empty()){
while(!in.empty()){
out.push(in.top());
in.pop();
}
}
return out.top();
}

void pop(){
if(out.empty()){
while(!in.empty()){
out.push(in.top());
in.pop();
}
}
out.pop();
}

bool isempty(){
    return (in.empty() and out.empty());
}

};

int main(){
Q q;
q.push(10);
q.push(20);
q.push(30);
while(!q.isempty()){
    cout<<q.top()<<" ";
    q.pop();
}



}