/*!
\file template.cpp
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <time.h>


using namespace std;

class abstractList
{
public:
	virtual void InsertHead ()=0; //добавление элемента в начало списка
	virtual void GetValue (int n)=0;//получение элемента из списка по его номеру
	virtual int remove (int n)=0; //удаление элемента из списка по номеру
	virtual int add (int n)=0; //добавление элемента в список по номеру
	virtual void printList()=0; //Печать списка

};


template <class T> class list: public abstractList 
{
private:
	list<T>* next;
	T value;

public:
	list() {next=0;};
		/**
			Функция добавления элемента в начало списка
		*/
	void InsertHead () //добавление элемента в начало списка
	{
		
		list *p = new list<T>; //создаем новый элемент
		T a;
		cin>>a;
		p->value = a; //заполняем его.
		p->next=this->next; //Заполняем его 
		this->next = p;

	}
/**
	Функция получения элемента из списка по его номеру
	*/
void GetValue (int n) //получение элемента из списка по его номеру
	{
		list<T> *p= this->next;
		for (int i = 1; i < n; i++)
		{
			p = p->next;
		}
		cout <<p->value <<endl; //"Значение: "
	}

/**
	Функция удаления элемента из списка по номеру
	*/
int remove (int n) //удаление элемента из списка по номеру
	{
		if(n>1){
			list<T> *p = this->next;
			int i;
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				list<T> *tmp = p->next;
				p->next = p->next->next;
				delete tmp;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			if (this->next!=0)
			{	
				list<T> *p = this->next;
				this->next=p->next->next;
				delete p;
				return 0;
			}
			else
			{
				return -1;
			}
		}
	}

/**
	Функция добавление элемента в список по номеру
	*/
int add (int n) //Добавление элемента в список по номеру
	{
		list<T> *p = this->next;
		int i;
		if(n>1)
		{
			T data;
			cin>> data;
			for (i = 1; (i < (n-1)) && (p!=0); i++)
			{
				p = p->next;
			}
			if (p!=0)
			{
				list<T> *newP = new list<T>; //создаем новый элемент
				newP->value = data; //заполняем его.
				newP->next=p->next; //Заполняем его 
				p->next = newP;
				return 0;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			InsertHead();
			return 0;
			
		}
	}


/**
	Функция вывода списка
	*/
	void printList() //"Список: ";
	{
		list<T> *p=this->next;
		while (p)
		{
			cout << p->value<< " ";
			p = p->next;
		}
		cout<<"\n";
	}

};




void testfunc(abstractList *pFirst)
{
	
	int n = 0; //кол-во операций
	cin >> n;

	int data;
	int num;
	char op;
	for (int i = 0; i < n; i++) //изначально, заполним список
	{	
		cin >> op;
		if(op=='a')
		{
			cin >> num;
			//cin >> data;
			if(	pFirst->add(num)<0)
			{
				cout << "Oshibka dobavlenia! Neverniy nomer!";
			}
		}
		else
		if(op=='d')
		{
			cin >> num;
			if(	pFirst->remove(num)<0)
			{
				cout << "Neverniy nomer!";
			}
		}
		
		
	}

};

//!Главная функция
int main()
{
	setlocale(LC_ALL, "rus");

	int couTest;
	cin >> couTest;
	abstractList *testList[10];
	char typeData;
	for (int index=0; index<couTest; index++){
		cin>>typeData;
		if (typeData=='i')
		{
			testList[index] = new list<int>; //указатель на начало списка
			testfunc(testList[index]);
		}
	else
		if (typeData=='s')
		{
			testList[index] = new list<string>; //указатель на начало списка
			testfunc(testList[index]);
		}
			else
		{
			cout<<"Error type!";
		}

	}
	for (int index=0; index<couTest; index++)
	{
		testList[index]->printList(); //указатель на начало списка

	}


	getchar();
	getchar();
	return 0;
};
