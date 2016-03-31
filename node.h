//****************************************************************************************************
//
//     File: node.h
//
//     Author: Jennifer Deutschmann
//
//     The struct definition of Node, edited to work two ways.
//			 
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node
{
	TYPE data;
	
	union
	{
		Node<TYPE> * prev;
		Node<TYPE> * right;
	};

	union
	{
		Node<TYPE> * next;
		Node<TYPE> * left;
	};
	
	Node ();
	Node ( TYPE d, Node<TYPE> * n = NULL, Node<TYPE> * p = NULL );
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> :: Node ()
{
	data = 0;
	next = NULL;
	prev = NULL;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE> :: Node ( TYPE d, Node<TYPE> * n, Node<TYPE> * p )
{
	data = d;
	next = n;
	prev = p;
}

//****************************************************************************************************

#endif

//****************************************************************************************************