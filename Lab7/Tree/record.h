//
// Created by yaros on 30.11.2022.
//

#ifndef SIAOD_RECORD_H
#define SIAOD_RECORD_H
#include <string>
using namespace std;
class record {
private:
    wchar_t key;
    int val;
public:
    record();
    record(wchar_t k, int v);
    bool operator==(const record &rhs) const;
    bool operator!=(const record &rhs) const;
    bool operator>(const record &rhs) const;
    bool operator<(const record &rhs) const;
    bool operator>=(const record &rhs) const;
    bool operator<=(const record &rhs) const;
    [[nodiscard]] wchar_t getKey() const;
    [[nodiscard]] int getVal() const;
};


#endif //SIAOD_RECORD_H
