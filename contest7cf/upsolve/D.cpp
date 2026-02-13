#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

/*
first sort the swords in desceding
we know that x will go from min sword value to max sword value
let's take x at max, and in single iteration go from max to least thus desceding sorted swords
decrease monsters by 1 at each sword, and if 0 then go to next level
*/

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> swords(n);
        vector<ll> monsters(n);
        for(auto &x: swords) cin >> x;
        for(auto &x: monsters) cin >> x;

        sort(swords.begin(),swords.end(),[](auto& a,auto &b){return a>b;});

        ll levels = 0;
        ll ans = 0;
        for(int i=0;i<n;i++){
            int x = swords[i];
            monsters[levels]--;
            if(levels < n && monsters[levels] == 0) levels++;
            ans = max(ans,x*levels);
            // cout << "x,levels="<<x << "," << levels << endl;
        }
        cout << ans << endl;


    }
}