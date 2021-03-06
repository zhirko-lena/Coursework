#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Order  
{
	char operation[3];
	int phone[50];
};
struct Flat 
{
	int room[5];  
	char street[50];
	int square;
	int floor[20];
	int price;

	void ShowFlatInfo()
	{
		cout << "Room: " << room << "\nStreet: " << street << "\nSquare: " << square << "\nFloor: " << floor << "\nPrice: " << price << endl;
		cout << "=================================================" << endl;
	}
};

int CounterOfRows(string path);
void Fill(Flat *Flat_list, int counter, string path);
void ShowFlatList(Flat *Flat_list, int counter, string path);

int main()
{
	int counter = 0;
	string path = "Flat.txt";
	int exit = false;
	int choise = 0;

	counter = CounterOfRows(path);
	Flat *Flat_list = new Flat[counter];
	Fill(Flat_list, counter, path);
	cout << "++++++++++++++++++++ Realestate Base ++++++++++++++++++++" << endl;
	cout << "____________________________________________________________________________________________" << endl << endl;

	for (int i = 0; exit == false; i++)
	{
		cout << "Show database of realestate - 1\nEdit the database of realestate - 2\nShow orders - 3\nClear the screen - 4\nExit - 0" << endl << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			system("cls");
			ShowFlatList(Flat_list, counter, path);
			cout << "\nPress any key to continue..." << endl;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.get();
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("cls");
			break;
		case 0:
			system("cls");
			cout << "Good bye!" << endl << endl;
			exit = true;
			break;
		default:
			cout << "ERROR. Wrong choise, try again" << endl;
			break;
		}
	}



	system("pause");
	return 0;
}

int CounterOfRows(string path) 
{

	ifstream readFile;
	int counter = 0;
	readFile.open(path);
	string data;
	while (!readFile.eof()) 
	{
		getline(readFile, data); 
		counter++;
	}
	return counter;
}

void Fill(Flat *Flat_list, int counter, string path) 
{
	ifstream readFile;
	char data_c;
	readFile.open(path);
	int i = 0;
	int j = 0;

	if (!readFile.is_open())
	{
		cout << "Can't open file" << endl;
	}
	else
	{
		int tmp = 0;
		while (readFile.get(data_c))   
		{
			if (int(data_c) != 47 && int(data_c) != 10 && tmp == 0) 
			{
				
				Flat_list[j].room[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 0) 
			{
				Flat_list[j].room[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 1) 
			{
				Flat_list[j].street[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 1)  
			{
				Flat_list[j].street[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 2)
			{
				Flat_list[j].square[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 2) 
			{
				Flat_list[j].square[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 3)
			{
				Flat_list[j].floor[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 3) 
			{
				Flat_list[j].floor[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================
			else if (int(data_c) != 47 && tmp == 4) 
			{
				Flat_list[j].price[i] = data_c;
				i++;
			}
			else if (int(data_c) == 47 && tmp == 4)
			{
				Flat_list[j].price[i] = '\0';
				i = 0;
				tmp++;
			}
			//================================================================================================================================

		}
	}
	readFile.close();
}


