/*
Problem: ZigZag Traversal
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1
Difficulty: Medium
Topic: Binary Tree
Pattern: BFS using deque

Approach:
- I thought of doing the BFS in both the direction and it could be possible by double ended deque ie deque .
- I managed to shift from left to right and right to left by a boolean .
- For left to right --> first added left and then right child so it can be accessed easily from back in reverse order .
- For right to left --> first added right and then left child so it can be accessed easily from front in reverse order .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .
*/

#include<vector>
#include<deque>
using namespace std ;

/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/


class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        
        vector<int> ans ;
        deque<Node*> dq ;
        dq.push_back(root) ;
        
        bool left_to_right = 1 ;
        
        while(!dq.empty()){
            
            int level_size = dq.size() ;
            
            if(left_to_right == 1){
                
                while(level_size--){
                    
                    Node *curr = dq.front() ;
                    
                    if(curr -> left != nullptr) dq.push_back(curr -> left) ;
                    if(curr -> right != nullptr) dq.push_back(curr -> right) ;
                    
                    ans.push_back(curr -> data) ;
                    dq.pop_front() ;
                }
                
                left_to_right = 0 ;
            }
            
            else{
                
                while(level_size--){
                    
                    Node *curr = dq.back() ;
                    
                    if(curr -> right != nullptr) dq.push_front(curr -> right) ;
                    if(curr -> left != nullptr) dq.push_front(curr -> left) ;
                    
                    ans.push_back(curr -> data) ;
                    dq.pop_back() ; 
                }
                
                left_to_right = 1 ;
            }
        }
        
        return ans ;
    }
};