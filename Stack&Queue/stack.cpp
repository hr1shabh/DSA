#include<bits/stdc++.h>
using namespace std;
template<typename t>
class Stack{
    int i = 0;
    vector<t> v;
    public:
int size(){
    return v.size();
}
bool isempty(){
return v.size() == 0;
}
void push(int data){
    v.push_back(data);
}
void pop(){
    v.pop_back();
}
t top(){
    return v.back();
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