#include <iostream>
#include <vector>

using namespace std;

int main(){
int n;
cin >> n;
int comp = n%10;
bool flag = true;

while(n){
    int t = n%10;
    if(t!=comp) {
        cout << "no";
        flag = false;
        break;
    }
    n/=10;
}
if(flag) cout << "yes";
}