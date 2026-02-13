#include <iostream>
using namespace std;

int protect(string s,int k,int n){
int pNum = 0;
for(int i=0;i<n;i++){
if(s[i]=='0'){}
else{
    int trigger=0;
    int j=i-1;
    while(j>=0&&j>= i-k+1){
        if(s[j] == '1') trigger=1;
        j--;
    }
    if(!trigger)pNum++;
}
}
return pNum;
}

int main(){
int t;
cin >> t;
while(t--){
int n,k;
cin >> n >> k;
string s;
cin >> s;
cout << protect(s,k,n) << endl;

}
}
