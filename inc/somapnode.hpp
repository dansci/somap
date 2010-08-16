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
  static int totalNodes;
  static int idGen;
  somapnode(int len, xypair pos, somapFunctorBase *comp, 
	    somapFunctorBase *corr);
  score correct(somapnode);
  score compare(somapnode);
  void setWeight(weights);
  weights getWeight();
  xypair getPosition();
  int getNodeID();
  void printWeight();
private:
  const int nodeID;
  weights dataStore;
  xypair position;
  somapCorrFunctorBase *corrector;
  somapCompFunctorBase *comparator;
};

int somapnode::totalNodes = 0;
int somapnode::idGen = 0;

#endif
