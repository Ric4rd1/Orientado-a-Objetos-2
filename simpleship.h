// =========================================================
// File: simpleship.h
// Author:
// Date:
// Description:
// =========================================================

#ifndef SIMPLE_SHIP_H
#define SIMPLE_SHIP_H

class SimpleShip {
protected:
  int id;

public:
  SimpleShip(int);
  SimpleShip(const SimpleShip&);

  int getId() const;

  bool operator==(const SimpleShip*);
  bool operator==(const SimpleShip&);

  bool operator<(const SimpleShip*);
  bool operator<(const SimpleShip&);

  virtual std::string toString() const = 0;
};

//Constructors
SimpleShip::SimpleShip(int _id){
  id = _id;
}

SimpleShip::SimpleShip(const SimpleShip &other){
  id = other.id;
}

//Getters
int SimpleShip::getId() const{
  return id;
}

//Methods
bool SimpleShip::operator==(const SimpleShip *other){
  return id == other->id;
}

bool SimpleShip::operator==(const SimpleShip &other){
  return id == other.id;
}

bool SimpleShip::operator<(const SimpleShip *other){
  return id < other->id;
}

bool SimpleShip::operator<(const SimpleShip &other){
  return id < other.id;
}
#endif
