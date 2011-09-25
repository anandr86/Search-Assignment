
#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <string>
#include <vector>

class State {
    static void* blob;
    State* parent;
	
	protected:
	    std::string name;
    
	public:
        static void setBlob(void* b);
        static void* getBlob();

        State(std::string name, State* parent = nullptr);
		void setParent(State* s);
        State* getParent();
		virtual std::string repr();

		virtual State* clone() = 0;
        virtual std::vector<State*> generateChildren() = 0;
        virtual bool isGoal() = 0;
        virtual int h() = 0;
        virtual bool equal(State* s) = 0;
};

#endif // __STATE_HPP__