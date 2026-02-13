#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll num;
        cin >> num;
        if(num%9 == 0){
            if((num-10)%11==0) cout << 0 <<endl;
            else cout << 10 << endl;
        }
        else cout << 0 << endl;
    }
}