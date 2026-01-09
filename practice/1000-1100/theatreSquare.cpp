#include <iostream>
#define ll long long
using namespace std;


int main(){
    ll n,m,a;
    cin >> n >> m >> a;
    ll side1,side2;
    side1 = (n+a-1)/a;
    side2 = (m+a-1)/a;
    cout << side1*side2;
    return 0;
}