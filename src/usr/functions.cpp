#include <somapnode.hpp>
#include <somapfunctors.hpp>

// This is a bit of a sandbox.  I don't know clearly what should be a
// class and what should be a function.

score RGBComp(somapnode n1, somapnode n2)
{
  weights w1 = n1.getWeight();
  weights w2 = n2.getWeight();
  
  double distsq = 0;
  score result;
  
  weights::iterator wi1, wi2;
  
  for (wi1 = w1.begin(), wi2 = w2.begin();
       wi1 != w1.end() && wi2 != w2.end();
       wi1++, wi2++) {
    distsq += pow(*wi1 - *wi2, 2);
  }
  
  // I'm allowing here for RESULT to have some other member signalling
  // an error (e.g. if the two weights were different lengths)
  result = sqrt(distsq);
  return result;
}
