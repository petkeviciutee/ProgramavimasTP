#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
using namespace std;

struct studentas {
	string Vardas, Pavarde;
	vector<int> paz = { 0 };
	int egz;
	float galutinis = 0;
};

int generavimas(vector<int> pazymiai);
void readFromFile(vector<studentas>& Eil, int kiek);


int main(){
	
vector<int> skaiciai;
int kiek = generavimas(skaiciai);
vector<studentas> studentai;
readFromFile(studentai, kiek);
vector<studentas> galvociai;
vector<studentas> vargsiukai;
int var = 0;
int galv = 0;

  //studentu skirstymas i dvi grupes
auto start = chrono::high_resolution_clock::now();
auto st = start;
for (int j = 0; j < kiek; j++) {
	float paz = 5.00;
	if (studentai.at(j).galutinis >= paz) {
			galvociai.push_back(studentai.at(j));
			galv++;
			}
	}
	
for (int i = 0; i < kiek; i++) {
	float paz = 5.00;
	if (studentai.at(i).galutinis < paz) {
			vargsiukai.push_back(studentai.at(i));
			var++;
		  	}
	}

//studentu failo rusiavimo i dvi grupes greičio (spartos) analize 
auto end = chrono::high_resolution_clock::now();
chrono::duration<double> diff = end - start;
cout << "Failo rusiavimas su " + to_string(kiek)+ " studentais i dvi grupes uztruko : " << diff.count() << " s\n";

string pav;
pav = "galvociai_" + to_string(kiek) + ".txt";
ofstream galv_failas(pav);
auto start2= chrono::high_resolution_clock::now();
auto st2 = start2;
for (int j = 0; j < kiek; j++) {
	float paz = 5.00;
	if (studentai.at(j).galutinis >= paz) {
			galv_failas << studentai.at(j).Vardas << setw(20) << studentai.at(j).Pavarde << setw(18) << studentai.at(j).galutinis << endl;
		                                  }
	}
	
//studentu failo isvedimo i galvocius greičio (spartos) analize 
auto end2 = chrono::high_resolution_clock::now();
chrono::duration<double> diff2 = end2 - start2;
cout << "Failo isvedimas su " + std::to_string(kiek) + " studentais  i galvocius uztruko : " << diff2.count() << " s\n";
  
pav = "vargsiukai_" + to_string(kiek) + ".txt";
ofstream vargs_failas(pav);
auto start1 = chrono::high_resolution_clock::now();
auto st1 = start1;
for (int i = 0; i < kiek; i++) {
	float paz = 5.00;
	if (studentai.at(i).galutinis < paz) {
			 vargs_failas << studentai.at(i).Vardas << setw(20) << studentai.at(i).Pavarde << setw(18) << studentai.at(i).galutinis << endl;
		                                  }
	}

//studentu failo isvedimo i vargsiukus greičio (spartos) analize 
auto end1 = chrono::high_resolution_clock::now();
chrono::duration<double> diff1 = end1 - start1;
cout << "Failo isvedimas su " + to_string(kiek) + " studentais  i vargsiukus uztruko : " << diff1.count() << " s\n";

return 0;
}

//atsitiktiniai skaiciai
int generate_random() {
return rand() % 10 + 1;
}

vector<int> auto_paz(int paz_sk) {
vector<int> skaiciai;
for (int i = 0; i < paz_sk; i++) {
		        skaiciai.push_back(generate_random());
	                                  }
return skaiciai;
}

float count_galutinis(vector<int> skaiciai) {
    studentas Eil;
    Eil.galutinis = 0.4 *accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate_random();
	
return Eil.galutinis;
}

//studentu atsitiktinis generavimas
int generavimas(vector<int> pazymiai) {
  int kiek;
  cout << "Iveskite studentu skaiciu: " << endl;
  cin >> kiek;
  
  string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
  auto start = chrono::high_resolution_clock::now();
  auto st = start;
  ofstream out_data(pavadinimas);
  vector<int> skaiciai;
  studentas Eil;
  out_data << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(20) << left << "Galutinis(vid.)"<< endl;


  for (int s = 1; s <= kiek; s = s + 1)	{
	skaiciai = auto_paz(5);
	out_data << setw(20) << "Vardas" + to_string(s) << setw(20) << "Pavarde" + to_string(s) << setw(18) << count_galutinis(skaiciai) << endl;
	skaiciai.clear();
	}

//studentu failo kurimo greičio (spartos) analize
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> diff = end - start;
  cout << to_string(kiek) + " studentu failo kurimas uztruko: " << diff.count() << " s\n";

return kiek;
}

//nuskaitymas is failo
void readFromFile(vector<studentas>& Eil, int kiek) {
  int student_counter = 0;
  ifstream fileRead;
  string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
  string buff;
  fileRead.open(pavadinimas);
  if (fileRead.is_open()) {
		auto start = chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> ws, buff);
		while (student_counter < kiek)
		{
		  Eil.resize(Eil.size() + 1);
		  fileRead >> Eil.at(student_counter).Vardas;
		  fileRead >> Eil.at(student_counter).Pavarde;
		  fileRead >> Eil.at(student_counter).galutinis;
		  student_counter++;
		}

 	//studentu failo nuskaitymo greičio (spartos) analize   
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << to_string(kiek) + " studentu failo nuskaitymas uztruko: " << diff.count() << " s\n";
	}
}
