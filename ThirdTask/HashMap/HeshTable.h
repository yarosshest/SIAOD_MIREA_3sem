#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <cstring>

class HeshTable {
	struct Item {
		const char *id;
		int shift;
		Item(const char *id, const int shift);
	};
	Item **table;
	unsigned size;
public:
	HeshTable();
	void Insert(const char *id, const int shift);
	int Remove(const char *id);
	int GetShift(const char *id) const;
	void Output() const;
private:
	unsigned Hash1(const char *id) const;
    unsigned Search(const char *id) const;
	void ReHash();
};

#endif
