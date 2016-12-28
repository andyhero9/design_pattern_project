#include<iostream>
#include<string>
#include<list>

using namespace std;

class Component //abstract base class,only offer api
{
public:
	Component(string name) { cNmae = name; }
	virtual ~Component() {}
	virtual void Add(Component *p) {}
	virtual void Show(int rank) {}
	string cNmae;
};

class AuthorB : public Component //the AuthorB
{
public:
	AuthorB(string name) : Component(name) {}
	virtual ~AuthorB() {}
	void Add(Component *p) { m_listComponent.push_back(p); } //in the middle of the tree to add sub_tree
	void Show(int rank)
	{
		for (int i = 0; i < rank; i++)
			cout << "-";
		cout << cNmae << endl;
		list<Component *>::iterator iter = m_listComponent.begin();
		for (; iter != m_listComponent.end(); iter++) //to show the next node
			(*iter)->Show(rank + 1);
	}
	list<Component *> m_listComponent;
};

class ReaderB : public Component //the ReaderB
{
public:
	ReaderB(string name) :Component(name) {}
	virtual ~ReaderB() {}
	virtual void Show(int rank) //to show
	{
		for (int i = 0; i < rank; i++)
			cout << "-";
		cout << cNmae << endl;
	}
};