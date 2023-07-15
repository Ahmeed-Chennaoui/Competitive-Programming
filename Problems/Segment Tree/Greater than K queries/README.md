# K-Query

  

## Problem Statement
Given a sequence of n numbers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>.
 For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence a<sub>i</sub>, a<sub>i+1</sub>, ... , a<sub>j</sub>.

### [Problem Link](https://www.spoj.com/problems/KQUERY/)

## Proposed Solution
###### This solution requires prior knowledge of segment trees

We create a segment tree where each leaf node i contains an array of length 1 containing a~i~ .
Each parent node contains the sorted result of merging the two child arrays.
 
For each range of length 2<sup>n</sup> we can find the number of elements greater than k by performing binary search to find the index of the first element greater than k, then subtracting that index from the length of the array.

By summing the results from the all the 2<sup>n</sup> ranges that intersect the the query we find the final result .
