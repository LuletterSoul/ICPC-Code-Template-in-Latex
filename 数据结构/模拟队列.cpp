#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int N = 100010;

int q[N], h,t,m,x;
string o;

void init(){
    h = 0, t = -1;
}

void push(int x){
    q[++t] = x;
}

void pop(){
    ++h;
}

int query(){
    return q[h];
}

string empty(){
    return h > t ? "YES" : "NO";
}

int main(){
    cin >> m;
    init();
    while(m--){
        cin >> o;
        if(o == "push"){
            cin >> x;
            push(x);
        }
        if(o == "pop"){
            pop();
        }
        if(o == "empty"){
            cout << empty() <<endl;
        }
        if(o == "query"){
            cout << query() << endl;
        }
    }
}