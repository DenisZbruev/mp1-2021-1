#include <clocale>
#include <iostream>
#include <cmath>//����� �� ������� ������������ ������ � �������;    ������ ������� � ������� ��� ����� �����;(8x8)    3 ����� - �������������;    6 ����� - ������ ������� ������ �������� ��� ����� 2 ������ ���� Matrix?
class Matrix//����� 1, ���������� 3
{
	int* matr;
public:
	/*int* new_matrix(int razmer)//���������� ��������� 
	{
		int* matr = new int[razmer];
		return (matr);
	}*/
	void getmatr(int num, int elem)//������������� ������� �� ������
	{
		matr[num] = elem;
	}
	int setmatr(int num)//���������� ������� �� ������
	{
		return(matr[num]);
	}
	Matrix(int razmer)
	{
		int i;
		int *matr = new int[razmer];
		for (i = 0; i < razmer; i++)
			matr[i] = 0;
	}
};

void main()
{
	int razmer, num, elem;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ������: ";
	std::cin >> razmer;
	//std::cout << razmer;
	Matrix m1(razmer);
	std::cout << "������� ����� ��������: ";
	std::cin >> num;
	std::cout << "������� �������: ";
	std::cin >> elem;
	//std::cout << elem;
	m1.getmatr(num, elem);
	std::cout << "������� ����� ��������, ������� ������ ������: ";
	std::cin >> num;
	elem = m1.setmatr(num);
	std::cout << elem << '\n';
	system("pause");
}