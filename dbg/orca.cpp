#include <iostream>

#include <boost/foreach.hpp>

#include "spinlib/orcaparser.h"
#include "spinlib/nucleus.h"

using namespace std;
using namespace Eigen;

int main(int argc, char** argv) {
  if (argc < 2) {
    cerr << "orca FILE missing" << endl;
    return 1;
  }

  OrcaParser parser(argv[1]);

  cout << "electron G Matrix:" << endl << parser.electronGMatrix() << endl;

  BOOST_FOREACH(const Nucleus& nuc, parser.nuclei()) {
    cout << "Nucleus: " << nuc.name << ", J = " << float(nuc.twoJ)/2 << ", g = " << nuc.g << endl;
    cout << nuc.A << endl;
  }

  return 0;
}
