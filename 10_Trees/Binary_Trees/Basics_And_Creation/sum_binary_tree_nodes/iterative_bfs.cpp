/*
Problem: Sum Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Iterative Depth First Search (BFS)

Approach:
- I just knew that the breadth first search iterates over all the nodes once .
- So , just initialised a variable from 0 and incremented by data of each node in each traversal .

Time Complexity: O(n)
Space Complexity: O(w) where w is the width of the Binary Tree . In worst case : w = n

*/


#include<queue>
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
    int sumBT(Node* root) {

        queue<Node*> q ;
        q.push(root) ;
        int ans = 0 ;
        
        while(!q.empty()){
            
            Node *curr = q.front() ;
            ans += curr -> data ;
            
            if(curr -> left != nullptr) q.push(curr -> left) ;
            if(curr -> right != nullptr) q.push(curr -> right) ;
            
            q.pop() ;
        }
        
        return ans ;
    }
};