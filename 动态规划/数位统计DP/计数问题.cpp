#include<iostream>
#include<cstring>
using namespace std;
const int N  = 100;
int dp[N][N][2][2], digit[N];

/*
    x: 统计的数字
    l: 第几位
    lead: 前导0
    sum: 当前整数包含x的个数
    limit: 是否达到上限
*/
int f(int x, int l, int sum, bool lead, bool limit){
    // 当前数字统计完了
    if(!l) return sum;
    // 记忆化搜索
    if(dp[l][sum][lead][limit] != -1) return dp[l][sum][lead][limit]; 
    int res =0;
    int k = limit ? digit[l] : 9;
    for(int i = 0; i <= k; i ++){
        bool ne_limit = limit && (i == k);
        if(lead && !i) // 含前导0，跳过继续搜 
            res += f(x, l-1, sum, true, ne_limit);
        else // 不含前导零, 判断当前位是否为x
            res += f(x, l-1, sum + (i == x), false, ne_limit);
    }
    // 返回第1~l位中的统计结果
    return dp[l][sum][lead][limit] = res;
}

int solve(int n, int x){
    int len = 0; 
    memset(dp, -1 ,sizeof dp);
    while(n){
        digit[++len] = n % 10;
        n /= 10;
    }
    return f(x, len, 0, true, true);
}

int main(){
    int a, b;
    while(scanf("%d%d",&a, &b) && a && b){
        if(a > b) swap(a, b);
        for(int i = 0 ; i <= 9; i++)
            printf("%d ", solve(b,i) - solve(a-1,i));
        puts("");
    }
    return 0;
}