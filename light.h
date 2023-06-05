// =========================================================
// File: light.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef LIGHT_H
#define LIGHT_H

#include "container.h"

class LightContainer : public Container {
public:
  LightContainer(int, int);
  LightContainer(const LightContainer&);

  double getConsumption() const;
};

//Constructors
LightContainer::LightContainer(int _id, int _weight)
: Container(_id, _weight, type){
    id = _id;
    if (_weight < 0){
      weight = 0;
    } else {
      weight = _weight;
    }
    type = LIGHT;
  
}

LightContainer::LightContainer(const LightContainer &other)
  : Container(other){
    id = other.id;
    weight = other.weight;
    type = other.type;
}

//Methods
double LightContainer::getConsumption() const {
  return weight * 2.5;
}

#endif
