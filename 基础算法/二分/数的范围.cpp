#include <iostream>
#include <algorithm>
using namespace std;
#define N 100010


int n,q,k;
int a[N];

int lower_find(int a[], int l, int r, int k){
    while(l < r){
        int mid = l + r >> 1;
        if(k <= a[mid]) r = mid;
        else l = mid+1;
    }
    return a[l] == k ? l : -1;
}

int upper_find(int a[], int l, int r, int k){
    while(l < r){
        int mid = l+r+1 >> 1;
        if(k >= a[mid]) l = mid;
        else r = mid -1;
    }
    return a[l] == k ? l : -1;
}

int main(){
    scanf("%d %d",&n, &q);
    for(int i= 0 ;i< n;i++) scanf("%d", &a[i]);
    for(int i =0 ;i < q;i++) {
        scanf("%d", &k);
        int res = lower_find(a, 0, n-1, k);
        if(res == -1) printf("%d %d", -1, -1);
        else{
           printf("%d ", res);
           res = upper_find(a, 0, n-1, k); 
           printf("%d", res);
        }
        if(i != q - 1)
            printf("\n");
    }
}