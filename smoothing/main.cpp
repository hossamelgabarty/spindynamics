/*
 *    Compute a smoothed powder average by reading multiple output files
 *    Copyright (C) 2013  Hossam Elgabarty <hossam.elgabarty@fu-berlin.de>
 * 
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 * 
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 * 
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "powder.h"

using namespace std;
namespace po = boost::program_options;
namespace fs = boost::filesystem;


int main(int argc, char** argv)
{
  // Declare the supported options.
  po::options_description desc("OPTIONS");
  desc.add_options()
    ("help,h", "show help message")
    ("spectrum,s", po::value< vector<string> >()->multitoken()->required(), "Input spectra")
    ("broaden,b", po::value<double>()->default_value(0.001), "Broadening, in units of seconds")
    ("npoints,n", po::value<long>()->default_value(1024), "Number of grid points")
    ("zerofill,z", po::value<int>()->default_value(0),"Zero fill for the FFT")
    ;
  
  po::variables_map vm;
  po::store(po::parse_command_line(argc, argv, desc), vm);
  
  if (vm.count("help")) {
    cout << desc << endl << endl;
    return 0;
  }
  
  try { po::notify(vm); }
  catch(...) {
    cerr << "Wrong number/type of arguments!\n";
    cout << desc << endl << endl;
    return 1;
  }

  
  vector<string> infiles = vm["spectrum"].as< vector<string> >();
  VectorX field,intensity;
  FreqSpectrumParser parser(infiles,field,intensity);
  
  


  return 0;
}
