#include <poincare/determinant.h>
#include <poincare/matrix.h>
extern "C" {
#include <assert.h>
}
#include <cmath>

namespace Poincare {

Expression::Type Determinant::type() const {
  return Type::Determinant;
}

Expression * Determinant::clone() const {
  Determinant * a = new Determinant(m_operands, true);
  return a;
}

Expression * Determinant::shallowReduce(Context& context, AngleUnit angleUnit) {
  Expression * e = Expression::shallowReduce(context, angleUnit);
  if (e != this) {
    return e;
  }
  Expression * op = editableOperand(0);
  if (!op->recursivelyMatches(Expression::isMatrix)) {
    return replaceWith(op, true);
  }
  return this;
}

// TODO: handle this exactly in shallowReduce for small dimensions.
template<typename T>
Expression * Determinant::templatedEvaluate(Context& context, AngleUnit angleUnit) const {
  Expression * input = operand(0)->evaluate<T>(context, angleUnit);
  Expression * result = nullptr;
  if (input->type() == Type::Complex) {
    result = input->clone();
  } else {
    assert(input->type() == Type::Matrix);
    result = static_cast<Matrix *>(input)->createDeterminant<T>();
  }
  delete input;
  return result;
}

}

