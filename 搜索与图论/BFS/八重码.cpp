#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
queue<string> q;
string u;
unordered_map<string,int> d;


int bfs(string u){
    q.push(u);
    d[u] = 0;
    string end = "12345678x";
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(t == end) return d[t];
        int k = t.find('x');
        int a = k / 3, b = k % 3;
        int dist = d[t];
        for(int i = 0 ; i < 4;i++){
            int x = a + dx[i], y = b + dy[i];
            if(x>=0 && x < 3 && y>=0 && y < 3){
                swap(t[x * 3 + y], t[k]);
                if(!d.count(t)){
                    d[t] = dist + 1;
                    q.push(t);
                }
                swap(t[x * 3 + y], t[k]);
            }
        }
        
    }
    return -1;
}


int main(){
    char c;
    for(int i = 0 ; i < 9;i++){
        scanf("%c ",&c);
        u+=c;
    }
    // cout << u << endl;
    printf("%d",bfs(u));
}

