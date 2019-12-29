#include <ensmallen.hpp>
#include <ensmallen_bits/problems/problems.hpp>

using namespace ens;
using namespace ens::test;

struct Optimizer
{
  template<typename FunctionType, typename... CallbackTypes>
  void Optimize(FunctionType& f, arma::mat& iterate, CallbackTypes&&... callbacks)
  {
    // Callback function.
    Callback::BeginOptimization(*this, f, iterate, callbacks...);
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