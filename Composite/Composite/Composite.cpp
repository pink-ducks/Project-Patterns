#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;

class Component
{
public:
	virtual void traverse() = 0; // OPERATION
};

class Leaf : public Component
{
	int value;
public:
	Leaf(int val)
	{
		value = val;
	}
	void traverse() // OPERATION
	{
		cout << value << ' ';
	}
};

class Composite : public Component
{
	vector < Component * > children;
public:
	void add(Component *ele)
	{
		children.push_back(ele);
	}
	void traverse() // OPERATION FORALL
	{
		for (int i = 0; i < children.size(); i++)
			children[i]->traverse();
	}
};

int main()
{
	Composite containers[4];

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 3; j++)
			containers[i].add(new Leaf(i * 3 + j));

	for (int i = 1; i < 4; i++)
		containers[0].add(&(containers[i]));

	for (int i = 0; i < 4; i++)
	{
		containers[i].traverse();
		cout << endl;
	}
}
/*
0 1 2 3 4 5 6 7 8 9 10 11
3 4 5
6 7 8
9 10 11
*/