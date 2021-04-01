#include <iostream>
using namespace std;
#define N 100010

int num[N];
int n,k;

int quick_sort(int num[], int l, int r,int k){
    if(l>=r) return 0;
    int x = num[l + r>>1], i = l-1, j= r+1;
    while(i < j){
        while(num[++i] < x);
        while(num[--j] > x);
        if(i < j) swap(num[i],num[j]);
    }
    
    int sk = j - l + 1;
    if(k <= sk) quick_sort(num, l, j, k);
    else quick_sort(num, j+1, r, k - sk);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i< n;i++) scanf("%d", &num[i]);
    quick_sort(num, 0, n-1, k);
    printf("%d", num[k-1]);
    return 0;
}