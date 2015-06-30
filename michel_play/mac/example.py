import sys
from ROOT import gSystem
gSystem.Load("libmichel3d_michel_play")
from ROOT import sample

try:

    print "PyROOT recognized your class %s" % str(sample)

except NameError:

    print "Failed importing michel_play..."

sys.exit(0)

