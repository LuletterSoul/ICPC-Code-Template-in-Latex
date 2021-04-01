#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<string.h>

using namespace std;

const int N = 110, M = 10010;
int s[N], f[M], n, k;


int sg(int x){
    if(f[x] != -1) return f[x];
    
    unordered_set<int> S;
    for(int i = 0; i < k; i++){
        if(x >= s[i]) S.insert(sg(x - s[i]));
    }
    for(int i = 0; i < n; i++){
        if(!S.count(i)) {
            return f[x] = i;
        }
    }
}

int main(){
    memset(f, -1, sizeof f);
    scanf("%d", &k);
    for(int i = 0 ; i < k;  i ++) scanf("%d", &s[i]);
    int res = 0;
    scanf("%d", &n);
    for(int i = 0 ; i < n; i ++) {
       int x;
       scanf("%d", &x);
       res ^= sg(x);
    }
    if(res) puts("Yes");
    else puts("No");
    return 0;
}