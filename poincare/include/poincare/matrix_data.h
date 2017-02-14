#ifndef POINCARE_MATRIX_DATA_H
#define POINCARE_MATRIX_DATA_H

#include <poincare/list_data.h>
#include <poincare/float.h>
#include <poincare/expression.h>

class MatrixData {
  public:
    MatrixData(ListData * listData);
    MatrixData(Expression ** newOperands, int numberOfOperands, int m_numberOfColumns, int m_numberOfRows, bool cloneOperands);
    ~MatrixData();
    void pushListData(ListData * listData);
    int numberOfRows();
    int numberOfColumns();
    Expression ** operands() const;
  private:
    int m_numberOfRows;
    int m_numberOfColumns;
    Expression ** m_operands;
    static Float * defaultExpression();
};

#endif
