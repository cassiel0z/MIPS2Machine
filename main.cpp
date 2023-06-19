#include <iostream>
#include <map>
#include <iomanip>
#include "utils.h"
#include "commands.h"

using namespace std;

map<string, int> init_Register(map<string, int> Register);

int main() {

#ifdef LOCAL
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
#endif
    map<string, int> map1;
    map1=init_Register(map1);
    int n;

    while (cin >> n) {
        char Instruction[81];
        if (n == -1)break;
        int i;
        for (i = 0; i < n; i++) {
            unsigned int M_code;
            string OP, OP_lower, Inst;
            cin >> OP;
            OP_lower = tolowchar(OP);
            if (OP_lower == "addi")
                M_code = ADDI(map1);
            else if (OP_lower == "addiu")
                M_code = ADDIU(map1);
            else if (OP_lower == "slti")
                M_code = SLTI(map1);
            else if (OP_lower == "sltiu")
                M_code = SLTIU(map1);
            else
                M_code = 0;
            cout<<"0x"<<hex<<setw(8)<<setfill('0')<<M_code<<endl;
        }
    }
    return 0;
}

map<string, int> init_Register(map<string, int> Register) {
    Register["$zero"] = 0;
    Register["$at"] = 1;
    Register["$v0"] = 2;
    Register["$v1"] = 3;
    Register["$a0"] = 4;
    Register["$a1"] = 5;
    Register["$a2"] = 6;
    Register["$a3"] = 7;
    Register["$t0"] = 8;
    Register["$t1"] = 9;
    Register["$t2"] = 10;
    Register["$t3"] = 11;
    Register["$t4"] = 12;
    Register["$t5"] = 13;
    Register["$t6"] = 14;
    Register["$t7"] = 15;
    Register["$s0"] = 16;
    Register["$s1"] = 17;
    Register["$s2"] = 18;
    Register["$s3"] = 19;
    Register["$s4"] = 20;
    Register["$s5"] = 21;
    Register["$s6"] = 22;
    Register["$s7"] = 23;
    Register["$t8"] = 24;
    Register["$t9"] = 25;
    Register["$k0"] = 26;
    Register["$k1"] = 27;
    Register["$gp"] = 28;
    Register["$sp"] = 29;
    Register["$fp"] = 30;
    Register["$ra"] = 31;
    return Register;
}

