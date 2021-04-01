#include <iostream>
#include <string>
using namespace std;

const int N = 100010;

string oper;
int m,k,x,idx,l[N],r[N],el[N];

void init(){
    // 0是左节点，1是右节点；
    r[0] = 1, l[1]=0;
    idx = 2;
}
//在第k个数的右边添加新节点
void add(int k, int x){
    el[idx] = x, l[idx] = k, r[idx] = r[k], l[r[k]] = idx, r[k] = idx ++;
}
//删除第k个节点
void del(int k){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
int main(){
    cin >> m;
    init();
    while(m--){
        cin >> oper;
        if(oper == "L"){
            cin >> x;
            add(0,x);
        }
        if(oper == "R"){
            cin >> x;
            add(l[1],x);
        }
        if(oper == "D"){
            cin >> k;
            del(k+1);
        }
        if(oper == "IL"){
            cin >> k >> x;
            add(l[k+1], x);
        }
        if(oper == "IR"){
            cin >> k >> x;
            add(k+1, x);
        }
    }
    for(int i = r[0]; i!=1; i = r[i]){
        cout << el[i] << ' ';
    }
    return 0;
}

