#include <iostream>
#include <map>
#include <iomanip>
#include "utils.h"
#include "commands.h"

using namespace std;

int main() {

    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);

    int n;

    while (cin >> n) {
        if (n == -1)break;
        int i;
        for (i = 0; i < n; i++) {
            unsigned int M_code;
            string OP, OP_lower, Inst;
            cin >> OP;
            OP_lower = toLowChar(OP);
            M_code=getMachineCode(OP_lower);
            cout<<"0x"<<hex<<setw(8)<<setfill('0')<<M_code<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


