/*
Problem: Level-Order Traversal
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1
Difficulty: Medium
Topic: Binary Tree
Pattern: Breadth First Search (BFS)

Approach:
- In level order traversal , my first approach was that for accessing nth level node , I require (n-1)th level nodes .
- So , A Queue was the most suitable data structure as I can access the nodes in FIFO order and push its children to the back .
- The children of node is pushed only if it exists , and the ending point is when current level has zero nodes .

Time Complexity: O(n)
Space Complexity: O(w) where w is the width of the Binary Tree . In worst case : w = n

Mistakes I made :
- Forgot to push the root in the queue outside loop .
- The base case when root is nullptr must be taken care of . (Not required in gfg)
*/

/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/


#include<vector>
#include<queue>
using namespace std ;

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        
        queue<Node*> q ;
        vector<int> ans ;
        if(root == nullptr) return ans ;

        q.push(root) ;
        
        while(!q.empty()){
            
            Node * temp = q.front() ;
            ans.push_back(temp-> data) ;
            
            if(temp-> left != nullptr){
                q.push(temp -> left) ;
            }
            
            if(temp-> right != nullptr){
                q.push(temp -> right) ;
            }
            
            q.pop() ;
        }
        
        return ans ;
    }
};