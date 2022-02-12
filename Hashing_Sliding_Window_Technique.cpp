#include <iostream>
using namespace std;
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

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

void getVerticalOrder(Node *root, int hdis, map<int, vi> &m)
{
    if (root == NULL)
    {
        return;
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis - 1, m);
    getVerticalOrder(root->right, hdis + 1, m);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, 0, n)
            cin >>
        a[i];
    int s = 0, ans = INT_MAX;
    rep(i, 0, k)
    {
        s += a[i];
    }
    ans = min(ans, s);
    rep(i, 1, n - k + 1)
    {
        s -= a[i - 1];
        s += a[i + k - 1];
        ans = min(ans, s);
    }
    cout << ans << endl;
    return 0;
}