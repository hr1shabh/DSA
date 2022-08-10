#include<bits/stdc++.h>
using namespace std;
/*
    Extended Euclidean gives answer for ax + by = gcd(a,b)
    It will tell us values of x and y which satisfy this eqn
    Time Complexity - O(log(max(a,b)))
*/
int extendedEuclidean(int a,int b,int &x,int &y){
    if(b == 0){x = 1; y = 0; return a;}
    int x1, y1;
    int d = extendedEuclidean(b, a%b, x1, y1);
    x = y1; y = x1 - y1 * (a/b);
    return d;
}
/*
    Modulo Inverse : the no. that should be multplied by a so that the result % Mod is equal to 1
    (a * MI) % Mod = 1
    where MI is modulo inverse
    How Euclidean algo helps ?
    (a * MI)% Mod - 1 = 0
    (a * MI)% Mod - 1 % Mod = 0
    it means they are completely divisible by M
    (a*MI) - 1 = K*M
    a*MI + (-K)*M = 1 .... similar to [ax + by = 1]
    ax + My = 1 ...given that gcd(a,M) = 1
*/
int moduloInverse(int a, int m){
    int x,y;
    int g = extendedEuclidean(a,m,x,y);
    if(g != 1) return -1;
    else return (x%m + m)%m;
}


int main(){
    int x,y;
    cout << moduloInverse(5,8) << endl;
}