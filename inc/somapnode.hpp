#ifndef __SOMAPNODE
#define __SOMAPNODE
#include <iostream>
#include <vector>
#include <memory>

enum {MAXWEIGHT=1};

// Most likely implementation
typedef double score;
typedef std::vector<double> weights;
typedef std::pair<int,int> xypair;

class somapnode {
public:
  // JARED: This offends my C sensibilities.  The next two members are
  // to keep track of instantiations of this class.  I don't like them
  // being members, because it makes it look like they're replicated
  // for each instantiation.  Is this OK?
  static int totalNodes;
  static int idGen;
  // JARED: You were previously opposed to passing in functions to
  // each node.  Are you OK with it now?
  somapnode(int _len, xypair _pos, somapFunctorBase *_comp, 
	    somapFunctorBase *_corr) :
    position(_pos), nodeID(idGen++), corrector(_corr), comparison(_comp)
  { totalNodes++; }
  // FIXME:  we need to pass the distance to CORRECT somehow.
  score correct(weights);
  score compare(weights);
  void setWeight(weights);
  weights getWeight();
  xypair getPosition();
  int getNodeID();
private:
  const int nodeID;
  weights dataStore;
  xypair position;
  somapFunctorBase *corrector;
  somapFunctorBase *comparator;
};

// JARED: if the static things were OK, is this the right place to set
// them?
int somapnode::totalNodes = 0;
int somapnode::idGen = 0;

#endif
