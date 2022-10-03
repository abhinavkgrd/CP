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

#define MOD 10e7 + 9
#define MAX_SIZE 1000001

class DSU
{
    int parent[MAX_SIZE];
    int size[MAX_SIZE];

public:
    DSU()
    {
        REP(i, 0, MAX_SIZE)
        {
            parent[i] = i;
        }
        fill_n(size, MAX_SIZE, 1);
    }

public:
    int find_set(int v)
    {
        if (parent[v] == v)
        {
            return parent[v];
        }
        else
        {
            return parent[v] = find_set(parent[v]);
        }
    }

public:
    void union_set(int u, int v)
    {
        int pu = find_set(u);
        int pv = find_set(v);
        if (size[pu] < size[pv])
        {
            swap(pu, pv);
        }
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

int main()
{
    DSU friendsGroups;
    REP(i, 0, 30)
    {
        int p1 = 0;
        int p2 = 0;
        while (p1 == p2)
        {
            p1 = rand() * 1.0 / RAND_MAX * 50;
            p2 = rand() * 1.0 / RAND_MAX * 50;
        }
        cout << "parent " << p1 << " " << friendsGroups.find_set(p1) << "\n";
        cout << "parent " << p2 << " " << friendsGroups.find_set(p2) << "\n";
        friendsGroups.union_set(p1, p2);
        cout << "parent " << p1 << " " << friendsGroups.find_set(p1) << "\n";
        cout << "parent " << p2 << " " << friendsGroups.find_set(p2) << "\n";
    }
    REP(i, 0, 30)
    {

        int p1 = 0;
        int p2 = 0;
        while (p1 == p2)
        {
            p1 = rand() * 1.0 / RAND_MAX * 50;
            p2 = rand() * 1.0 / RAND_MAX * 50;
        }
        cout << "parent " << p1 << " " << friendsGroups.find_set(p1) << " parent " << p2 << " " << friendsGroups.find_set(p2) << "\n";
        string areFriends = friendsGroups.find_set(p1) != -1 && friendsGroups.find_set(p2) != -1 && friendsGroups.find_set(p1) == friendsGroups.find_set(p2) ? "yes" : "no";
        cout << "are " << p1 << " and " << p2 << " friends? => " << areFriends << "\n";
    }
}