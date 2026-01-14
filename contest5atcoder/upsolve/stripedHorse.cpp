#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

/*
here what we will do is, first we need to observe that, we will always select w consective numbers, so basically
we can group the separate numbers by their modulo value with 2w. This give us a way to always find consecutive sum in O(N).

After that we know that the bucket size is always w, now simply what x does is, it will move the bucket forward and backward depending
on the value of x
for ex. 
if w = 2
for x=0;
indexes : 0,1
x=-1:
indexes: 1,2

so on and so forth, so basically the sole purpose of x is to simply move the bucket forward and backward, and thus
we'll simply move it ourselves and find the min value of such bucket because we can choose any x
*/

ll ans(vector<ll>& arr, ll n, ll w){
ll period = 2*w;
vector<ll> remainder(period,0); // grouping by modulo, where the index symbolises the value of modulo
for(ll i=0;i<n;i++){
remainder[i%period] += arr[i];
}

// now create a bucket
ll bucket = 0;
ll answer = 0;
for(ll i=0;i<w;i++){
    bucket += remainder[i];
}
answer = bucket;
// now an import thing we need to observe is that we need a circular list of the remainders
// this is because say in examples such as index = 1,2,3,4 -> if we want a bucket where [4,1] included, we simply just need
// to add the same array once to make it circular, i.e index = 1,2,3,4,1,2,3,4 -> this way we get all the possible combinations

vector<ll> circular(period*2);
for(ll i=0;i<period*2;i++){
    circular[i] = remainder[i%period];
}

// now let's move the bucket
for(ll i=w;i<period+w;i++){
    bucket += circular[i];
    bucket -= circular[i-w];
    answer = min(answer,bucket);
}
return answer;

}
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,w;
        cin >> n >> w;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << ans(arr,n,w) << endl;
    }
}