#include <iostream>
#include "Tree.h"
#include "TreeNode.h"

using namespace std;

int main()
{
	Tree firstTree;
	firstTree.fillTree();

	firstTree.displayTree();

	cout <<"Tree height(indexing starts from 0): " << firstTree.getHeight()<<endl;

	int level;
	cout << "Enter level(indexing starts from 0): ";
	cin >> level;

	cout << "Amount of nodes on level " << level << " is: " << firstTree.countNodesOnLevel(level)<<endl;

	system("pause");
}
