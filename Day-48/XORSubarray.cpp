#include <iostream>
#include <vector>

using namespace std;

class Triesnode
{
public:
    Triesnode *next[2];
    Triesnode()
    {
        next[0] = NULL;
        next[1] = NULL;
    }
};

Triesnode *build(vector<int> &a)
{
    Triesnode *root = new Triesnode();
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        Triesnode *cur = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (cur->next[bit] == NULL)
                cur->next[bit] == new Triesnode();
            cur = cur->next[bit];
        }
    }
    return root;
}

int helper(Triesnode *root, vector<int> &a)
{
    int res = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int nums = a[i];
        Triesnode *it = root;
        int curr_max = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = ((nums >> i) & 1) ? 0 : 1;
            if (it->next[bit])
            {
                curr_max <<= 1;
                curr_max |= 1;
                it = it->next[bit];
            }
            else
            {
                curr_max <<= 1;
                curr_max |= 0;
                it = it->next[bit ^ 1];
            }
        }
        res = max(res, curr_max);
    }
    return res;
}

int main()
{
    vector<int> a = {3, 10, 5, 15, 2};
    Triesnode *root = build(a);
    int ans = helper(root, a);
    cout << ans << endl;
    return 0;
}