#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a = pow(2,n);
    cout << a-2*n << endl;
    return 0;
}