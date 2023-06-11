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
#include <iostream>

#include "container.h"
#include "simpleship.h"

class Port {
private:
  int id;
  double x, y;
  std::list<Container*> containers;
  std::list<SimpleShip*> history;
  std::list<SimpleShip*> current;

public:
  Port(int, double, double);
  Port(const Port&);

  int getId() const;
  double getX() const;
  double getY() const;
  std::list<Container*> getContainers();
  std::list<SimpleShip*> getHistory();
  std::list<SimpleShip*> getCurrent();

  double getDistance(Port*) const;
  void incomingShip(SimpleShip*);
  void outgoingShip(SimpleShip*);

  bool contains(Container*);
  void add(Container*);
  void remove(Container*);

  std::string toString() const;
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

std::list<Container*> Port::getContainers() {
  return containers;
}

std::list<SimpleShip*> Port::getHistory() {
  return history;
}

std::list<SimpleShip*> Port::getCurrent() {
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

std::string Port::toString() const{
  std::stringstream ss;
  //ss << "Port " << id << " (" << x << ", " << y << ")" << endl;
  return "0";
}
#endif
