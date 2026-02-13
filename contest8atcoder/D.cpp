#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long
using namespace std;
/*
this approach TLEs as it is O(n^2)
*/
// void solve(){
//         ll n;
//     cin >> n;
//     ll sum = 0;
//     vector<ll> arr(n);
//     for(auto &x:arr){
//         cin >> x;
//         sum += x;

//     }
//     vector<ll> copy = arr;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             ll limit = arr[i] + abs(j-i);

//             if( i == j) continue;
//             copy[j] = min(copy[j],limit);

//         }

//     }

//     for(auto x:copy)sum -= x;
//     cout << sum << endl;
//     return ;
// }

/*
let's do this in O(n)*/
void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum=0;
    for(auto &x:arr) {cin >> x;sum+=x;}
    for(int i=1;i<n;i++){
        arr[i] = min(arr[i-1]+1,arr[i]);
    }
    for(int i=n-2;i>=0;i--){
        arr[i] = min(arr[i+1]+1,arr[i]);
    }
    for(auto x:arr) sum-=x;
    cout << sum << endl;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }

}