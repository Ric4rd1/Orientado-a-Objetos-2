// =========================================================
// File: ship.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef SHIP_H
#define SHIP_H

#include <list>
#include <string>
#include <sstream>
#include <iomanip>
#include "container.h"
#include "light.h"
#include "heavy.h"
#include "refrigerated.h"
#include "liquid.h"
#include "simpleship.h"
#include "port.h"

class Ship : public SimpleShip {
private:
  int currentWeight, totalWeight;
  int currentNumberOfAllContainers, maxNumberOfAllContainers;
  int currentNumberOfHeavyContainers, maxNumberOfHeavyContainers;
  int currentNumberOfRefrigeratedContainers, maxNumberOfRefrigeratedContainers;
  int currentNumberOfLiquidContainers, maxNumberOfLiquidContainers;
  double fuel, fuelConsumptionPerKM;
  Port *currentPort;
  std::list<Container*> containers;

  bool contains(Container*);
  void remove(Container*);

public:
  Ship(int, Port*, int, int, int, int, int, double);
  Ship(const Ship&);

  int getId() const;
  int getCurrentWeight() const;
  int getTotalWeight() const;
  int getCurrentNumberOfAllContainers() const;
  int getMaxNumberOfAllContainers() const;
  int getCurrentNumberOfHeavyContainers() const;
  int getMaxNumberOfHeavyContainers() const;
  int getCurrentNumberOfRefrigeratedContainers() const;
  int getMaxNumberOfRefrigeratedContainers() const;
  int getCurrentNumberOfLiquidContainers() const;
  int getMaxNumberOfLiquidContainers() const;
  double getFuel() const;
  double getFuelConsumptionPerKM() const;
  Port* getCurrentPort() const;
  std::list<Container*> getCurrentContainers() const;

  bool sailTo(Port*);
  void reFuel(double);
  bool load(Container*);
  bool unLoad(Container*);

  std::string toString() const;
};

//Constructors
Ship::Ship(int _id, Port *_currentPort, int _totalWeight, 
  int _maxNumberOfAllContainers, int _maxNumberOfHeavyContainers, 
  int _maxNumberOfRefrigeratedContainers, int _maxNumberOfLiquidContainers, 
  double _fuelConsumptionPerKM)
  : SimpleShip(_id){
  currentWeight = 0;
  currentNumberOfAllContainers = 0;
  currentNumberOfHeavyContainers = 0;
  currentNumberOfRefrigeratedContainers = 0;
  currentNumberOfLiquidContainers = 0;
  fuel = 0;
  currentPort = _currentPort;
  totalWeight = _totalWeight;
  maxNumberOfAllContainers = _maxNumberOfAllContainers;
  maxNumberOfHeavyContainers = _maxNumberOfHeavyContainers;
  maxNumberOfRefrigeratedContainers = _maxNumberOfRefrigeratedContainers;
  maxNumberOfLiquidContainers = _maxNumberOfLiquidContainers;
  fuelConsumptionPerKM = _fuelConsumptionPerKM;
}

Ship::Ship(const Ship &other)
  : SimpleShip(other){
    currentWeight = other.currentWeight;
    currentNumberOfAllContainers = other.currentNumberOfAllContainers;
    currentNumberOfHeavyContainers = other.currentNumberOfHeavyContainers;
    currentNumberOfRefrigeratedContainers = other.currentNumberOfRefrigeratedContainers;
    currentNumberOfLiquidContainers = other.currentNumberOfLiquidContainers;
    fuel = other.fuel;
    currentPort = other.currentPort;
    totalWeight = other.totalWeight;
    maxNumberOfAllContainers = other.maxNumberOfAllContainers;
    maxNumberOfHeavyContainers = other.maxNumberOfHeavyContainers;
    maxNumberOfRefrigeratedContainers = other.maxNumberOfRefrigeratedContainers;
    maxNumberOfLiquidContainers = other.maxNumberOfLiquidContainers;
    fuelConsumptionPerKM = other.fuelConsumptionPerKM;
}

//Getters
int Ship::getId() const{
  return id;
}

int Ship::getCurrentWeight() const{
  return currentWeight;
}

int Ship::getTotalWeight() const{
  return totalWeight;
}

int Ship::getCurrentNumberOfAllContainers() const{
  return currentNumberOfAllContainers;
}

int Ship::getMaxNumberOfAllContainers() const{
  return maxNumberOfAllContainers;
}

int Ship::getCurrentNumberOfHeavyContainers() const{
  return currentNumberOfHeavyContainers;
}

int Ship::getMaxNumberOfHeavyContainers() const{
  return maxNumberOfHeavyContainers;
}

int Ship::getCurrentNumberOfRefrigeratedContainers() const{
  return currentNumberOfRefrigeratedContainers;
}

int Ship::getMaxNumberOfRefrigeratedContainers() const{
  return maxNumberOfRefrigeratedContainers;
}

int Ship::getCurrentNumberOfLiquidContainers() const{
  return currentNumberOfLiquidContainers;
}

int Ship::getMaxNumberOfLiquidContainers() const{
  return maxNumberOfLiquidContainers;
}

double Ship::getFuel() const{
  return fuel;
}

double Ship::getFuelConsumptionPerKM() const{
  return fuelConsumptionPerKM;
}

Port* Ship::getCurrentPort() const{
  return currentPort;
}

std::list<Container*> Ship::getCurrentContainers() const{
  return containers;
}

//Methods
bool Ship::sailTo(Port *port){
  return 0;
}



#endif
