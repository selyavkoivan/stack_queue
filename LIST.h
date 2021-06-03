#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <class A>
struct LIST {
	A* first;
	A* last;
	int count;
	
	LIST()
	{
		this->first = this->last = NULL;

		count = 0;
	}

	void add(A* newElement)
	{

		if (!this->count)
		{
			this->last = this->first = newElement;
		}
		else
		{
			this->last->next = newElement;
			this->last = this->last->next;
		}
		this->count++;

	}
	void print()
	{

		A* currentElement = this->first;
		while (currentElement != this->last->next)
		{
			currentElement->output();
			currentElement = currentElement->next;
		}
	}

	void fread(string fileName)
	{
		cout << "ferf";
		ifstream file(fileName);
		if (!file.is_open()) return;
		while (!file.eof())
		{
			A* newEl = new A;
			newEl->fread(file);
			this->add(newEl);

		}
		file.close();

	}


	void fwrite(string fileName)
	{


		if (!this->count)
		{
			remove(fileName.c_str());
			return;
		}
		else
		{

			ofstream file(fileName);
			A* currentPosition = new A;
			currentPosition = this->first;
			while (currentPosition != this->last->next)
			{

				currentPosition->fwrite(file);

				currentPosition = currentPosition->next;
			}


			file.close();
		}

	}

	void del(A* delData)
	{
		A* currentState = new A;
		currentState = this->first;
		if (currentState->compare(delData))
		{
			if (currentState == this->last && currentState == this->first)
			{
				delete currentState;
				this->first == this->last == NULL;
				this->count--;

				return;
			}
			else
			{

				this->first = this->first->next;
				delete currentState;
				this->count--;
				return;
			}
		}
		while (currentState != this->last->next)
		{

			if (currentState->next->compare(delData))
			{

				if (currentState->next == this->last)
				{
					delete currentState->next;
					this->last = currentState;
					this->count--;

					return;
				}
				A* a = currentState->next;
				currentState->next = currentState->next->next;
				this->count--;
				delete a;
				return;
			}
			currentState = currentState->next;
		}
	}
	A* check(A* newEl)
	{

		A* iterator = new A;
		iterator = this->first;
		while (iterator != this->last->next)
		{
			if (iterator->compare(newEl))
			{

				return iterator;
			}
			iterator = iterator->next;
		}

		return NULL;


	}

};
