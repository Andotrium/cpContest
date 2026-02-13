#include <iostream>
#include <vector>
#include <set>
#include <string>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> u(n); // number of unique characters uptil that point
        set<char> uc; // unique character set to count the number of unique characters we'll encounter uptil that point
        uc.insert(s[0]);
        for(int i=0;i<n;i++){
            uc.insert(s[i]);
            u[i] = uc.size();
        }
        ll sum = 0;
        for(auto x:u) sum += x;
        cout<<sum<<endl;
    }
}