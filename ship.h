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

using namespace std;

class Ship : public SimpleShip {
private:
  int currentWeight, totalWeight;
  int currentNumberOfAllContainers, maxNumberOfAllContainers;
  int currentNumberOfHeavyContainers, maxNumberOfHeavyContainers;
  int currentNumberOfRefrigeratedContainers, maxNumberOfRefrigeratedContainers;
  int currentNumberOfLiquidContainers, maxNumberOfLiquidContainers;
  double fuel, fuelConsumptionPerKM;
  Port *currentPort;
  list<Container*> containers;

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
  list<Container*> getCurrentContainers() const;

  bool sailTo(Port*);
  void reFuel(double);
  bool load(Container*);
  bool unLoad(Container*);

  string toString() const;
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

list<Container*> Ship::getCurrentContainers() const{
  return containers;
}

//Methods
bool Ship::sailTo(Port *port){
  if (currentPort == port){
    return false;
  } else {
    double distance = currentPort->getDistance(port);
  double acum = 0;
    for (list<Container*>::iterator it = containers.begin(); it != containers.end(); it++){
      acum += (*it)->getConsumption();
    }
    double fuelConsumption = (distance * fuelConsumptionPerKM) + (acum);
    if (fuelConsumption > fuel){
      return false;
    } else {
      fuel -= fuelConsumption;
      currentPort->outgoingShip(this);
      currentPort = port;
      currentPort->incomingShip(this);
      return true;
    }
  }
}

void Ship::reFuel(double amount){
  if (amount < 0){
    fuel = 0;
  } else {
    fuel += amount;
  }
}

bool Ship::load(Container *container){
  if (currentPort->contains(container) == false){
    return false;
  } else if (currentNumberOfAllContainers >= maxNumberOfAllContainers){
    return false;
  } else if (currentWeight + container->getWeight() > totalWeight){
    return false;
  } else if (container->getType() == HEAVY && currentNumberOfHeavyContainers >= maxNumberOfHeavyContainers){
    return false;
  } else if (container->getType() == REFRIGERATED && currentNumberOfRefrigeratedContainers >= maxNumberOfRefrigeratedContainers){
    return false;
  } else if (container->getType() == LIQUID && currentNumberOfLiquidContainers >= maxNumberOfLiquidContainers){
    return false;
  } else {
    currentPort->remove(container);
    containers.push_back(container);
    currentNumberOfAllContainers++;
    currentWeight += container->getWeight();
    if (container->getType() == HEAVY){
      currentNumberOfHeavyContainers++;
    } else if (container->getType() == REFRIGERATED){
      currentNumberOfRefrigeratedContainers++;
    } else if (container->getType() == LIQUID){
      currentNumberOfLiquidContainers++;
    }
    return true;
  }
}

bool Ship::contains(Container *container){
  list<Container*>::iterator it;
  for (it = containers.begin(); it != containers.end(); it++){
    if (*it == container){
      return true;
    }
  }
  return false;
}

void Ship::remove(Container *container){
  list<Container*>::iterator it;
  for (it = containers.begin(); it != containers.end(); it++){
    if (*it == container){
      containers.erase(it);
      currentNumberOfAllContainers--;
      currentWeight -= container->getWeight();
      if (container->getType() == HEAVY){
        currentNumberOfHeavyContainers--;
      } else if (container->getType() == REFRIGERATED){
        currentNumberOfRefrigeratedContainers--;
      } else if (container->getType() == LIQUID){
        currentNumberOfLiquidContainers--;
      }
      break;
    }
  }
}

bool Ship::unLoad(Container *container){
  if (contains(container) == false){
    return false;
  } else {
    currentPort->add(container);
    remove(container);
    return true;
  }
}

string Ship::toString() const{
  stringstream aux;
  aux << std::fixed << std::setprecision(2);

  aux << '\t' << endl;
  aux << "Ship " << id << ": " << fuel << endl;

  if(currentNumberOfAllContainers != 0){
  aux << '\t' << '\t' << "Light Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == LIGHT){
      aux << " " << (*it)->getId();
    }
  }
  aux << endl;

  aux << '\t' << '\t' << "Heavy Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == HEAVY){
      aux << " " << (*it)->getId();
    }
  }
  aux << endl;

  aux << '\t' << '\t' << "Refrigerated Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == REFRIGERATED){
      aux << " " << (*it)->getId();
    }
  }
  aux << endl;

  aux << '\t' << '\t' << "Liquid Containers:";
  for (list<Container*>::const_iterator it = containers.begin(); it != containers.end(); ++it){
    if ((*it)->getType() == LIQUID){
      aux << " " << (*it)->getId();
    }
  }
  aux << endl;
  }
  return aux.str();
}





#endif
