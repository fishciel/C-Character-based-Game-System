/*CS302-002, Program 3, May 2023
This BST.cpp file contains the implementation of the 
Node and BST class.
The required functions like insert, remove, display,
and remove all are all supported by the BST.
A character pointer is expected as an argument for
most functions (insert, remove).
Every node "has a" Character *
A BST manages a collection of nodes
functions return true on success*/

#include "BST.h"
using namespace std;

//default constructor for a node
Node::Node() : character(nullptr), left(nullptr), right(nullptr)
{
}



//destructor (data mems are taken care of by BST destructor)
Node::~Node()
{
}



//this func returns the left child
Node *& Node::get_left()
{
    return left;
}



//this func returns the right child
Node *& Node::get_right()
{
    return right;
}



//this func checks if the character 
//is the same as the one passed in
bool Node::equal_to(const Character * new_data) const
{
	if(character->equal_to(new_data) == true)
		return true;
	return false;
}



//this func checks if the character 
//is less than the one passed in
bool Node::less_than(const Character* new_data) const
{
	if(character->less_than(new_data) == true)
		return true;
	return false;
}



//this func checks if the character 
//is greater than or equal the one passed in
bool Node::greater_than_or_equal(const Character* new_data) const
{
	if(character->less_than(new_data) == false)
		return true;
	return false;
}



//this func returns the character 
Character* Node::get_data() const
{
    return character;
}


//this func displays the node data
bool Node::display() const
{
	return character->display();
}



//set the left child
bool Node::set_left(Node * node)
{
	left = node;
	return true;
}



//set the right child
bool Node::set_right(Node * node)
{
	right = node;
	return true;
}



//set the data
bool Node::set_data(const Character * a_chara)
{
	//character = a_chara;

	Character * copy = const_cast<Character *>(a_chara);
	character = copy;
	return true;
}

/****************************************/

//default constructor for BST, sets root to nullptr
BST::BST() : root(nullptr) {}



//destructor, removes all nodes, uses remove all function
//i.e. deallocates all dynamic mem and sets to zero eqv
BST::~BST()
{
	if(root)
		remove_all(root);
	if(!root)
		cout << "Arena is empty.\n\n";
	else
		cout << "Arena is not empty.\n\n";
}



//insert func that inserts a chara into the BST (wrapper)
bool BST::insert(const Character * a_chara)
{
	return insert(root, a_chara);
}



//insert func that inserts a chara into the BST (recursive)
bool BST::insert(Node *& root, const Character * a_chara)
{
	if(!root)
	{
		root = new Node;
		root->set_data(a_chara);
		root->set_left(nullptr);
		root->set_right(nullptr);

		cout << "Test, added: " << endl;
		root->display();
		return true;
	}

	if(root->less_than(a_chara) == true)
	{
		return insert(root->get_left(), a_chara);
	}
	else
	{
		return insert(root->get_right(), a_chara);
	}
}



//this function displays ALL nodes in the BST (wrapper)
bool BST::display() const
{
	if(!root)
	{
		cout << "Nothing to display...\n\n";
		return false;
	}
	return display(root);
}



//this function displays ALL nodes in the BST (recursive)
bool BST::display(Node * root) const
{
	if(!root)
		return true;
	display(root->get_left());
	root->display();
	return display(root->get_right());
}



//this func removes all nodes in the BST (wrapper)
bool BST::remove_all()
{
	if(!root)
	{
		cout << "No characters to remove...\n";
		return false;
	}
	return remove_all(root);
}



//this func removes all nodes in the BST (recursive)
bool BST::remove_all(Node *& root)
{
	if(!root)
		return true;

	remove_all(root->get_right());
	remove_all(root->get_left());

	delete root;
	root = nullptr;
	return true;
}



//removes the node w/matching character name (wrapper)
bool BST::remove(const Character * to_remove)
{
	if(!root)
		return false;
	return remove(root, to_remove);
}



//removes the node w/matching character name (recursive)
bool BST::remove(Node *& root, const Character * to_remove)
{
	if(!root)
	{
		cout << "A match was not found...\n\n";
		return false;
	}

	//match is less than root, go left
	Node * temp = nullptr;
	if(root->equal_to(to_remove) == true)
	{
		//no children, is leaf
		if(!root->get_left() && !root->get_right())
		{
			delete root;
			root = nullptr;
			return true;
		}
		//only has left child
		else if(root->get_left() && !root->get_right())
		{
			temp = root->get_left();
			delete root;
			root = temp;
			return true;
		}
		//only has right child
		else if(!root->get_left() && root->get_right())
		{
			temp = root->get_right();
			delete root;
			root = temp;
			return true;
		}
		//has both a left and right child
		Node * prev = nullptr;
		Node * current = root->get_right();
		//don't need to traverse to find IOS
		if(!current->get_left())
		{
			//root gets it's right child data
			root->set_data(current->get_data());
			//hold onto rest of tree
			temp = current->get_right();
			//can delete the IOS now
			delete current;
			current = nullptr;
			return true;
		}

		//look for IOS
		while(current->get_left())
		{
			prev = current;
			current = current->get_left();
		}
		//root gets it's right child data
		root->set_data(current->get_data());
		//hold onto rest of tree
		temp = current->get_right();
		//can delete the IOS now
		delete current;
		current = nullptr;
		prev->get_left() = temp;
		return true;
	}
	
	//match is less than
	if(to_remove->less_than(root->get_data()))
		return remove(root->get_left(), to_remove);

	//match is greater or equal
	else
		return remove(root->get_right(), to_remove);
}


/****************************************************/
