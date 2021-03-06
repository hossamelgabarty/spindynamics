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

#include "mpi_slave.h"

#include "mpi_iface.h"

#include "spinlib/spinhamiltonian.h"
#include "spinlib/experiment.h"

using namespace std;

MPISlave::MPISlave(const mpi::communicator& comm, const Experiment& exp)
: m_comm(comm)
, m_exp(exp)
, m_resonanceField(m_exp)
{
  if (comm.rank() == MASTER_RANK) {
    cerr << "MPISlave created in master rank!" << endl;
    comm.abort(1);
    return;
  }

}

MPISlave::~MPISlave()
{

}

void MPISlave::work()
{
  Commands cmd;
  while(true) {
    m_comm.recv(MASTER_RANK, TAG_CMD, cmd);
    switch(cmd) {
      case CMD_CLOSE:
        return;
      case CMD_BISECT: {
        /*
         * bisect range and decide whether it is resonant or not.
         *
         * input: BisectInput
         * output: BisectAnswer
         */
        BisectInput input;
        m_comm.recv(MASTER_RANK, TAG_BISECT_INPUT, input);
        m_exp.orientation = input.orientation.orientation;
        m_comm.send(MASTER_RANK, TAG_BISECT_RESULT, m_resonanceField.checkSegment(input.from, input.to));
        break;
      }
      case CMD_DIAGONALIZE: {
        /*
         * diagonlize spin hamiltonian and reply with eigen values and derivative of it
         *
         * input: fp B - static B field node
         * output: BisectNode
         */
        DiagonalizeInput input;
        m_comm.recv(MASTER_RANK, TAG_DIAGONALIZE_INPUT, input);
        m_exp.orientation = input.orientation.orientation;
        m_comm.send(MASTER_RANK, TAG_DIAGONALIZE_RESULT, m_resonanceField.diagonalizeNode(input.B));
        break;
      }
      case CMD_FINDROOTS: {
        /*
         * find roots in given input segment
         *
         * input: BisectInput
         * output: vector<fp>
         */
        BisectInput input;
        m_comm.recv(MASTER_RANK, TAG_FINDROOTS_INPUT, input);
        m_exp.orientation = input.orientation.orientation;
        vector<fp> answer = m_resonanceField.findRootsInSegment(input.from, input.to);
        m_resonanceField.cleanupResonancyField(answer);
        m_comm.send(MASTER_RANK, TAG_FINDROOTS_RESULT, answer);
        break;
      }
      case CMD_INTENSITY: {
        /*
        * calculate intensity at given B
        *
        * input: fp B
        * output: fp intensity
        */
        IntensityInput input;
        m_comm.recv(MASTER_RANK, TAG_INTENSITY_INPUT, input);
        m_exp.orientation = input.orientation.orientation;
        SpinHamiltonian H(input.B, m_exp);
        m_comm.send(MASTER_RANK, TAG_INTENSITY_RESULT, H.calculateIntensity());
        break;
      }
    }
  }
}
