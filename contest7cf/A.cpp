#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,s,x;
        cin >> n >> s >> x;
        vector<ll> arr(n);
        ll sum = 0;
        for(auto &x:arr) {
            cin >> x;
            sum += x;
        }
        if((sum <=s)&&(s-sum)%x == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}