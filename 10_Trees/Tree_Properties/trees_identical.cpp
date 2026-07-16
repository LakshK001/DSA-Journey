/*
Problem: Identical Trees
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- If we do pre order traversal for both the binary trees simultaneously , they will traverse in same order .
- The only cases that exist for non identical trees are that value of corresponding nodes not equal or a particular node either r1 or r2 does not exist .
- So , return 0 for these cases and if both the r1 and r2 are null , this implies end of the branch , return 1  --> Base Case .


Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

*/


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    bool compare(Node* r1 , Node* r2){
        if(r1 == nullptr && r2 == nullptr) return 1 ;
        if(r1 == nullptr || r2 == nullptr) return 0 ;
        
        if(r1 -> data != r2 -> data) return 0 ;
        
        return compare(r1-> left , r2 -> left ) && compare(r1 -> right , r2 -> right) ;
    }
    
    bool isIdentical(Node* r1, Node* r2) {
        
        return compare(r1 , r2);
    }
};