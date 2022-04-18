#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

struct Node
{
    int key;
    Node *left, *right;
};

Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void getVerticalOrder(Node *root, int hdist, map<int, vi> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hdist].push_back(root->key);
    getVerticalOrder(root->left, hdist - 1, m);
    getVerticalOrder(root->right, hdist + 1, m);
}

signed main()
{
    Node *root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(4);
    root->left->left = newNode(3);
    root->left->right = newNode(11);
    root->right->left = newNode(14);
    root->right->right = newNode(6);
    map<int, vector<int>> m;
    int hdist = 0;
    getVerticalOrder(root, hdist, m);
    map<int, vi>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        for (int i = 0; i < (it->ss).size(); i++)
        {
            cout << (it->ss)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}