#include <iostream>
#include <map>
#include <iomanip>
#include "utils.h"
#include "commands.h"

using namespace std;

int main() {

    freopen("../test2.in","r",stdin);
    freopen("../test2.out","w",stdout);
    int n;

    while (cin >> n) {
        if (n == -1)break;
        int i;
        for (i = 0; i < n; i++) {
            unsigned int M_code = 0;
            string OP, OP_lower, Inst;
            cin >> OP;
            OP_lower = toLowChar(OP);
            if(OP_lower=="addi"){
                M_code=ADDI();
            }else if(OP_lower=="addiu"){
                M_code=ADDIU();
            }
            else if(OP_lower=="slti"){
                M_code=SLTI();
            }else if(OP_lower=="sltiu"){
                M_code=SLTIU();
            }
            cout<<"0x"<<hex<<setw(8)<<setfill('0')<<M_code<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


