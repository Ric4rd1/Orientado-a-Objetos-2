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
  vector<SimpleShip*> ships;
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

  // TO DO
  /*
  container
  puertos
  ship
*/

  inputFile>>c>>s>>p>>n;

  for(int i = 0 ; i <= n ; i++){

    int eventType;
    inputFile>> eventType;
    int weight = 0;
    string type = "";

    switch (eventType){
      case (1): //Create a container
        inputFile>> idPort;
        inputFile>> weight;
        inputFile>> type;

        if (type == "B"){
          if (weight <= 3500){
            containers[idContainer] = new LightContainer(idContainer, weight);

          } else {
            containers[idContainer] = new HeavyContainer(idContainer, weight);
          }
        } else if (type == "R"){
          containers[idContainer] = new RefrigeratedContainer(idContainer, weight);
        } else if (type == "L"){
          containers[idContainer] = new LiquidContainer(idContainer, weight);
        }
        *ports[idPort].add(containers[idContainer]);
        idContainer++;

      break;
      case (2): //Create a ship

      break;
      case (3): //Create a port

      break;
      case (4): //Load a container to a ship

      break;
      case (5): //Unload a container from a ship

      break;
      case (6): //Sail a ship to a port

      break;
      case (7): //Refuel a ship

      break;
    }

  }

  ports[idPorts] = new Port(idPorts, x, y);
  idPorts++;

  inputFile.close();
  outputFile.close();
  return 0;
}