#include "familyTree.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

familyTree::familyTree(const std::vector<int>& familyMembers)
{
    //constructor that builds a tree using the elements from the familyMembers vector, this functions contains the line
    root = buildTree(familyMembers , 0);
}

familyTree::binTreeNode* familyTree::buildTree(const vector<int>& familyMembers, 
size_t index)
{
    //a recursive function that constructs a binary tree using the elements of the
    //familyTree vector, must traverse the familyTree vector in a preorder
    //fashion and returns binTreeNode* pointers back in order to link to
    //the parent’s left or right side. For any index, index * 2 + 1 would
    //access the left child and (index + 1) * 2 accesses the right child.
    //In each function you need to check for index out of bounds and if
    //familyTree[index] == -1 implies a null pointer in an intermediate
    //level of the binary tree.
    
    //out of bounds 
    if (index >= familyMembers.size())
    {
        return nullptr;
    }
    //is -1?
    if (familyMembers[index] == -1)
    {
        return nullptr;
    }

    //create the node
    binTreeNode* r;
    r = new binTreeNode();
    r->wealth = familyMembers[index];    //assign data
    r->left = buildTree(familyMembers, (index*2)+1); //left operations
    r->right = buildTree(familyMembers, (index+1)*2);//right operations

    return r;
}

familyTree::~familyTree()
{
    //destructor that contains the following line 
    deallocateTree(root);
}

void familyTree::deallocateTree(binTreeNode * r)
{
    //a recursive function that deallocates the tree in a postorder fashion
    if (r == nullptr)
        return;
    deallocateTree(r->left);
    deallocateTree(r->right);

    r->left = nullptr;
    r->right = nullptr;
    r->wealth = 0;
    delete r;
    
    return;
}

void familyTree::updateInheritance()
{
    //a function that contains 
    updateInheritance(root);
}

void familyTree::updateInheritance(binTreeNode * grandParent)
{
    //a recursive function that passes in a grand parent pointer and
    //determines the sum of its grandchildren (must determine which
    //grandchildren are cousins) and swaps the sums of the cousin wealth,
    //then recursively tries further down the tree
    int tempLeft = 0;
    int tempRight = 0;
    //if the current node doesnt exist, do nothing/return out. 
    if (grandParent == nullptr)
        return;
    
    if (grandParent->left != nullptr) //if there is a left child
    {
        if (grandParent->right != nullptr) //if there is a right child
        {
            if (grandParent->left->left != nullptr) //if there is a cousin 1
                tempLeft += grandParent->left->left->wealth;
            if (grandParent->left->right != nullptr) //if there is a cousin 2
                tempLeft += grandParent->left->right->wealth;
            if (grandParent->right->left != nullptr) //if there is a cousin 3
                tempRight += grandParent->right->left->wealth;
            if (grandParent->right->right != nullptr) //if there is a cousin 4
                tempRight += grandParent->right->right->wealth;
            if (grandParent->left->left != nullptr) //if there is a cousin 1
                if (tempRight != 0)
                    grandParent->left->left->wealth = tempRight;
            if (grandParent->left->right != nullptr) //if there is a cousin 2
                if (tempRight != 0)
                    grandParent->left->right->wealth = tempRight;
            if (grandParent->right->left != nullptr) //if there is a cousin 3
                if (tempLeft != 0)
                    grandParent->right->left->wealth = tempLeft;
            if (grandParent->right->right != nullptr) //if there is a cousin 4
                if (tempLeft != 0)
                    grandParent->right->right->wealth = tempLeft;
        }
        //if theres no right child
    }
    //if theres no left child

    //call next child
    updateInheritance(grandParent->left);   //left operations
    updateInheritance(grandParent->right);  //right operations

    return;
}

void familyTree::outputTree()
{
    //a function that contains 
    outputTree(root);
}

void familyTree::outputTree(binTreeNode * r)
{
    //a recursive function that outputs the data fields of each node
    //using a preorder traversal
    if (r == nullptr)
        return;
    cout << r->wealth << endl;    //cout data

    outputTree(r->left);  //this will process the entire left side of r
    outputTree(r->right);    //entire right side

    return;
}