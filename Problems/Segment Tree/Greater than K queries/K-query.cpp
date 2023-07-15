#include <bits/stdc++.h>
#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

typedef long long ll;
using namespace std;

class SegmentTree
{
    vector<vector<ll>> tree;
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
    void printTree()
    {
        for (int i = 0; i < 2 * size; i++)
        {
            cout << i << " : ";
            for (int j = 0; j < tree[i].size(); j++)
                cout << tree[i][j] << " ";
            cout << endl;
        }
    }

private:
    void buildTree(vector<long long> &array, int treeIndex, int left, int right)
    {
        if (left == right)
        {
            if (left < array.size())
                tree[treeIndex].push_back(array[left]);
            return;
        }
        int mid = (left + right) / 2;
        buildTree(array, 2 * treeIndex, left, mid);
        buildTree(array, 2 * treeIndex + 1, mid + 1, right);
        tree[treeIndex].resize(tree[treeIndex * 2].size() + tree[treeIndex * 2 + 1].size());
        int i = 0, j = 0, k = 0;
        while (j < tree[treeIndex * 2].size() && k < tree[treeIndex * 2 + 1].size())
        {
            if (tree[treeIndex * 2][j] < tree[treeIndex * 2 + 1][k])
            {
                tree[treeIndex][i] = tree[treeIndex * 2][j];
                j++, i++;
            }
            else
            {

                tree[treeIndex][i] = tree[treeIndex * 2 + 1][k];
                k++, i++;
            }
        }
        while (j < tree[treeIndex * 2].size())
        {
            tree[treeIndex][i] = tree[treeIndex * 2][j];
            ++j, ++i;
        }
        while (k < tree[treeIndex * 2 + 1].size())
        {
            tree[treeIndex][i] = tree[treeIndex * 2 + 1][k];
            ++k, ++i;
        }
    }

    long long query(int treeIndex, int left, int right, int queryLeft, int queryRight, int v)
    {
        if (queryLeft > right || queryRight < left)
            return 0;
        if (queryLeft <= left && right <= queryRight)
            return tree[treeIndex].end() -
                   upper_bound(tree[treeIndex].begin(), tree[treeIndex].end(), v);
        int mid = (right + left) / 2;
        long long q1 = query(2 * treeIndex, left, mid, queryLeft, queryRight, v);
        long long q2 = query(2 * treeIndex + 1, mid + 1, right, queryLeft, queryRight, v);
        return q1 + q2;
    }

public:
    long long query(int left, int right, int v)
    {
        return query(1, 0, size - 1, left, right, v);
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
        int i, j, k;
        cin >> i >> j >> k;
        cout << tree.query(i - 1, j - 1, k) << endl;
    }
    return 0;
}
