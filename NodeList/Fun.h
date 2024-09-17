#pragma once

struct Node
{
	int data;
	Node* next;
};


//Инициализация

void init(Node* head);


//Добавление

void AddBeg(Node*& head, int data);

void AddEnd(Node* head, int data);

void AddFindElem(Node* head, int FindData, int data);


//Удаление

void DelAll(Node*& head);

void DelHead(Node*& head);

void DelAfterFindElem(Node* head, int data);

void DelElem(Node* temp);

void DelAllOcc(Node*& head, int data);


//Доп функции

bool isEmpty(Node* head);

void PrintList(Node*& head);

Node* FindElem(Node* head, int data);

void DelAllOcc2(Node*& head);