#include <iostream>
#include <vector>

using namespace std;

class Tries
{
public:
    class node
    {
    public:
        bool end;
        node *next[26];
        node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    node *tries;
    Tries()
    {
        tries = new node();
    }

    void insert(string word)
    {
        int i = 0;
        node *it = tries;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                it->next[word[i] - 'a'] = new node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    bool search(string word)
    {
        int i = 0;
        node *it = tries;
        while (i < word.size())
        {
            if (it->next[word[i] - 'a'] == NULL)
            {
                return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }
};

int main()
{
    Tries *mytries = new Tries();
    vector<string> word = {"aaaa", "bbbb", "cccc"};
    for (auto w : word)
    {
        mytries->insert(w);
    }
    if (mytries->search("dddd"))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}