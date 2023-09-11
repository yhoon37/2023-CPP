#include "Excel.h"
#include <iostream>
Excel::Excel(std::vector<std::vector<Cell>> data){this->data = data;}

double Excel::average(int fromRow, int fromCol, int toRow, int toCol) const{
    double sum=0.0;
    int count=0;
    for(int i=fromRow; i<toRow+1; i++){
        for(int j=fromCol; j<toCol+1; j++){
            if((this->data)[i][j].getType() == STRING){
            }
            else if((this->data)[i][j].getType() == INT){
                sum += (this->data)[i][j].getIntVal();
            }
            else if((this->data)[i][j].getType() == DOUBLE){
                sum += (this->data)[i][j].getDoubleVal();
            }
            count++;
        }
    }
    return sum/count;
}