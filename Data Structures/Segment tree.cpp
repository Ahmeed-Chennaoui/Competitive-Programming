#include <bits/stdc++.h>

using namespace std;

class SegmentTree
{
    vector<long long> tree;
    int size;
    int neutral_element = 0;

public:
    SegmentTree(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        tree.assign(size * 2, neutral_element);
    }
    SegmentTree(vector<long long> &array)
    {
        size = 1;
        while (size < array.size())
            size *= 2;
        tree.assign(2 * size, neutral_element);
        buildTree(array, 1, 0, size - 1);
    }

private:
    long long merge(int a, int b)
    {
        return a + b;
    }
    void buildTree(vector<long long> &array, int treeIndex, int left, int right)
    {
        if (left == right)
        {
            tree[treeIndex] = array[left];
            return;
        }
        int mid = (left + right) / 2;
        buildTree(array, 2 * treeIndex, left, mid);
        buildTree(array, 2 * treeIndex + 1, mid + 1, right);
        tree[treeIndex] = merge(tree[2 * treeIndex], tree[2 * treeIndex + 1]);
    }
    void update(int treeIndex, int left, int right, int i, int v)
    {
        if (i > right || i < left)
            return;
        if (left == right)
        {
            tree[treeIndex] += v;
            return;
        }
        int mid = (right + left) / 2;
        update(2 * treeIndex, left, mid, i, v);
        update(2 * treeIndex + 1, mid + 1, right, i, v);

        tree[treeIndex] = merge(tree[treeIndex * 2], tree[treeIndex * 2 + 1]);
    }

    long long query(int treeIndex, int left, int right, int queryLeft, int queryRight)
    {
        if (queryLeft <= left && right <= queryRight)
            return tree[treeIndex];
        if (queryLeft > right || queryRight < left)
            return neutral_element;
        int mid = (right + left) / 2;
        long long q1 = query(2 * treeIndex, left, mid, queryLeft, queryRight);
        long long q2 = query(2 * treeIndex + 1, mid + 1, right, queryLeft, queryRight);
        return merge(q1, q2);
    }

public:
    void update(int i, int v)
    {
        update(1, 0, size - 1, i, v);
    }
    long long query(int left, int right)
    {
        return query(1, 0, size - 1, left, right);
    }
};

int main()
{

    return 0;
}