#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define MOD 10e7 + 9

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
    string s;
    cin >> s;
    int cnt[26];
    fill_n(cnt, 26, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        int x = min(n / k, 26);
        char cp = 'a' + x;
        for (int j = 0; j < x; j++)
        {
            //  cout << "cnt[" << char('a' + j) << "] " << cnt[j] << "\n";
            cnt[j]--;
            if (cnt[j] <= -1)
            {
                cp = 'a' + j;
                break;
            }
        }
        ans += cp;
    }
    cout << ans << "\n";
}

int main()
{
    setup();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}