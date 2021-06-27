#!/usr/bin/env python
"""
To get the examples from `cppreference.com <https://en.cppreference.com/>`__:

- html downloaded
- find examples
- pandoc convert
- extract examples

Needs:

- bash
- wget
- rg (ripgrep)
- pandoc

"""

import os
import shlex
from numpy import base_repr
from glob import glob
import string
namechars = set(string.punctuation)-{'_'}

encpp = 'en.cppreference.com'

def rindices(regex, lns):
  regex = re.compile(regex)
  for i, ln in enumerate(lns):
    if regex.search(ln):
      yield i

def doextract(fll,lineidx):
  llen = len(fll)
  lnri = fll[lineidx]
  cspaces = lambda x: len(x)-len(x.lstrip())
  spaces = cspaces(lnri)
  spaces6 = spaces+6
  first = lineidx
  while True:
    first = first+1
    if cspaces(fll[first])==spaces6 or first > lineidx+9:
      break
  if first <= lineidx+9:
    last = first
    while True:
      last = last+1
      if cspaces(fll[last])<spaces6 or last > llen:
        break
  #first,last
  example = [x[spaces6:] for x in fll[first:last] if len(x.strip())!=0]
  return "".join(example)

def fileexamples(filename,orgpath):
  is_c = filename[3] == '_'
  fll = open(filename).readlines()
  ricpp = rindices(r"^\s*\.\.\s*container::\s*cpp\s*source-cpp",fll)
  ric = rindices(r"^\s*\.\.\s*container::\s*c\s*source-c",fll)
  lri = list(ricpp)+list(ric)
  m = 0
  for lineidx in lri:
    ccpp = is_c and '/c/' or '/cpp/'
    orgn = orgpath.split(ccpp)[1].replace('/','_')
    nmn = ''.join([x for x in orgn if x not in namechars])
    if m>0:
      nmn = nmn + "_" + str(m)
    m = m+1
    srcname = '.'+ccpp+nmn+'.'+ccpp[1:-1]
    exename = '../_build'+ccpp+nmn+'.exe'
    if not os.path.exists(srcname):
      smpl = doextract(fll,lineidx)
      smpl = smpl.encode().replace(b'\xc2\xa0',b'\x20').decode()
      if 'main' in smpl:
        cmplr = is_c and 'gcc -std=c99 -pthread' or 'g++ --std=c++20 -pthread'
        exe = '(cd ../_build'+ccpp+';./'+os.path.basename(exename)+')'
        fsmpl = "/*\n{} -o {} {} && {}\n{}\n*/\n{}\n".format(
          cmplr,exename,srcname,exe,'https://'+encpp+'/'+orgpath,smpl)
        #fsmpl
        with open(srcname,"w") as f:
          f.write(fsmpl)

class cppreference:
  def __init__(self,dst='~/Downloads'):
    self.lscpp=[]
    self.lsc=[]
    self.rst2org = {}
    self.dst = os.path.expanduser(dst)
    os.chdir(self.dst)
  def __call__(self):
    self.html_download()
    self.find_examples()
    self.pandoc_convert()
    self.extract_samples()
  def html_download(self):
    os.system('wget -r -np -nc https://'+encpp+'/')
    self.dst = os.path.join(self.dst,encpp)
    os.chdir(self.dst)
  def find_examples(self):
    os.system("rg -l t-example > t-example.txt")
    os.system("rg -l main > main.txt")
    texample = open("t-example.txt").readlines()
    maintxt = open("main.txt").readlines()
    stexample = set(texample)
    smaintxt = set(maintxt)
    sboth = stexample&smaintxt
    self.lscpp=[x.strip() for x in sorted(sboth) if x.startswith("w/cpp/")]
    self.lsc=[x.strip() for x in sorted(sboth) if x.startswith("w/c/")]
  def pandoc_convert(self):
    self.rst2org = {}
    with open('pandoccvt.sh','w') as pc:
      for i,lsb in enumerate(self.lscpp):
        lsq = shlex.quote(lsb)
        frst = 'rst%s.rst'%i
        pc.write("pandoc -f html -t rst {} -o {}\n".format(lsq,frst))
        self.rst2org[frst] = lsb
      for i,lsb in enumerate(self.lsc):
        lsq = shlex.quote(lsb)
        frst = 'rst_%s.rst'%i
        pc.write("pandoc -f html -t rst {} -o {}\n".format(lsq,frst))
        self.rst2org[frst] = lsb
    os.system('rm rst*.rst')
    os.system('bash pandoccvt.sh')
  def extract_samples(self):
    rstglob = list(sorted(glob("rst*.rst")))
    assuredir = lambda x: os.path.exists(x) or os.makedirs(x,exist_ok=True)
    assuredir('c')
    assuredir('cpp')
    assuredir('../_build/c')
    assuredir('../_build/cpp')
    for filename in rstglob:
      #filename = rstglob[0]
      orgpath = self.rst2org[filename]
      fileexamples(filename,orgpath)

if __name__ == '__main__':
  self = cppreference()
  self()
