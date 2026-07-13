# Mistakes Log


## Binary Trees


### Mistake 1 : Increasing counter for nullptr 
Problem : Height of Binary Tree 
Mistake : I incremented the counter of number of nodes at nullptr also .
Fix : Subtracted that nullptr count while returning height .


### Mistake 2 : Wrong base case and integer overflow
Problem : Sum Root to Leaf Nodes

Mistake : 1. I took the base case as when root becomes null ptr which includes the leaf node twice and included the nodes who have a single child also .
2. Initialised a variable which can be overflowed as int .

Fix : 1. Changed the base case to when the leaf node is there which removed duplication and unnecessary addition .
2. Changed the variable to ling long .


## Mistake 3 : Constraint not read and edge case
Problem : Construct String from Binary Tree

Mistake : 1. I didnt read the constraints carefully and assume that value of each node is single digit and positive .
2 . Missed the edge case of pushing 0 value as string .

Fix : 1. Added conditions and accessing of each digit for multi digit and negative numbers .
2 . Added extra condition when value is 0 . 