//init(�����������) 
//���������� � ��������: 
//    ���������� � ������ 
//               � ����� 
//               ����� ������������� �������� 
//    ��������   ���� ������ 
//               ������ 
//               ����� ��������� 
//               ����� �������� 
//               ��� ��������� 
//����� �� ������ 
//����� �� ����� 
//�������� �� ������� 

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
		cout << " 1 - �������� \n 2 - ������� \n 0 - �����" << endl;
		cin >> count;
		switch (count)
		{
		case 1:
			while (count1 != 0)
			{
				cout << " 1 - � ������ \n 2 - � ����� \n 3 - ����� ��������� \n 0 - �����" << endl;
				cin >> count1;
				switch (count1)
				{
				case 1:
					cout << "������� �����: " << endl;
					cin >> data;
					AddBeg(list, data);
					PrintList(list);
					break;
				case 2:
					cout << "������� �����: " << endl;
					cin >> data;
					AddEnd(list, data);
					PrintList(list);
					break;
				case 3:
					cout << "������� ����� ����� �������� ��������: " << endl;
					int FindData;
					cin >> FindData;
					cout << "������� ����� ������� ��������: " << endl;
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
				cout << "1 - ���� ������ \n 2 - ������ \n 3 - ����� ������������� �������� \n 4 - ��� ��������� \n 0 - �����" << endl;
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
					cout << "������� �����: " << endl;
					cin >> data;
					DelAfterFindElem(list, data);
					PrintList(list);
					break;
				case 4:
					cout << "������� �����: " << endl;
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