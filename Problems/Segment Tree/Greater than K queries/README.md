# K-Query

  

## Problem Statement
Given a sequence of n numbers a~1~, a~2~, ..., a~n~.
 For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence a~i~, a~i+1~, ... , a~j~.

### [Problem Link](https://www.spoj.com/problems/KQUERY/)

## Proposed Solution
###### This solution requires prior knowledge of segment trees

We create a segment tree where each leaf node i contains an array of length 1 containing a~i~ .
Each parent node contains the sorted result of merging the two child arrays.
 
For each range of length 2^n^ we can find the number of elements greater than k by performing binary search to find the index of the first element greater than k, then substracting that index from the length of the array.

By summing the results from the all the 2^n^ ranges that intersect the the query we find the final result .
