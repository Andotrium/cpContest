#include <iostream>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll p,q;
        cin >> p >> q;
        if(p<q && (3*p-2*q)>=0){
            cout << "Bob"<<endl;
        }
        else cout << "Alice"<<endl;
    }
}