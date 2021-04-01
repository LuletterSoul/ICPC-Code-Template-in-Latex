#include <iostream>
#include <algorithm>
using namespace std;
#define N 100010
int num[N];
int n;
int quick_sort(int num[], int l, int r){
    if(l >= r) return 0;
    int mid = num[l+r >> 1], i = l-1, j = r + 1;
    while(i < j){
        while(num[++i] < mid);
        while(num[--j] > mid);
        if(i < j) swap(num[i],num[j]);
    }
    quick_sort(num, l, j);
    quick_sort(num, j + 1, r);
}
int main(){
    scanf("%d", &n);
    for(int i =0 ;i < n ; i++) scanf("%d", &num[i]);
    quick_sort(num, 0, n-1);
    for(int i = 0; i < n; i++) printf("%d ", num[i]);
    return 0;
}