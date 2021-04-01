#include<iostream>
#include <string.h>
using namespace std;

const int N = 100010;
char oper[2];
int idx=0,n,x, el[N],ne[N],h[N], mod =100003;

void insert(int x){
    int t = (x % mod + mod) % mod;
    el[idx] = x, ne[idx] = h[t], h[t] = idx++;
}
bool query(int x){
    int t = (x % mod + mod) % mod;
    for(int i = h[t]; i!= -1;i = ne[i]){
        if(el[i] == x) return true;
    }
    return false;
}

int main(){
    scanf("%d", &n);
    memset(h,-1,sizeof(h));
    while(n--){
        scanf("%s%d",oper,&x);
        if(oper[0]=='I'){
            insert(x);
        }
        if(oper[0] == 'Q'){
            bool is_exisit = query(x);
            if(is_exisit)
                printf("%s\n","Yes");
            else
                printf("%s\n","No");
        }
    }
}