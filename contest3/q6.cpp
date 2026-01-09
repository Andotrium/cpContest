#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> ans(vector<vector<int>> a,int maxLen){
vector<int> answer;
int aLen = 0;
while(aLen != maxLen){
sort(a.begin(),a.end());
answer.insert(answer.end(),a[0].begin(),a[0].end());
aLen += a[0].size();
auto it = a.begin();
while(it != a.end()){
if(it->size() <= aLen){
a.erase(it);
}
else {it++;}
}

for(int i=0;i<a.size();i++){
fill(a[i].begin(),a[i].begin()+aLen-1,0);
}

}
return answer;
}





int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int maxLen = 0;

    // Read all arrays and find max length
    for(int i = 0; i < n; i++) {
        int len;
        cin >> len;
        maxLen = max(maxLen, len);
        a[i].resize(len);
        for(int j = 0; j < len; j++) {
            cin >> a[i][j];
        }
    }
cout << "ans:"<<endl;
vector<int> answer = ans(a,maxLen);
for(int x:answer){cout << x << " ";}
cout << endl;
    }

}
