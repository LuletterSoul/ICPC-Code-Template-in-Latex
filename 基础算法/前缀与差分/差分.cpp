#include <iostream>
using namespace std;

#define N 100010

int a[N], b[N];
int n,m,l,r,c;

int insert(int b[],int l, int r , int c){
    b[l] += c;
    b[r+1] -= c;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n;i++) scanf("%d", &a[i]);
    for(int i=1; i<=n;i++) insert(b,i,i,a[i]);
    while(m--){
        scanf("%d %d %d",&l, &r, &c);
        insert(b,l,r,c);
    }
    for(int i=1;i<=n;i++)
        b[i] += b[i-1];
    for(int i=1;i<=n;i++) printf("%d ", b[i]);
}