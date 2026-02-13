#include <iostream>
#include <string>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(auto&x:a) cin >> x;
    vector<string>b;
    sort(a.begin(),a.end(),[](auto& a, auto& b){
        return a>b;
    });
    for(auto x:a){
        string s = "";
        for(ll i=0;i<x;i++){
            s += "1";
        }
        b.push_back(s);
    }
    ll j=b[0].size()-1;
    while(j>=0){
        for(int i=1;i<n;i++){
            if(j-b[i].size()<0){
                continue;
            }
            
        }
    }
    
}