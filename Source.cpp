#include<iostream>
#include<queue>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T>* leftchild;
	Node<T>* rightchild;

	Node()
	{
		data = T();
		leftchild = NULL;
		rightchild = NULL;
	}
};

template <class T>
class Tree
{
private:
	Node<T>* root;
	bool Samevaluescheck(Node<T>* R1, Node<T>* R2)
	{
		if (R1 == NULL && R2 == NULL) //if both become NULL returns true
		{
			return true;
		}
		else if (R1 == NULL)// if either is NULL then return false
		{
			return false;
		}
		else if (R2 == NULL)
		{
			return false;
		}

		//default case
		//comparing data and then calling the function recursively for left and right child
		return (R1->data == R2->data && Samevaluescheck(R1->leftchild, R2->leftchild) && Samevaluescheck(R1->rightchild, R2->rightchild));
	}

public:
	Tree()
	{
		root = NULL;
	}
	void insert(T d)
	{
		queue<Node<T>*> Queue;
		if (root == NULL)
		{
			root = new Node<T>;
			root->data = d;
		}
		else
		{
			Queue.push(root);
			Node<T>* temp = NULL;

			while (true)
			{
				temp = Queue.front();
				Queue.pop();

				if (temp->leftchild == NULL)
				{
					temp->leftchild = new Node<T>;
					temp->leftchild->data = d;
					break;
				}
				else if (temp->rightchild == NULL)
				{
					temp->rightchild = new Node<T>;
					temp->rightchild->data = d;
					break;

				}
				else
				{
					Queue.push(temp->leftchild);
					Queue.push(temp->rightchild);
				}

			}

		}
	}
	void display()
	{
		queue<Node<T>*> Queue;
		if (root == NULL)
		{
			cout << "Tree doesn't exist" << endl;
			return;
		}
		else
		{
			Queue.push(root);
			Node<T>* temp = root;
			cout << temp->data << " ";

			while (true)
			{
				temp = Queue.front();
				Queue.pop();
				if (temp->leftchild != NULL)
				{
					cout << temp->leftchild->data << " ";
				}

				if (temp->rightchild != NULL)
				{
					cout << temp->rightchild->data << " ";

				}

				if (temp->leftchild != NULL && temp->rightchild != NULL)
				{

					Queue.push(temp->leftchild);
					Queue.push(temp->rightchild);
				}
				else
				{
					break;
				}

			}

		}
	}
	bool replace(T olditem, T newitem)
	{
		queue<Node<T>*> Queue;
		if (root == NULL)
		{
			cout << "Tree doesn't Exist" << endl;
			return false;
		}
		else
		{
			Queue.push(root);
			Node<T>* temp = root;
			if (temp->data == olditem)//root case;
			{
				temp->data = newitem;
				return true;
			}

			while (true)
			{
				temp = Queue.front();
				Queue.pop();

				if (temp->leftchild != NULL && temp->leftchild->data == olditem)
				{
					temp->leftchild->data = newitem;
					return true;
				}

				if (temp->rightchild != NULL && temp->rightchild->data == olditem)
				{
					temp->rightchild->data = newitem;
					return true;

				}

				if (temp->rightchild != NULL && temp->leftchild != NULL)
				{
					Queue.push(temp->leftchild);
					Queue.push(temp->rightchild);
				}
				else
				{
					return false;
				}

			}

		}
	}
	Node<T>* returnRoot()
	{
		return root;// getter for the root
	}
	bool Subtreecheck(Node<T>* T1, Node<T>* T2)
	{
		if (T1 == NULL)		//if T1 is empty or becomes empty T2 cannot be subtree of an empty tree
		{
			return false;
		}
		else if (T2 == NULL)		//NULL tree is subtree of all trees
		{
			return true;
		}
		else if (Samevaluescheck(T1, T2))	//Comparing both trees node by node 
		{
			return true;
		}
		return Subtreecheck(T1->leftchild, T2) || Subtreecheck(T1->rightchild, T2); //default case(Searches in leftchild of T1 if found return true otherwise searches rightchild of T1)

	}
};

int main()
{
	Tree<int> T1;
	for (int i = 0; i < 7; i++)
	{
		T1.insert(i);
	}

	if (T1.Subtreecheck(T1.returnRoot(), T1.returnRoot()->leftchild))
	{
		cout << "T2 is a Subtree of T1" << endl;
	}
	else
	{
		cout << "T2 is NOT a Subtree of T1" << endl;
	}


	return 0;
}
