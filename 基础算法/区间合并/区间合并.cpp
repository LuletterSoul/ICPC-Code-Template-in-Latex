#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> PII;

int n;
int l, r;
vector<PII> segs;

int merge(vector<PII> &segs){
    sort(segs.begin(),segs.end());
    int st = -2e9, ed = -2e9;
    vector<PII> res;
    for(auto seg : segs){
        if(ed < seg.first){
            if(st!=-2e9)  res.push_back({st,ed});
            st = seg.first;
            ed = seg.second;
        }
        else{
            ed = max(ed, seg.second);
        }
    }
    if(st != -2e9) res.push_back({st,ed});
    return res.size();
}

int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%d %d", &l,&r);
        segs.push_back({l,r});
    }
    int res = merge(segs);
    printf("%d", res);
    return 0;
}