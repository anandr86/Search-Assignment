
#include <state.hpp>
#include <memory>
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

State::State(string name)
{
  this->name = name;
}

void State::setParent(spState parent)
{
  this->parent = parent;
}

spState State::getParent()
{
  return this->parent;
}

string State::repr()
{
  return name;
}
