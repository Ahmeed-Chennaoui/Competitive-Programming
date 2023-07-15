#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef long long ll;
using namespace std;

class SegmentTree
{
    vector<pair<ll, ll>> tree;
    int size;

public:
    SegmentTree(vector<long long> &array)
    {
        size = 1;
        while (size < array.size())
            size *= 2;
        tree.resize(2 * size);
        buildTree(array, 1, 0, size - 1);
    }

private:
    void buildTree(vector<long long> &array, int treeIndex, int left, int right)
    {
        if (left == right)
        {
            if (left < array.size())
                tree[treeIndex] = {array[left], LLONG_MIN};
            return;
        }
        int mid = (left + right) / 2;
        buildTree(array, 2 * treeIndex, left, mid);
        buildTree(array, 2 * treeIndex + 1, mid + 1, right);
        vector<ll> m = {tree[treeIndex * 2].first, tree[treeIndex * 2].second,
                        tree[treeIndex * 2 + 1].first, tree[treeIndex * 2 + 1].second};
        sort(m.begin(), m.end());
        tree[treeIndex] = {m[2], m[3]};
    }
    void update(int treeIndex, int left, int right, int i, int v)
    {
        if (i < left || i > right)
            return;
        if (left == right)
        {
            tree[treeIndex] = {v, LLONG_MIN};
            return;
        }
        int mid = (left + right) / 2;
        update(treeIndex * 2, left, mid, i, v);
        update(treeIndex * 2 + 1, mid + 1, right, i, v);
        vector<ll> m = {tree[treeIndex * 2].first, tree[treeIndex * 2].second,
                        tree[treeIndex * 2 + 1].first, tree[treeIndex * 2 + 1].second};
        sort(m.begin(), m.end());
        tree[treeIndex] = {m[2], m[3]};
    }

    pair<ll, ll> query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if (queryLeft > right || queryRight < left)
            return {LLONG_MIN, LLONG_MIN};
        if (queryLeft <= left && right <= queryRight)
            return tree[treeIndex];
        int mid = (right + left) / 2;
        pair<ll, ll> q1 = query(2 * treeIndex, left, mid, queryLeft, queryRight);
        pair<ll, ll> q2 = query(2 * treeIndex + 1, mid + 1, right, queryLeft, queryRight);
        vector<ll> m = {q1.first, q1.second, q2.first, q2.second};
        sort(m.begin(), m.end());
        return {m[2], m[3]};
    }

public:
    void update(int i, int v)
    {
        update(1, 0, size - 1, i, v);
    }
    pair<ll, ll> query(int left, int right)
    {
        return query(1, 0, size - 1, left, right);
    }
};
int main()
{
    FastIO;
    ll n, temp, q;
    vector<long long> a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    SegmentTree tree(a);
    cin >> q;
    while (q--)
    {
        char c;
        int i, j;
        cin >> c >> i >> j;
        if (c == 'Q')
        {
            pair<ll, ll> res;
            res = tree.query(--i, --j);
            cout << res.first + res.second << endl;
        }
        if (c == 'U')
        {
            tree.update(--i, j);
        }
    }
    return 0;
}
