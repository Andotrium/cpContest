#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
Problem: https://codeforces.com/problemset/problem/2147/B
it's a good question, and you can actually make good observations once you start building it from n=1
a solution is to build the array of the following type
[ n, n-1, n-2, ..., 3, 2, 1, n, 1, 2, 3, ..., n-2, n-1 ]
 now when n+1 arrives, we know that it'll have a maximum distance of 2n+1 (if we place both (n+1)s on the extreme side of our array)
 but 2n+1 is not a multiple of n+1, and it's off only by 1
 so n+1 has to go at a distance of (n+1), but previously
 the n that we had placed, now when n+1 has arrived, now suddenly we see that we have 1 extra space left at the end
 so take the previous n and place it at the end

 so this way we can arrive at the answer
 the combination will always look like this
 [ n, n-1, n-2, ..., 3, 2, 1, n, 1, 2, 3, ..., n-2, n-1 ]

*/

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> ans(2*n);
        for(int i=0;i<2*n;i++){
            if(i==0){
                ans[i] = n;
            }
            else if(i<n){
                ans[i] = n-i;
            }
            else if(i == n) ans[i] = n;
            else {
                ans[i] = i-n;
            }
        }
        for(auto x:ans) cout << x << " ";
        cout << endl;
    }
}