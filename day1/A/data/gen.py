import yaml
import os
import random
import math
import numpy as np

datapath = os.path.dirname(__file__)
probpath = os.path.dirname(datapath)

with open(os.path.join(probpath, 'conf.yaml'), mode='r', encoding='UTF-8') as f:
    file = yaml.safe_load(f)

np.random.seed(8889)
random.seed(8889)
finished_generation = []
pren = 0

for data_group in file['data']:
    cases = data_group['cases']
    n = data_group['args']['n']
    a = data_group['args']['a']
    sp = data_group['args']['sp']
    
    newCases = set(cases).difference(set(finished_generation))
    
    for case in newCases:
        with open(os.path.join(datapath, "%d.in" % case), mode = 'w', encoding='UTF-8') as f:
            f.write(str(n) + "\n")
            arr = []
            if sp is True:
                def gcd(a: int, b: int):
                    return gcd(b, a % b) if b != 0 else a
                
                candidate = [i for i in range(1, a + 1)]
                for p in range(n):
                    newval = random.choice(candidate)
                    arr.append(newval)
                    new_candidate = []
                    for num in candidate:
                        if gcd(num, newval) == 1:
                            new_candidate.append(num)
                    candidate = new_candidate
                
                random.shuffle(arr)
            else:
                arr = [random.randint(1, a) for _ in range(n)]
            
            for index, num in enumerate(arr):
                if index != 0:
                    f.write(" ")
                f.write(str(num))
            f.write("\n")
        
        os.system("std.exe < %d.in > %d.ans" % (case, case))
        print("Case %d Finished." % case)
        finished_generation.append(case)
