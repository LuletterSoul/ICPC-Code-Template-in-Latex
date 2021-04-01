#include<iostream>
#include<algorithm>
using namespace std;

#define N 100010

int q[N];
int n;
long long res=0;

int merge_sort(int q[], int l, int r){
    if(l>=r) return 0;
    int mid = l + r >> 1;
    merge_sort(q,l,mid);
    merge_sort(q,mid+1,r);
    int i=l,j=mid+1,k=0,tmp[r-l+1];
    while(i<=mid&&j<=r){
        if(q[i] <= q[j]) tmp[k++] = q[i++];
        else {
            tmp[k++] = q[j++];
            res += (mid - i + 1);
        }
    }
    while(i<=mid) tmp[k++] = q[i++];
    while(j<=r) tmp[k++] = q[j++];
    for(int i=0,j=l;j<=r;i++,j++) q[j] = tmp[i];
}

int main(){
    scanf("%d", &n);
    for(int i= 0; i< n ; i++) scanf("%d", &q[i]);
    merge_sort(q, 0, n-1);
    printf("%ld",res);
    return 0;
}