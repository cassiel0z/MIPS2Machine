#ifndef MIPS2MACHINE_COMMANDS_H
#define MIPS2MACHINE_COMMANDS_H

#include <iostream>
#include <cstdio>
#include <bitset>
#include "utils.h"

using namespace std;

map<string, int> register_map = {
        {"$zero", 0},
        {"$at",   1},
        {"$v0",   2},
        {"$v1",   3},
        {"$a0",   4},
        {"$a1",   5},
        {"$a2",   6},
        {"$a3",   7},
        {"$t0",   8},
        {"$t1",   9},
        {"$t2",   10},
        {"$t3",   11},
        {"$t4",   12},
        {"$t5",   13},
        {"$t6",   14},
        {"$t7",   15},
        {"$s0",   16},
        {"$s1",   17},
        {"$s2",   18},
        {"$s3",   19},
        {"$s4",   20},
        {"$s5",   21},
        {"$s6",   22},
        {"$s7",   23},
        {"$t8",   24},
        {"$t9",   25},
        {"$k0",   26},
        {"$k1",   27},
        {"$gp",   28},
        {"$sp",   29},
        {"$fp",   30},
        {"$ra",   31}
};

int getMachineCode(const string &op) {
    string rs, rt, rd, immediate;
    map<string, string> operator_map = {
            {"addi",  "001000"},
            {"addiu", "001001"},
            {"slti",  "001010"},
            {"sltiu", "001011"},
    };
    string raw;
    getline(cin, raw);
    raw = format(raw);
    vector<string> res = split(raw, ",");

    rt = bitset<5>(register_map[res[0]]).to_string();
    rs = bitset<5>(register_map[res[1]]).to_string();
    immediate = bitset<16>(stoi(res[2])).to_string();
    return binary2Decimal(operator_map[op] + rs + rt + immediate);
}

#endif //MIPS2MACHINE_COMMANDS_H
