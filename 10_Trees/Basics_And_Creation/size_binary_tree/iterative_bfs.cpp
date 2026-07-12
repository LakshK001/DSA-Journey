/*
Problem: Size Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/size-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Iterative Depth First Search (BFS)

Approach:
- I just knew that the breadth first search iterates over all the nodes once .
- So , just added count initialised from 0 and incremented by 1 in each node traversal .

Time Complexity: O(n)
Space Complexity: O(w) where w is the width of the Binary Tree . In worst case : w = n

*/



/*
Definition for Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

#include<queue>
using namespace std ;

class Solution {
  public:
    int getSize(Node* root) {
        
        int count = 0 ;
        queue<Node*> q ;
        q.push(root) ;
        
        while (!q.empty()){
            
            Node *curr = q.front() ;
            count++ ;
            
            if(curr-> left != nullptr) q.push(curr -> left) ;
            if(curr-> right != nullptr) q.push(curr -> right) ;
            
            q.pop() ;
            
        }
        
        return count ;
    }
};