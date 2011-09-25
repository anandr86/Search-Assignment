
#ifndef __SEARCH_HPP__
#define __SEARCH_HPP__

#include <state.hpp>

class Search {
	protected:
		State* const start;
		std::vector<State*>* constructPath(State* s);
    public:
        Search(State* start);
        virtual std::vector<State*>* run() = 0;
        virtual void reset() = 0;
};

#endif //__SEARCH_HPP__