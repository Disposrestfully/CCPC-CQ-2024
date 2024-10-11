import yaml
import os
import sys
import random
import math
import numpy as np
import subprocess

datapath = os.path.dirname(__file__)
probpath = os.path.dirname(datapath)
downpath = os.path.join(probpath, "down")
stdpath = os.path.join(probpath, 'psj', 'std.cpp')

with open(os.path.join(probpath, 'conf.yaml'), mode='r', encoding='UTF-8') as f:
    file = yaml.safe_load(f)

np.random.seed(990880)
random.seed(990880)
MAXL = file['args']['len']
MAXK = file['args']['k']

def printcase(isdown: bool, id: int, data: list):
    path = os.path.join(downpath if isdown else datapath, str(id))
    with open(path + ".in", 'w') as f:
        assert data[1] <= MAXK and data[2] <= MAXK and data[1] > 0 and data[2] > 0 and len(data[0]) <= MAXL
        f.write(data[0] + "\n" + str(data[1]) + " " + str(data[2]) + "\n")
    os.system(f"std.exe < {path}.in > {path}.ans")
    #print(f"{"down" if isdown else "data"} {id} complete.", file=sys.stderr, flush=True)
    print(f"{"down" if isdown else "data"} {id} complete.")

# Compile
os.system(f"g++ -o std {stdpath} -O2 -DRUNGEN")

# Data Func
def coin_flip(prob):
    return random.random() < prob

# Gen Data
printcase(False, 1, ("".join([chr(random.randint(33, 126)) for _ in range(random.randint(1, MAXL))]), random.randint(1, MAXK), random.randint(1, MAXK)))
printcase(False, 2, ("".join([chr(random.randint(33, 126)) for _ in range(random.randint(1, MAXL))]), random.randint(1, MAXK), random.randint(1, MAXK)))
printcase(False, 3, ("".join(["\'" for _ in range(MAXL)]), random.randint(1, MAXK), random.randint(1, MAXK)))
printcase(False, 4, ("".join(["\"" for _ in range(MAXL)]), random.randint(1, MAXK), random.randint(1, MAXK)))
printcase(False, 5, ("".join([chr(random.randint(33, 126)) for _ in range(MAXL)]), MAXK, 1))
printcase(False, 6, ("".join([chr(random.randint(33, 126)) for _ in range(MAXL)]), random.randint(1, MAXK), 2))
printcase(False, 7, ("".join([chr(random.randint(33, 126)) for _ in range(MAXL)]), MAXK, MAXK))
printcase(False, 8, ("".join([chr(random.randint(33, 126)) for _ in range(MAXL)]), MAXK, 2500))
printcase(False, 9, (("\'"), 1, MAXK))
printcase(False, 10, (("\"\'"), 3, MAXK - 1))
printcase(False, 11, (chr(random.randint(33, 126)), random.randint(1, MAXK), random.randint(1, MAXK)))

# Gen Down
printcase(True, 3, ("".join([chr(ind) for ind in range(33,127)]), MAXK, MAXK))