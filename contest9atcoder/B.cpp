#include <iostream>
using namespace std;

int digitSum(int num,int k){
    int sum=0;
    while(num){
        sum += num%10;
        if(sum > k) return -1;
        num/=10;
    }
    return sum;
}

int main(){
    int n,k;
    cin >> n >> k;
    int ans=0;
    for(int i=1;i<=n;i++){
        if(digitSum(i,k)==k){
            ans++;
        }
    }
    cout << ans;
}