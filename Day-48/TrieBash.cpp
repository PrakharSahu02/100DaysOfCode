#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int size = 32;

class node
{
public:
    node *next[2];
    node()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

node *tries;

void insert(int num)
{
    node *it = tries;
    for (int i = size - 1; i >= 0; i--)
    {
        int bit = num >> i & 1;
        if (!it->next[bit])
        {
            it->next[bit] = new node();
        }
        it = it->next[bit];
    }
}

int query(int num)
{
    node *it = tries;
    int ans = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        int bit = num >> i & 1;
        int opposite = bit ^ 1;
        if (it->next[opposite])
        {
            it = it->next[opposite];
            ans |= 1 << i;
        }
        else
        {
            it = it->next[opposite ^ 1];
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
    {
        cin >> i;
    }
    tries = new node();
    insert(0);
    vector<int> rmax(n + 1, 0);
    int r = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        r = r ^ a[i];
        if (i != n - 1)
        {
            rmax[i] = max(rmax[i + 1], query(r));
        }
        else
        {
            rmax[i] = query(r);
            insert(r);
        }
    }
    free(tries);

    tries = new node();
    int l = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        l = l ^ a[i];
        ans = max(ans, rmax[i + 1] + query(l));
        insert(l);
    }
    cout << ans << endl;
    return 0;
}