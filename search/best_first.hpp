
#ifndef __BEST_FIRST_HPP__
#define __BEST_FIRST_HPP__

#include <state.hpp>
#include <vector>

class BestFirst : public Search {
	public:
		BestFirst(State* start);
		std::vector<State*>* run();
		void reset();
};

#endif // __BEST_FIRST_HPP__