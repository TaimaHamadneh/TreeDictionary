# TreeDictionary
This data structure is a Tree where each node represents a character. Each path in the tree starting from the root and ending in one of the leaves represents a certain string. The leaves contain a special character ‘$’ which indicates the end of the string. The following figure is an example of this data structure.<br>

![tree](https://user-images.githubusercontent.com/98472054/235759866-232f42bd-c5f3-4a92-8fce-9c256fa3630c.PNG) <br>

Your task is to build this data structure by implementing the following operations: Insert (char *s). This operation inserts the string s in the tree.<br>

Delete (char *s). This operation deletes the string s from the tree.<br>
Search (char *s). This operation prints Yes or No based on whether the string s exists in the tree or not.<br>
StartsWith(char *s). This operation prints all strings that start with string s. Strings are sorted then printed.<br>
Longest(). This operation prints the longest string stored in the tree (assume there is only one such string).<br><br>

Input Format<br>

N (the number of commands, N is an integer)<br>
command 1<br>
command 2<br>
...<br>
command N<br>
<b>Constraints</b><br>

N is between 1 to 500

Output Format<br><br>

result of command 1<br>
result of command 2<br>
...<br>
result of command N<br><br>
Sample Input 0<br><br>

12<br>
insert Mall<br>
insert Me<br>
insert Mat<br>
insert Cat<br>
insert Rat<br>
insert Mandy<br>
delete Mandy<br>
startwith Ma<br>
search Cat<br>
search Me<br>
search Mandy<br>
longest<br><br>

Sample Output 0<br><br>
Mall<br>
Mat<br>
YES<br>
YES<br>
NO<br>
Mall<br>


