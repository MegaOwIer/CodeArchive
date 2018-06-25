import os
import sys
import time

def terminate(s):
    print(s)
    sys.exit()

if __name__ == "__main__":
    argv = sys.argv
    dirName = argv[1]
    fileName = argv[2]
    baseName = os.path.splitext(fileName)[0]
    if fileName.endswith(".cpp"):
        res = os.system("g++ " + fileName + " -o " + baseName + " -O2 -Wall -Wextra -std=c++11 -Wl,-stack=1024000000")
        if res:
            terminate("Compile Error")
        print("---Compile Success---")
        start = time.time()
        res = os.system("cd " + dirName + " && " + baseName)
        if res:
            terminate("Runtime Error with code " + str(res))
        print("\nTime Used:\n{}".format(time.time()-start))
    elif fileName.endswith(".py"):
        start = time.time()
        res = os.system("cd " + dirName + " && python " + fileName)
        if res:
            terminate("Runtime error")
        print("\nTime Used:\n{}".format(time.time()-start))
