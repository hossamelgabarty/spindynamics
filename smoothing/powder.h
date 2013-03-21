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


#ifndef POWDER_H
#define POWDER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>

#include <unsupported/Eigen/FFT>
#include <spinlib/eigentypes.h>

class smooth
{

public:
  smooth(const VectorX& field, const VectorX& intensity, const int npoints, const fp broadening, const int zerofill);
  virtual ~smooth();
    
private:
  const VectorX& field;
  const VectorX& intensity;
  const int npoints;
  const fp broadening;
  const int zerofill;
  VectorX uniformFieldGrid;
  
  void makeFieldGrid();
  const VectorX convolute();
};

class FreqSpectrumParser
{
public:
  FreqSpectrumParser(const std::vector<std::string>, VectorX&, VectorX&);
  
private:
  const std::vector<std::string> input_files;
  VectorX& field;
  VectorX& intensity;
  void parse();
};

#endif // POWDER_H
