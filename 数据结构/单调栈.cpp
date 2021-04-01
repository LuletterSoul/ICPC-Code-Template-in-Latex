#include <iostream>
using namespace std;

const int N = 100010;

int s[N], a[N], t=0,n;


int main(){
    scanf("%d", &n);
    for(int i = 0 ;i < n; i++) scanf("%d", &a[i]);
    for(int i = 0;i < n; i++){
        while(t && s[t] >= a[i]) t--;
        if(t){
            printf("%d ",s[t]);
        }
        else{
            printf("%d ",-1);
        }
        s[++t] = a[i];
    }
    return 0;
}