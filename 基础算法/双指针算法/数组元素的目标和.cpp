#include<iostream>
#include<algorithm>
using namespace std;

#define N 100010

int n,m,x;
int a[N], b[N];

int main(){
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 0 ;i < n; i++) scanf("%d", &a[i]);
    for(int i = 0 ;i < m; i++) scanf("%d", &b[i]);
    int i = n-1,j = 0;
    while(i >= 0  || j < m){
        if(i>=0 && a[i] + b[j] > x) i--;
        else if(j < m && a[i] +b[j] < x) j++;
        else if(i>=0 && j< m && a[i]+b[j] == x){
            printf("%d %d",i ,j);
            break;
        };
    }
    return 0;
}
