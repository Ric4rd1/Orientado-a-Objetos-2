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

  //outputFile << "pepo peg" << '\n';
  // TO DO

  inputFile>>c>>s>>p>>n;

  for(int i = 0 ; i <= n ; i++){
    int eventType;
    inputFile>> eventType;
    
    switch (eventType){
      case (1): //Create a container
        int weight, initPort;
        char type;
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
          int totalWeight, maxAll, maxHeavy, maxRefrigerated, maxLiquid;
          double fuelConsumption;
          inputFile>> initPort; inputFile>> totalWeight; inputFile>> maxAll; inputFile>> maxHeavy; 
          inputFile>> maxRefrigerated; inputFile>> maxLiquid; inputFile>> fuelConsumption;

          ships[idShip] = new Ship(idShip, ports[initPort], totalWeight, maxAll, maxHeavy, maxRefrigerated, maxLiquid, fuelConsumption);
          
          idShip++;
      break;
      case (3): //Create a port
          double x, y;
          inputFile>> x; inputFile>> y;

          ports[idPort] = new Port(idPort, x, y);
          idPort++;
      break;
      case (4): //Load a container to a ship
          int shipId, containerId;
          inputFile>> shipId; inputFile>> containerId;

          ships[shipId]->load(containers[containerId]);
      break;
      case (5): //Unload a container from a ship
          inputFile>> shipId; inputFile>> containerId;

          ships[shipId]->unLoad(containers[containerId]);
      break;
      case (6): //Sail a ship to a port
          int portId;
          inputFile>> shipId; inputFile>> portId;

          ships[shipId]->sailTo(ports[portId]);
      break;
      case (7): //Refuel a ship
          double fuel;
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