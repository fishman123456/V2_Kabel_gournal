// V2_Kabel_gournal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//http://blog.kislenko.net/show.php?id=1402
// в качестве разделителя используем знаки < > имя слоя и имя блока на одной строке 
// 7.HA-S1<siren>
// Надо добавить в программу сборку строк это начо файла
//  (defun C : F_Blockinsert(/ x1 x2 x3)
//	(setq actdoc(vla - get - ActiveDocument(vlax - get - acad - object)))
//	(setq obj(vla - get - ModelSpace actdoc))
//	(setq x1 1); начальное значение списка равно нулю, потом его увеличиваем на еденицу и получаем список
//	(setq x2 1); на сколько будем увеличивать порядковый номер элемента списка
//	; Запоминаем текущее состояние режимов ORTHO, SNAP И OSNAP
//	(setq	old_ortho(getvar "ORTHOMODE")
//		old_snap(getvar "SNAPMODE")
//		old_osnap(getvar "OSMODE")
//	)
//	; отключаем режимы ORTHO, SNAP И OSNAP
//	(princ "\n Input : F_Blockinsert "); формирование файла происходит с помощью С++, Спасибо обучению в Академми ШАГ, ныне ТОР
//	(setvar "ORTHOMODE" 0); и лично Бакун Александр Владимтрович
//	(setvar "SNAPMODE" 0)
//	(setvar "OSMODE" 0)
//-----------------
// Это конец файла
//   (alert "Закончили")
//)
#include<Windows.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	string lisp_1; // начало строки лиспа
	string lisp_2; // середина строки лиспа
	string lisp_3; // конец строки лиспа
	int count_1{ 0 };
	int count_2{ 0 };
	int orX{ 2000 };
	int orY{ 2000 };
	int orZ{ 0 };
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
		count_1++;					// кол-во элементов в файле + одна строка сверху пустая
	}
	cout << "count_1 = " << count_1 << endl; // счетчик для вывода на консоль
	//cin.sync();
//cin.get();
	ifstream input("test.txt"); //Открываешь первый файл для чтения
	string string_buf; //Строка-буфер
	ofstream output("output.txt"); //Открываешь второй файл для записи
	output << "(defun C:F_Blockinsert(/ x1 x2 x3)\n";
	output << " (setq actdoc(vla-get-ActiveDocument(vlax-get-acad-object)))\n";
	output << "	(setq obj(vla-get-ModelSpace actdoc))\n";
	output << "(setq x1 1); начальное значение списка равно нулю, потом его увеличиваем на еденицу и получаем список\n";
	output << "(setq x2 1); на сколько будем увеличивать порядковый номер элемента списка\n";
	output << "; Запоминаем текущее состояние режимов ORTHO, SNAP И OSNAP\n";
	output << "(setq old_ortho(getvar \"ORTHOMODE\")\n";
	output << "old_snap(getvar \"SNAPMODE\")\n";
	output << "old_osnap(getvar \"OSMODE\")\n";
	output << "	)\n";
	output << "	; отключаем режимы ORTHO, SNAP И OSNAP\n";
	output << "(princ \"Input : F_Blockinsert \"); формирование файла происходит с помощью С++, Спасибо обучению в Академми ШАГ, ныне ТОР\n";
	output << "(setvar \"ORTHOMODE\" 0); и лично Бакун Александр Владимтрович\n";
	output << "(setvar \"SNAPMODE\" 0)\n";
	output << "(setvar \"OSMODE\" 0)\n";

	while (getline(input, string_buf))  //Считываешь из файла строку (пока не EOF)End Of File
	{
		if (getline(input, string_buf, '<'))
		{
			orX += 4000; // увеличиваем координату по Х
			string s_orX = to_string(orX); // переводим число в строку для вставки в файл txt
			string s_orY = to_string(orY); // переводим число в строку для вставки в файл txt
			string s_orZ = to_string(orZ); // переводим число в строку для вставки в файл txt

			lisp_1 = "(command \"_.-layer\" \"_m\" \""; // строка из лиспа для автокада - начало
			lisp_1.append(string_buf); // складываем строку из файла и строку lisp1
			lisp_2 = "\" \"\") (vla-InsertBlock obj(vlax-3D-point '("+ s_orX+" "+ s_orY+" " + s_orZ + "))  \"";
			// строка из лиспа для автокада - середина
			//lisp_2 = "\" \"\") (vla-InsertBlock obj(vlax-3D-point '( 4000  107376 0))  \"";// строка из лиспа для автокада - середина
			lisp_1.append(lisp_2); // складываем строку из файла и строку lisp2
		}
		if (getline(input, string_buf, '>'))
		{
			lisp_1.append(string_buf);
			lisp_3 = "\" 1 1 1 0)";// строка из лиспа для автокада - конец
			lisp_1.append(lisp_3); // добавляем в конец строки
			//cout << endl;
		}
		//cout << lisp_1 << endl;
		output << lisp_1 << endl;  //И записываешь эту строку в выходной файл	
		count_2++;
	}
	//cout << "count_2 = " << count_2 << endl;
	output << "(alert \"Закончили\")\n";
	output << ")\n";
		//) << endl;  //записываем заключительную строку в выходной файл	
	input.close();
	output.close();
	system("pause");
	return 0;
}

