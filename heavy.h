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
: Container(_id, _weight, HEAVY){
}

HeavyContainer::HeavyContainer(int _id, int _weight, ContainerType T)
: Container(_id, _weight, T){
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
