/*
Problem: Height of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- The depth or height of binary tree is defined as number of edges between the the 0th and last level .
- This means the height can be either in the left or right subtree and it will include one node itself , this exists for every node .
- The base case will be when root becomes null and it return -1 because it counts the number of nodes instead of edges .
- n nodes --> n-1 edges 


Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

*/

#include<algorithm>
using namespace std ;
/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        
        if(root == nullptr) return -1 ;
        return 1 + max(height(root-> left) , height(root-> right)) ;
    }
};