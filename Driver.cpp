/*
 * Colin Maxwell
 * Data Structures & Algorithms 5T1
 * Final Project
 * 8/6/21
 */

#include "BinaryTree.h"
#include<iostream>

using namespace std;


int main() {

	/* --- Identical Tree Example --- */

	//Binary Tree 1
	BinaryTree tree1;
	tree1.insert('a');
	tree1.insert('b');
	tree1.insert('c');

	//Binary Tree 2
	BinaryTree tree2;
	tree2.insert('b');
	tree2.insert('a');
	tree2.insert('c');


	/* Testing Trees */
	cout << endl;

	//Calling isSameTree from tree1 object
	if (!tree1.isSameTree(&tree2))
	{
		cout << "False! They are not identical trees\n";
	}
	else
		cout << "True! They are both identical trees\n";

	//Calling isSameTree from tree2 object
	if (!tree2.isSameTree(&tree1))
	{
		cout << "False! They are not identical trees\n";
	}
	else
		cout << "True! They are both identical trees\n";




	/* --- Unidentical Tree Example --- */

	//Binary Tree 3
	BinaryTree tree3;
	tree3.insert('b');
	tree3.insert('a');
	tree3.insert('c');

	//Binary Tree 4
	BinaryTree tree4;
	tree4.insert('c');
	tree4.insert('b');
	tree4.insert('a');
	tree4.insert('d');

	cout << endl;
	//Calling isSameTree from tree3 object
	if (!tree3.isSameTree(&tree4))
	{
		cout << "False! They are not identical trees\n";
	}
	else
		cout << "True! They are both identical trees\n";

	//Calling isSameTree from tree4 object
	if (!tree4.isSameTree(&tree3))
	{
		cout << "False! They are not identical trees\n";
	}
	else
		cout << "True! They are both identical trees\n";



	cout << "\n\n";
	system("pause");
	return 0;
}