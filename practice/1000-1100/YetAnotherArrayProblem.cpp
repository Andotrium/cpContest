#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    while(b!=0){
        a = a%b;
        swap(a,b);
    }
    return a;
}
ll ans(vector<ll>& arr, ll size){
    ll G=arr[0];
    for(ll i=1;i<size;i++){
        G = gcd(G,arr[i]);
    }
    vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53,59};
    for(ll x:primes){
        if(G%x != 0){
            return x;
        }
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll s;
        cin >> s;
        vector<ll> arr(s);
        for(ll i=0;i<s;i++){
            cin >> arr[i];
        }
        cout<<ans(arr, s) << endl;
    }
    return 0;
}