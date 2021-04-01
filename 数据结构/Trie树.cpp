#include<iostream>
using namespace std;

const int N = 2e4 + 10;

char oper[2],str[N];
int cnt[N],n, s[N][26],idx=0;

void insert(char * str){
    int p = 0;
    for(int i = 0 ; str[i]; i++){
        int c = str[i] - 'a';
        if(!s[p][c]) s[p][c] = ++idx;
        p = s[p][c];
    }
    ++cnt[p];
}

int query(char * str){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int c = str[i] - 'a';
        if(!s[p][c]) return 0;
        p = s[p][c];
    }
    return cnt[p];
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%s %s",oper,str);
        // cout << oper <<endl << str <<endl;
        if(oper[0] == 'I'){
            // printf("%d\n",insert())
            insert(str);
        }
        if(oper[0] == 'Q'){
            printf("%d\n", query(str));
        }
    }
    return 0;
}