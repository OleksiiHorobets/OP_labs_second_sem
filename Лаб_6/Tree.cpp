#include "Tree.h"

Node* Tree::Insert(Node* curr_node, int value)
{
    if (!curr_node) return new Node(value);
    if (curr_node->value > value)  curr_node->left = Insert(curr_node->left, value);
    else curr_node->right = Insert(curr_node->right, value);

    return curr_node;
}

Tree::Tree()
{
    this->root = nullptr;
}

bool Tree::isEmpty()
{
    return this->root == nullptr;
}

void Tree::Insert(int value)
{
    root = Insert(root, value);
}

void Tree::displayTree(const string& prefix_msg, const Node* node, bool isLeft)
{
    if (node)
    {
        cout << prefix_msg;
        cout << (isLeft ? "|--" : "L--");
        cout << node->value << endl;
        displayTree(prefix_msg + (isLeft ? "|   " : "    "), node->left, true);
        displayTree(prefix_msg + (isLeft ? "|   " : "    "), node->right, false);
    }
}

int Tree::calculateHeight(Node* node)
{
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);
    return max(leftHeight, rightHeight) + 1;
}

void Tree::displayTree()
{
    this->displayTree("", root, false);
}

void Tree::traversalPreorder()
{
    if (root) {
        traversalPreorder(this->root);
    }
}

int Tree::getHeight()
{
    return calculateHeight(root) - 1;
}

int Tree::countNodesOnLevel(int depth)
{
    return countNodesOnLevel(root, 0, depth);
}

void Tree::fillTree()
{
    int n;
    cout << "Enter nodes amount: ";
    cin >> n;

    int temp_value;
    cout << "\nEnter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> temp_value;
        this->Insert(temp_value);
    }
}

int Tree::countNodesOnLevel(Node* node, int curr_depth, int desired_depth)
{
    if (!node) {
        return 0;
    }
    if (curr_depth == desired_depth) {
        return 1;
    }
    else {
        return countNodesOnLevel(node->left, curr_depth + 1, desired_depth) +
            countNodesOnLevel(node->right, curr_depth + 1, desired_depth);
    }
}

void Tree::traversalPreorder(Node* curr_node)
{
    if (curr_node->left) traversalPreorder(curr_node->left);
    cout << "Current node: " << curr_node->value << endl;
    if (curr_node->right) traversalPreorder(curr_node->right);
}



