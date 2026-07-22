// Cousins -->  Two nodes are cousins if they are at the same depth but have different parents.

/*
Problem: Check if Two Nodes are Cousins
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1
Difficulty: Medium
Topic: Binary Tree
Pattern: BFS with conditions

Approach:
- The key concept is that both the nodes will be on same level but will not have same parent .
- So , traversed level wise level ensuring that a and b are not child of same parents , if happens return 0 .
- If we get a and b both in one level now --> cousin confirmed . So, I used a flag that increments each time we find any of a or b .
- If , at the end of the level flag == 2 --> cousin confirmed . Else if values are not in binary tree or not on the same level --> return 0 .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .
*/

#include<queue>
using namespace std ;

/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    bool areCousins(Node* root, int a, int b) {
        
        queue<Node*> q ;
        q.push(root) ;
        
        while(!q.empty()){
            
            int level_size = q.size() ;
            int flag = 0 ;
            
            for(int i=0 ; i<level_size ; i++){
                
                Node *curr = q.front() ;
                int l = -1 , r = -1 ;
                
                if(curr -> left != nullptr){
                    q.push(curr -> left) ;
                    l = curr -> left -> data ;
                }
                
                if(curr -> right != nullptr){
                    q.push(curr -> right) ;
                    r = curr -> right -> data ;
                }
                
                if((l == a && r == b) || (l == b && r == a)) return 0 ;
                if(l == a || l == b || r == a || r == b) flag += 1 ;
                
                q.pop() ;
            }
            
            if( flag == 2 ) return 1 ;
        }
        
        return 0 ;
    }
};