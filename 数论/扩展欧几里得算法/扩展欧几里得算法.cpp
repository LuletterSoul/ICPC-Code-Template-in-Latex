#include<iostream>
using namespace std;

/*
(a,b) = (b, a%b) ==> 
ax + by = d
(a - a//b * b)x + by = d
ax + b(y - a //b *x) = d
y' = y - a//b *x
*/
int exgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b,a%b,y,x);
    y -= (a/b)*x;
    return d;
}

int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int a, b, x ,y;
        scanf("%d%d",&a,&b);
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
    return 0;
}