#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> yCord;
        vector<int> xCord;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            xCord.push_back(temp);
        }
        for (int i = 0; i < m; i++)
        {
            int temp;
            cin >> temp;
            yCord.push_back(temp);
        }


        cout << m+n << endl;
    }
}
