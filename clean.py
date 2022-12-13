def clean (src, flag):
    indxpc = 0
    indxWhtspc = 0
    indxpar = 0
    try:
        file = open(src,"r")
    except:
        print("File doesn't open (probably doesn't exist)")
        return

    out = "{}.clean.c".format(src)
    outfile = open(out, "w")

    line = file.readline()
    while line:
        line = line.strip()
        try:
            indxpc = line.index(';') # to remove pathCondition and assert lines
            indxWhtspc = line.index(' ') # to remove extern lines
            indxpar = line.index('a') # removes int __attribute__
        except:
            pass

        if(line[0:indxWhtspc] == "extern" or line[0:indxpar] == "int __" or
        (flag==1 and (line[0:indxpc] == "$pathCondition()" or line[0:indxpc] == "$assert(0)"))):
            line = "//{}".format(line)
        line = line.replace("(int __attribute__((__$input__))  )", "")
        line = line.replace("(int )", "")
        line = line.replace("return (0);", "")
        if line[0:5] == "if (\"": #remove the quotes in the repair condition
            line = line.replace("\"", "")
        outfile.write("{}\n".format(line))
        line = file.readline()

    print("write: {}".format(out))
    file.close()
    outfile.close()

if __name__ == '__main__':
    import sys
    try:
        src = sys.argv[1]
        flag = int(sys.argv[2]) #flag = 1 comment out $pathCondition otherwise leave it
        clean(src, flag)
    except:
        print("Not enough arguments")
