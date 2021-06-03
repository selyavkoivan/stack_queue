#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;


class stack
{
private:
	string* strings;
	int size;
	int maxSize;

public:
	int getMaxSize() { return maxSize; }
	int getSize() { return size; }
	stack()
	{

		maxSize = 8;
		strings = new string[maxSize];
		size = 0;
	}
	void add(string data)
	{
		if (size != maxSize)
		{
			strings[size] = data;
			size++;
		}
		else
		{
			for (int i = 1; i < maxSize; i++)
			{
				strings[i - 1] = strings[i];
			}
			strings[maxSize] = data;
		}
	}
	string get()
	{
		return strings[size - 1];
	}
	void del()
	{
		if (!size) return;
		size--;
	}
	~stack()
	{
		
		strings = NULL;
		delete strings;
	}
};

void stackMenu()
{
	stack myStack;
	while (true)
	{
		system("cls");
		cout << "1. - добавить\n";
		cout << "2. - удалить\n";
		cout << "3. - посмотреть\n";
		cout << "4. - посмотреть последний\n";
		cout << "5. - назад\n>> ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{

			string newData;
			cout << "Введите строку : ";
			cin >> newData;
			myStack.add(newData);
			break;
		}
		case 2:
		{
			myStack.del();
			break;
		}
		case 3:
		{
			stack copyOfMyStack = myStack;
			cout << "кол-во " << copyOfMyStack.getSize() << endl;
			while (copyOfMyStack.getSize())
			{
				cout << copyOfMyStack.get() << "\n";
				copyOfMyStack.del();
			}
			system("pause");
			break;
		}
		case 4:
		{
			if(myStack.getSize())cout << myStack.get() << "\n";
			system("pause");
			break;
		}
		case 5: return;
		default: break;
		}
	}
}



struct list_int
{
	int number;
	list_int* next;
	list_int() { next = NULL; }
	list_int(int number)
	{
		this->number = number;
	}

};
class priority_queue
{
private:
	list_int* first;
	list_int* last;
	int counter;
public :
	priority_queue() { first = last = NULL; counter = 0; }
	int getCount() { return counter; }

	void add(int newNumber)
	{
		if (!counter)
		{
			first = last = new list_int(newNumber);
			counter++;
		}
		else
		{
			if (newNumber > first->number)
			{
				list_int* first= new list_int(newNumber);
				first->next = this->first;
				this->first = first;
				counter++;
				
			}
			else if (newNumber < last->number)
			{
				last->next = new list_int(newNumber);
				last = last->next;
				counter++;
			}
			else
			{
				for (auto it = first; it != last->next; it = it->next)
				{
					if (newNumber > it->next->number)
					{
						list_int* newNext = new list_int(newNumber);
						
						list_int* nextAfterNext = it->next;
						
						newNext->next = nextAfterNext;
						
						it->next = newNext;
						
						counter++;
						return;
					}
				}
			}
		}
	}
	int getFirst() { return first->number ; }
	int getLast() { return last->number; }
	void delFirst()
	{
		if (!counter) return;
		else if (counter == 1)
		{
			first = last = NULL;
			delete first;
			counter--;
		}
		else
		{
			list_int* newFirst = first->next;
			first = NULL;
			delete first;
			counter--;
			first = newFirst;

		}
	}
};

void queueMenu()
{
	priority_queue myQueue;
	while (true)
	{
		system("cls");
		cout << "1. - добавить\n";
		cout << "2. - удалить\n";
		cout << "3. - посмотреть\n";
		cout << "4. - посмотреть последній\n";
		cout << "5. - назад\n>> ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{

			int newData;
			cout << "Введите число : ";
			cin >> newData;
			myQueue.add(newData);
			break;
		}
		case 2:
		{
			myQueue.delFirst();
			break;
		}
		case 3:
		{
			priority_queue copyOfMyQueue= myQueue;
			cout << "кол-во " << myQueue.getCount() << endl;
			while (copyOfMyQueue.getCount())
			{
				cout << copyOfMyQueue.getFirst() << "\n";
				copyOfMyQueue.delFirst();
			
			}
			system("pause");
			break;
		}
		case 4:
		{
			if(myQueue.getCount())cout << myQueue.getLast() << "\n";
			system("pause");
			break;
		}
		case 5: return;
		default: break;
		}
	}
}




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (true)
	{
		system("cls");
		cout << "1. - stack\n";
		cout << "2. - priority_queue\n";
		cout << "3. - назад\n>> ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:

			stackMenu();

			break;

		case 2:
			queueMenu();
			break;
		case 3: return 0;
		default:
			break;
		}
	}
}