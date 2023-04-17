/*
 * Colin Maxwell
 * Data Structures & Algorithms 5T1
 * Final Project
 * 8/6/21
 */

#include <vector>
#include <stack>
#include <iostream>
using namespace std;


/* -------- Stack Linked List Implementation --------- */

//Stack Node Class
class stackNode {

public:

    char data;
    stackNode* next = NULL;

    //OverLoaded Constructor
    stackNode(char data);
};

stackNode::stackNode(char data) {
    this->data = data;
}

//Linked List implementation of Stack Class
class StackList {
public:

    stackNode* front;
    stackNode* tail;

    //No-Args Constructor
    StackList();

    //Variable to keep track of stack size
    int stackSize = 0;

    //Methods
    void push(char data);
    char pop();
    char top();
    bool isEmpty();
    char size();

};

//No-Args()
StackList::StackList() {
    this->front = NULL;
    this->tail = NULL;
}

//isEmpty()
bool StackList::isEmpty() {
    if (tail == NULL)
        return true;
    else
        return false;
}

//Push()
void StackList::push(char data) {
    stackNode* newNode = new stackNode(data);

    newNode->data = data;

    if (front == NULL)
    {
        front = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
    stackSize++; //Incrementing Stack Size
} //End Push()


//Pop()
char StackList::pop() {

    if (isEmpty()) {
        cout << "\nstack is empty, nothing to pop off the stack\n";
        return -1;
    }

    stackNode* temp = front;
    char nodeData = front->data;

    //If its the only node in the stack, set values to Null
    if (front == tail)
    {
        front = NULL;
        tail = NULL;
        delete(front);
        stackSize--;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->next == tail)
            {
                nodeData = tail->data;
                temp->next = NULL;
                delete(tail);
                tail = temp;
                stackSize--;
                break;
            }

            temp = temp->next;
        }

        return nodeData;
    }

    return nodeData;

}//End Pop()

//Top()
char StackList::top() {
    return tail->data;
}

//Size()
char StackList::size() {

    return stackSize;
}




/* Binary Tree Implementation */

#pragma once
class BinaryTree
{
private:
    struct Node
    {
        char value;
        Node* left;
        Node* right;
    };

    Node* root;

    /* Private Methods */

    // recursive insert
    void insert(Node*&, Node*&);

    // recursive populating stack
    void populatingStack(StackList*, Node*);


public:

    // No-Args Constructor
    BinaryTree() {
        root = NULL;
    }

    /* Public Methods */
    void insert(char input);
    bool search(char input);
    void populateStackWithTree(StackList*);

    /* Final Project Method */
    bool isSameTree(BinaryTree* anotherTree);

};



/* --- Insert methods ---*/
void BinaryTree::insert(Node*& rootNode, Node*& newNode)
{
    if (rootNode == NULL)
        rootNode = newNode;

    // if newNode.value < rootNode.value , recursively insert rootNode.left
    else if (newNode->value < rootNode->value)
        insert(rootNode->left, newNode);

    // if newNode.value > rootNode.value , recursively insert rootNode.right
    else if (newNode->value > rootNode->value)
        insert(rootNode->right, newNode);

    // error case
    else
        cout << "\nERROR\n";
} //End (private) insert()

void BinaryTree::insert(char input)
{
    Node* newNode = new Node;

    newNode->value = input;
    newNode->right = newNode->left = NULL;

    // Insert newNode into tree
    insert(root, newNode);
} //End (public) insert()



/* --- Search Method --- */
bool BinaryTree::search(char input)
{
    Node* nodePtr = root;

    while (nodePtr)
    {
        //If value is found, return true
        if (nodePtr->value == input)
        {
            //cout << "Value " << nodePtr->value << ", found!";
            return true;
        }
        else if (input < nodePtr->value)
            nodePtr = nodePtr->left;
        else
            nodePtr = nodePtr->right;
    }

    return false;
}


/* --- Populate Stack with TreeNodes.data Methods ---- */
void BinaryTree::populateStackWithTree(StackList* theStack)
{
    //Sending stack and root to private method
    populatingStack(theStack, root);
}

void BinaryTree::populatingStack(StackList* theStack, Node* tree)
{
    if (tree != NULL)
    {
        populatingStack(theStack, tree->left);
        theStack->push(tree->value);
        populatingStack(theStack, tree->right);
    }
}


/* ----- Final Project Method ----- */
bool BinaryTree::isSameTree(BinaryTree* secondTree)
{
    //Stacks
    StackList s1;
    StackList s2;

    populateStackWithTree(&s1);                //Populates first stack
    secondTree->populateStackWithTree(&s2);    //Populates second stack

    //If sizes are not the same, the trees are automatically not identical
    if (s1.size() != s2.size())
    {
        //cout << "Not same tree\n";
        return false;
    }

    char stackValue = NULL;
    while (!s1.isEmpty()) {
        stackValue = s1.top();

        if (!secondTree->search(s1.top()))
        {
            return false;
        }

        s1.pop();
    } //Exits loop if all the elements match the other tree's elements


    //Passed all tests, the trees are matching
    return true;
}