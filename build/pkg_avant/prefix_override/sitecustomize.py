import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/avant/Grupo-6-Trainee-Avant/install/pkg_avant'
