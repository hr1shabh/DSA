#include<bits/stdc++.h>
using namespace std;

class node{
public:
char data;
unordered_map<char,node*> m;
bool terminal;
node(char d){
    data = d;
    terminal = false;
}
};

class trie{
node* root;
int cnt;
public:
trie(){
    root = new node('\0');
    cnt = 0;
}


void insert(char *s){
node* temp = root;
for(int i = 0;s[i]!='\0';i++){
    char c = s[i];
    if(temp->m.count(c)){
        temp = temp->m[c];
    }
    else{
        node* n = new node(c);
        temp->m[c] = n;
        temp = n;
    } }
    temp->terminal = true;
}



bool find(char *s){
    node* temp = root;
for(int i = 0;s[i]!='\0';i++){
    char c = s[i];
    if(temp->m.count(c)==0){
     return false;
    }
    else{
        temp = temp->m[c];
    }
}
return temp->terminal;
}



};

int main(){

char c[][10] = {"lol","lmao","apple","cat","ape"};

trie t;
for(int i = 0;i<5;i++){
  t.insert(c[i]);
}

char w[10];
cin>>w;
if(t.find(w)) cout<<"YES";
else cout<<"NO";

}

//search complexity -> key length
//better than hashing since for large no.s collisions will be more
//can be used for prefix search (auto complete)