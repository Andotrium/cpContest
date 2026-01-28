#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> swords(n);
        vector<ll> b(n);
        for (auto &x : swords)
            cin >> x;
        for (auto &x : b)
            cin >> x;

        sort(swords.begin(), swords.end());
        ll bIndex = 0;
        ll numSwords = n;
        vector<ll> tempB;
        while (bIndex < n && numSwords > 0)
        {
            if (numSwords >= b[bIndex])
            {
                numSwords -= b[bIndex];
                tempB.push_back(0);
                bIndex++;
            }
            else
            {
                tempB.push_back(b[bIndex] - numSwords);
                numSwords = 0;
            }
        }
        // cout << "b index: " << bIndex << endl;
        vector<ll> levelsForX;
        if (bIndex == n)
        {
            levelsForX.push_back(bIndex);
            bIndex--;
        }
        // for(int i=n-1;i>=0;i--){
        //     if(bIndex >= 0 && tempB[bIndex] == b[bIndex]) bIndex -- ;
        //     tempB[bIndex] ++ ;
        //     levelsForX.push_back(bIndex);
        // }
        for (int i = n - 1; i >= 0; i--)
        {
            if (bIndex < 0)
            {
                levelsForX.push_back(0);
                continue;
            }

            if (tempB[bIndex] == b[bIndex])
                bIndex--;

            if (bIndex >= 0)
                tempB[bIndex]++;

            levelsForX.push_back(max(0LL, bIndex));
        }

if (!levelsForX.empty() && levelsForX[0] == n) levelsForX.pop_back();

        // cout << "levels for x array : ";
        // for(auto x:levelsForX) cout << x << " " ;
        for (int i = 0; i < n; i++)
        {
            levelsForX[i] *= swords[i];
        }
        auto maxscore = *(max_element(levelsForX.begin(), levelsForX.end()));
        cout << maxscore << endl;
    }
}