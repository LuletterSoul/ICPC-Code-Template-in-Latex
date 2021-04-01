#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

int m;
int s[N], t=0, x;
string oper;

void init(){
    t = 0;
}

void push(int x){
    s[++t] = x;
}

void pop(){
    --t;
}

string empty(){
    return t == 0 ? "YES" : "NO";
}

int query(){
    return s[t];
}


int main(){
    cin >> m;
    init();
    while(m--){
        cin >> oper;
        if(oper == "push"){
            cin >> x;
            push(x);
        }
        if(oper == "pop"){
            pop();
        }
        if(oper == "empty"){
            cout << empty() << endl;
        }
        if(oper == "query"){
            cout << query() << endl;
        }
    }
}
