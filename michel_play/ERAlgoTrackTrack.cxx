#ifndef ERTOOL_ERALGOTRACKTRACK_CXX
#define ERTOOL_ERALGOTRACKTRACK_CXX

#include "ERAlgoTrackTrack.h"

namespace ertool {

  ERAlgoTrackTrack::ERAlgoTrackTrack(const std::string& name) : AlgoBase(name)
  {}

  void ERAlgoTrackTrack::Reset()
  {}

  void ERAlgoTrackTrack::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAlgoTrackTrack::ProcessBegin()
  {}

  bool ERAlgoTrackTrack::Reconstruct(const EventData &data, ParticleGraph& graph)
  {
    // Get MC particle set
    auto const& mc_graph = MCParticleGraph();
    auto const& mc_evtdata = MCEventData();
    auto const& mcparticles = mc_graph.GetParticleArray();
    
    // instantiate objects to use
    ::ertool::Particle recoPart;

    
    return true;
  }

  void ERAlgoTrackTrack::ProcessEnd(TFile* fout)
  {}

}

#endif
