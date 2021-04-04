//����������� ����� ����������.
//����� ������ ������� ���������� � �������.������ ����� ����������� ���������� ������� : ��������, ��������, ���������, ����������, ���� ������ � ������(����, �����, ���), �����(� ������).������ �������� ������������ �� �������� � �����.������ �������� �� ������� �����. �� ������ ����� ��������������, �� ���� ���� 2 ������ � ���������� ���������, �� ������ - ���, ��� ����� ������
//����� ������ ��������� ����������� ��������� ������.
//����� ������ ������������� ��������� �������� : 1) �������� �����, 2) �������� ������ ���������� ������, 3) ����� ����� �� �������� � ����, 4) ������ ��� ������ ��������� ���������, 5) ������ ��� ������, �������� � ������ � ��������� ����, 6) ������ �������� ����� ������� � ����������� �������, 7) ������ �������� ����� ������� � ����������� ������� � ��������� ����, 8) ������ ������� ����� �������, 9) ������� �����, 10) ��������� ���������� � ����, 11) ������� ���������� �� �����.
#include <fstream>
#include <clocale>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <windows.h>
#include <string>
#include <conio.h>
#include <vector>
#define N 13//����� ������� � ���� 
using  namespace std;
struct Film
{
	string film_name;//�������� ���� ������ ������ �������������������� ����� 
	string director;//��������
	string screenwriter;//����� ��������
	string musician;//��� �����������
	int year, month, day;//���� ������
	int fees;//�����
};
class Filmoteka
{
	int size;//����� ������� � ����������
	std::vector<struct Film> F;
public:
	Filmoteka(int razmer)
	{
		size = razmer;
	}
	void set_in_file(string name_of_file)//���������� ���������� � ����
	{
		ofstream fout;
		fout.open(name_of_file);
		size = F.size();
		for (int i = 0; i < size; i++)
		{
			fout << F[i].film_name << '\n';
			fout << F[i].director << '\n';
			fout << F[i].year << '\n';
			fout << F[i].fees << '\n';
		}
		fout.close();
	}
	void get_from_file(string name_of_file)
	{
		ifstream fin(name_of_file);
		struct Film Temp;
		F.clear();
		for (int i = 0; i < size; i++)
		{
			fin.get();
			getline(fin, Temp.film_name);
			fin >> Temp.year;
			fin >> Temp.fees;
			F.push_back(Temp);
		}
		size = F.size();
		fin.close();
	}
	void delete_film(string name, int year)//������� �����
	{
		int i = 0, delete_num;
		std::vector<struct Film> TMP;
		while (i < size)//������� ����� ����� �������� 
		{
			if ((F[i].film_name == name) && (F[i].year == year))
			{
				break;
			}
			i++;
		}
		delete_num = i;
		size--;//��������� �� 1 ������
		for (i = 0; i < delete_num; i++)//��������� � tmp ��� ����� ������� s �� ������ tmp_num; +1
		{
			TMP.push_back(F[i]);// = F[i];
		}
		for (i = delete_num + 1; i < size; i++)//��������� � tmp ��� ����� ������� s ����� ������ tmp_num; +1
		{
			TMP.push_back(F[i - 1]);
		}
		F.clear();
		//����� ����������� ������ s �������� �� 1 ������� � ������������ � ���� ��� �������� tmp
		for (i = 0; i < size; i++)
		{
			F.push_back(TMP[i]);
		}
		TMP.clear();//������� ������ ���������� ������� �� ������ ��������
	}
	void setfilm(struct Film Temp)//�������� �����
	{
		int i;
		if (F.empty() == true)// ���� ������ ��� ����
		{
			size++;
			F.push_back(Temp);
		}
		else {
			std::vector<struct Film> TMP;
			i = 0;
			while ((F[i].film_name > Temp.film_name) && (i < size))//������� ����� ����� ��������    (s[i] >temp)
			{
				i++;
			}
			int tmp_num;//==i
			while ((F[i].film_name == Temp.film_name) && (i < size))//���������� ������� ��� ������ ����� �� ����
			{
				if (F[i].year > Temp.year)//S[i+1].year>Temp.year
				{
					break;
				}
				i++;
			}
			tmp_num = i;
			size++;
			for (i = 0; i < tmp_num; i++)//��������� � tmp ��� ����� ������� s �� ������ tmp_num; +1
			{
				TMP.push_back(F[i]);// = F[i];
			}
			TMP.push_back(Temp);
			for (i = tmp_num + 1; i < size; i++)//��������� � tmp ��� ����� ������� s ����� ������ tmp_num; +1
			{
				TMP.push_back(F[i - 1]);
			}
			F.clear();
			//����� ����������� ������ s �������� �� 1 ������� � ������������ � ���� ��� �������� tmp
			for (i = 0; i < size; i++)
			{
				F.push_back(TMP[i]);
			}
			//F = TMP;
			TMP.clear();//������� ������ ���������� ������� �� ������ ��������
		}
	}
	vector <struct Film> get_films_of_director(string director)//������ ��� ������ ��������� ���������
	{
		int i;
		std::vector<struct Film> TMP;
		for (i = 0; i < size; i++)//��������� � tmp ��� ����� ������� s ����� ������ tmp_num; +1
		{
			if (F[i].director == director)
			{
				TMP.push_back(F[i]);
			}
		}
		return(TMP);
		TMP.clear();
	}
	struct Film find_film_by_name_and_year(string name, int year)//����� ����� �� �������� � ����
	{
		int i;
		struct Film film;
		for (i = 0; i < size; i++)//��������� � tmp ��� ����� ������� s ����� ������ tmp_num; +1
		{
			if ((F[i].year == year)&&(F[i].film_name==name))
			{
				film= F[i];
				break;
			}
		}
		return(film);
	}
	vector <struct Film> get_films_in_year(int year)
	{
		int i;
		std::vector<struct Film> TMP;
		for (i = 0; i < size; i++)//��������� � tmp ��� ����� ������� s ����� ������ tmp_num; +1
		{
			if (F[i].year == year)
			{
				TMP.push_back(F[i]);
			}
		}
		return(TMP);
		TMP.clear();
	}
	vector <struct Film> get_films_with_max_fees(int num_films_with_max_fees)
	{
		int i, size_copy = size, j, max_fees, elem_num;
		std::vector<struct Film> COPY;//COPY-����� ������� F  
		std::vector<struct Film> MAX_FEES;//��������� ������
		COPY = F;
		for (i = 0; i < num_films_with_max_fees; i++)//   while (MAX_FEES.size() < num_films_with_max_fees)
		{
			max_fees = 0;
			size_copy = COPY.size();
			for (j = 0; j < size_copy; j++)
			{
				if (COPY[j].fees > max_fees)//>
				{
					max_fees = COPY[j].fees;
				}
			}//����� �������� ��������
			for (j = 0; j < size_copy; j++)//������� ����� ����� �������� 
			{
				if (COPY[j].fees == max_fees)
				{
					break;
				}
				j++;
			}
			elem_num = j;
			MAX_FEES.push_back(COPY[elem_num]);
			//������� �� COPY ������� � ������� elem_num
			swap(COPY[elem_num], COPY.back());
			COPY.pop_back();
		}
		COPY.clear();
		return(MAX_FEES);
		MAX_FEES.clear();

	}
	vector <struct Film> get_films_with_max_fees_in_year(int num_films_with_max_fees, int year)
	{
		int i, size_copy, j, max_fees, elem_num;
		std::vector<struct Film> COPY;//COPY-����� ������� F  
		std::vector<struct Film> MAX_FEES;//��������� ������
		for (i = 0; i < size; i++)
		{
			if (F[i].year == year)
				COPY.push_back(F[i]);
		}
		size_copy = COPY.size();
		for (i = 0; i < num_films_with_max_fees; i++)//   while (MAX_FEES.size() < num_films_with_max_fees)
		{
			max_fees = 0;
			size_copy = COPY.size();
			for (j = 0; j < size_copy; j++)
			{
				if (COPY[j].fees > max_fees)//>
				{
					max_fees = COPY[j].fees;
				}
			}//����� �������� ��������
			for (j = 0; j < size_copy; j++)//������� ����� ����� �������� 
			{
				if (COPY[j].fees == max_fees)
				{
					break;
				}
				j++;
			}
			elem_num = j;
			MAX_FEES.push_back(COPY[elem_num]);
			//������� �� COPY ������� � ������� elem_num
			swap(COPY[elem_num], COPY.back());
			COPY.pop_back();
		}
		COPY.clear();
		return(MAX_FEES);
		MAX_FEES.clear();

	}
	int search_num_of_film(struct Film Temp)
	{
		int film_num, i=0;
		while ((F[i].film_name == Temp.film_name) && (i < size))//���������� ������� ��� ������ ����� �� ����
		{
			if (F[i].year > Temp.year)//S[i+1].year>Temp.year
			{
				break;
			}
			i++;
		}
		film_num = i;
		return(film_num);
	}
	void change_data_film(struct Film Temp, int film_num)
	{
		F.push_back(Temp);//��������� � ����� ������������ �����
		swap(F[film_num], F.back());//������ ��� ������ � ������� �������
		F.pop_back();//�������� ���������� ������
	}
	vector <struct Film> get_all_films()
	{
		return(F);
	}
	int get_size()
	{
		size = F.size();
		return (size);
	}
	~Filmoteka()
	{
		F.clear();
	}
};
void print(struct Film F)//�������� 1 �����
{
	std::cout << "�������� ������: ";
	std::cout << F.film_name << '\n';
	std::cout << "��� ���������: ";
	std::cout << F.director << '\n';
	std::cout << "��� ����������: ";
	std::cout << F.screenwriter << '\n';
	std::cout << "��� ����������: ";
	std::cout << F.musician << '\n';
	std::cout << "���� ������ � ������: ����, �����, ��� ";
	std::cout << F.year << '\n';
	std::cout << "���: ";
	std::cout << F.year << '\n';
	std::cout << "�����: ";
	std::cout << F.fees << '\n' << '\n'; 
	string musician;//��� �����������
	int year, month, day;//���� ������

}
void print(vector <struct Film> F)//�������� ������ �������
{
	int size = F.size();
	for (int i = 0; i < size; i++)
	{
		/*std::cout << "�������� ������: ";
		std::cout << F[i].film_name << '\n';
		std::cout << "��� ���������: ";
		std::cout << F[i].director << '\n';
		std::cout << "���: ";
		std::cout << F[i].year << '\n';
		std::cout << "�����: ";
		std::cout << F[i].fees << '\n' << '\n';*/
		print(F[i]);
	}
}
void showmenu()
{
	char* menu[N] = { "�������� ����� ", "�������� ������ ���������� ������", "����� ����� �� �������� � ����", "������ ��� ������ ��������� ���������", "������ ��� ������, �������� � ������ � ��������� ����", 
		"������ �������� ����� ������� � ����������� �������", "������ �������� ����� ������� � ����������� ������� � ��������� ����", 
		"������ ������� ����� �������", "������� �����", "��������� ���������� � ����", "������� ���������� �� �����", "������� �� ����� ��� ������ ", "�����"};//������ � ���������� ��������
	short int menu_number[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0 };//������ � �������� ������� ������ ����
	int i;
	std::cout << "��������: " << '\n';
	for (i = 0; i < N; i++)
	{
		std::cout << menu_number[i] << ". ";
		std::cout << menu[i] << '\n';
	}
	std::cout << "������� ����� ��������, ������� ���������� ���������: ";
}
void main()
{
	int i, num = 1, size = 0, num_films_with_max_fees, num_operation = 1, film_num;//��� ������� ������������ ��������, ��������� �� �������� ������������� �����, razmer=0
	class Filmoteka Filmoteka1(size);
	struct Film Temp, film;//film-����� ��� 3 ������
	string name_of_file;
	vector <struct Film> F;//������, � ������� ������������ ������ ��� ������ ������� ������ 
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	i = 0;
	while (num != 0)// razmer != 3
	{
		//std::cout << "������� ����� ������ (0, ���� ������ ���������; 1, ���� ������ �������� ������; 2, ���� ������ �������� ��� ������, 3-���� ������ ������� �����, 4-���� ������ ������ ��� ������ ������� ���������): ";
		showmenu();
		std::cin >> num;
		if (num == 0)
			break;
		switch (num)
		{
		case 1://�������� �����
			std::cin.get();
			std::cout << "������� �������� ������: "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, Temp.film_name);
			std::cout << "������� ��� ���������: "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, Temp.director);
			std::cout << "������� ��� ������ � ������: ";
			std::cin >> Temp.year;
			std::cout << "������� �������� ����� ������: ";
			std::cin >> Temp.fees;
			Filmoteka1.setfilm(Temp);
			break;
		case 2://�������� ������ ������
			std::cin.get();
			std::cout << "������� �������� ������, ������� ���������� ��������: ";
			std::getline(std::cin, Temp.film_name);
			std::cout << "������� ��� ������ � ������: ";
			std::cin >> Temp.year;//��� ����� ����� ����� � ��������� ��� Temp
			Temp = Filmoteka1.find_film_by_name_and_year(Temp.film_name, Temp.year);
			film_num = Filmoteka1.search_num_of_film(Temp);
			while (num_operation!=0)
			{
				std::cout << "������� 0, ���� ������ ��������� �����";
				std::cout << "������� 1, ���� ������ �������� �������� ������" << '\n';
				std::cout << "������� 2, ���� ������ �������� ��� ���������" << '\n';
				std::cout << "������� 3, ���� ������ �������� ��� ����������" << '\n';
				std::cout << "������� 4, ���� ������ �������� ��� �����������" << '\n';
				std::cout << "������� 5, ���� ������ �������� ���� ������ � ������" << '\n';
				std::cout << "������� 6, ���� ������ �������� ���� ����� � ������" << '\n';
				std::cin >> num_operation;
				switch (num_operation)
				{
				case 1:
					std::cin.get();
					std::cout << "������� ���������� �������� ������: "; //����������  ���������� �������� �������� �������
					std::getline(std::cin, Temp.film_name);
					break;
				case 2:
					std::cin.get();
					std::cout << "������� ���������� ��� ���������: ";
					std::getline(std::cin, Temp.director);
					break;
				case 3:
					std::cin.get();
					std::cout << "������� ���������� ��� ����������: ";
					std::getline(std::cin, Temp.screenwriter);
					break;
				case 4:
					std::cin.get();
					std::cout << "������� ���������� ��� �����������: ";
					std::getline(std::cin, Temp.musician);
					break;
				case 5:
					std::cout << "������� ���������� ����� ���: ";
					std::cin >> Temp.day;
					std::cout << "������� ���������� ����� ������: ";
					std::cin >> Temp.month;
					std::cout << "������� ���������� ���: ";
					std::cin >> Temp.year;
					break;
				case 6:
					std::cout << "������� ���������� ����� �������� ������ (� ������): ";
					std::cin >> Temp.fees;
				}
				Filmoteka1.change_data_film(Temp, film_num);
			}
		    //�������� ���� ������
			break;
		case 3://����� ����� �� �������� � ����
			std::cin.get();
			std::cout << "������� �������� ������, ������� ���������� �����: "; 
			std::getline(std::cin, Temp.film_name);
			std::cout << "������� ��� ������ � ������: ";
			std::cin >> Temp.year;
			film=Filmoteka1.find_film_by_name_and_year(Temp.film_name, Temp.year);
			print(film);
			break;
		case 4://������ ��� ������ ��������� ��������� 
			F.clear();
			std::cin.get();
			std::cout << "������� ��� ���������: "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, Temp.director);
			F = Filmoteka1.get_films_of_director(Temp.director);
			print(F);
			break;
		case 5://������ ��� ������, �������� � ������ � ��������� ����
			F.clear();
			std::cout << "������� ��� ������ ������ � ������: ";
			std::cin >> Temp.year;
			F = Filmoteka1.get_films_in_year(Temp.year);
			print(F);
			break;
		case 6: //������ �������� ����� ������� � max �������
			F.clear();
			std::cout << "������� ����� ������� � ������������� �������: ";
			std::cin >> num_films_with_max_fees;
			F = Filmoteka1.get_films_with_max_fees(num_films_with_max_fees);
			print(F);
			break;
		case 7://������ �������� ����� ������� � max ������� � ��������� ����
			F.clear();
			int year;
			std::cout << "������� ����� ������� � ������������� �������: ";
			std::cin >> num_films_with_max_fees;
			std::cout << "������� ���, �� ������� ������ �������� ������: ";
			std::cin >> year;
			F=Filmoteka1.get_films_with_max_fees_in_year(num_films_with_max_fees, year);
			print(F);
			break;
		case 8: //������ ������
			size = Filmoteka1.get_size();
			std::cout << "������� ����� �������: " << size;
			break;
		case 9://������� �����
			std::cin.get();
			std::cout << "������� �������� ������: "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, Temp.film_name);
			std::cout << "������� ��� ������ ������ � ������: ";
			std::cin >> Temp.year;//���������� ���� ��������� Temp, ����� �� �������� ������ ��� ������ � ��������� ������ � ����� ���� int - ���
			Filmoteka1.delete_film(Temp.film_name, Temp.year);
			break;
		case 10://��������� ���������� � ����
			std::cin.get();
			std::cout << "������� ��� �����, �������� ��� ���������� (�������� .txt): "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, name_of_file);
			Filmoteka1.set_in_file(name_of_file);
			break;
		case 11://��������� ���������� � ����
			/*bool flag;
			std::cout << "���������! ������ �������� ������� ����������! ������ ���������� (���� ��, ������� 1, ����� 0): ";
			std::cin >> flag;
			if (flag == true)
			{*/
			std::cin.get();
			std::cout << "������� ��� �����, �������� ��� ���������� (�������� .txt): "; //����������  ���������� �������� �������� �������
			std::getline(std::cin, name_of_file);
			Filmoteka1.get_from_file(name_of_file);
			//}
			break;
		case 12://������� �� ����� ��� ������
			F.clear();
			F = Filmoteka1.get_all_films();
			print(F);
			break;
		}
	}
	F.clear();
	system("pause");//strcmp (str1, str2)-��������� 2 ������
}