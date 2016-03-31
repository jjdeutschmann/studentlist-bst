//****************************************************************************************************
//
//     File: BST.h
//
//     Author: Jennifer Deutschmann
//
//     The definition for the class BST (binary search tree). Uses recursion.
//
//	   Other files needed:
//	   1. node.h	 
//		
//****************************************************************************************************

#ifndef BST_H
#define BST_H

//****************************************************************************************************

#include <cmath>

#include "node.h"

//****************************************************************************************************

template <typename TYPE>
class BST
{
	private:
		Node<TYPE> * root;
		void _destruct (Node<TYPE> * pRoot);
		Node<TYPE> * _insert (Node<TYPE> * pRoot, const TYPE & dataIn);
		Node<TYPE> * _remove (Node<TYPE> * pRoot, const TYPE & dataOut);
		Node<TYPE> * _search (Node<TYPE> * pRoot, const TYPE & dataOut) const;
		void _traverse (Node<TYPE> * pRoot, void (*process)(TYPE d)) const;
		int _getCount (Node<TYPE> * pRoot) const;
		int _getHt (Node<TYPE> * pRoot) const;
		bool _isBalanced(Node<TYPE> * pRoot) const;
	public:
		BST ();
		~BST ();
		bool insert (const TYPE & dataIn);
		bool remove (TYPE & dataOut);
		bool search (TYPE & dataOut) const;
		bool update (const TYPE & dataOut);
		void traverse (void (*process)(TYPE d)) const;
		int getCount () const;
		int getHt () const;
		bool isEmpty () const;
		bool isFull () const;
		bool isBalanced () const;
};

//****************************************************************************************************

template <typename TYPE>
BST<TYPE> :: BST ()
{
	root = NULL;
}

//****************************************************************************************************

template <typename TYPE>
BST<TYPE> :: ~BST ()
{
	_destruct (root);
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: insert (const TYPE & dataIn)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _search (root, dataIn);

	if ( !pFound )
	{
		root = _insert(root, dataIn);
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: remove (TYPE & dataOut)
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _search (root, dataOut);

	if ( pFound )
	{
		dataOut = pFound -> data;
		root = _remove (root, dataOut);
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: search (TYPE & dataOut) const
{
	bool success = false;
	Node<TYPE> * pFound;

	pFound = _search (root, dataOut);

	if ( pFound )
	{
		dataOut = pFound -> data;
		success = true;
	}

	return success;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: update (const TYPE & dataIn)
{
	bool success = true;
	Node<TYPE> * pFound;

	pFound = _search (root, dataIn);

	if ( pFound )
	{
		pFound -> data = dataIn;
		success = true;
	}

	return true;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE> :: traverse (void (*process)(TYPE d)) const
{
	_traverse ( root, process );
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE> :: getCount () const
{
	return ( _getCount(root) );
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE> :: getHt () const
{
	return ( _getHt(root) - 1 );
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: isEmpty () const
{
	return ( root == NULL );
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: isFull () const
{
	bool full = true;
	Node<TYPE> * pTest = new (nothrow) Node<TYPE>;

	if ( pTest )
	{
		full = false;
		delete pTest;
	}

	return full;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: isBalanced () const
{
	return ( _isBalanced(root) );
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE> :: _destruct (Node<TYPE> * pRoot)
{
	if ( pRoot )
	{
		_destruct (pRoot -> left);
		_destruct (pRoot -> right);
		delete pRoot;
	}
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> :: _insert (Node<TYPE> * pRoot, const TYPE & dataIn)
{
	if ( pRoot )
	{
		if (pRoot -> data > dataIn)
			pRoot -> left = _insert (pRoot -> left, dataIn);
		else
			pRoot -> right = _insert (pRoot -> right, dataIn);
	}
	else
		pRoot = new (nothrow) Node<TYPE> (dataIn);

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> :: _remove (Node<TYPE> * pRoot, const TYPE & dataOut)
{
	Node<TYPE> * pDel;
	Node<TYPE> * pMax;

	if ( pRoot )
	{
		if ( pRoot -> data > dataOut )
			pRoot -> left = _remove(pRoot -> left, dataOut);
		else if ( pRoot -> data < dataOut )
			pRoot -> right = _remove(pRoot -> right, dataOut);
		else
		{
			if ( (pRoot -> left) && (pRoot -> right) )
			{
				pMax = pRoot -> left;

				while ( pMax && (pMax -> right) )
					pMax = pMax -> right;

				pRoot -> data = pMax -> data;

				pRoot -> left = _remove (pRoot -> left, pMax -> data);
			}
			else
			{
				pDel = pRoot;

				pRoot = (pRoot -> right) ? (pRoot -> right) : (pRoot -> left);

				delete pDel;
			}
		}
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> * BST<TYPE> :: _search (Node<TYPE> * pRoot, const TYPE & dataOut) const
{
	if ( pRoot )
	{
		if ( pRoot -> data > dataOut )
			pRoot = _search (pRoot -> left, dataOut);
		else if ( pRoot -> data < dataOut )
			pRoot = _search (pRoot -> right, dataOut);
	}

	return pRoot;
}

//****************************************************************************************************

template <typename TYPE>
void BST<TYPE> :: _traverse (Node<TYPE> * pRoot, void (*process)(TYPE d)) const
{
	if ( pRoot )
	{
		_traverse (pRoot -> left, process);
		process ( pRoot -> data );
		_traverse (pRoot -> right, process);
	}
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE> :: _getCount (Node<TYPE> * pRoot) const
{
	int count;

	if ( pRoot )
		count = 1 + _getCount(pRoot -> left) + _getCount(pRoot -> right);
	else
		count = 0;

	return count;
}

//****************************************************************************************************

template <typename TYPE>
int BST<TYPE> :: _getHt (Node<TYPE> * pRoot) const
{
	int height;

	if ( pRoot )
		height = 1 + max( _getHt(pRoot -> left), _getHt(pRoot -> right) );
	else
		height = 0;

	return height;
}

//****************************************************************************************************

template <typename TYPE>
bool BST<TYPE> :: _isBalanced(Node<TYPE> * pRoot) const
{
	bool result;
	int leftHt;
	int rightHt;

	if ( pRoot )
	{
		leftHt = _getHt(pRoot -> left);
		rightHt = _getHt(pRoot -> right);

		result = ((abs(leftHt - rightHt) <= 1) && _isBalanced(pRoot -> left)
			&& _isBalanced(pRoot -> right));
	}
	else
		result = true;

	return result;
}

//****************************************************************************************************

#endif

//****************************************************************************************************