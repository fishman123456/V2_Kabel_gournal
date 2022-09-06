// V2_Kabel_gournal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//http://blog.kislenko.net/show.php?id=1402

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	//setlocale(LC_ALL, "RUS");
	//system("chcp 1251"); // настраиваем кодировку консоли
	ifstream file;            // создать поточный объект file
	file.open("test.txt");    // открыть файл на чтение
	if (!file) return 1;      // возврат по ошибке отрытия
	char str[80];             // статический буфер строки
	// Считывать и отображать строки в цикле, пока не eof
	while (!file.getline(str, sizeof(str)).eof())
		cout << str << endl;     // вывод прочитанной строки на экран
	cin.sync(); cin.get();
	ifstream input("test.txt"); //Открываешь первый файл для чтения
	string string; //Строка-буфер
	ofstream output("output.txt"); //Открываешь второй файл для записи
	while (getline(input, string, ' '))  //Считываешь из файла строку (пока не EOF)End Of File
		output << string << endl;  //И записываешь эту строку в выходной файл
	system("pause");
	return 0;
}

