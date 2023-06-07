// =========================================================
// File: refrigerated.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "heavy.h"

class RefrigeratedContainer : public HeavyContainer {
public:
  RefrigeratedContainer(int, int);
  RefrigeratedContainer(const RefrigeratedContainer&);

  double getConsumption() const;
};

//Constructors
RefrigeratedContainer::RefrigeratedContainer(int _id, int _weight)
: HeavyContainer(_id, _weight, REFRIGERATED){
}

RefrigeratedContainer::RefrigeratedContainer(const RefrigeratedContainer &other)
  : HeavyContainer(other){
    id = other.id;
    weight = other.weight;
    type = other.type;
}

//Methods
double RefrigeratedContainer::getConsumption() const {
  return weight * 5.0;
}

#endif
