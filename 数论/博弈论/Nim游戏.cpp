#include<iostream>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    int x; 
    scanf("%d", &x);
    for(int i = 0; i < n -1; i++){
        int y;
        scanf("%d",&y);
        x ^=y;
    }
    if(x) puts("Yes");
    else puts("No");
    return 0;
}