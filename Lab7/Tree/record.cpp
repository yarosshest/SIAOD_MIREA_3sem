//
// Created by yaros on 30.11.2022.
//

#include "record.h"

#include <utility>

record::record(wchar_t k, int v) {
    key = k;
    val = v;
}

bool record::operator==(const record &rhs) const {
    return val == rhs.val;
}

bool record::operator!=(const record &rhs) const {
    return val != rhs.val;
}

bool record::operator>(const record &rhs) const {
    return val > rhs.val;
}

bool record::operator<(const record &rhs) const {
    return val < rhs.val;
}

bool record::operator>=(const record &rhs) const {
    return val >= rhs.val;
}

bool record::operator<=(const record &rhs) const {
    return val <= rhs.val;
}

wchar_t record::getKey() const {
    return key;
}

int record::getVal() const {
    return val;
}

record::record() {
    key = L' ';
    val = 0;
}


