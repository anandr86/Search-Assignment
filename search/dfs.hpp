
#ifndef __DFS_HPP__
#define __DFS_HPP__

#include <search.hpp>
#include <state.hpp>
#include <memory>

class DFS : public Search {
public:
  DFS(spState start);
  virtual std::shared_ptr<std::vector<spState>> run();
  virtual void reset();
};

#endif // __DFS_HPP__
