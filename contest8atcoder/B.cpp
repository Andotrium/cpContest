#include <iostream>
#define ll long long

using namespace std;

bool ok(ll x,ll n,ll k){
    ll sum = n*(x+1) + (1+x)*x/2;
    return sum >= k;

}

int main(){
    ll n,k;
    cin >> n >> k;
    ll low = 0;
    ll high = 2e9;
    ll ans = 0;
    while(high >= low){
        ll mid = low + (high-low)/2;
        if(ok(mid,n,k)){
            ans = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout << ans;

}