#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i, a, b) for (int i = a; i < b; i++)

ll MOD = 10e7 + 9;

void setupFileIO()
{
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}
void setup()
{
    // setupFileIO();
    ios::sync_with_stdio(0);
    cin.tie(0);
}

void solve()
{
    // solution goes here
    int n, k;
    cin >> n >> k;
    string a[n];
    set<string> aSet;
    REP(i, 0, n)
    {
        a[i] = "";
        REP(j, 0, k)
        {
            char c;
            cin >> c;
            a[i] += c;
            aSet.insert(a[i]);
        }
    }

    map<string, int> cnt;
    REP(i, 0, n)
    {
        set<string> bSet;
        bSet.insert(aSet.begin(), aSet.end());
        REP(j, 0, n)
        {
            if (bSet.find(a[j]) == bSet.end())
            {
                continue;
            }
            bSet.erase(a[j]);
            string b = "";
            REP(kx, 0, k)
            {
                if (a[i][kx] == a[j][kx])
                {
                    b += a[i][kx];
                }
                else if ((a[i][kx] == '1' && a[j][kx] == '2') || (a[i][kx] == '2' && a[j][kx] == '1'))
                {
                    b += '0';
                }
                else if ((a[i][kx] == '0' && a[j][kx] == '2') || (a[i][kx] == '2' && a[j][kx] == '0'))
                {
                    b += '1';
                }
                else
                {
                    b += '2';
                }
            }
            if (bSet.find(b) != bSet.end())
            {
                // cout << a[i] << " " << a[j] << " " << b << "\n";
                bSet.erase(b);
                cnt[a[i]]++;
            }
        }
    }
    ll ans = 0;
    for (auto x : cnt)
    {
        // cout << x.F << " " << x.S << "\n";
        if (x.S >= 2)
        {
            ans += x.S * (x.S - 1) / 2;
        }
    }
    cout << ans << "\n";
}

int main()
{

    setup();

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }
}