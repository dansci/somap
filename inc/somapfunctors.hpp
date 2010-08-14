#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

typedef double score;

class somapFunctorBase {
public:
  virtual score operator() (weights w) = 0;
};

class somapLinOpFunctor : public somapFunctorBase {
private:
  // Linear function: y = A * function( m*x ) + c
  double (*function)(double);
  double A, m, c;
public:
  somapLinOpFunctor(double (*_fn)(double), double _A, double _m,
		    double _c): A(_A), m(_m), c(_c), function(_fn) {}
  virtual double operator() (double x)
  {
    return A * (*function) ( m*x ) + c;
  }
};

template <class T1, class T2> class somapFunctorProduct :
  public somapFunctorBase {
private:
  // The two functors to be combined into a product
  T1 *F1;
  T2 *F2;
public:
  somapFunctorProduct(T2 *_F1, T2 *_F2) : F1(_F1), F2(_F2) {}
  virtual double operator() (double x)
  {
    return (*F1)(x) * (*F2)(x);
  }
};

#endif
