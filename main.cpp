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

  int idContainer, idPorts, idShip;
  idContainer = idPorts = idShip = 0;


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
  for(){

  }
  inputFile>>tipoEvento;

  inputFile>>x>>y;
  ports[idPorts] = new Port(idPorts, x, y);
  idPorts++;

  inputFile.close();
  outputFile.close();
  return 0;
}