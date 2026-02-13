#include <iostream>
#include <vector>
#define ll long long

using namespace std;

vector<ll> answer(vector<ll> arr, ll n){
ll presentIndex = 0;
ll presentBiggest = n;
vector<ll> ansArray;
while(presentIndex < n && presentBiggest >= 0){
    
    if(arr[presentIndex] != presentBiggest){
        // then find the presentBiggest and switch it with that one
        ll l=presentIndex,r=presentIndex;
        for(ll i=0;i<n;i++){
            if(arr[i] == presentBiggest){
                r = i;
                break;
            }
        }
        for(ll i=r;i>=l;i--) ansArray.push_back(arr[i]);
        for(ll i=r+1;i<n;i++) ansArray.push_back(arr[i]);
        return ansArray;
    }
    else {
        ansArray.push_back(arr[presentIndex]);
        presentIndex++;
        presentBiggest -- ;
    }
}
if(!ansArray.size()) return arr;
return ansArray;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x: arr) cin >> x;
        vector<ll> real = answer(arr,n);
        for(auto x: real) cout << x << " ";
        cout << endl;

    }
}