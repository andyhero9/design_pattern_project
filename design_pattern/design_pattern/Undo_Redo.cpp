#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Model
{
public:
	Model() {}  //constructor
	virtual ~Model() {}  //destructor
	virtual void Show() = 0;  //pure Virtual functions, Subclasses must implement this function
};


class State : public Model
{
public:
	State(string name) : nState(name) {}
	~State() {}
	void Show()
	{
		cout << "**************************************" << endl;
		cout << "Current State : " << nState << endl;
	}
	string nState;
};

class Transformer
{
public:
	stack< Model* > undoStack;//use stack  to store th undo Model
	stack< Model* > redoStack;//use stack  to store th redo Model
	Transformer(Model *pCmd)
	{
		undoStack.push(pCmd);//push the first state
	}
	~Transformer()
	{
		while (false == undoStack.empty())
		{
			delete undoStack.top();
			undoStack.pop();
		}
		while (false == redoStack.empty())
		{
			delete redoStack.top();
			redoStack.pop();
		}
	}
	void showState(Model *pCmd) //
	{
		pCmd->Show();
		undoStack.push(pCmd);
	}
	void Undo()
	{
		if (undoStack.size() < 2) //no state to undo
		{
			cout << "undo failed" << endl;
			return;
		}
		cout << "undo:" << endl;
		Model *pCmd = undoStack.top();
		redoStack.push(pCmd);//store new state
		undoStack.pop();//pop
		pCmd = undoStack.top();//return to the last state
		pCmd->Show();
	}

	void Redo()
	{
		if (redoStack.empty())//no state to redo
		{
			cout << "redo failed" << endl;
			return;
		}
		cout << "redo:" << endl;
		Model *pCmd = redoStack.top();
		pCmd->Show();
		redoStack.pop();
		undoStack.push(pCmd);
	}
};