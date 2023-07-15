# Maximum Sum

  

## Problem Statement
Given a sequence of n numbers a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>.
There are 2 types of operations :
##### update ('U', i , x ):
This operation sets the value of a<sub>i</sub> to x.
##### query ('Q', x , y ):
You must find i and j such that x ≤ i, j ≤ y and i != j, such that the sum a<sub>i</sub>+a<sub>j</sub> is maximized. Print the sum a<sub>i</sub>+a<sub>j</sub>.


### [Problem Link](https://www.spoj.com/problems/KGSS/)

## Proposed Solution
###### This solution requires prior knowledge of segment trees

We create a segment tree where each leaf node i contains a pair of integers a and -∞.
Each parent node contains the maximum and the second maximum of all the elements beneath it.

By find the maximum and second maximum from the all the 2<sup>n</sup> ranges that intersect the the query, we can sum those 2 values for the result.
