#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m ;
    string s,t;
    cin >> s >> t;
    cin >> q;
    vector<string> words(q);
    for(auto &x: words) cin >> x;

    set<char> takah;
    set<char> aoki;
    for(auto x:s){
        takah.insert(x);
    }
    for(auto x:t){
        aoki.insert(x);
    }

    for(auto x:words){
        int lang1 = 0;
        int lang2 = 0;
        for(auto y:x){
            if(takah.find(y) != takah.end()) lang1++;
            if(aoki.find(y) != aoki.end()) lang2++;
        }
        if((lang1) == x.size() && lang2<x.size()) cout << "Takahashi" << endl;
        else if((lang2) == x.size() && lang1 < x.size()) cout << "Aoki" << endl;
        else cout << "Unknown" << endl;
    }

}