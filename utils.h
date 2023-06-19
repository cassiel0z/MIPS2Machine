#ifndef MIPS2MACHINE_UTILS_H
#define MIPS2MACHINE_UTILS_H

#include <iostream>
#include <vector>

using namespace std;

int binary2Decimal(string b){
    int res=0;
    for(int i=0;i<b.length();i++){
        res=res*2+(b[i]-48);
    }
    return res;
}

string tolowchar(string  p)
{
    string r;
    r=p;

    string::iterator it1,it2;
    it2=r.begin();
    for(it1=p.begin();it1!=p.end();it1++,it2++)
    {
        if((*it1>='A')&&(*it1<='Z'))
        {
            *it2=*it1+0x20;
        }
        else if((*it1>='a')&&(*it1<='z'))
            *it2=*it1;
        else
        {
            r="error";
            break;
        }
    }
    return r;
}


vector<string> split(const string &str, const string &pattern)
{
    vector<string> res;
    if(str.empty())
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != std::string::npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

#endif //MIPS2MACHINE_UTILS_H
