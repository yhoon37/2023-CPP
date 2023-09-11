#ifndef UNTITLED_EXCEL_H
#define UNTITLED_EXCEL_H
#include <vector>
#include "Cell.h"

class Excel {
public:
    Excel(std::vector<std::vector<Cell>> data);
    double average(int fromRow, int fromCol, int toRow, int toCol) const;
private:
    std::vector<std::vector<Cell>> data;
};

#endif //UNTITLED_EXCEL_H
