#include <iostream>
using namespace std;
# define N 100010

double n;

int main(){
    scanf("%lf", &n);
    double l = -10000, r = 10000, x=0;
    while(r - l >= 10e-8){
        x = (l + r) / 2;
        if(x * x * x >=n) r = x;
        else l = x;
    }
    printf("%lf", x);
}