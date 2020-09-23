import os
import sys
import glob
import json
# import numpy as np

PWD = os.path.abspath(os.path.dirname(__file__))
SO_pattern = f'{PWD}/build/**/binding*.cpython-*.so'
SOs = glob.glob(SO_pattern, recursive=True)
assert SOs, f'not any matched SO file found, should be like {SO_pattern}, did you turn on `-DBUILD_BINDINGS=ON` when cmake'
sys.path.insert(0, os.path.dirname(SOs[0]))

import binding
pod = binding.Pod()
print(pod.optional)
assert pod.optional is None
pod.optional = "text"
print(pod.optional)
assert pod.optional == "text"