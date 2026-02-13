#include <iostream>
#include <vector>
#include <string>
#define ll long long
using namespace std;


/*
just a stupid question, the only important thing to learn here is that 
the number of of queries can be really large, and don't do the grouping of states for every query
do it only once and then use that grouping for all the queries
learning:
-> read the limits carefully, and understand what they mean while running the problem
*/

ll answer(string&s, vector<pair<char,ll>>& a,ll num){
    if(a.size() == 1 && a[0].first == 'A' ) return num;
    ll aSize = a.size();
    ll index = 0;
    ll time = 0;
    while(num>0){
        if(a[index%aSize].first == 'A'){
            num -= a[index%aSize].second;
            time += a[index%aSize].second;
        }
        else{
            ll temp = a[index%aSize].second;
            while(num && temp){
                num >>=1;
                time ++ ;
                temp -- ;
            }
        }
        index ++ ;
    }
    return time - abs(num);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        string s;
        cin >> s;

        vector<pair<char,ll>> arr;
        ll tempCounter;
        for(int i=0;i<n;){
            if(s[i] == 'A'){
                while(i<n && s[i] == 'A'){
                    i++;
                    tempCounter ++;
                }
                arr.push_back({'A',tempCounter});
                tempCounter = 0;
            }
            else{
                while(i<n && s[i] == 'B'){
                    i++;
                    tempCounter ++;
                }
                arr.push_back({'B',tempCounter});
                tempCounter = 0;
            }
        }
        while(q--){
            ll num;
            cin >> num;
            cout << answer(s,arr,num) << endl;
        }
    }
}