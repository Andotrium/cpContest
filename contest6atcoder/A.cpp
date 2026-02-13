#include <iostream>
#include <vector>

#define ll long long 
using namespace std;

int main(){
    ll p,q,x,y;
    cin >> p >> q;
    cin >> x >> y ;
    if((p+100 > x && q + 100 > y ) && (p<=x && q <= y)) cout << "Yes";
    else cout << "No";
    return 0;

}