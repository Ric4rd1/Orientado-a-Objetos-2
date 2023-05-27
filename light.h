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

LightContainer::LightContainer(int _id, int _weight):Container(_id, _weight, LIGHT){
  id = _id;
  weight = _weight;
  type = LIGHT;
}

#endif
