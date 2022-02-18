#include <iostream>
#include <cassert>
#include "binaryTree.h"

using namespace std;

binaryTree::binaryTree()
{
    root = NULL;
}

bool binaryTree::isEmpty() const
{
    return(root == NULL);
}

int binaryTree::height(binaryTreeNode* p) const
{
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->llink), height(p->rlink));
}

int binaryTree::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

int binaryTree::treeHeight() const
{
    return height(root);
}
// DO NOT MODIFY FUNCTIONS ABOVE

void binaryTree::initSum()
{
    sum = 0;
}

void binaryTree::addValue(int value)
{
    sum += value;
}

void binaryTree::preorder_mod(binaryTreeNode* p)
{
    if (p != NULL)
    {
        if (p->llink != nullptr)
            addValue(p->llink->info);
        preorder_mod(p->llink);
        preorder_mod(p->rlink);
    }
}

int binaryTree::getSumOfAllLeftNodes()
{
    initSum();
    preorder_mod(root);

    return sum;
}

// DO NOT MODIFY FUNCTIONS BELOW
void binaryTree::insert(const int& insertItem)
{
    binaryTreeNode* current; //pointer to traverse the tree
    binaryTreeNode* trailCurrent; //pointer behind current
    binaryTreeNode* newNode; //pointer to create the node

    newNode = new binaryTreeNode;
    assert(newNode != NULL);
    newNode->info = insertItem;
    newNode->llink = NULL;
    newNode->rlink = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        current = root;
        while (current != NULL)
        {
            trailCurrent = current;
            if (current->info == insertItem)
            {
                cerr << "The insert item is already in the list-";
                cerr << "duplicates are not allowed." << insertItem << endl;
                return;
            }
            else if (current->info > insertItem)
                current = current->llink;
            else
                current = current->rlink;
        }
        if (trailCurrent->info > insertItem)
            trailCurrent->llink = newNode;
        else
            trailCurrent->rlink = newNode;
    }
}

void binaryTree::destroy(binaryTreeNode*& p)
{
    if (p != NULL)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = NULL;
    }
}

void binaryTree::destroyTree()
{
    destroy(root);
}

binaryTree::~binaryTree()
{
    destroy(root);
}

void binaryTree::deleteFromTree(binaryTreeNode*& p)
{
    binaryTreeNode* current;//pointer to traverse the tree
    binaryTreeNode* trailCurrent; //pointer behind current
    binaryTreeNode* temp; //pointer to delete the node

    if (p == NULL)
        cerr << "Error: The node to be deleted is NULL." << endl;
    else if (p->llink == NULL && p->rlink == NULL)
    {
        temp = p;
        p = NULL;
        delete temp;
    }
    else if (p->llink == NULL)
    {
        temp = p;
        p = temp->rlink;
        delete temp;
    }
    else if (p->rlink == NULL)
    {
        temp = p;
        p = temp->llink;
        delete temp;
    }
    else
    {
        current = p->llink;
        trailCurrent = NULL;
        while (current->rlink != NULL)
        {
            trailCurrent = current;
            current = current->rlink;
        }//end while
        p->info = current->info;
        if (trailCurrent == NULL) //current did not move; current == p->llink; adjust p
            p->llink = current->llink;
        else
            trailCurrent->rlink = current->llink;
        delete current;
    }
}

void binaryTree::deleteNode(const int& deleteItem)
{
    binaryTreeNode* current; //pointer to traverse the tree
    binaryTreeNode* trailCurrent; //pointer behind current
    bool found = false;
    if (root == NULL)
        cout << "Cannot delete from the empty tree." << endl;
    else
    {
        current = root;
        trailCurrent = root;
        while (current != NULL && !found)
        {
            if (current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                if (current->info > deleteItem)
                    current = current->llink;
                else
                    current = current->rlink;
            }
        }//end while
        if (current == NULL)
            cout << "The delete item is not in the tree." << endl;
        else if (found)
        {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->llink);
            else
                deleteFromTree(trailCurrent->rlink);
        }
    }
}
