#include <clocale>
#include <iostream>
#include <cmath>//����� �� ������� ������������ ������ � �������;    ������ ������� � ������� ��� ����� �����;(8x8)    3 ����� - �������������;    6 ����� - ������ ������� ������ �������� ��� ����� 2 ������ ���� Matrix?
#include <cstdlib>
class Matrix//����� 1, ���������� 3
{
	int** matr;
	int size=0;//����� �����
	//int size2 = 0;//����� ��������
public:
	Matrix(int razmer /*int razmer2*/)
	{
		int i, j;
		size = razmer;
		//size2 = razmer2;
		//int* matr = new int[size];
		matr = (int**)malloc(sizeof(int) * size*size);
		for (int i = 0; i < /*size1*/size; i++)
		{
			matr[i] = (int*)malloc(sizeof(int) * size);
		}
		for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			matr[i][j] = 0;
	}
	/*int* new_matrix(int razmer)//���������� ��������� 
	{
		int* matr = new int[razmer];
		return (matr);
	}*/
	void getmatr(int num1, int num2, int elem)//������������� ������� �� ������
	{
		matr[num1][num2] = elem;
	}
	int setmatr(int num1, int num2)//���������� ������� �� ������
	{
		return(matr[num1][num2]);
	}
	~Matrix()
	{
		free (matr);
	}
	int setsize(void)//������ ������
	{
		return(size);
	}
};

void main()
{
	int razmer, /*razmer2*/ num1, num2, elem;
	setlocale(LC_ALL, "Russian");
	std::cout << "������� ����� �����: ";
	std::cin >> razmer;
	/*std::cout << "������� ����� ��������: ";
	std::cin >> razmer2;*/
	Matrix m1(razmer/*razmer2*/);
	std::cout << "������� ����� ��������(������): ";
	std::cin >> num1;
	std::cout << "������� ����� ��������(�������): ";
	std::cin >> num2;
	std::cout << "������� �������: ";
	std::cin >> elem;
	//std::cout << elem;
	m1.getmatr(num1, num2, elem);
	std::cout << "������� ����� ��������, ������� ������ ������(������): ";
	std::cin >> num1;
	std::cout << "������� ����� ��������, ������� ������ ������(�������): ";
	std::cin >> num2;
	elem = m1.setmatr(num1, num2);
	std::cout << elem << '\n';
	razmer = m1.setsize();
	std::cout << razmer <<'x'<< razmer <<'\n';
	system("pause");
}