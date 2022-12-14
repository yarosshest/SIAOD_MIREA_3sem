#include <iostream>
#include <cstring>
#include "HeshTable.h"

using namespace std;

//Конструктор записи
//Создание записи с заданной позицией и ключом
HeshTable::Item::Item(const char *id, const int shift): shift(shift)
{
    char *tmp_id = new char[strlen(id)];
    strcpy(tmp_id, id);
    this->id = tmp_id;
}

//Конструктор таблицы
//Создание таблицы с заданным размером и заполнение нулями
HeshTable::HeshTable(): size(5)
{
    table = new Item*[size];
    for (unsigned i = 0; i < size; i++) {
        table[i] = 0;
    }
}

//Метод вставки
//Указатетель помещается на место с заданным ключом если оно пусто то вставляется в эту ящейку , иначе вызвается вставляеться в следующию пустую ячейку
void HeshTable::Insert(const char *id, const int shift)
{
    unsigned key = Hash1(id);
    unsigned index;
    while (true) {
        for (unsigned i = 0; i < size; i++) {
            index = (key + i) % size;
            if (table[index] == nullptr) {
                Item *it = new Item(id, shift);
                table[index] = it;
                return;
            }
        }
        ReHash();
    }
}

//Метод удаления
//Удаляет запись с заданным ключом
int HeshTable::Remove(const char *id)
{
    unsigned key = Hash1(id);
    unsigned index;
    for (unsigned i = 0; i < size; i++) {
        index = (key + i) % size;  // key2 = (key1 + key2) % size
        if (table[index] != nullptr) {
            if (0 == strcmp(table[index]->id, id)) {
                int shift = table[index]->shift;
                delete table[index];
                table[index] = nullptr;
                return shift;
            }
        }
    }
    return -1;
}

//Метод поиска
//Возвращает позицию записи с заданным ключом
int HeshTable::GetShift(const char *id) const
{
    int index = Search(id);
    if (index == -1)
        return index;
    return table[index]->shift;
}

//Метод рехеширования
//Увеличивает размер таблицы в 2 раза и перестраивает таблицу
void HeshTable::ReHash()
{
    unsigned old_size = size;
    size *= 2;
    Item **tmp_table = table;
    table = new Item*[size];
    unsigned i;
    for (i = 0; i < size; i++) {
        table[i] = nullptr;
    }
    for (i = 0; i < old_size; i++) {
        if (tmp_table[i] != nullptr) {
            Insert(tmp_table[i]->id, tmp_table[i]->shift);
            delete tmp_table[i];
        }
    }
    delete [] tmp_table;
}


//Метод хеширования
//Возвращает хеш ключа
unsigned HeshTable::Hash1(const char *id) const
{
    unsigned key = 0x0;
    for (unsigned i = 0; i < strlen(id); i++) {
        unsigned x = sizeof(unsigned)*8 / id[i]%10;
        unsigned mask = id[i] + 7*(id[i]%13);
        key ^= id[i];
        key = ((key << x) | (key >> (sizeof(unsigned)*8 - x)));
        if (id[i] % 3 == 0)
            key |= mask;
        else if (id[i] % 3 == 1)
            key &= mask;
        else
            key ^= mask;
    }
    return key;
}


//Метод вывода таблицы
//Выводит таблицу на экран
void HeshTable::Output() const
{
    for (unsigned i = 0; i < size; i++) {
        if (table[i] == nullptr)
            cout << "null" << endl;
        else
            cout << table[i]->id << " :: " << table[i]->shift << endl;
    }
}

//Метод поиска
//Возвращает индекс записи с заданным ключом
unsigned HeshTable::Search(const char *id) const
{
    unsigned key = Hash1(id);
    int i;
    for (i = 0; i < size; i++) {
        unsigned index = (key + i) % size;
        if (table[index] != nullptr) {
            if (0 == strcmp(table[index]->id, id)) {
                return index;
            }
        }
    }
    return -1;
}

