#include<iostream>
#include<windows.h>
#include<string>
using namespace std;

struct Date {
	unsigned short int day;
	unsigned short int month;
	unsigned short int year;
};

struct Record {
	char name[20];
	char type;
	float cost;
	int mini;
	struct Date data;
};

void printDate(unsigned short int day, unsigned short int month, unsigned short int year) {
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
}

void out(struct Record l) {
	cout << left;
	cout << '|'; cout.width(21); cout << l.name;
	cout << '|'; cout.width(12); cout << l.type;
	cout.precision(2);  cout << '|'; cout.width(20); cout << l.cost;
	cout << '|'; cout.width(33); cout << l.mini;
	cout << '|'; printDate(l.data.day, l.data.month, l.data.year);
	cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');
}

void MyCentr(const char* s, int wLine) {
	int w = strlen(s);
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta); cout << " ";
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Record records[3];

	records[0] = { "Папка", 'К', 4.75000, 4, {03,07,2022} };
	records[1] = { "Бумага", 'К', 13.9, 10000, {03,04,2021} };
	records[2] = { "Калькулятор", 'О', 411.000, 1, {04,03,2022} };

	unsigned short int d; cin >> d;
	unsigned short int m; cin >> m;
	unsigned short int y; cin >> y;
	struct Date z = { d, m, y };

	int x = 4;
	for (int i = 0; i < 3; i++)
		if (z.month == records[i].data.month)
			if (z.day == records[i].data.day)
				if (z.year == records[i].data.year)
					x = i;

	cout << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << "|" << endl;
	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Прайс-лист"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

	cout << "|"; MyCentr("Наименование товара", 21);
	cout << "|"; MyCentr("Тип товара", 12);
	cout << "|"; MyCentr("Цена за 1 шт (грн)", 20);
	cout << "|"; MyCentr("Минимальное количество в партии", 33);
	cout << "|"; MyCentr("Дата", 10);
	cout << "|" << endl;
	cout << "|"; cout.width(101); cout.fill('-'); cout << right; cout << "|" << endl;
	cout.fill(' ');

	for (int i = 0; i < 3; i++)
		if (i != x)
			out(records[i]);

	cout.fill(' ');  cout << "|"; cout.width(100); cout << left << "Примечание: К – канцтовары, О - оргтехника"; cout << "|" << endl;
	cout << "|"; cout.fill('-'); cout.width(101);  cout << right << "|" << endl;
	cout.fill(' ');

	/*Используя функцию malloc()/calloc() создать динамический массив A,
	элементами которого будут структура Record, созданная в практической работе №1.
	В массив А добавить столько соответствующих записей из массива Table[],
	сколько указано в качестве целочисленного значения поля (элемента структуры).
	*/
	Record* A;
	int n = 3;
	A = (Record*)malloc(n * sizeof(Record));
	for (int i = 0; i < n; i++) {
		strcpy_s(A[i].name, records[i].name);
		A[i].type = records[i].type;
	}
	/*malloc() -
	Выделяет память длиной в t байт и возвращает указатель на начало выделенной
	памяти. В случае неудачного выполнения возвращает NULL*/

	//Используя функцию new создать массив В и скопировать 10 записей массива А. 
	Record** B;
	B = (Record**) new Record * [10];
	for (int i = 0; i < 10; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = records[i];
	}

	//Остальные записи в массиве А удалить.
	A = (Record*)realloc(A, 10 * sizeof(Record));
	/*realloc() -
	Изменяет размер ранее выделенного блока памяти, на начало которого
	указывает указатель b, до размера в n байт. Если указатель b имеет
	значение NULL, то есть память не выделялась, то действие функции
	аналогично действию malloc().*/

	cout << endl;
	//Вывести на экран адреса первого элемента массива Тable, массива А и массива В.
	cout << "адреса первого элемента массива Тable = " << &records[0] << endl;
	cout << "адреса первого элемента массива А = " << &A[0] << endl;
	cout << "адреса первого элемента массива В = " << &B[0] << endl;

	/*Вывести на экран в виде таблицы:
	адрес А[i], значение A[i]->строковое_поле, адрес В[i], значение В[i]->строковое_поле.
	*/
	for (int i = 0; i < 10; i++) {
		cout << "адрес А[i] = " << &A[i] << " ";
		cout << "значение A[i]->строковое_поле = " << A[i].name << " ";
		cout << "адрес В[i] = " << &B[i] << " ";
		cout << "значение В[i]->строковое_поле = " << B[i]->name << " ";
		cout << endl;
	}
}