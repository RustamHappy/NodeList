#include<iostream>
#include"Fun.h"

using namespace std;



void init(Node* head)
{
	head->data = 0;
	head->next = nullptr;
}

void AddBeg(Node*& head, int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void AddEnd(Node* head, int data)
{
	Node* temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	Node* LastElem = new Node;
	LastElem->data = data;
	temp->next = LastElem;
	LastElem->next = nullptr;
}

void AddFindElem(Node* head, int FindData, int data)
{
	Node* temp = FindElem(head, FindData);
	if (temp == nullptr)
	{
		cout << "Элемент не найден" << endl;
		return;
	}
	Node* Elem = new Node;
	Elem->data = data;
	Elem->next = temp->next;
	temp->next = Elem;
}





void DelAll(Node*& head)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}
	Node* current = head;
	Node* temp;
	while (current != nullptr)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
	current = nullptr;
	temp = nullptr;

}

void DelHead(Node*& head)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}

	Node* temp = head;
	head = head->next;
	delete temp;
}

void DelAfterFindElem(Node* head, int data)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}

	Node* temp = FindElem(head, data);
	if (temp == head)
	{
		DelHead(head);
	}
	else
	{
		Node* NodeToDel = temp->next;
		temp->next = NodeToDel->next;
		delete NodeToDel;
	}
}

void DelElem(Node* temp)
{
	if (isEmpty(temp))
	{
		cout << "Список пуст" << endl;
		return;
	}

	Node* NodeToDel = temp->next;
	temp->next = NodeToDel->next;
	delete NodeToDel;
}

void DelAllOcc(Node*& head, int data)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}

	while (head && head->data == data)
	{
		DelHead(head);
	}
	Node* temp = head;
	while (temp && temp->next)
	{
		if (temp->next->data == data)
		{
			DelElem(temp);
		}
		else
		{
			temp = temp->next;
		}
	}
}




void PrintList(Node*& head)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}
	Node* temp = head;
	int i = 1;
	while (temp != nullptr)
	{
		cout << i << ": " << temp->data << endl;
		i++;
		temp = temp->next;
	}
	cout << endl;
}

bool isEmpty(Node* head)
{
	return (head == nullptr);
}

Node* FindElem(Node* head, int data)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return nullptr;
	}

	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->data == data)
		{
			return temp;
		}
		temp = temp->next;
	}
	cout << "Элемент не найден" << endl;
	return nullptr;
}

void DelAllOcc2(Node*& head)
{
	if (isEmpty(head))
	{
		cout << "Список пуст" << endl;
		return;
	}

	Node* StandTemp = head;
	bool isDuplicate = false;
	while (StandTemp)
	{
		Node* GoTemp = StandTemp;
		while (GoTemp->next != nullptr)
		{
			if (GoTemp->next->data == StandTemp->data)
			{
				isDuplicate = true;
				break;
			}
			else
			{
				GoTemp = GoTemp->next;
			}
		}
		if (isDuplicate)
		{
			DelAllOcc(head, StandTemp->data);
			isDuplicate = false;
			StandTemp = head;
		}
		else
		{
			StandTemp = StandTemp->next;
		}
	}
}