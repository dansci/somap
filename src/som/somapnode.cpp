#include <somapnode.hpp>
#include <rng.hpp>

// increments both totalNodes and idGen
somapnode(int _len, xypair _pos, somapFunctorBase *_comp, 
	  somapFunctorBase *_corr) :
  position(_pos), nodeID(idGen++), corrector(_corr), comparison(_comp),
  dataStore(0)
{
  //NB: this reserve thing is Jared's; I don't understand it yet
  totalNodes++;
  dataStore.reserve(_len);
  
  // randomize the initial weights...
  RandomNumberEngine rand;
  for (int i=0; i < _len; i++)
    dataStore.push_back(rand.GetUniformRandomReal(0, MAXWEIGHT));
}

score somapnode::correct(weights w) { return (*correction)(w); }
score somapnode::compare(weights w) { return (*comparison)(w); }

void somapnode::printWeight() {

  weights::iterator wi = dataStore.begin();
  std::cout << "weights are:\n";
  while (wi != dataStore.end())
    std::cout << *wi++ << " ";
  std::cout << std::endl;
}

void somapnode::setWeight(weights input) {
  dataStore = input;
}

weights somapnode::getWeight() {
  return (*this).dataStore;
}

xypair somapnode::getPosition() {
  return (*this).position;
}
