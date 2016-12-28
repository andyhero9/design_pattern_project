#include<iostream>
#include<string>
#include<list>

using namespace std;

class Observer // Observer
{
public:
	Observer() {}
	string O_name;
	virtual ~Observer() {}
	virtual void update() {}
	//void update() {}
};

class Subject  // Object  (being Observered)
{
public:
	Subject() {}   
	virtual ~Subject() {}

	list <Observer* > observers;
	string subjectState;

	void Adder(Observer *observer)  //add Observer
	{
		observers.push_back(observer);
	}
	void Deleter(Observer *observer)  //delete Observer
	{
		observers.remove(observer);
	}
	void Sender()  //notify Observer
	{
		list <Observer* >::iterator send_list = observers.begin();
		for (; observers.end() != send_list; send_list++)
		{
			(*send_list)->update();
		}
	}
	string GetState() { return subjectState; } // set state
	void SetState(string value) { subjectState = value; }  //get state
};

class Author : public Subject  //
{
public:
	string Author_name;
	Author(string name) :Author_name(name) {}
	virtual ~Author() {}
	string GetState() { return subjectState; }
	void SetState(string value) { subjectState = Author_name + value; }
};

class Reader : public Observer
{
public:
	string Observer_name;
	Subject *author_list;  // to Observe more authors
	string Observer_state;
	Reader(string name, Subject *author_list) :Observer_name(name), author_list(author_list) { O_name = name; }
	virtual ~Reader() {}
	void update()
	{
		Observer_state = author_list->GetState();
		cout << Observer_name << " : " << Observer_state << endl;
	}
};