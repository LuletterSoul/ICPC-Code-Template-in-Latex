#include<iostream>
using namespace std;
#define N 100010
int a[N];
int S[N];
int n,m,l,r;
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=n; i++) scanf("%d", &a[i]);
    for(int i =1 ;i<=n;i++) S[i] = S[i-1] + a[i];
    while(m--){
        scanf("%d %d", &l, &r);
        printf("%d\n" ,S[r] - S[l-1]);
    }
}