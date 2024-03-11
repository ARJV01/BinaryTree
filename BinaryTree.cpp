#include<iostream>
#include<cctype>
#include<iomanip>
#include<cstring>

using namespace std;

class Node {//node class for binary tree
public:
  int value;
  Node* right;
  Node* left;
  Node* next;

  Node(int newValue) {//constructor
    left = NULL;
    right = NULL;
    next = NULL;
    value = newValue;
  }
  int getV() {//returns value
    return value;
  }
  Node* getR() {//returns right
    return right;
  }
  void setR(Node* newRight) {//sets right
    right = newRight;
  }
  Node* getL() {//returns left
    return left;
  }
  void setN(Node* newNext) {//sets next
    next = newNext;
  }
  Node* getN() {//returns next
    return next;
  }
  void setL(Node* newLeft) {//sets left
    left = newLeft;
  }
  ~Node() {}//destructor
};

void print(Node* root,int level);
void arrayNuller(int (&ary)[],int size);
void add(int (&ary)[],int &size, Node* &root);
void sort(int ary[],int counter,Node* &root);


int main() {
  int ary[80];
  char input[20];
  bool stillR = true;
  Node* root = NULL;
  int counter =0;
  arrayNuller(ary , 80);
  while(stillR == true) {
    cout << "enter add print or quit" << endl;
    cin >> input;
    cin.ignore(256, '\n');
      if (strcmp(input, "add") == 0) {
	add(ary, counter,root);
      }
      if (strcmp(input, "print") == 0) {
        print(root,0);
      }
      if (strcmp(input, "quit") == 0) {
	stillR = false;
      }
  }
  
  return 0;
}

void arrayNuller(int (&ary)[], int size) {//Makes all elemnts in an array NULL
  for(int i = 0; i < size; i++) {
    ary[i] = '\0';
  }
}

void add(int (&ary)[], int &counter,Node* &root) { // Will add inputs from the line
  cout << "enter how many numbers you wish to input up too 100 " << endl;
  int inputL = 0;
  int i = 0;
  cin >> inputL;
  int input = 0;
  cout << "enter your numbers" << endl;
  while(i < inputL) {
    cin >> input;
    cin.ignore(256, '\n');
    ary[counter] = input;
    sort(ary,counter,root);
    counter++;
    i++;
  }
}

void sort(int ary[],int counter,Node* &root) {
  if(root == NULL) {//when there is nothing in the tree
    root = new Node(ary[counter]);
    return;
  }
  else {// if the root is not null
    Node* current = root;
    Node* parent = NULL;
    bool right = NULL;
    while(current != NULL) {//iterate down the left or right sub trees
      parent = current;
      if(current->getV() < ary[counter]) {//left subtree
	current = current ->getL();
	right = false;
      }
      else if(current->getV() > ary[counter]) {//right subtree
	current = current -> getR();
	right = true;
      }

  }
    if(right == true) {//set new right node
      parent ->setR(new Node(ary[counter]));
    }
    else if(right != false) {//set new left node
      parent -> setL(new Node(ary[counter]));
    }
  }
}

void print(Node* root,int level) {//will print the tree
  if (!root) {
    return;
  }
  print(root->getR(), level++);

  for(int i = 0; i < level; i++) {
    cout << "\t";
  }
  cout << root->getV() << endl;
  print(root->getL(), level++);
}
