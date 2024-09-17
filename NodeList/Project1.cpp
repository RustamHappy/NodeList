//init(конструктор) 
//добавление и удаление: 
//    добавление В начало 
//               В конец 
//               после определенного элемента 
//    удаление   Весь список 
//               голова 
//               после заданного 
//               после элемента 
//               все вхождения 
//Поиск по списку 
//вывод на экран 
//проверка на пустоту 

#include<iostream>
#include"Fun.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int count = -1;
	int count1 = -1;
	int count2 = -1;
	Node* list = new Node;
	init(list);
	int data;
	while (count != 0)
	{
		cout << " 1 - добавить \n 2 - удалить \n 0 - Выход" << endl;
		cin >> count;
		switch (count)
		{
		case 1:
			while (count1 != 0)
			{
				cout << " 1 - В начало \n 2 - В конец \n 3 - после заданного \n 0 - назад" << endl;
				cin >> count1;
				switch (count1)
				{
				case 1:
					cout << "Введите число: " << endl;
					cin >> data;
					AddBeg(list, data);
					PrintList(list);
					break;
				case 2:
					cout << "Введите число: " << endl;
					cin >> data;
					AddEnd(list, data);
					PrintList(list);
					break;
				case 3:
					cout << "Введите число после которого вставить: " << endl;
					int FindData;
					cin >> FindData;
					cout << "Введите число которое вставить: " << endl;
					cin >> data;
					AddFindElem(list, FindData, data);
					PrintList(list);
					break;
				}
			}
			count1 = -1;
			break;
		case 2:
			while (count2 != 0)
			{
				cout << "1 - Весь список \n 2 - Голова \n 3 - После определенного элемента \n 4 - все вхождения \n 0 - назад" << endl;
				cin >> count2;
				switch (count2)
				{
				case 1:
					DelAll(list);
					PrintList(list);
					break;
				case 2:
					DelHead(list);
					PrintList(list);
					break;
				case 3:
					cout << "Введите число: " << endl;
					cin >> data;
					DelAfterFindElem(list, data);
					PrintList(list);
					break;
				case 4:
					cout << "Введите число: " << endl;
					cin >> data;
					DelAllOcc(list, data);
					PrintList(list);
					break;
				}
			}
			count2 = -1;
			break;
		}
	}
}