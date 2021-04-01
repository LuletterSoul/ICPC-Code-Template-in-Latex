#include <iostream>
using namespace std;

const int N = 100010;
char oper[3];
int p[N], s[N], n, m , x, y;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <=n; i++) p[i] = i,s[i] = 1;
    while(m--){
        scanf("%s",oper);
        if(oper[0] == 'C'){
            scanf("%d%d",&x, &y);
            int px = find(x), py = find(y);
            if(px != py){
                s[py] += s[px];
                p[px] = py; 
            } 
        }
        if(oper[0] == 'Q'){
            if(oper[1] == '1'){
                scanf("%d%d",&x, &y);
                if(find(x) == find(y)) printf("Yes\n");
                else printf("No\n");
            }
            if(oper[1] == '2'){
                 scanf("%d",&x);
                 printf("%d\n", s[find(x)]);
            }
        }
    }
}

