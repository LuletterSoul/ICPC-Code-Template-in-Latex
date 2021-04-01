#include<iostream>
#include<unordered_set>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 110;
int s[N],f[N], n;
int sg(int x){
    if(f[x]!=-1) return f[x];
    
    unordered_set<int> S;
    
    for(int i = 0 ; i < x; i++)
        for(int j = 0 ; j <= i; j++)
            S.insert(sg(i) ^ sg(j));
    
    for(int i = 0; ; i++)
        if(!S.count(i)) return f[x] = i;
}

int main(){
    scanf("%d", &n);
    int res = 0;
    memset(f, -1, sizeof f);
    for(int i = 0 ; i < n; i++){
        int x;
        scanf("%d", &x);
        res ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
}