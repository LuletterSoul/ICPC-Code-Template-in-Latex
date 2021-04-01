#include <iostream>
using namespace std;
const int N = 1e5 * 31 + 10;


int n, son[N][2],idx=0;

void insert(int x){
    int p = 0;
    for(int i = 31; i>=0;i--){ // 贪心，从整数最高位开始构造Tried树；
        int b = x >> i & 1;
        if(!son[p][b]) son[p][b] = ++idx;
        p = son[p][b];
    }
}

int query(int x){
    int p = 0, res=0;
    for(int i = 31;i >=0; i--){
        int b = x >> i & 1;
        if(!son[p][!b]){
            res = 2 * res;
            p = son[p][b];
        }
        else{
            res = 2 * res + 1;
            p = son[p][!b];
        }
    }
    return res;
}


int main(){
    scanf("%d", &n);
    int res = 0,x=0;
    for(int i = 0; i < n;i ++){
        scanf("%d", &x);
        insert(x);
        res = max(res, query(x));
    }
    printf("%d", res);
    
    return 0;
}