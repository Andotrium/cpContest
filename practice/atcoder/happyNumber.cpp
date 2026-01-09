#include <iostream>
#include <set>
#include <vector>
using namespace std;

int digitSum(int x){
    int sum = 0;
    while(x>0){
        sum += pow(x%10,2);
        x /= 10;
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    set<int> real;
    while(n != 1 && real.find(n) == real.end()){
        real.insert(n);
        n = digitSum(n);
    }
    cout << ((n==1)?"Yes":"No");
    return 0;

}