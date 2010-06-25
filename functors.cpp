#include "functors.hpp"
#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) 
{
  // this is the generic functor which can be passed to the nodes
  TFunctor *f1;

  // These are linear functors (fn, Amplitude, freq, intercept)
  // i.e.  1 * sin(1 * x) + 0
  TLinOpFunctor sinFunctor(&std::sin, 1, 1, 0);
  // and 1 * exp( -1 * x) + 0
  TLinOpFunctor expFunctor(&std::exp, 1, -1, 0);

  TFunctorProduct<TLinOpFunctor, TLinOpFunctor> 
    prodFunctor(&sinFunctor, &expFunctor);

  // now we can evaluate it as if it were a TFunctor:
  f1 = &prodFunctor;
  std::cout << "prodFunctor(3.2) = sin(3.2)*exp(-3.2) = " 
	    << (*f1)(3.2) << std::endl;
							    
  return 0;
}
