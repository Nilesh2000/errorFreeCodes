//A program to create a BST of integers and search an element in it.
//A binary search tree should not have duplicate nodes.
# include <iostream>

using namespace std;

struct BstNode
{
    int Data;
    BstNode *Left, *Right;
};

//Function to allocate memory for a new node.
BstNode* newNode(int Data)
{
    BstNode *newNode = new BstNode(); //Memory allocation for new node.
    newNode -> Data = Data;
    newNode -> Left = newNode -> Right = NULL;
    return newNode;
}

BstNode* insertNewNode(BstNode* Root, int Data)
{
    if(Root == NULL) //If the tree or subtree has no elements
      return newNode(Data);

    if(Root -> Data >= Data) //If data stored in the root node is greater than the data to be inserted, make sure to insert the new node in the left subtree.
    {
        Root -> Left = insertNewNode(Root -> Left, Data);
    }
    else //Else, just insert it into the right subtree.
    {
        Root -> Right = insertNewNode(Root -> Right, Data);
    }
    return Root; //Return address of the root node every time a new node is inserted in the tree..
}

bool searchForElement(BstNode* Root, int Data)
{
    if(Root == NULL)
      return false;

    else if(Root -> Data == Data)
      return true;

    else if(Root -> Data >= Data) //If data stored in root node is greater than the data to be searched, then continue to search in the left subtree.
      return searchForElement(Root -> Left, Data);

    else //Else, search in the right subtree.
      return searchForElement(Root -> Right, Data);
}

int main(void)
{
    BstNode *Root = NULL;
    Root = insertNewNode(Root, 15);
    Root = insertNewNode(Root, 10);
    Root = insertNewNode(Root, 20);
    Root = insertNewNode(Root, 25);
    Root = insertNewNode(Root, 8);
    Root = insertNewNode(Root, 12);
    Root = insertNewNode(Root, 16);
    if(searchForElement(Root, 8) == true)
      cout << "Found";
    else
      cout << "Not found.";
    return 0;
}
