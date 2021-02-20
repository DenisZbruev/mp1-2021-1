
#include <clocale>
#include <iostream>
#include <cmath>
void clean(void);
void clean(void)//������� ����� �����
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}
#define N 5
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
	Time(int s, int m, int h)//�����������
	{
		seconds = s;
		minutes = m;
		hours = h;
	}
	int getseconds() { return seconds; }//��������?
	int getminutes() {
	return minutes;
	}//������� ��� ������ � ������� ������
	int gethours() { return hours; }
	void set_time() {//��������� �������
		std::cout << "������� ����� - ������� ���, ����� ������ � �������, ������ ��� ������� enter: ";
		std::cin >> hours >> minutes >> seconds;
		while ((hours >= 24)||(hours<0))
		{
			std::cout << "������� ������ ���, ����������� ������: ";
			std::cin >> hours;
		}
		while ((minutes >= 60) || (minutes < 0))
		{
			std::cout << "������� ������� ������, ����������� ������: ";
			std::cin >> minutes;
		}
		while ((seconds >= 60) || (seconds < 0))
		{
			std::cout << "������� ������� �������, ����������� ������: ";
			std::cin >> seconds;
		}
	}
	void raznica()//���������� �������
	{
		int s, m, h;
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
		std::cout <<"�������: "<< abs(hours-h)<<":"<< abs(minutes - m) << ":"<<abs(seconds - s)<<'\n';
	}
	void move()//����� �������
	{
		int s, m, h;
		bool flag;
		std::cout << "���� ������ �������� ����� � ������� �������, ������� 1, ���� � ������� ������� 0: ";
		std::cin >> flag;
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

		while (((flag==1)&&((hours+h) >= 24)) || ((flag == 0) && (((hours - h) < 0))))
		{
			std::cout << "������ ������� ������� ����� �� �����, ����������� ������: ";
			std::cin >> h;
		}
		while (((flag == 1) && ((minutes + m) >= 60)) || ((flag == 0) && ((minutes - m) < 0)))
		{
			std::cout << "������ ������� ������� ����� �� �������, ����������� ������: ";
			std::cin >> m;
		}

		while (((flag == 1) && ((seconds + s) >= 60)) || ((flag == 0) && ((seconds - s) < 0)))
		{
			std::cout << "������ ������� ������� ����� �� ��������, ����������� ������: ";
			std::cin >> s;
		}

		if (flag == 1)
		{
			seconds = seconds + s;
			minutes = minutes + m;
			hours = hours + h;
		}
		else
		{
			seconds = seconds - s;
			minutes = minutes - m;
			hours = hours - h;
		}
	}
};

void main()
{
	int  num, s=0, m=0, h=0;
	bool flag = 1;
	setlocale(LC_ALL, "Russian");
	Time t(s, m, h);//�������� �����������
	while (flag == 1)
	{
		showmenu();
		std::cin >> num;
		switch (num)
		{
		case 1:
			t.set_time();//�������������
			break;
		case 2:
			std::cout << "������� �����: " << t.gethours() << ":" << t.getminutes() << ":" << t.getseconds() << '\n';
			break;
		case 3:
			t.raznica();
			break;
		case 4:
			t.move();
			break;
		case 0:
			flag = 0;
		}
	}	
	system("pause");
}