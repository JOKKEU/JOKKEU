#include <iostream>

struct Node 
{
	int data;
	Node* left;
	Node* right;

	Node(int value) : data(value), left(nullptr), right(nullptr) {}; 
};

class BinaryTree 
{
private:
	Node* root;
public:
	BinaryTree() = default;
	~BinaryTree() { clear(root); root = nullptr; }

	Node* getRoot() const { return root; }
	void insert(int value) 
	{
		Node* newNode = new Node(value);
		if (!root) {
			root = newNode;
			return ;
		}
		else {
			Node* current = root;
			while (current != nullptr) 
			{
				if (value < current->data) 
				{
					if (current->left)
					{
						current = current->left;
					}
					else
					{
						current->left = newNode;
						break;
					}
				}
				else 
				{
					if (current->right)
					{
						current = current->right;
					}
					else
					{
						current->right = newNode;
						break;
					}
				}
			}
		}
	}



	bool find(int value) 
	{
		bool flag = false;
		if (!root) 
		{
			return false;
		}
		else 
		{
			Node* current = root;
			while (current != nullptr)
			{
				if (current->data == value)
				{
					return true;
				}
				else if (current->data > value)
				{
					current = current->left;
				}
				else 
				{
					current = current->right;
				}
			}
		}
		return false;
	}

	void inOrderPrint(std::ostream& os, Node* node) const;

	void clear(Node* node) {
		if (node) {
			clear(node->left);
			clear(node->right);
			delete node;
		}
	}


};

void BinaryTree::inOrderPrint(std::ostream& os, Node* node) const {
	if (node != nullptr) {
		inOrderPrint(os, node->left);
		os << node->data << " ";
		inOrderPrint(os, node->right);
	}
}

std::ostream& operator<<(std::ostream& os, const BinaryTree& tree)
{
	if (tree.getRoot() == nullptr) {
		os << "Tree is empty";
	}
	else {
		tree.inOrderPrint(os, tree.getRoot());
	}
	return os;
}


int main()
{

}