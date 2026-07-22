/*
Problem: Height of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- I have learnt the another defination of height such that it is the difference of highest and lowest levels .
- I tried to simulate the levels in recursion and updated the height as I reach to a lower level .
- Important observation :- This method will count nullptr as another level , so I am subtracting 1 from the calculated height .


Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

Mistakes I made :
- I missed that important observation point initially but figured it out later .
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

    void height_calc(Node* root , int &ht , int level){
        if(root == nullptr){
            ht = max(ht , level) ;
            return ;
        }

        height_calc(root -> left , ht , level+1 ) ;
        height_calc(root -> right , ht , level+1 ) ;
    }

    int height(Node* root) {
        int ht = 0 ;
        height_calc(root , ht , 0) ;
        return ht-1 ;
    }
};