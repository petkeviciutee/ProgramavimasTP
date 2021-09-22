#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iterator>
using namespace std;

struct studentas {
    string Vardas, Pavarde;
    vector<int> paz = { 0 };
    int egz;
    float Galutinisvid;
};
void read_from_file(vector<studentas>& grupe, int* pazymiu_sk);
double Mediana(vector <int> vec);
void print_student(vector<studentas> grupe, int pazymiu_sk);
unsigned int countWordsInString(string const& str);


int main()
{
    int pazymiu_sk;
    char temp;
    vector<studentas> grupe;
    read_from_file(grupe, &pazymiu_sk);
    print_student(grupe, pazymiu_sk);
  

return 0;
}
//Nuskaitymo funkcija
void read_from_file(vector<studentas>& grupe, int* pazymiu_sk)
{
    int student_counter = 0;
    int temp;
    ifstream fileRead;
    string buff;
    fileRead.open("studentai.txt");
    if (fileRead.is_open())
    {
        getline(fileRead >> ws, buff);
        *pazymiu_sk = countWordsInString(buff) - 3;
        while (true)
        {

            grupe.resize(grupe.size() + 1);
            fileRead >> grupe.at(student_counter).Vardas;
            if (fileRead.eof()) {grupe.pop_back(); break; }
            fileRead >> grupe.at(student_counter).Pavarde;
            for (int i = 0; i < *pazymiu_sk; i++)
            {
                fileRead >> temp;
                grupe.at(student_counter).paz.push_back(temp);
            }
            fileRead >> grupe.at(student_counter).egz;
          
            grupe.at(student_counter).Galutinisvid = grupe.at(student_counter).Galutinisvid / *pazymiu_sk;
            grupe.at(student_counter).Galutinisvid = grupe.at(student_counter).Galutinisvid * 0.4 + 0.6 * grupe.at(student_counter).egz;
            student_counter++;
        }
    }
    else {cout << "-\n"; }
}
unsigned int countWordsInString(string const& str)
{
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}


double Mediana(vector <int> vec){
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0)
    throw domain_error("tuscias vektorius");
  sort(vec.begin(),vec.end());
  vecSize vid = size/2;
  return size % 2 == 0 ? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}

void print_student(vector<studentas> grupe, int pazymiu_sk) //atspausdina rezultatus
{
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(18) << left << "Galutinis(vid.)/" << left << "Galutinis(med.)\n"
      << "--------------------------------------------------------------------------\n";


    for (int i = 0; i < grupe.size(); i++)
    {
        output << setw(20) << left << grupe[i].Vardas << setw(20) << left << grupe[i].Pavarde << setw(18) << left << grupe[i].Galutinisvid << Mediana(grupe[i].paz) << endl;
    }
    output << "\n\n";
}
