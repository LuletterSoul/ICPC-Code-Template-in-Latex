#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define N 300000 + 10
typedef pair<int,int> PII;
vector<PII> opers,query;
vector<int> alls;
int a[N];

int n, m, x,c, l,r;

int binary_search(int k){
    int l = 0 , r = alls.size() - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(k <= alls[mid]) r = mid;
        else l = mid + 1;
    }
    return alls[l] == k ? l+1 : -1;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0 ;i < n; i++){
        scanf("%d %d", &x, &c);
        opers.push_back({x,c});
        alls.push_back(x);
    }
    
    for(int i= 0; i < m; i++){
        scanf("%d %d", &l, &r);
        query.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(auto p : opers){
        int index = binary_search(p.first);
        a[index] += p.second;
    }
    
    for(int i = 1; i<= alls.size(); i++) a[i] = a[i-1] + a[i];
    
    for(auto p : query){
        int l = binary_search(p.first);
        int r = binary_search(p.second);
        printf("%d\n", a[r] - a[l-1]);
    }
    
}