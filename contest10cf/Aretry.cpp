#include <iostream>
#define ll long long
using namespace std;

ll dsum(ll n){
    ll sum = 0;
    while(n){
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        ll ans = 0;
        for(int i=0;i<=81;i++){
            ll y = x + i;
            if(dsum(y) == i) ans++;
        }
        cout << ans << endl;
    }
}