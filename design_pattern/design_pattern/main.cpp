#include<iostream>
#include <string>
#include "Composite.cpp"
#include "Observer.cpp"
#include "Undo_Redo.cpp"

using namespace std;

void observerMenu()
{
	Subject *authors = new Author("authors");
	authors->SetState("default");
	string readers;
	string states;
	int chose;
	int tag = 0;
	cout << "welcome to lib" << endl;
	while (0 == tag)
	{
		list<Observer*>::iterator it = authors->observers.begin();
		cout << "**************************************" << endl;
		cout << "Observer" << endl;
		cout << "**************************************" << endl;
		cout << "please chose what to do:" << endl
			<< "1.add reader" << endl
			<< "2.print state" << endl
			<< "3.change state" << endl
			<< "4.delete reader" << endl
			<< "0.exit" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
		{
			cout << "**************************************" << endl;
			cout << "please create a reader:" << endl;
			cin >> readers;
			Observer *reader = new Reader(readers, authors);
			authors->Adder(reader);
			break;
		}
		case 2:
		{
			cout << "**************************************" << endl;
			authors->Sender();
			break;
		}
		case 3:
		{
			cout << "**************************************" << endl;
			cout << "please enter a state:" << endl;
			cin >> states;
			authors->SetState(states);
			break;
		}
		case 4:
		{
			cout << "**************************************" << endl;
			cout << "please enter a name:" << endl;
			cin >> readers;
			int flag = 0;
			Observer  *temp = *it;
			while (flag<authors->observers.size())
			{
				temp = *it;
				if (temp->O_name == readers)
				{
					delete temp;
					authors->Deleter(temp);
					flag = authors->observers.size() + 1;
				}
				else
				{
					it++;
					flag++;
				}
			}
			authors->Sender();
			break;
		}
		case 0:
		{
			tag = 1;
			delete authors;
			break;
		}
		default:
			break;
		}
	}
}

void compositeMenu()
{
	Component *root = new AuthorB("Authors");
	string cases;
	int tag = 0;
	int chose;
	while (0 == tag)
	{
		cout << "**************************************" << endl;
		cout << "Composite" << endl;
		cout << "**************************************" << endl;
		cout << "please choose to create:" << endl
			<< "1.create a reader" << endl
			<< "2.create an author" << endl
			<< "0.exit" << endl;
		cin >> chose;
		switch (chose)
		{
			case 1:
			{
				cout << "**************************************" << endl;
				cout << "please enter a name:" << endl;
				cin >> cases;
				Component *leaf = new ReaderB(cases);
				root->Add(leaf);
				root->Show(0);
				break;
			}
			case 2:
			{
				cout << "**************************************" << endl;
				cout << "please enter a name:" << endl;
				cin >> cases;
				Component *mid = new AuthorB(cases);
				root->Add(mid);
				root->Show(0);
				cout << "**************************************" << endl;
				cout << "Do you want to add reader for this author?" << endl
					<< "1.yes" << endl
					<< "2.no" << endl;
				cin >> chose;
				while (1 == chose)
				{
					cout << "**************************************" << endl;
					cout << "please enter a name:" << endl;
					cin >> cases;
					Component *leaf = new ReaderB(cases);
					mid->Add(leaf);
					root->Show(0);
					cout << "**************************************" << endl;
					cout << "Do you want to add reader for this author?" << endl
						<< "1.yes" << endl
						<< "2.no" << endl;
					cin >> chose;
				}
				break;
			}
			case 0:
			{
				tag = 1;
				delete root;
				break;
			}
			default:
				break;

		}
	}
}

void undo_redoMenu()
{
	Transformer *temp = new Transformer(new State("default"));
	int chose;
	int tag = 0;
	string states;
	while (0 == tag)
	{
		cout << "**************************************" << endl;
		cout << "Undo/Redo" << endl;
		cout << "**************************************" << endl;
		cout << "please chose:" << endl
			<< "1.Change the state" << endl
			<< "2.Undo" << endl
			<< "3.Redo" << endl
			<< "0.Exit" << endl;
		cin >> chose;
		switch (chose)
		{
		case 1:
		{
			cout << "please enter a state:" << endl;
			cin >> states;
			temp->showState(new State(states));
			break;
		}
		case 2:
		{
			temp->Undo();
			break;
		}
		case 3:
		{
			temp->Redo();
			break;
		}
		case 0:
		{
			tag = 1;
			delete temp;
			break;
		}
		default:
			break;
		}
	}
}

int main()
{
	int num;
	int flag = 0;
	while (0==flag)
	{
		cout << "**************************************" << endl;
		cout << "Design Pattern" << endl;
		cout << "**************************************" << endl;
		cout << "please choose one:" << endl
			<< "1.Observer" << endl
			<< "2.Composite" << endl
			<< "3.Undo/Redo" << endl
			<< "0.Exit" << endl;
		cin >> num;
		switch (num)
		{
			case 1:
			{
				observerMenu();
				break;
			}
			case 2:
			{
				compositeMenu();
				break;
			}
			case 3:
			{
				undo_redoMenu();
				break;
			}
			case 0:
			{
				flag = 1;
				break;
			}
			default:
				break;
		}
	}
}