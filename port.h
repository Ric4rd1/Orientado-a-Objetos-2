// =========================================================
// File: port.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef PORT_H
#define PORT_H

#include <list>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>


#include "container.h"
#include "simpleship.h"

using namespace std;

class Port {
private:
  int id;
  double x, y;
  list<Container*> containers;
  list<SimpleShip*> history;
  list<SimpleShip*> current;

public:
  Port(int, double, double);
  Port(const Port&);

  int getId() const;
  double getX() const;
  double getY() const;
  list<Container*> getContainers();
  list<SimpleShip*> getHistory();
  list<SimpleShip*> getCurrent();

  double getDistance(Port*) const;
  void incomingShip(SimpleShip*);
  void outgoingShip(SimpleShip*);

  bool contains(Container*);
  void add(Container*);
  void remove(Container*);

  string toString() const;
};

//Constructors
Port::Port(int _id, double _x, double _y){
  id = _id;
  x = _x;
  y = _y;
}

Port::Port(const Port &other){
  id = other.id;
  x = other.x;
  y = other.y;
  containers = other.containers;
  history = other.history;
  current = other.current;
}

//Getters
int Port::getId() const{
  return id;
}

double Port::getX() const{
  return x;
}

double Port::getY() const{
  return y;
}

list<Container*> Port::getContainers() {
  return containers;
}

list<SimpleShip*> Port::getHistory() {
  return history;
}

list<SimpleShip*> Port::getCurrent() {
  return current;
}

//Methods
double Port::getDistance(Port *other) const{
  return sqrt(pow(x - other->x, 2) + pow(y - other->y, 2));
}

void Port::incomingShip(SimpleShip *ship){
  if (find(current.begin(), current.end(), ship) == current.end()){
    current.push_back(ship);
  }
}

void Port::outgoingShip(SimpleShip *ship){
  if (find(current.begin(), current.end(), ship) != current.end()){
    current.remove(ship);
   if (find(history.begin(), history.end(), ship) == history.end()) {
    	history.push_back(ship);
  	}
  }
}

bool Port::contains(Container *container){
  return find(containers.begin(), containers.end(), container) != containers.end();
}

void Port::add(Container *container){
  containers.push_back(container);
}

void Port::remove(Container *container){
  containers.remove(container);
}

string Port::toString() const{
  stringstream ss;
  ss << "Port " << id << ": (" << x << ", " << y << ")" << '\n';

  ss << '\t' << "Light Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == LIGHT){
      ss << " " << (*it)->getId();
    }
  }
  ss << endl;

  ss << '\t' << "Heavy Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == HEAVY){
      ss << " " << (*it)->getId();
    }
  }
  ss << endl;

  ss << '\t' << "Refrigerated Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == REFRIGERATED){
      ss << " " << (*it)->getId();
    }
  }
  ss << endl;

  ss << '\t' << "Liquid Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == LIQUID){
      ss << " " << (*it)->getId();
    }
  }
  ss << endl;

  for (list<SimpleShip*>::const_iterator it = current.begin(); it != current.end(); ++it){
    ss << (*it)->toString();
    ss << endl;
  }
  

  return ss.str();
}
#endif
