// =========================================================
// File: heavy.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef HEAVY_H
#define HEAVY_H

#include "container.h"

class HeavyContainer : public Container {
public:
  HeavyContainer(int, int);
  HeavyContainer(int, int, ContainerType);
  HeavyContainer(const HeavyContainer&);

  double getConsumption() const;
};

//Constructors
HeavyContainer::HeavyContainer(int _id, int _weight)
: Container(_id, _weight, type){
    id = _id;
    if (_weight < 0){
      weight = 0;
    } else {
      weight = _weight;
    }
    type = HEAVY;
  
}

HeavyContainer::HeavyContainer(const HeavyContainer &other)
  : Container(other){
    id = other.id;
    weight = other.weight;
    type = other.type;
}

//Methods
double HeavyContainer::getConsumption() const {
  return weight * 3.0;
}

#endif
