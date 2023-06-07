// =========================================================
// File: liquid.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef LIQUID_H
#define LIQUID_H

#include "heavy.h"

class LiquidContainer : public HeavyContainer {
public:
  LiquidContainer(int, int);
  LiquidContainer(const LiquidContainer&);

  double getConsumption() const;
};

//Constructors
LiquidContainer::LiquidContainer(int _id, int _weight)
: HeavyContainer(_id, _weight, LIQUID){
}

LiquidContainer::LiquidContainer(const LiquidContainer &other)
  : HeavyContainer(other){
    id = other.id;
    weight = other.weight;
    type = other.type;
}

//Methods
double LiquidContainer::getConsumption() const {
  return weight * 4.0;
}
#endif
