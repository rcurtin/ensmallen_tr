#include <ensmallen.hpp>
#include <ensmallen_bits/problems/problems.hpp>

using namespace ens;
using namespace ens::test;

struct Optimizer
{
  template<typename FunctionType>
  void Optimize(FunctionType& f, arma::mat& iterate)
  {
    // Dummy operation.
    f.Evaluate(iterate);
  }
};

int main()
{
  RosenbrockFunction rf;
  arma::mat parameters = rf.GetInitialPoint();
  Optimizer opt;

  opt.Optimize(rf, parameters);
  return 0;
}