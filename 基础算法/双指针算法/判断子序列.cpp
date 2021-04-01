#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
#define N 100010

int a[N],b[N];
int n,m;
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0 ;i < n ;i ++) scanf("%d", &a[i]);
    for(int i = 0 ;i < m ;i ++) scanf("%d", &b[i]);
    int i = 0, j = 0;
    for(; j < m; j++){
        if(i < n && a[i] == b[j]) i++;
    }
    if(i == n) printf("Yes");
    else printf("No");
    
    return 0;
}