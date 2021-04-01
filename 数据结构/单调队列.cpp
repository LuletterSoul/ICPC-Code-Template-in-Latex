#include <iostream>
using namespace std;

const int N = 1000010;
int n,k,q[N],a[N];
int h=0,t=-1;


int main(){
    scanf("%d %d",&n,&k);
    for(int i = 0 ; i < n;i++) scanf("%d", &a[i]);
    
    for(int i = 0; i< n;i++) {
        while(h<=t && q[h] < i - k + 1) h++; // 去除不在滑动窗口内的下标;
        while(h<=t && a[q[t]]>= a[i]) t--; // 单调队列中所有元素小于当前元素；
        q[++t] = i; // 队列储存的是下标；
        if(i+1>=k){ // 滑动窗口未完全进入不输出；
            printf("%d ", a[q[h]]);
        }
    }
    puts("");
    h=0, t=-1;
    for(int i = 0; i< n;i++) {
        while(h<=t && q[h] < i - k + 1) h++;
        while(h<=t && a[q[t]]<= a[i]) t--;
        q[++t] = i;
        if(i+1>=k){
            printf("%d ", a[q[h]]);
        }
    }
    
    return 0;
}