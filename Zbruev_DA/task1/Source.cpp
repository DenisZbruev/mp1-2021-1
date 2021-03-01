
#include <clocale>
#include <iostream>
#include <cmath>
#define N 5//����� ������� � ���� 
void showmenu()
{
	char* menu[N] = { "���������� ����� (�� ��������� ����� ����� 0:0:0)", "������ �����", "��������� ������� ����� �������� �������� � ������������� (� �����, ������� � ��������)", "�������� ����� �� �������� ��������", "�����"};//������ � ���������� ��������
	short int menu_number[N] = { 1, 2, 3, 4, 0};//������ � �������� ������� ������ ����
	int i;
	std::cout << "��������: "<<'\n';
	for (i = 0; i < N; i++)
	{
		std::cout << menu_number[i]<<". ";
		std::cout << menu[i] << '\n';
	}
	std::cout << "������� ����� ��������, ������� ���������� ���������: ";
}
class Time
{
	int seconds;
	int minutes;
	int hours;
public:
	Time(int h, int m, int s)//�����������
	{
		seconds = s;
		minutes = m;
		hours = h;
	}
	int getseconds() { return seconds; }
	int getminutes() {return minutes;}
	int gethours() {return hours; }//������� ��� ������ � ������� ������(������ �����)
	void settime(int h, int m, int s)//��������� �������
	{
		seconds = s;
		minutes = m;
		hours = h;
	}
	
	int raznica(int h, int m, int s)//���������� �������
	{
		int sum1=0;
		int sum2 = 0;
		sum1 = h * 3600 + m * 60 + s;//����� ������ ��� �������, ����������� � ������ 
		sum2 = hours * 3600 + minutes * 60 + seconds;//����� ������ ��� �������, ���������� � ����������
		return (sum1-sum2);//���������� ������� � �������� 
	}
	int move(int h, int m, int s, bool flag)//����� �������
	{
		while (((flag==1)&&((hours+h) >= 24)) || ((flag == 0) && (((hours - h) < 0))))
		{
			return 1;//�� ������������� ����� �������� � main ��������, ������� �� ����� ������ (����, ������, �������) 
		}
		while (((flag == 1) && ((minutes + m) >= 60)) || ((flag == 0) && ((minutes - m) < 0)))
		{
			return 2;
		}

		while (((flag == 1) && ((seconds + s) >= 60)) || ((flag == 0) && ((seconds - s) < 0)))
		{
			return 3;
		}

		if (flag == 1)
		{
			seconds = seconds + s;
			minutes = minutes + m;
			hours = hours + h;
			return 0;//���� ��� ������, ���������� 0
		}
		else
		{
			seconds = seconds - s;
			minutes = minutes - m;
			hours = hours - h;
			return 0;//���� ��� ������, ���������� 0
		}
	}
};
void main()
{
	int  num, s=0, m=0, h=0, sum=0;
	bool flag = 1;//���� ��� ����
	bool f;//���� ��� 4 ������
	setlocale(LC_ALL, "Russian");
	Time t(s, m, h);//�������� �����������
	while (flag == 1)
	{
		showmenu();
		std::cin >> num;
		switch (num)
		{
		case 1: //������������� ����� 
			std::cout << "������� ����� - ������� ���, ����� ������ � �������, ������ ��� ������� enter: ";
			std::cin >> h >> m >> s;
			while ((h >= 24) || (h < 0))//������������ ��������
			{
				std::cout << "������� ������ ���, ����������� ������: ";
				std::cin >> h;
			}
			while ((m >= 60) || (m < 0))
			{
				std::cout << "������� ������� ������, ����������� ������: ";
				std::cin >> m;
			}
			while ((s >= 60) || (s < 0))
			{
				std::cout << "������� ������� �������, ����������� ������: ";
				std::cin >> s;
			}
			t.settime(h, m, s);
			break;
		case 2://������ ����� 
			std::cout << "������� �����: " << t.gethours() << ":" << t.getminutes() << ":" << t.getseconds() << '\n';
			break;
		case 3://���������� �������
			std::cout << "������� ����� - ������� ���, ����� ������ � �������, ������ ��� ������� enter: ";
			std::cin >> h >> m >> s;
			while ((h >= 24) || (h < 0))
			{
				std::cout << "������� ������ ���, ����������� ������: ";
				std::cin >> h;
			}
			while ((m >= 60) || (m < 0))
			{
				std::cout << "������� ������� ������, ����������� ������: ";
				std::cin >> m;
			}
			while ((s >= 60) || (s < 0))
			{
				std::cout << "������� ������� �������, ����������� ������: ";
				std::cin >> s;
			}
			sum=t.raznica(h, m, s);
			h = sum / 3600;
			sum = sum % 3600;
			if (h > 23)
				h = h % 24;
			m = sum / 60;
			sum = sum % 60;
			s = sum;
			std::cout << "�������: " << h <<':'<<m<< ':'<< s<<'\n';
			break;
		case 4://����� �������
			std::cout << "���� ������ �������� ����� � ������� �������, ������� 1, ���� � ������� ������� 0: ";
			std::cin >> f;
			std::cout << "������� �������� ������� - ������� ���, ����� ������ � �������, ������ ��� ������� enter: ";
			std::cin >> h >> m >> s;
			while ((h >= 24) || (h < 0))
			{
				std::cout << "������� ������ ���, ����������� ������: ";
				std::cin >> h;
			}
			while ((m >= 60) || (m < 0))
			{
				std::cout << "������� ������� ������, ����������� ������: ";
				std::cin >> m;
			}
			while ((s >= 60) || (s < 0))
			{
				std::cout << "������� ������� �������, ����������� ������: ";
				std::cin >> s;
			}
			t.move(s, m, h, f);

			while (t.move(h, m, s, f) != 0)
			{
				if(t.move(h, m, s, f)==1)
				{
					std::cout << "������ ������� ������� ����� �� �����, ����������� ������: ";
					std::cin >> h;
				}
				if (t.move(h, m, s, f) == 2)
				{
					std::cout << "������ ������� ������� ����� �� �������, ����������� ������: ";
					std::cin >> m;
				}
				if (t.move(h, m, s, f) == 3)
				{
					std::cout << "������ ������� ������� ����� �� ��������, ����������� ������: ";
					std::cin >> s;
				}
			}
			break;
		case 0:
			flag = 0;
		}
	}	
	system("pause");
}