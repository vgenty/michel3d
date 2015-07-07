/**
 * \file ERAlgoTrackShower.h
 *
 * \ingroup michel_play
 * 
 * \brief Class def header for a class ERAlgoTrackShower
 *
 * @author vgenty
 */

/** \addtogroup michel_play

    @{*/

#ifndef ERTOOL_ERALGOTRACKSHOWER_H
#define ERTOOL_ERALGOTRACKSHOWER_H

#include "ERTool/Base/AlgoBase.h"

namespace ertool {

  /**
     \class ERAlgoTrackShower
     User custom Algorithm class made by kazuhiro
   */
  class ERAlgoTrackShower : public AlgoBase {
  
  public:

    /// Default constructor
    ERAlgoTrackShower(const std::string& name="ERAlgoTrackShower");

    /// Default destructor
    virtual ~ERAlgoTrackShower(){};

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
