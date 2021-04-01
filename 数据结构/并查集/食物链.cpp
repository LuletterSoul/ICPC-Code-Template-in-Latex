#include <iostream>
using namespace std;

const int N = 50010;


int n,k,d,x,y,res=0,dist[N],p[N];

int find(int x){
    if(p[x] != x){
        int t = find(p[x]);
        dist[x] += dist[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++) p[i] = i, dist[i] = 0;
    while(k--){
        scanf("%d%d%d",&d,&x,&y);
        if( x > n || y > n) res++;
        else{
            if(d==1){
                int px = find(x), py = find(y);
                if(px == py && (dist[x] - dist[y]) % 3) res++;
                else if(px!=py){
                    p[px] = py;
                    dist[px] = dist[y] - dist[x];
                }
            }
            else{
                int px = find(x), py =find(y);
                if(px == py && (dist[x] - dist[y] - 1) %3) res++;
                else if(px!=py){
                    p[px] = py;
                    dist[px] = dist[y] + 1 -dist[x];
                }
            }
        }
    }
    printf("%d",res);
}