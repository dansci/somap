class TFunctor {
public: 
  virtual double operator() (double x) = 0;
};

class TLinOpFunctor : public TFunctor {
private:
  double (*fn)(double);
  double A, m, c;
public:
  TLinOpFunctor(double (*_fn)(double), double _A, double _m, double _c):
    A(_A), m(_m), c(_c), fn(_fn) {}
  virtual double operator() (double x)
  {
    return A * (*fn)( m*x ) + c;
  }
};

template <class T1, class T2> class TFunctorProduct : public TFunctor {
private:
  T1 *o1;
  T2 *o2;
public:
  TFunctorProduct(T1 *_o1, T2 *_o2) : o1(_o1), o2(_o2) {}
  virtual double operator() (double x) 
  {
    return (*o1)(x) * (*o2)(x);
  }
};
