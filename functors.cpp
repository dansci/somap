#include "functors.hpp"
#include "node.hpp"
#include <iostream>
#include <cmath>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
  // this is the generic functor which can be passed to the nodes
  TFunctor *f1;

  // These are linear functors (fn, Amplitude, freq, intercept)
  TLinOpFunctor sinFunctor(&std::sin, 1, 1, 0);
  TLinOpFunctor expFunctor(&std::exp, 1, -1, 0);

  TFunctorProduct<TLinOpFunctor, TLinOpFunctor> 
    prodFunctor(&sinFunctor, &expFunctor);
  
  f1 = &prodFunctor;
  TFunctor *f2 = &expFunctor;

  node n1(xypair(0, 0), f1, f2);
  
  double x = atof(argv[1]);
  std::cout << "n1.f1() = " << n1.compare(x) << "\n" <<
    "n1.f2() = " << n1.correct(x) << std::endl;
  
  std::cout << "node id of n1 is: " << n1.getNodeID() << 
    " and total nodes is: " << node::totalNodes << std::endl;

  node n2[9];
  node *n4 = new node();
  delete n4;

  node n3(xypair(2, 1), f1, f2);

  std::cout << "node id of n3 is: " << n3.getNodeID() << 
    " and total nodes is: " << node::totalNodes << std::endl;

    
  
  return 0;
}
