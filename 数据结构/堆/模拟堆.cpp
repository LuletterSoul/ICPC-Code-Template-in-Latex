#include <iostream>
#include <string.h>
using namespace std;
const int N = 100010;

char o[3];
// string o;
int idx=0,n,sz=0,x,k,h[N],hp[N],ph[N];


void heap_swap(int u, int d){
    swap(ph[hp[u]],ph[hp[d]]);
    swap(h[u],h[d]);
    swap(hp[u],hp[d]);
}

int down(int u){
    int t = u;
    if(2*u<=sz && h[2*u] < h[t]) t = 2*u;
    if(2*u+1<=sz &&h[2*u+1] < h[t]) t = 2*u+1;
    if(u!=t){
        heap_swap(u,t);
        down(t);
    }
}


int up(int u){
    while (u/2 && h[u] < h[u/2]){
        heap_swap(u/2,u);
        u >>=1;
    }
}


int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%s", o);
        if(!strcmp(o,"I")){ // 插入一个数
            scanf("%d", &x);
            h[++sz] = x;
            hp[sz] = ++idx;
            ph[idx] = sz;
            up(sz);
        }
        if(!strcmp(o,"PM")){ // 输出当前集合中的最小值
            printf("%d\n", h[1]);
        }
        if(!strcmp(o,"DM")){ // 删除当前集合的最小值
            heap_swap(1,sz--);
            down(1);
        }
        if(!strcmp(o,"D")){ // 删除第k个插入的数
            scanf("%d", &k);
            int u = ph[k];
            heap_swap(u, sz--);
            up(u);
            down(u);
        }
        if(!strcmp(o,"C")){ // 修第k个插入的数
            scanf("%d%d",&k, &x);
            h[ph[k]] = x;
            up(ph[k]);
            down(ph[k]);
        }
    }
}