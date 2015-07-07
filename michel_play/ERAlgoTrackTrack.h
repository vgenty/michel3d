/**
 * \file ERAlgoTrackTrack.h
 *
 * \ingroup michel_play
 * 
 * \brief Class def header for a class ERAlgoTrackTrack
 *
 * @author vgenty
 */

/** \addtogroup michel_play

    @{*/

#ifndef ERTOOL_ERALGOTRACKTRACK_H
#define ERTOOL_ERALGOTRACKTRACK_H

#include "ERTool/Base/AlgoBase.h"

namespace ertool {

  /**
     \class ERAlgoTrackTrack
     User custom Algorithm class made by kazuhiro
   */
  class ERAlgoTrackTrack : public AlgoBase {
  
  public:

    /// Default constructor
    ERAlgoTrackTrack(const std::string& name="ERAlgoTrackTrack");

    /// Default destructor
    virtual ~ERAlgoTrackTrack(){};

    /// Reset function
    void Reset();

    /// Function to accept fclite::PSet
    void AcceptPSet(const ::fcllite::PSet& cfg);

    /// Called @ before processing the first event sample
    void ProcessBegin();

    /// Function to evaluate input showers and determine a score
    bool Reconstruct(const EventData &data, ParticleGraph& graph);

    /// Called after processing the last event sample
    void ProcessEnd(TFile* fout=nullptr);

  };
}
#endif

/** @} */ // end of doxygen group 
