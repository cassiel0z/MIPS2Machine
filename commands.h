#ifndef MIPS2MACHINE_COMMANDS_H
#define MIPS2MACHINE_COMMANDS_H

#include <iostream>
#include <cstdio>
#include <bitset>
#include "utils.h"

using namespace std;

int ADDI( map<string, int> map){
    string addi=bitset<6>(8).to_string();
    string rs,rt,imm;
    string raw;
    cin>>raw;
    vector<string> res=split(raw,",");
    rt= bitset<5>(map[res[0]]).to_string();
    rs= bitset<5>(map[res[1]]).to_string();
    imm= bitset<16>(stoi(res[2])).to_string();
    return binary2Decimal(addi+rs+rt+imm);
}

int ADDIU(map<string, int> map){
    string addiu=bitset<6>(9).to_string();
    string rs,rt,imm;
    string raw;
    cin>>raw;
    vector<string> res=split(raw,",");
    rt= bitset<5>(map[res[0]]).to_string();
    rs= bitset<5>(map[res[1]]).to_string();
    imm= bitset<16>(stoi(res[2])).to_string();
    return binary2Decimal(addiu+rs+rt+imm);
}

int SLTI(map<string, int> map){
    string slti=bitset<6>(10).to_string();
    string rs,rt,imm;
    string raw;
    cin>>raw;
    vector<string> res=split(raw,",");
    rt= bitset<5>(map[res[0]]).to_string();
    rs= bitset<5>(map[res[1]]).to_string();
    imm= bitset<16>(stoi(res[2])).to_string();
    return binary2Decimal(slti+rs+rt+imm);
}

int SLTIU(map<string, int> map){
    string sltiu=bitset<6>(11).to_string();
    string rs,rt,imm;
    string raw;
    cin>>raw;
    vector<string> res=split(raw,",");
    rt= bitset<5>(map[res[0]]).to_string();
    rs= bitset<5>(map[res[1]]).to_string();
    imm= bitset<16>(stoi(res[2])).to_string();
    return binary2Decimal(sltiu+rs+rt+imm);
}

#endif //MIPS2MACHINE_COMMANDS_H
