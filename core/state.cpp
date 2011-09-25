
#include <state.hpp>
#include <string>

using namespace std;

void* State::blob = nullptr;

void State::setBlob(void* blob)
{
    State::blob = blob;
}

void* State::getBlob()
{
    return State::blob;
}

State::State(string name, State* parent)
{
    this->name = name;
    this->parent = parent;
}

void State::setParent(State* parent)
{
    this->parent = parent;
}

State* State::getParent()
{
    return this->parent;
}

string State::repr()
{
	return name;
}