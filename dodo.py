'''
Parallel build and run all examples.

doit
doit --continue -n 7

'''

import os
import re
import sys
thispath = os.path.dirname(__file__)
if sys.path[0] != thispath:
    sys.path.insert(0, thispath)
from cppreference_com_examples import rindices
target = lambda l: l.split('-o')[1].split()[0].strip()
normjoin = lambda *x: os.path.normpath(os.path.join(*x)).replace("\\", "/")
def task_compile():
    dir = os.getcwd()
    regexp = re.compile(r"^(g\+\+|gcc|clang) ")
    exts=set(['.c','.cpp'])
    for root, dirs, files in os.walk(dir):
        if '.' in root: continue
        for d in dirs: os.makedirs('../_build/'+d,exist_ok=True)
        for name in files:
            if any(name.endswith(ext) for ext in exts):
                f = normjoin(root,name)
                with open(f,encoding="utf-8") as fb:
                    lines=[l.strip() for l in fb.readlines()]
                    res = [(i,lines[i]) for i in rindices(regexp, lines)]
                    for (i,l) in res:
                        try:
                            tgt = target(l)
                            yield {'name': f,
                               'actions': [l],
                               'file_dep': [f],
                               'targets': [tgt],
                               }
                        except:
                            print(tgt)


#list(task_compile())
