#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;
/*
just a stupid question
using my bruteforce approach first found all the subsequences and then tried satisfying both
the conditions for each substring but time complexity too high
simply count all the 0s or 1s and output the their indexes
*/

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> p;
        for(int i=0;i<n;i++){
            if(s[i] == '0') p.push_back(i+1);
        }
        cout << p.size() << endl;
        for(auto x:p) cout << x << " ";
        cout << endl;
    }
}