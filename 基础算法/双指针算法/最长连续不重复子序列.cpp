#include<iostream>
#include<algorithm>
using namespace std;


#define N 100010

int n,a[N];
int cnt[N];

int main(){
    scanf("%d", &n);
    int res = 0;
    for(int i=0; i<n;i++) scanf("%d", &a[i]);
    
    for(int i = 0,j=i ;  i< n; i++){
        ++cnt[a[i]];
        while(cnt[a[i]] > 1) --cnt[a[j++]];
        res = max(res, i-j + 1);
    }
    
    printf("%d", res);
    
    return 0;
}