#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void getOrder(Node *root, int hd, map<int, vector<int>> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hd].push_back(root->data);
    getOrder(root->left, hd - 1, m);
    getOrder(root->right, hd + 1, m);
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(7);
    map<int, vector<int>> m;
    int hd = 0;
    getOrder(root, hd, m);

    map<int, vector<int>>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << "";
        }
        cout << endl;
    }
    return 0;
}