/*
Problem: Left View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Iterative BFS using queues

Approach:
- The left view of tree clearly shows the first element of every level .
- So , I just traversed the whole binary tree using queues and level wise by getting the size of each level .
- I pushed back the first element of every level in the array .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(w) where w is width of binary tree . In worst case , w = n .
*/

#include<vector>
#include<queue>
using namespace std ;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        
        vector<int> left_view ;
        if(root == nullptr) return left_view ;
        
        queue<Node*> level ;
        level.push(root) ;
        
        while(!level.empty()){
            int level_size = level.size() ;
            
            for(int i=0 ; i<level_size ; i++){
                
                Node *curr = level.front() ;
                if(i == 0){    // First element of the level
                    left_view.push_back(curr -> data) ;
                }
                
                if(curr -> left != nullptr) level.push(curr -> left) ;
                if(curr -> right != nullptr) level.push(curr -> right) ;
                
                level.pop() ;
            }
        }
        
        return left_view ;
    }
};