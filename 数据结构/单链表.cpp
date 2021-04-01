
#include <iostream>
#include <string>
using namespace std;
const int N = 100010;
string c;
int head,idx,el[N],ne[N],k,x,m;
void init(){
    head = -1;
    idx = 0;
}
void add_head(int x){
    el[idx] = x, ne[idx] = head, head = idx++;
}
void add(int k, int x){
    el[idx] = x; ne[idx] = ne[k], ne[k] = idx++;
}
void del_head(){
    head = ne[head];
}
void del(int k){
    ne[k] = ne[ne[k]];
}
int main(){
    cin >> m;
    init();
    while(m--){
        cin >> c;
        if(c == "H"){
            cin >> x;
            add_head(x);
        }
        if(c == "D"){
            cin >> k;
            if(!k) del_head();
            else del(k-1);
        }
        if(c =="I"){
            cin >> k >> x;
            add(k-1,x);
        }
    }
    for(int i = head; i!=-1;i=ne[i]){
       cout << el[i] << ' ';
    }
    return 0;
}
