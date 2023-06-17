#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "container.h"
#include "light.h"
#include "heavy.h"
#include "refrigerated.h"
#include "liquid.h"
#include "simpleship.h"
#include "ship.h"
#include "port.h"

using namespace std;

int main(int argc, char* argv[]) {
  ifstream inputFile;
  ofstream outputFile;

  vector<Container*> containers;
  vector<Ship*> ships;
  vector<Port*> ports;

  int idContainer, idPort, idShip;
  idContainer = idPort = idShip = 0;
  int eventType;
  int weight, initPort;
  char type;
  int totalWeight, maxAll, maxHeavy, maxRefrigerated, maxLiquid;
  double fuelConsumption;
  double x, y;
  int portId;
  int shipId, containerId;
  double fuel;

  int c, s, p, n;

  if (argc != 3) {
    cout << "usage: " << argv[0] << " input_file output_file\n";
    return -1;
  }

  inputFile.open(argv[1]);
  if (!inputFile.is_open()) {
    cout << argv[0] << ": File \"" << argv[1] << "\" not found\n";
    return -1;
  }

  outputFile.open(argv[2]);

  inputFile>>c>>s>>p>>n;
  
  containers.resize(c);
  ships.resize(s);
  ports.resize(p);

  for(int i = 0 ; i < n ; i++){
    inputFile>> eventType;
    
    switch (eventType){
      case (1): //Create a container
        inputFile>> initPort;
        inputFile>> weight;
        inputFile>> type;

        if (type == 'B'){
          if (weight <= 3000){
            containers[idContainer] = new LightContainer(idContainer, weight);
          } else {
            containers[idContainer] = new HeavyContainer(idContainer, weight);
          }
        } else if (type == 'R'){
          containers[idContainer] = new RefrigeratedContainer(idContainer, weight);
        } else if (type == 'L'){
          containers[idContainer] = new LiquidContainer(idContainer, weight);
        }
        ports[initPort]->add(containers[idContainer]);
        idContainer++;
      break;
      case (2): //Create a ship
          inputFile>> initPort; inputFile>> totalWeight; inputFile>> maxAll; inputFile>> maxHeavy; 
          inputFile>> maxRefrigerated; inputFile>> maxLiquid; inputFile>> fuelConsumption;

          ships[idShip] = new Ship(idShip, ports[initPort], totalWeight, maxAll, maxHeavy, maxRefrigerated, maxLiquid, fuelConsumption);
          ports[initPort]->incomingShip(ships[idShip]);
          idShip++;
      break;
      case (3): //Create a port
          inputFile>> x; inputFile>> y;

          ports[idPort] = new Port(idPort, x, y);
          idPort++;
      break;
      case (4): //Load a container to a ship
          inputFile>> shipId; inputFile>> containerId;

          ships[shipId]->load(containers[containerId]);
      break;
      case (5): //Unload a container from a ship
          inputFile>> shipId; inputFile>> containerId;

          ships[shipId]->unLoad(containers[containerId]);
      break;
      case (6): //Sail a ship to a port
          inputFile>> shipId; inputFile>> portId;

          ships[shipId]->sailTo(ports[portId]);
      break;
      case (7): //Refuel a ship
          inputFile>> shipId; inputFile>> fuel;

          ships[shipId]->reFuel(fuel);
      break;
    }
  }

  for (int i = 0; i < ports.size(); i++){
    outputFile<<ports[i]->toString()<<endl;
    outputFile<<endl;
  }

  inputFile.close();
  outputFile.close();
  return 0;
}
