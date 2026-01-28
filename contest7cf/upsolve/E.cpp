#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

// time complexity = O(n* root(n))
/*
first make an array 0-> n indexed
for all elements in the array mark the dp[a] = 1
then iterate over 1->n, and then find all the divisors of the numbers from 1->n (remember this can be done in root(n) time)
and then for all divisors of x(1->n) let's say we're at the divisor y
dp[x] = min(dp[x],dp[y]+dp[x/y])
then print all the values of dp
*/
vector<ll> divisors(ll num){
    vector<ll> ans;
    if(num == 1) return {1};
    for(int i=2;i*i<=num;i++){
        if(num%i == 0) {ans.push_back(i);ans.push_back(num/i);}
    }

    return ans;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        ll maximum = LLONG_MIN;
        for(auto &x:arr) {cin >> x; maximum = max(x,maximum);};
        vector<ll> dp(n+1,INT_MAX);
        for(auto x:arr) dp[x] = 1;

        for(ll i=1;i<=n;i++){
            vector<ll> divisorList = divisors(i);

            for(auto y:divisorList){
                dp[i] = min(dp[i], dp[y]+dp[i/y]);
            }

        }
        for(int i=1;i<=n;i++){
            if(dp[i] == INT_MAX) cout << -1 << " ";
            else cout << dp[i] << " ";
        }
        cout << endl;
    }
}