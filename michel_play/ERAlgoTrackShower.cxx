#ifndef ERTOOL_ERALGOTRACKSHOWER_CXX
#define ERTOOL_ERALGOTRACKSHOWER_CXX

#include "ERAlgoTrackShower.h"

namespace ertool {

  ERAlgoTrackShower::ERAlgoTrackShower(const std::string& name) : AlgoBase(name)
  {}

  void ERAlgoTrackShower::Reset()
  {}

  void ERAlgoTrackShower::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAlgoTrackShower::ProcessBegin()
  {}

  bool ERAlgoTrackShower::Reconstruct(const EventData &data, ParticleGraph& graph)
  {return true;}

  void ERAlgoTrackShower::ProcessEnd(TFile* fout)
  {}

}

#endif
