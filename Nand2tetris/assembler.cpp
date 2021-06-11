#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class symbolTable
{
private:
    class Node;
private:
    Node** table;
    int max;
    int count;
public:
    symbolTable()
    {
        count = 0;
        max = 20;
        table = new Node * [max];
        for (int i = 0; i < max; i++)
        {
            table[i] = NULL;
        }
    }
    ~symbolTable()
    {
        for (int i = 0; i < count; i++)
        {
            delete table[i];
        }
        delete[] table;
    }
    bool is_Exist(string str)
    {
        for (int i = 0; i < count; i++)
        {
            if (table[i]->Sym == str)
                return true;
        }
        return false;
    }
    void ensuremax()
    {
        if (count >= max - 1)
        {
            Node** temp = new Node * [max * 3 / 2];
            for (int i = 0; i < count; i++)
            {
                temp[i] = table[i];
            }
            delete[] table;
            table = temp;
            max = max * 3 / 2;
        }
    }
    void addSym(string str, int value)
    {
        Node* newNode = new Node(str, value);
        table[count] = newNode;
        count++;
        ensuremax();
    }
    void addSym(string str, string bina)
    {
        Node* newNode = new Node(str, bina);
        table[count] = newNode;
        count++;
        ensuremax();
    }
    int getvalue(string str)
    {
        for (int i = 0; i < count; i++)
        {
            if (str == table[i]->Sym)
                return table[i]->value;
        }
        return 0;
    }
    string getbina(string str) {
        for (int i = 0; i < count; i++)
        {
            if (str == table[i]->Sym)
                return table[i]->bina;
        }
        return "0";
    }
private:
    class Node
    {
    private:
        string Sym;
        int value;
        string bina;
        friend class symbolTable;

    public:
        Node(string str, int value)
        {
            this->Sym = str;
            this->value = value;
        }
        Node(string str, string bina) {
            this->Sym = str;
            this->bina = bina;
        }
    };
};
bool isNumber(string s)
{
    if (s.length() > 10) return false;
    for (unsigned int i = 0; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}
string to_binary(int n) {
    int a[100];
    string ss;
    int i;
    for (i = 0; n > 0; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    int j = 16 - i;
    while (j > 0) {
        ss.push_back('0');
        j--;
    }
    for (i = i - 1; i >= 0; i--)
    {
        string temp = to_string(a[i]);
        char c = temp[0];
        ss.push_back(c);
    }
    return ss;
}
void defaultSymTable(symbolTable& symTable)
{
    symTable.addSym("SCREEN", 16384);
    symTable.addSym("KDB", 24576);
    symTable.addSym("SP", 0);
    symTable.addSym("THIS", 3);
    symTable.addSym("THAT", 4);
    symTable.addSym("ARG", 2);
    symTable.addSym("LCL", 1);
    symTable.addSym("R1", 1);
    symTable.addSym("R2", 2);
    symTable.addSym("R0", 0);
    symTable.addSym("R3", 3);
    symTable.addSym("R4", 4);
    symTable.addSym("R5", 5);
    symTable.addSym("R6", 6);
    symTable.addSym("R7", 7);
    symTable.addSym("R8", 8);
    symTable.addSym("R9", 9);
    symTable.addSym("R10", 10);
    symTable.addSym("R11", 11);
    symTable.addSym("R12", 12);
    symTable.addSym("R13", 13);
    symTable.addSym("R14", 14);
    symTable.addSym("R15", 15);
    symTable.addSym("0", "0101010");
    symTable.addSym("1", "0111111");
    symTable.addSym("-1", "0111010");
    symTable.addSym("D", "0001100");
    symTable.addSym("A", "0110000");
    symTable.addSym("M", "1110000");
    symTable.addSym("!D", "0001101");
    symTable.addSym("!A", "0110001");
    symTable.addSym("!M", "1110001");
    symTable.addSym("-D", "0001111");
    symTable.addSym("-A", "0110011");
    symTable.addSym("-M", "1110011");
    symTable.addSym("D+1", "0011111");
    symTable.addSym("1+D", "0011111");//
    symTable.addSym("1+A", "0110111");//
    symTable.addSym("A+1", "0110111");
    symTable.addSym("1+M", "1110111");
    symTable.addSym("M+1", "1110111");
    symTable.addSym("1-D", "0001110");
    symTable.addSym("D-1", "0001110");
    symTable.addSym("1-A", "0110010");
    symTable.addSym("A-1", "0110010");
    symTable.addSym("1-M", "1110010");
    symTable.addSym("M-1", "1110010");
    symTable.addSym("D+A", "0000010");
    symTable.addSym("A+D", "0000010");
    symTable.addSym("D+M", "1000010");
    symTable.addSym("M+D", "1000010");
    symTable.addSym("D-A", "0010011");
    symTable.addSym("A-D", "0010011");
    symTable.addSym("D-M", "1010011");
    symTable.addSym("M-D", "1010011");
    symTable.addSym("A-D", "0000111");
    symTable.addSym("D-A", "0000111");
    symTable.addSym("M-D", "1000111");
    symTable.addSym("D-M", "1000111");
    symTable.addSym("D&A", "0000000");
    symTable.addSym("A&D", "0000000");
    symTable.addSym("D&M", "1000000");
    symTable.addSym("M&D", "1000000");
    symTable.addSym("D|A", "0010101");
    symTable.addSym("A|D", "0010101");
    symTable.addSym("D|M", "1010101");
    symTable.addSym("M|D", "1010101");
}
void jumptable(symbolTable&symTable){
     symTable.addSym("AMD", "111");
     symTable.addSym("M" , "001" );symTable.addSym("D" , "010" );
     symTable.addSym("MD" , "011" );symTable.addSym("A" , "100" );
     symTable.addSym("AM" , "101" );
     symTable.addSym("AD", "110");symTable.addSym("null", "000");
     symTable.addSym("JGT", "001"); symTable.addSym("JEQ", "010"); 
     symTable.addSym("JGE", "011"); symTable.addSym("JLT", "100");
     symTable.addSym("JNE", "101"); symTable.addSym("JLE", "110");
     symTable.addSym("JMP", "111");

}
int main()
{

    symbolTable symTable;
    defaultSymTable(symTable);
    symbolTable jumpTable;
    jumptable(jumpTable);


    string filein = "D:\Rect.asm";
    string fileout="";
    for (int i = 0; filein[i] != '.'; i++) {
        fileout += filein[i];
    }
    fileout += ".hack";
    ofstream outtemp("temporary.asm", ios::out);
    ifstream input;
    input.open(filein);
    string line;
    int count = 0;


    //Lay dia chi cua thu tuc
    while (getline(input, line)) {
        if (line == "") continue;
        istringstream iss(line); // iss gio la cai lenh moi lay vo do, day no vo instream
        string Lenh;
        iss >> Lenh;
        if (Lenh == "//")continue;
        if (Lenh[0] != '(') count++;
        if (Lenh[0] == '(') {
            size_t found = Lenh.find_first_of(')');
            string label;
            if (found != string::npos) {
                for (int i = 1; i < found; i++) {
                    label.push_back(Lenh[i]);
                }
                if (!symTable.is_Exist(label)) {
                    symTable.addSym(label, count);
                }
            }
        }
    }
    input.close();
    input.open(filein);

    //Lay dia chi bien
    int varCounter = 16;
    while (getline(input, line)) {
        if (line == "") continue;
        istringstream iss(line); // iss gio la cai lenh moi lay vo do, day no vo instream
        string Lenh;
        iss >> Lenh;
        if (Lenh == "//") continue;
        if (Lenh[0] == '@') {
            Lenh.erase(0, 1);
            if (symTable.is_Exist(Lenh))
                continue;
            if (!isNumber(Lenh)) {
                symTable.addSym(Lenh, varCounter);
                varCounter++;
            }
        }
    }
    input.close();
    input.open(filein);


    //Thay noi dung
    while (getline(input, line)) {
        if (line == "") continue;
        istringstream iss(line);
        string Lenh;
        iss >> Lenh;
        if (Lenh == "//") continue;
        string out;
        if (Lenh[0] == '(')continue;
        if (Lenh[0] == '@') {
            out = "@";
            Lenh.erase(0, 1);
            if (symTable.is_Exist(Lenh)) {
                out += to_string(symTable.getvalue(Lenh));
            }
            else out += Lenh;
        }
        else out = Lenh;
        outtemp << out << '\n';
    }
    outtemp.close();
    input.close();
    ifstream myfile;
    myfile.open("temporary.asm");
    ofstream output(fileout, ios::out);

    while (getline(myfile, line))
    {
        if (line == "") continue;
        istringstream iss(line); 
        string Lenh;
        string ss;
        iss >> Lenh;
        if (Lenh == "//")continue;
        if (Lenh[0] == '@') {
            ss.clear();
            Lenh.erase(0, 1);
            ss = to_binary(stoi(Lenh));
            output << ss << "\n";
            continue;
        }
        else {
            ss.clear();
            ss = "111";
            string Ins;
            string jump;
            int found = Lenh.find_first_of(';');
            if (found != string::npos)
            {
                jump.clear();
                for (int i = found + 1; i < Lenh.size(); i++) {
                    jump.push_back(Lenh[i]);
                }
                Ins.clear();
                for (int i = 0; i < found; i++) {
                    Ins.push_back(Lenh[i]);
                }
            }
            else Ins = Lenh;
            found = Ins.find_first_of('=');
            string ALU,dest;
            for (int i = found + 1; i < Ins.size(); i++) {
                ALU.push_back(Ins[i]);
            }
            for (int i = 0; i < found; i++) {
                dest.push_back(Ins[i]);
            }
            ss+= symTable.getbina(ALU);
            ss += jumpTable.getbina(dest);
            if (jump != "") {
                ss += "00";
                ss += jumpTable.getbina(jump);
            }                    
            else ss += "000";
            output << ss << "\n";
            continue;
        }
    }
    myfile.close();
    output.close();
}
