#ifndef ERTOOL_ERALGOTRACKTRACK_CXX
#define ERTOOL_ERALGOTRACKTRACK_CXX

#include "ERAlgoTrackTrack.h"

namespace ertool {

  ERAlgoTrackTrack::ERAlgoTrackTrack(const std::string& name) : AlgoBase(name)
  {
    _verbose = false;
  }

  void ERAlgoTrackTrack::Reset()
  {}

  void ERAlgoTrackTrack::AcceptPSet(const ::fcllite::PSet& cfg)
  {}

  void ERAlgoTrackTrack::ProcessBegin()
  {
    _output_tree = new TTree("out_tree","aho_tree");
    _output_tree->Branch("_dist",&_dist,"_dist/D");
    
  }

  bool ERAlgoTrackTrack::Reconstruct(const EventData &data, ParticleGraph& graph)
  {

    // Loop through Particles associated with a shower object
    
    // const CombinationSet_t GetNodeCombinations( const size_t combination_size,
    // 						const RecoType_t type = kINVALID_RECO_TYPE,
    // 						const bool unassessed_only = false,
    // 						const int pdg_code = 0) const;
    
    const auto comb = graph.GetNodeCombinations(2,RecoType_t::kTrack);
    for(const auto& c : comb) {
	
	auto const& track1 = data.Track(graph.GetParticle(c[0]).RecoID());
	auto const& track2 = data.Track(graph.GetParticle(c[1]).RecoID());
	
	// for (auto const& t1 : graph.GetParticleNodes(RecoType_t::kTrack)){
	//   for (auto const& t2 : graph.GetParticleNodes(RecoType_t::kTrack)){
	
	//auto const& shower = data.Shower(graph.GetParticle(p).RecoID());
	
	//if( _alg_emp.LL(true, shower._dedx, -1) > _alg_emp.LL(false, shower._dedx, -1)){
      
	// Loop through Particles associated with a track
	
	
	// get track objects
	
	// calculate distance between track end point and shower start point
	
	
	auto const& track1End   = track1.back();
	auto const& track2Start = track2.front();
	
	//auto const shwrStart = shower.Start();
	//double dist = shwrStart.Dist(trackEnd);
	
	// fill histogram with distance
	//shower_st_to_track_end->Fill(dist);
	
	//Check if this shower is at the end of this tracks,
	//Making sure the track is longer than the minimum length required
	// if( (shower.Start().Dist(track.back()) < _maxDistance) && 
	//     (track.Length() > _minMuonLength) )
	//   {
	      
	//     // we found a new michel!
	//     n_michel_e++;
	      
	//     // edit the particle's information
	//     graph.GetParticle(p).SetParticleInfo(11,
	// 					 ParticleMass(11),
	// 					 trackEnd,
	// 					 shower.Dir()*shower._energy);

	//     // also since we know it, add info on relationship
	//     // between michel electron and muon track
	//     // first: node of parent
	//     // second: node of child
	//     graph.SetParentage(t,p);

	    // finally, if in verbose mode, cout some info
	if (_verbose){
	  std::cout << "We found two tracks!!! track1End: "
		    << track1End   << " track2Start "
		    << track2Start << " thats it..." 
		    << std::endl;
	}
	
	// fill histogram with michel electron energy
	//michel_energy->Fill(shower._energy);
	
	// we found that this shower is a michel 
	
	// -> stop looping through tracks
	// break;
	
	//End if michel was found
	
	_dist = track1End.Dist(track2Start);
	_output_tree->Fill();
	_dist = 0.0;

      }//End loop over tracks
    //End if shower is likely an electron
    //End loop over showers
    
    return true;
  }
  
  void ERAlgoTrackTrack::ProcessEnd(TFile* fout)
  {
    _output_tree->Write();
  }
  
}

#endif
