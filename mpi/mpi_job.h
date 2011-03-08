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

#ifndef MW_MPI_JOB_H
#define MW_MPI_JOB_H

#include "mpi_iface.h"

#include "spinlib/resonancefield.h"

class MPIMaster;

class MPIJob {
public:
  MPIJob(MPIMaster *master);
  virtual ~MPIJob();

  virtual void start() = 0;
  virtual void handleResult() = 0;

protected:
  MPIMaster* const m_master;
};

class BisectStartJob : public MPIJob {
public:
  BisectStartJob(MPIMaster* master, const fp from, const fp to);
  virtual ~BisectStartJob();

  virtual void start();
  virtual void handleResult();

private:
  const fp m_from;
  const fp m_to;
  BisectNode m_fromAnswer;
  BisectNode m_toAnswer;
  int m_handledResults;
};

class BisectJob : public MPIJob {
public:
  BisectJob(MPIMaster* master, const BisectNode& from, const BisectNode& to);
  virtual ~BisectJob();

  virtual void start();
  virtual void handleResult();

private:
  const BisectNode m_from;
  const BisectNode m_to;
  BisectAnswer m_answer;
};

class FindRootsJob : public MPIJob {
public:
  FindRootsJob(MPIMaster* master, const BisectNode& from, const BisectNode& to);
  virtual ~FindRootsJob();

  virtual void start();
  virtual void handleResult();

private:
  const BisectNode m_from;
  const BisectNode m_to;
  std::vector<fp> m_answer;
};

class IntensityJob : public MPIJob {
public:
  IntensityJob(MPIMaster* master, const fp B);
  virtual ~IntensityJob();

  virtual void start();
  virtual void handleResult();

private:
  const fp m_B;
  fp m_answer;
};

#endif // MW_MPI_JOB_H
