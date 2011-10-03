
#include <search.hpp>
#include <state.hpp>
#include <vector>
#include <memory>

using namespace std;

Search::Search(spState st) : start(st)
{
}

shared_ptr<vector<spState>> Search::constructPath(spState s)
{
  auto path = make_shared<vector<spState>>();
  while(s != nullptr) {
    path->push_back(s);
    s = s->getParent();
  }

  return path;
}
