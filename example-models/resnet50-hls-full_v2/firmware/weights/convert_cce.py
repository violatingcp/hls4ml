#!/usr/bin/python

import sys

File=sys.argv[1]
outFileName=File.replace(".txt",".coe")

outFile = open(outFileName, 'w')
outFile.write('memory_initialization_radix=10;\n')

inFile = open(File, "r")
outFile.write(inFile.read()+";")

outFile.close()
inFile.close()
