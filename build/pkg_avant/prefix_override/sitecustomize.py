import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/avant/simulation/starts/avant_ws/install/pkg_avant'
