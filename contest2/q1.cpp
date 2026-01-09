#include <iostream>
#include <string>
#include <vector>
using namespace std;

int numRequired(string s, int len){
vector<char> arr;
int zeroCount=0,oneCount=0;
for(char c: s){
arr.push_back(c);
if(c == '0') zeroCount ++ ;
else oneCount ++ ;}

int ans = 0;
// cout << "zerocount == " << ans <<endl;
// cout << "zero,1 index="<< arr[0] << "," << arr[1] << endl;
for(int i=0;i<zeroCount;i++){
if( arr[i] == '1') {ans++; }
}
return max(ans,0);

}
int main(){
int t;
cin >> t;
while(t--){
string s;
int len;
cin >> len;
cin >> s;
cout << numRequired(s, len)<<endl;
}
}
