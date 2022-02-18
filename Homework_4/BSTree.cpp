#include "BSTree.h"
#include "BSTNode.h"

BSTree::BSTree()
{
	rootNode = nullptr;
}

BSTree::~BSTree()
{
	//implement destructor
	delete rootNode;
}

int countHeight(BSTNode *start)
{
	if (nullptr == start)
	{
		return -1;
	}
	else
	{
		int ld = countHeight(start->getLeftChild());
		int rd = countHeight(start->getRightChild());
		
		return max(ld, rd) + 1;
	}
}

int BSTree::getHeight() const
{
	return countHeight(rootNode);
}

int countNodes(BSTNode* start)
{
	if (nullptr == start)
	{
		return 0;
	}
	else
	{
		return 1 + countNodes(start->getLeftChild()) + countNodes(start->getRightChild());
	}
}

int BSTree::getNumNodes() const
{
	return countNodes(rootNode);
}

string preorder(BSTNode* node, string ret = "") {
	if (node == nullptr)
		return ret + "[NULL]";
	return ret + node->getKey() + "\n" + preorder(node->getLeftChild(), ret + "l>") + "\n" + preorder(node->getRightChild(), ret + "r>");
}

string BSTree::getRepresentation()
{
	//implement function
	return ">" + preorder(rootNode);
}

BSTNode* BSTree::getNode(string key)
{
	//implement function
	BSTNode* current = rootNode;
	while (current != nullptr) {
		if (current->getKey().compare(key) == 0)
			return current;
		else if (current->getKey().compare(key) > 0)
			current = current->getLeftChild();
		else if (current->getKey().compare(key) < 0)
			current = current->getRightChild();
	}
	return nullptr;
}

bool BSTree::addNode(string key)
{
	BSTNode* newNode = new BSTNode(key);
	addNode(newNode);
	return true;
}

bool BSTree::addNode(BSTNode* item)
{
	//implement function
	if (rootNode == nullptr) {
		rootNode = item;
		return true;
	}
	else {
		BSTNode* current = rootNode;
		while (current != nullptr) {
			if (item->getKey().compare(current->getKey()) < 0) {
				if (current->getLeftChild() == nullptr) {
					current->setLeftChild(item);
					current = nullptr;
				}
				else current = current->getLeftChild();
			}
			else {
				if (current->getRightChild() == nullptr) {
					current->setRightChild(item);
					current = nullptr;
				}
				else current = current->getRightChild();
			}
		}
	}
	return false;
}