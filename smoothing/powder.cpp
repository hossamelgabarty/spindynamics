/*
    Smoothing a stick spectrum by convoluting with a gaussian.
    Copyright (C) 2013  Hossam Elgabarty <hossam.elgabarty@fu-berlin.de>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "powder.h"


using namespace std;
namespace po = boost::program_options;
namespace fs = boost::filesystem;

smooth::smooth(const VectorX& A, const VectorX& B, const int C, const fp D, const int E)
  :field(A)
  ,intensity(B)
  ,npoints(C)
  ,broadening(D)
  ,zerofill(E)
{
  makeFieldGrid();
  uniformFieldGrid.resize(npoints);
}

smooth::~smooth()
{

}

fix npoints

smooth::makeFieldGrid()
{
  double fieldMin=field.minCoeff();
  double fieldMax=field.maxCoeff();
  double range = fieldMax-fieldMin;
  double delta = range/npoints;
  
  for ( unsigned int i=0; i<npoints; ++i)
    {
      uniformFieldGrid(i)=fieldMin+i*delta;
    }
}

smooth::convolute()
{

}

//const VectorX smooth::convolute(const VectorX&, const int npoints, const fp broadening, const fp zfill) const
//{
//Eigen::FFT<double> fft;
  
  //std::vector<double> timevec = MakeMyData();
  //std::vector<std::complex<double> > freqvec;
  
  //fft.fwd( freqvec,timevec);
  // manipulate freqvec
  //fft.inv( timevec,freqvec);
//}


FreqSpectrumParser::FreqSpectrumParser(const vector<string> spectra, VectorX& A, VectorX& B)
:input_files(spectra)
,field(A)
,intensity(B)
{
 parse(); 
}

void FreqSpectrumParser::parse()
{
  string temp;
  ifstream currentfile;
  double col1, col2, col6;
  string line;
  stringstream sline;
  vector<double> v_field;
  vector<double> v_intensity;
  
  for (unsigned int i=0; i<input_files.size(); ++i)
    {
    currentfile.open(input_files[i].c_str());
    while(currentfile.good())
      {
	currentfile >> col1 >> col2 >> temp >> temp >> temp >> col6;
	v_field.push_back(col1);
	v_intensity.push_back(col2*col6);
      }
    currentfile.close(); 
    v_intensity.pop_back();
    v_field.pop_back();
  }

  field.resize(v_field.size(),1);
  intensity.resize(v_intensity.size(),1);
  
  

  for (unsigned int i=0; i<v_field.size(); ++i)
  {
    field(i)=v_field[i];
    intensity(i)=v_intensity[i];
  }
}
