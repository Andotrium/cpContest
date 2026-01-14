#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define ll long long 
using namespace std;

/*
a really good problem, here you binary search on the answer itself
let's say the answer is t
now the number of good integers in t = (t-x+1) - (bad integers)
bad integers = number of integers that are in the list A
bad integers = upper_bound(t) - lower_bound(x)
and thus you have to find the smallest number of good integers greater than or equal to y
*/

void answer(vector<ll>& arr, ll n, ll q){
    while(q--){
        ll x,y;
        cin >> x >> y;
        ll left = x, right=x+y+n, ans=-1;
        while(right >= left){
            ll mid = left+(right-left)/2;
            // mid is our guessed number
            // now at any point when total numbers between x and mid minus the numbers that are in the array
            // then that can be a possible answer
            ll cnt = upper_bound(arr.begin(),arr.end(),mid)-lower_bound(arr.begin(),arr.end(),x);
            ll temp = (mid-x+1)-cnt;
            if(temp >= y){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }

        }
        cout << ans << endl;
    }
}

int main(){
    ll n,q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    answer(arr, n,q);
}