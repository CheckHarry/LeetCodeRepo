







#define mod 1000000007
    
int countOrders(int n) {
    long long ans = 1;
    for (int i = 1 ; i <= n ; i ++) ans = ans * i * (2*i - 1) % mod;
    return ans;
}