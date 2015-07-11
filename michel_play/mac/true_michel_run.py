import sys

if len(sys.argv) < 2:
    msg  = '\n'
    msg += "Usage 1: %s $INPUT_ROOT_FILE\n" % sys.argv[0]
    msg += '\n'
    sys.stderr.write(msg)
    sys.exit(1)

from seltool import ertool
from larlite import larlite as fmwk

# Create ana_processor instance
my_proc = fmwk.ana_processor()

# Set input root file
for x in xrange(len(sys.argv)-1):
    my_proc.add_input_file(sys.argv[x+1])

# Specify IO mode
my_proc.set_io_mode(fmwk.storage_manager.kREAD)

# Specify output root file name
my_proc.set_ana_output_file("ertool_hist.root")

my_algo    = ertool.AlgoMichelE()
my_ana     = ertool.ERAnaMichelE()
my_anaunit = fmwk.ExampleERSelection()

my_anaunit.SetShowerProducer(True,"mcreco");
#my_anaunit.SetTrackProducer (False,"trackkalmanhitcc");

my_anaunit.SetShowerProducer(True,"mcreco");
#my_anaunit.SetTrackProducer (False,"trackkalmanhitcc");
my_anaunit._mgr._mc_for_ana = True

my_anaunit._mgr.AddAna(my_ana)
my_anaunit._mgr.AddAlgo(my_algo)
my_proc.add_process(my_anaunit)

# run!
my_proc.run()

# done!
print
print "Finished running ana_processor event loop!"
print

sys.exit(0)

