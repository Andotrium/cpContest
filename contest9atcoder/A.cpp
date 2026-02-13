#include <iostream>
#include <vector>
#define ll long long
using namespace std;

// number of the form = (1/2^n-1)
// 
int main(){
    ll n;
    cin >> n;
    bool trig = false;
    while(n/10){
        ll digit = n%10;
        n/=10;
        ll digit2 = n%10;
        if(digit != digit2){
            cout << "No";
            trig = true;
            break;
        }
    }
    if(!trig){
        cout << "Yes";

    }
}