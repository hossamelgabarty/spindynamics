/*
 * This file is part of my bachelor thesis.
 *
 * Copyright 2011 Milian Wolff <mail@milianw.de>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef MW_BACHELOR_TYPES_H
#define MW_BACHELOR_TYPES_H

// typedef double fp;
// typedef long double fp;
typedef float fp;

/****************** MPI Types ******/
#include <boost/mpi.hpp>
#include <boost/lexical_cast.hpp>

namespace mpi = boost::mpi;

class BisectInput
{
public:
  BisectInput()
  { }

  BisectInput(fp _from, fp _to, fp _mwFreqGHz)
  : from(_from), to(_to), mwFreqGHz(_mwFreqGHz)
  { }

  fp from;
  fp to;
  fp mwFreqGHz;

private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & from;
    ar & to;
    ar & mwFreqGHz;
  }
};

class BisectAnswer
{
public:
  BisectAnswer()
  { }

  enum Status {
    Continue, Resonant, NotResonant
  };

  BisectAnswer(Status _status, fp _from, fp _mid, fp _to)
  : status(_status), from(_from), mid(_mid), to(_to)
  { }

  Status status;
  fp from;
  fp mid;
  fp to;

private:
  friend class boost::serialization::access;

  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & status;
    ar & from;
    ar & mid;
    ar & to;
  }
};

/****************** EIGEN Types ***********/

#include <complex>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

typedef complex<fp> c_fp;

typedef Matrix<fp, 2, 2> Matrix2;
typedef Matrix<c_fp, 2, 2> Matrix2c;

typedef Matrix<fp, 3, 3> Matrix3;
typedef Matrix<c_fp, 3, 3> Matrix3c;

typedef Matrix<fp, 4, 4> Matrix4;
typedef Matrix<c_fp, 4, 4> Matrix4c;

typedef Matrix<fp, Dynamic, Dynamic> MatrixX;
typedef Matrix<c_fp, Dynamic, Dynamic> MatrixXc;

typedef Matrix<fp, 3, 1> Vector3;
typedef Matrix<c_fp, 3, 1> Vector3c;

typedef Matrix<fp, 4, 1> Vector4;
typedef Matrix<c_fp, 4, 1> Vector4c;

typedef Matrix<fp, Dynamic, 1> VectorX;
typedef Matrix<c_fp, Dynamic, 1> VectorXc;

#endif // MW_BACHELOR_TYPES_H
