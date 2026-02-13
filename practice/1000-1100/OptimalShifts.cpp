#include <iostream>
#include <string>
using namespace std;
int ans(string s, int len){
    int maxzeroC = 0;
    int startzeroC = 0;
    int presentZero = 0;
    int i = 0;
    for(auto x:s){
        if(x == '1'){
            break;
        }
        startzeroC++;
    }
    while(i < len){
        if(s[i] == '0'){
            presentZero ++ ;
        }
        else {
            maxzeroC = max(maxzeroC,presentZero);
            presentZero = 0;  
        }
        i++;
    }
    maxzeroC = max(maxzeroC,presentZero+startzeroC);
    return maxzeroC;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int len;
        cin >> len;
        string s;
        cin >> s;
        cout<<ans(s,len)<<endl;

    }
    return 0;
}