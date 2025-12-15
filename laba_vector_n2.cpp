#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <string>
#include <algorithm>
#include <cctype>

void check_fin(std::ifstream&);
void check_fout(std::ofstream&);
void From_file_to_vec_surname(std::ifstream&, std::vector<std::string>&);
void print_vec(const std::vector<std::string>&);
void sort_arr(std::vector<std::string>&);
void fout_cout(std::ofstream&, const std::vector<std::string>&);
void fout_groups(std::ifstream&, std::ofstream&, const std::vector<std::string>&, std::vector<std::string>&);

int main()
{
    try
    {
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
        std::ifstream fin;
        fin.open("Students.txt");
        check_fin(fin);
        std::vector<std::string> MyVec;
        From_file_to_vec_surname(fin, MyVec);
        sort_arr(MyVec);
        print_vec(MyVec);
        std::ofstream fout;
        fout.open("fio.txt");
        check_fout(fout);
        fout_cout(fout, MyVec);
        fout.close();
        std::ofstream fout2;
        fout2.open("Groups.txt");
        check_fout(fout2);
        std::vector<std::string> FoutVec;
        fin.clear();
        fout_groups( fin,fout2,MyVec,FoutVec);
        fout_cout(fout2, FoutVec);
        fin.close();
        fout2.close();
    }
    catch (const char* msq)
    {
        std::cout << msq;
    }
    return 0;
}
void check_fin(std::ifstream& fin)
{
    if (!fin.is_open())
    {
        throw "not isnt exists";
    }
    if (!fin)
    {
        throw "input file error";
    }
    if (fin.peek() == EOF)
    {
        throw "filse if empty";
    }
}
void check_fout(std::ofstream& fout)
{
    if (!fout)
    {
        throw "file not open";
    }
}
void From_file_to_vec_surname(std::ifstream& fin, std::vector<std::string>& MyVec)
{
    std::string temp;
    std::string garbage;
    while (getline(fin, temp, ';'))
    {
        MyVec.push_back(temp);
        getline(fin, garbage, ';');
        getline(fin, garbage);
    }
}
void print_vec(const std::vector<std::string>& MyVec)
{
    size_t size = MyVec.size();
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << MyVec[i] << '\n';
    }
}
void sort_arr(std::vector<std::string>& MyVec)
{
    std::sort(MyVec.begin(), MyVec.end());
}
void fout_cout(std::ofstream& fout, const std::vector<std::string>& MyVec)
{
    int16_t size = MyVec.size();
    for (size_t i = 0; i < size; ++i)
    {
        fout << MyVec[i] << '\n';
    }
}
void fout_groups(std::ifstream& fin, std::ofstream& fout, const std::vector<std::string>& MyVec, std::vector<std::string>& FoutVec)
{
    std::string MyStr;
    std::string temp_str;
    int16_t course = 0;
    int16_t group = 0;
    int16_t size;
    int16_t prov_group = 0;
    int16_t prov_course = 0;
    std::vector<std::string> FoutVec_temp;
    for (size_t i = 1; i < 4; ++i)
    {
        temp_str.clear();
        for (size_t k = 1; k < 3; ++k)
        {
            fin.clear();
            fin.seekg(0);
            temp_str = "course " + std::to_string(i) + " group " + std::to_string(k);
            FoutVec.push_back(temp_str);
            FoutVec_temp.clear();
            for (size_t g = 0; g < 24; ++g)
            {
                prov_group = 0;
                prov_course = 0;
                getline(fin, MyStr);
                size = MyStr.size();
                for (size_t h = 0; h < size; ++h)
                {
                    if (isdigit(static_cast<unsigned char>(MyStr[h])) && prov_course == 0)
                    {
                        course = MyStr[h] - '0';
                        prov_course = 1;
                    }
                    else if(isdigit(static_cast<unsigned char>(MyStr[h])) && prov_group == 0)
                    {
                        group = MyStr[h] - '0';
                        prov_group = 1;
                    }
                }
                if (course == i && group == k)
                {
                    int16_t point = MyStr.find(';');
                    MyStr = MyStr.substr(0, point);
                    FoutVec_temp.push_back(MyStr);
                    sort(FoutVec_temp.begin(), FoutVec_temp.end());
                }
            }
            FoutVec.insert(FoutVec.end(), FoutVec_temp.begin(), FoutVec_temp.end());
        }
    }
}
