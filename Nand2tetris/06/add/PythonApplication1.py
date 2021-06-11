import sys

A,B,C={},{},{}

filename = sys.argv[1]

def main():
    a= pre(filename)
    toA(a)
    toB(a)
    toC(a)
    results=subtitle(a)
    writeto(results)


    a= pre(filename)
    toA(a)
    toB(a)
    toC(a)
    results=subtitle(a)
    writeto(results)

    a= pre(filename)
    toA(a)
    toB(a)
    toC(a)
    results=subtitle(a)
    writeto(results)


    a= pre(filename)
    toA(a)
    toB(a)
    toC(a)
    results=subtitle(a)
    writeto(results)

def pre(filename):
    file=open(filename)
    a=file.readlines()
    a = map(filter_line, a)
    a = [i.strip() for i in [x for x in a] ]
    a = filter(lambda x: x!= '', a)
    return a

def subtitle(a):
    f=[]
    for i in a:
        if is_a_command(i):
            f.append(A[i])
        elif is_c_command(i):
            f.append(C[i])
        return f

def toB(a):
    x=0
    for i in a:
        x+=1
        if is_L_commnand(i):
            x-=1
            B[i[1:-1]]=to2(x)

def toA(a):
    RAM0 = 6
    for i in a:
        if is_a_command(i):
            val=i[1:]
            if tryint(val) is not None:
                A[i]=to2(int(val))
            elif val in predef.keys():
                A[i]=to2(predef[val])
            elif val in B.keys:
                A[i]=B[val]
            elif i in A.keys():
                continue
            else:
                A[i]=to2(begin)
                begin+=1

def toC(a):
    for i in a:
        if is_c_command(i):
            semi=i.find(';')
            equa=i.find('=')

            if equa!=-1 and semi != -1:
                dest=i[:equa]
                comp=i[equa+1:semi]
                jump=i[semi+1:]
                abit=set_abit(comp)
                C[i]=first+abit+comp_table[comp]+dest_table[dest]+jump_table[jump]
            if equa==-1 and semi != -1:
                 comp: i[:semi]
                 jump=i[semi+1:]
                 abit=set_abit(comp)
                 C[i]=first+abit+comp_table[comp]+dest_table["null"]+jump_table[jump]
            if equa != -1 and semi == -1: #dest=comp
                dest = i[:equa]
                comp = i[equa+1:]
                abit = set_abit(comp)
                C[i] = first + abit + comp_table[comp] + dest_table[dest] + jump_table["null"]

def writeto(a):
    name=filter-line(filename, op=".")
    name+=".hack"
    file=open(name,'w')
    for i in a:
        file.write(i+"\n")
    file.close()

def to2(i):
    b=[]
    a=[32]
    index=0
    for i in [0..i]:
        b[index]=i % 2
        i/=2
        index+=1
    j=16-index
    k=16-index
    for j in [0..k]:
        b+='0'
        j-=1
    for index in [0..index-1]:
        temp=str(a[i])
        w=temp[0]
        b+=w
    return b


    
jump_table = {
    "null" : "000",
    "JGT" : "001",
    "JEQ" : "010",
    "JGE" : "011",
    "JLT" : "100",
    "JNE" : "101",
    "JLE" : "110",
    "JMP" : "111"
}

dest_table =  {
    "null" : "000",
    "M" : "001",
    "D" : "010",
    "MD" : "011",
    "A" : "100",
    "AM" : "101",
    "AD" : "110",
    "AMD" : "111"
}

predef = {
    "SP" : 0,
    "LCL" : 1,
    "ARG" : 2,
    "THIS" : 3,
    "THAT" : 4,
    "R0" : 0,
    "R1" : 1,
    "R2" : 2,
    "R3" : 3,
    "R4" : 4,
    "R5" : 5,
    "R6" : 6,
    "R7" : 7,
    "R8" : 8,
    "R9" : 9,
    "R10" : 10,
    "R11" : 11,
    "R12" : 12,
    "R13" : 13,
    "R14" : 14,
    "R15" : 15,
    "SCREEN" : 16384,
    "KBD" : 24576
}

comp_table = {
    "0" : "101010",
    "1" : "111111",
    "-1" : "111010",
    "D" : "001100",
    "A" : "110000",
    "M" : "110000",
    "!D" : "001101",
    "!A" : "110001",
    "!M" : "110001",
    "-D" : "001111",
    "-A" : "110011",
    "-M" : "110011",
    "D+1" : "011111",
    "1+D" : "011111",
    "1+A" : "110111",
    "A+1" : "110111",
    "1+M" : "110111",
    "M+1" : "110111",
    "1-D" : "001110",
    "D-1" : "001110",
    "1-A" : "110010",
    "A-1" : "110010",
    "1-M" : "110010",
    "M-1" : "110010",
    "D+A" : "000010",
    "A+D" : "000010",
    "D+M" : "000010",
    "M+D" : "000010",
    "D-A" : "010011",
    "A-D" : "010011",
    "D-M" : "010011",
    "M-D" : "010011",
    "A-D" : "000111",
    "D-A" : "000111",
    "M-D" : "000111",
    "D-M" : "000111",
    "D&A" : "000000",
    "A&D" : "000000",
    "D&M" : "000000",
    "M&D" : "000000",
    "D|A" : "010101",
    "A|D" : "010101",
    "D|M" : "010101",
    "M|D": "010101"
}  
def tryint(s, base=10, val=None):
  try:
    return int(s, base)
  except ValueError:
    return val
  
to2 = lambda x: x >= 0 and str(bin(x))[2:] or "-" + str(bin(x))[3:]
first = "111" # for bits 15,14,13

def set_abit(comp):
  if comp.find('M') != -1:
    return "1"
  else:	
    return "0"
def to2(a):
  num = to_binary(a)
  length = len(num)
  diff = 16 - length
  rest = [ "0" for i in range(diff) ]
  rest = "".join(rest)
  return rest + num

def filter_line(a, op="//"):
  idx = a.find(op)
  if idx == -1:
    return a
  elif idx == 0:
    return ''
  else:
    if op == "//":
      a = a[:(idx-1)]
    else:
      a = a[:idx]
  return a    

is_l_command = lambda i : i.find('(') != -1 and i.find(')') != -1    
is_a_command = lambda i : i.find('@') != -1   
is_c_command = lambda i : i.find("(") == -1 and i.find("@") == -1

if __name__ == "__main__":
    main()

    

