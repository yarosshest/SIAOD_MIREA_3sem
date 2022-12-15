#include "Manager.h"

using namespace std;

//Метод чтения из файла
//Чтнение из файла по позиции и запись в таблицу
void Manager::SaveEntry(int shift)
{
	Auto ph = *file.readAuto(shift);
	table.Insert(ph.getNumber(), shift);
}
//Метод удаления
//Вызов метода удаления из таблицы и  файла
void Manager::Remove(const char *id)
{
	file.dellAuto(const_cast<char *>(id));
	table.Remove(id);
}

//Метод поиска
//Вызов метода поиска в таблице и чтения из файла
Auto Manager::Search(const char *id)
{
	int shift = table.GetShift(id);
	return *file.readAuto(shift);
}

//Метод вывода
//Вывод таблицы и файла
void Manager::Output() const
{
	cout << "=====" << endl;
	cout << "+@+@+File: " << endl;
	file.outputBin();
	cout << "+@+@+Table: " << endl;
	table.Output();
	cout << "=====" << endl;
}


Manager::Manager(string bin, string txt) : table() {
    file = BinWriter(bin, txt);
}

//Метод вставки файла
//Вставка всех записей файла в таблицу
void Manager::pasteFile() {
    vector<Auto> autos = file.getAutos();
    for (int i = 0; i < autos.size(); i++) {
        table.Insert(autos[i].getNumber(), i);
    }
}

int Manager::SearchFile(const char *id) {
    return file.getIndexById(const_cast<char *>(id));
}
