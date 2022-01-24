#include <iostream>
using namespace std;

template <class T>
struct Node
{
	T data;
	Node<T> *next;
	Node(T data, Node<T> *next)
	{
		this->data = data;
		this->next = next;
	}
};

template <class T>
class LinkedList
{
	Node<T> *head;

public:
	LinkedList()
	{
		head = NULL;
	}
	void insertEnd(T data)
	{
		Node<T> *temp = head;
		if (temp == NULL)
		{
			insertBegin(data);
			return;
		}
		Node<T> *newNode = new Node<T>(data, NULL);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void insertBegin(T data)
	{
		Node<T> *newNode = new Node<T>(data, head);
		head = newNode;
	}
	void insertAfter(T refer, T data)
	{
		Node<T> *newNode = new Node<T>(data, NULL);
		Node<T> *temp = head;
		if (!head)
		{
			throw "Empty list";
		}
		while (temp->data != refer)
		{
			temp = temp->next;
			if (temp == NULL)
				throw "No such refer elem found";
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	void insertBefore(T refer, T data)
	{
		Node<T> *newNode = new Node<T>(data, NULL);
		Node<T> *temp = head;
		if (!head)
		{
			throw "Empty list";
		}
		else if (head->next == NULL)
		{
			// one node list
			if (refer == head->data)
			{
				insertBegin(data);
				return;
			}
			else
				throw "No refer element found";
		}
		else if (head->data == refer)
		{
			insertBegin(data);
			return;
		}
		while (temp->next->data != refer)
		{
			temp = temp->next;
			if (temp->next == NULL)
				throw "No refer element found";
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	void deleteBegin()
	{
		if (!head)
		{
			throw "Empty list";
		}
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
	void deleteEnd()
	{
		if (!head)
		{
			throw "Empty list";
		}
		Node<T> *temp = head;
		Node<T> *prev_temp = temp;
		while (temp->next != NULL)
		{
			prev_temp = temp;
			temp = temp->next;
		}
		if (temp == prev_temp)
		{
			delete temp;
			head = NULL;
		}
		else
		{	delete temp;
			prev_temp->next = NULL;
		}
	}
	void deleteAfter(T data)
	{
		if (!head)
		{
			throw "Empty list";
		}
		else if (head->next == NULL)
		{
			// one node list
			throw "One node list , so cannot delete after.";
		}
		Node<T> *temp = head;
		while (temp->data != data)
		{
			temp = temp->next;
			if (temp->next == NULL)
			{
				throw "No such data elem found";
			}
		}
		Node<T> *temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
	}
	void display()
	{
		Node<T> *temp = head;
		cout << "List is:===========" << endl;
		if (head == NULL)
		{
			cout << "The list is empty";
			return;
		}
		while (temp->next != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << temp->data;
		cout << "\nEnd of list:===========" << endl;
	}
};

int main()
{
	LinkedList<int> l;
	l.insertBegin(34);
	l.insertBegin(364);
	l.insertEnd(4);
	l.insertBegin(341);
	l.insertEnd(78);
	l.display();
	l.insertAfter(341, 72);
	l.insertBefore(34, 27);
	l.display();
	l.deleteBegin();
	l.deleteEnd();
	try
	{
		l.deleteAfter(364);
	}
	catch (const char *e)
	{
		cout << e << endl;
	}

	l.display();
	return 0;
}
