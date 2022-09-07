// V2_Kabel_gournal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//http://blog.kislenko.net/show.php?id=1402
#include<Windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
	string lisp_1;
	string lisp_2;
	string lisp_3;
	string string_sum1;
	string string_sum2;
	string string_sum3;
	int count_1{ 0 };
	int count_2{ 0 };
	//setlocale(LC_ALL, "RUS");
	//system("chcp 1251"); // настраиваем кодировку консоли
	ifstream file;            // создать поточный объект file
	file.open("test.txt");    // открыть файл на чтение
	if (!file) return 1;      // возврат по ошибке отрытия
	char str[40];             // статический буфер строки
	// Считывать и отображать строки в цикле, пока не eof
	while (!file.getline(str, sizeof(str)).eof())
	{
		cout << str << endl;     // вывод прочитанной строки на экран
		count_1++;
	}
	cout << "count_1 = " << count_1 << endl;
		//cin.sync();
	//cin.get();
	ifstream input("test.txt"); //Открываешь первый файл для чтения
	string string_buf; //Строка-буфер
	ofstream output("output.txt"); //Открываешь второй файл для записи
	while (getline(input, string_buf))  //Считываешь из файла строку (пока не EOF)End Of File
	{
		if (getline(input, string_buf, '<'))
		{
			
			lisp_1 = "(command \"_.-layer\" \"_m\" \""; // строка из лиспа для автокада - начало
			lisp_1.append(string_buf); // складываем строку из файла и строку lisp1
			lisp_2 = "\" \"\") (vla-InsertBlock obj(vlax-3D-point '(4000 107376 0))  \"";// строка из лиспа для автокада - середина
			lisp_1.append(lisp_2); // складываем строку из файла и строку lisp2
		}
	
		if (getline(input, string_buf,'>'))
		{
			lisp_1.append(string_buf);
			lisp_3 = "\" 1 1 1 0)";// строка из лиспа для автокада - конец
			lisp_1.append(lisp_3);
			cout << endl;
			//string_sum3 = lisp_3 + string_buf; // складываем строку из файла и строку lisp3
		}
			cout << lisp_1 << endl;
			output << lisp_1 << endl;  //И записываешь эту строку в выходной файл	
			count_2++;	
	}
	cout << "count_2 = " << count_2 << endl;
	input.close();
	output.close();
	system("pause");
	return 0;
}

