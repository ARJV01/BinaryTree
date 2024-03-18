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
  void setV(int newV) {
    value = newV;
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

int findC (Node* parent, int value);
void print(Node* root,int level);
void arrayNuller(int (&ary)[],int size);
void add(int (&ary)[],int &size, Node* &root);
void sort(int ary[],int counter,Node* &root);
void find(Node* root,int value);
Node* findR(Node* root,int value);
void remove(Node* &n, Node* current,Node* parent,Node* root); 

int main() {
  int ary[80];
  char input[20];
  bool stillR = true;
  Node* root = NULL;
  int counter =0;
  arrayNuller(ary , 80);
  while(stillR == true) {
    cout << "enter add remove print find or quit" << endl;
    cin >> input;
    cin.ignore(256, '\n');
      if (strcmp(input, "add") == 0) {
	add(ary, counter,root);
      }
      if (strcmp(input, "print") == 0) {
        print(root,0);
      }
      if (strcmp(input, "remove") == 0) {
	  cout <<"Please enter the value you wish to remove " << endl;
	  int findI = 0;
	  Node* temp = root;
	  cin >> findI;
	  Node* n = findR(temp,findI);
	  remove(n,root,NULL,root);
      }
      if (strcmp(input, "find") == 0) {
	int value = 0;
	cout << "please enter in a number" << endl;
	cin >> value;
	find(root,value);
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
  while(i < inputL) {
    cout << "enter a number " << endl;
    cin >> input;
    cin.ignore(256, '\n');
    ary[counter] = input;
    sort(ary,counter,root);
    counter++;
    i++;
  }
}

void sort(int ary[],int counter,Node* &root) {//sorts the values from add
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
      if(current->getV() > ary[counter]) {//left subtree
	current = current ->getL();
	right = false;
      }
      else if(current->getV() < ary[counter]) {//right subtree
	current = current -> getR();
	right = true;
      }

  }
    if(right == true) {//set new right node
      parent ->setR(new Node(ary[counter]));
    }
    else if(right == false) {//set new left node
      parent -> setL(new Node(ary[counter]));
    }
  }
}

void print(Node* root,int level) {//will print the tree
  if (!root) {//if nothing in tree or nothing left to print
    return;
  }
  print(root->getR(), level + 1);//prints out the left subtree

  for(int i = 0; i < level; i++) {
    cout << "\t";
  }
  cout << root->getV() << endl;//prints the current value
  print(root->getL(), level + 1);//prints the left subtree
}

void find(Node* root,int value) {//will find values
  if (!root) {
    return;
  }

  if(root -> getV() == value) {
    cout << "The given value is in the tree" << endl;
    return;
  }
  find(root->getR(), value);//searches the left subtree
  find(root->getL(), value);//searches the left subtree
}

void remove(Node* &n,Node* current,Node* parent,Node* root) {  
  if (n == NULL) {//if n is null
    return;
  }

  if (n->getL() == NULL && n->getR() == NULL) { //no children
    if (parent != NULL) {//if there is a parent
      if (parent->getL() == n) {//if n is left
	      parent->setL(NULL);//set parent left to null
      }
      else {
	      parent->setR(NULL);//sets right to null
        }
    }
	else {
            root = NULL; // If root is being removed
        }
        delete n;
        return;
    }

    if((n->getL() == NULL) != (n->getR() == NULL)) { //one child
        Node* child;
	if (n->getL() != NULL) {//if left child exists
	  child = n->getL();
	}
	else {//if right child exists
	  child = n->getR();
	}
        if (parent != NULL) {//if there is a parent
	  if (parent->getL() == n) {//if parents lchild is n
                parent->setL(child);
	  }
	  else {//if rchild is n
                parent->setR(child);
	  }
	}
	  else {//if the root needs to be removed
            root = child;
        }
        delete n;
        return;
    }
}

Node* findR(Node* root,int value) {//will find values
  if (!root) {
    return NULL;
  }

  if(root -> getV() == value) {
    return root;
  }
  findR(root->getR(), value);//searches the left subtree
  findR(root->getL(), value);//searches the left subtree
  return NULL;
}

int findC (Node* parent, int value) {
  if(parent->getL()->getV() == value) {
    return 1;
  }

  if(parent ->getR()->getV() == value) {
    return 2;
  }

  return 0;
}
