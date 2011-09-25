
#ifndef __DFS_HPP__
#define __DFS_HPP__

#include <search.hpp>
#include <state.hpp>

class DFS : public Search {
    public:
        DFS(State* start);
        virtual std::vector<State*>* run();
		virtual void reset();
};

#endif // __DFS_HPP__