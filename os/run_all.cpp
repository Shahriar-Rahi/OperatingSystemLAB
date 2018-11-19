#include <iostream>
#include <windows.h>
#include <cstring>
#include <cstdlib>
#include <sstream>

int main()
{
    std::string arg = "<sstfinput.txt";
    std::string end = ":_#!#$";
    std::stringstream ss;
    std::cout << "fcfs" << end << std::endl;
    ss << "./fcfs.exe " <<  arg;
    system(ss.str().c_str());

    std::cout << "\nsstf " << end << std::endl;
    ss.str("");
    ss << "./sstf.exe " <<  arg;
    system(ss.str().c_str());

    std::cout << "\nlook " << end << std::endl;
    ss.str("");
    ss << "./look.exe " <<  arg;
    system(ss.str().c_str());

    std::cout << "\nscan " << end << std::endl;
    ss.str("");
    ss << "./scan.exe " <<  arg;
    system(ss.str().c_str());

    std::cout << "\ncscan " << end << std::endl;
    ss.str("");
    ss << "./cscan.exe " <<  arg;
    system(ss.str().c_str());

    std::cout << "\nclook " << end << std::endl;
    ss.str("");
    ss << "./clook.exe " <<  arg;
    system(ss.str().c_str());

}