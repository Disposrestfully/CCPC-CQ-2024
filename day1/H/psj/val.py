import yaml
import os
import random
import math
import numpy as np
import subprocess

psjpath = os.path.dirname(__file__)
probpath = os.path.dirname(psjpath)
downpath = os.path.join(probpath, "down")
datapath = os.path.join(probpath, "data")
valpath = os.path.join(probpath, 'psj', 'val.cpp')

with open(os.path.join(probpath, 'conf.yaml'), mode='r', encoding='UTF-8') as f:
    file = yaml.safe_load(f)

os.system(f"g++ -o val {valpath} -O2")

def runval(isdown: bool, id: int):
    with open(os.path.join(downpath if isdown else datapath, str(id) + ".in"), "r") as f:
        if subprocess.run(f"val.exe", stdin=f).returncode != 0:
            exit()
    print(f"{"down" if isdown else "data"} {id} complete.")

for data_group in file['data']:
    cases = data_group['cases']
    for case in cases:
        runval(isdown = False, id = case)

for data_group in file['samples']:
    cases = data_group['cases']
    for case in cases:
        runval(isdown = True, id = case)