#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Node
{
    char val;
    Node* child[256];
    Node* parent;
};

class Tree {
public:
    Node* root;
    
    //Constructor for a tree data structure
    Tree() {
        root = new Node();
        root->parent = NULL;
        root->val = '*';
        Node* curr = root;
    }
    
    //Insert function that inserts a string into a tree data structure.
    void insert(string s){
        Node* curr = root;
        
        for (int i = 0; i < s.length(); i++) {
            if (curr->child[s[i]] == NULL) {
                curr->child[s[i]] = new Node();
                curr->child[s[i]]->val = s[i];
                curr->child[s[i]]->parent = curr;
            }
            curr = curr->child[s[i]];
        }
        curr->child['$'] = new Node();
        curr->child['$']->val = '$';
        curr->child['$']->parent = curr;
    }
    
    //Search function that prints Yes or No based on whether the string s exists in the tree or not.
    void search(string s){
        Node* curr = root;
        if (curr == nullptr) {
            cout << "NO\n";
            return;
        }
        for (int i = 0; i < s.length(); i++){
            if (curr->child[s[i]] == NULL){
                cout << "NO\n";
                return;
            }
            curr = curr->child[s[i]];
        }
        if (curr->child['$'] != NULL) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
    
    }
    
    //Delete function that deletes the string s from the tree.
    void delet(string s){
        Node* curr = root;
        
        if (curr == nullptr) {
            return;
        }
        for (int i = 0; i < s.length(); i++){
            if (curr->child[s[i]] == NULL){
                return;
            }
            curr = curr->child[s[i]];
        }
        curr->child['$'] = NULL;

        while (curr != root) {
            curr = curr->parent;
        }
    }
    
    //Startwith function that prints all strings that start with string s.
    void startwith(string s){
        Node* curr = root;
        if (curr == nullptr) {
            return;
        }
        for (int i = 0; i < s.length(); i++){
            if (curr->child[s[i]] == NULL){
                return;
            }
            curr = curr->child[s[i]];
        }
        recursiveFun(curr, s);//re
    }
    
    void recursiveFun(Node* curr, string s1) {//re
        if (curr->child['$'] != NULL) {
            cout << s1 << "\n";
        }
        for (int i = 0; i < 256; i++) {
            if (curr->child[i] != NULL) {
                recursiveFun(curr->child[i], s1 + curr->child[i]->val);
            }
        }
    }
    
    //Longest function that prints the longest string stored in the tree.
    void longest(Node* node, string current, string& longestS){
        current += node->val;
        if (current.length() > longestS.length()){
            longestS = current;
        }
        for (int i = 0; i < 256; i++){
            if (node->child[i] != NULL){
                longest(node->child[i], current, longestS);
            }
        }
   }

};


int main()
{
    //Tree Object
    Tree* objTree = new Tree();
    //Read int value, which is num of the input
    int number;
    cin >> number;
    number++;
    
    //Vector of string
    vector<string> child(number);
    // Read in each command and store it in the vector.
    for (int i = 0; i < number; i++) {
        getline(cin, child[i]);
    }
    // Process each command to complete users ask.
    for (int i = 1; i < number; i++) {
        stringstream s3(child[i]);
        string cmd, word;
        s3 >> cmd >> word;
        if (cmd == "insert") {
            objTree->insert(word);
        }
        else if (cmd == "startwith") {
            objTree->startwith(word);
        }
        else if (cmd == "search") {
            objTree->search(word);
        }
        else if (cmd == "delete") {
            objTree->delet(word);
        }
        else if (cmd == "longest") {
            string longestString;
            objTree->longest(objTree->root, "", longestString);
            for (int i = 0; i < longestString.size(); i++) {
                if (longestString[i] != '*' && longestString[i] != '$') {
                    cout << longestString[i];
                }
                if (longestString[i] == '$')
                    break;
            }
        }
    }
    return 0;
}
