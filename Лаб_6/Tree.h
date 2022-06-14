#pragma once
#include <vector>
#include <iostream>
#include "TreeNode.h"

using namespace std;

class Tree
{
private:
	Node* root = nullptr;

	void traversalPreorder(Node* curr_node);

	Node* Insert(Node* curr_node, int value);

	void displayTree(const string& prefix_msg, const Node* node, bool isRight);

	int calculateHeight(Node* node);

	int countNodesOnLevel(Node* node, int cur_depth, int desired_depth);

public:
	Tree();

	bool isEmpty();
	void Insert(int value);
	
	void displayTree();


	void traversalPreorder();

	int getHeight();

	int countNodesOnLevel(int depth);

	void fillTree();
};