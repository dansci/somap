#ifndef __SOMAPFUNCTORS
#define __SOMAPFUNCTORS
#include <somapnode.hpp>
#include <cmath>

typedef double score;
typedef double modification;  // to quantify the degree of correction
typedef double time_t;	// in case i want to use advanced time struct

class somapCompFunctorBase {
public:
  virtual score operator() (somapnode n) = 0;
};

class somapCorrFunctorBase {
public:
  virtual modification operator() (somapnode n, time_t t) = 0;
};


/* I don't know if the following stuff should actually inherit from
   base functors.  It's probably heavily dependent on what I'm
   comparing, e.g. RGB, histograms, etc.  Maybe the specifics should
   go in a different file.  */

/* I'm keeping these just to remember how to use functors; they're way
   obsolete by now. */

// class somapCorrLinOpFunctor : public somapFunctorBase {
// private:
//   // Linear function: y = A * function( m*x ) + c
//   double (*function)(double);
//   double A, m, c;
// public:
//   somapLinOpFunctor(double (*_fn)(double), double _A, double _m,
// 		    double _c): A(_A), m(_m), c(_c), function(_fn) {}
//   virtual double operator() (double x)
//   {
//     return A * (*function) ( m*x ) + c;
//   }
// };

// template <class T1, class T2> class somapFunctorProduct :
//   public somapFunctorBase {
// private:
//   // The two functors to be combined into a product
//   T1 *F1;
//   T2 *F2;
// public:
//   somapFunctorProduct(T2 *_F1, T2 *_F2) : F1(_F1), F2(_F2) {}
//   virtual double operator() (double x)
//   {
//     return (*F1)(x) * (*F2)(x);
//   }
// };

#endif
