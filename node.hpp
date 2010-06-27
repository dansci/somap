#include <vector>

typedef std::pair<int,int> xypair;
//typedef std::vector<int> weights;
// i've set this to see if the functors will work as such
typedef double weights;
typedef double score;

class node {
private:
  const int nodeID;
  xypair position;
  TFunctor *correction;
  TFunctor *comparison;
  weights dataStore;
public:
  static int totalNodes;
  static int idGen;
  node();
  node(xypair pos, TFunctor *comp, TFunctor *corr);
  ~node() {--totalNodes;};
  int getNodeID() { return nodeID; };
  xypair getPosition() { return position; };
  weights getWeights() { return dataStore; };
  score correct(weights w) { return (*correction)(w); };
  score compare(weights w) { return (*comparison)(w); };
  void setWeight(weights w) {dataStore = w;};
};

int node::totalNodes = 0;
int node::idGen = 0;

node::node(xypair _pos, TFunctor *_comp, TFunctor *_corr) :
  position(_pos), nodeID(node::idGen++), correction(_corr), comparison(_comp)
{ node::totalNodes++;};

node::node() : nodeID(node::idGen++) {node::totalNodes++;};
	       
  
  
