#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>
using namespace std;

struct studentas {
    string vardas, pavarde;
    vector <float> paz = {0};
    int egz;
    float tarpinis;
    float galutinisvid;
    float galutinismed;
};

double Mediana(vector <float> &vec);

int main ()
{
    int n, p, sk;
    float sum = 0, laik, vid, med;
    cout << "Iveskite studentu skaiciu: " << endl;
    cin >> n;
    
    vector <studentas> grupe;
    studentas laikinas;
    grupe.reserve(n);
    
    for (int i = 0; i < n;i++){
        cout << "Iveskite " << i + 1<< "-o studento varda ir pavarde: " << endl;
        cin >> laikinas.vardas >> laikinas.pavarde;
      
        cout << "Iveskite studento pazymius (kai baigsite iveskite bet kokia raide): "<<endl;
        while (cin >> laik)
        {
          laikinas.paz.push_back(laik);
          sum+=laik;
        }
        cin.clear();
        cin.ignore(10000,'\n');
  
        cout << "Iveskite " << i + 1 << " -o studento egzamino pazymi: " << endl;
        cin >> laikinas.egz;
          if(laikinas.egz < 0 || laikinas.egz > 10) {cout << "ERROR IVEDETE NETINKAMA SKAICIU" << endl;
                                                     cout << "Iveskite " << i + 1 << " -o studento egzamino ivertinima: " ;
                                                     cin >> laikinas.egz;}
        
        vid = accumulate(laikinas.paz.begin(), laikinas.paz.end(), 0.0)/laikinas.paz.size();
        med = Mediana(laikinas.paz);
        
        laikinas.galutinisvid = vid * 0.4 + laikinas.egz * 0.6;
        laikinas.galutinismed = med * 0.4 + laikinas.egz * 0.6;
        grupe.push_back(laikinas);
        laikinas.paz.clear();
    }
    
    
    cout << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Egzaminas" << setw(15) << "Galutinis(vid)/" << setw(15) << "Galutinis(med)" << endl;

    for(auto &kint: grupe){
      
        cout<<setw(15)<<kint.vardas<<setw(15) <<kint.pavarde << setw(10)<<kint.egz << setw(10)<< setprecision(2)<< kint.galutinisvid << setw(10) << setprecision(2)<< kint.galutinismed <<  endl;
     
    }


return 0;
}
//funkcija
double Mediana(vector <float> &vec){
  typedef vector<float>::size_type vecSize;
  vecSize size = vec.size();
  if (size == 0)
    throw domain_error("tuscias vektorius");
  sort(vec.begin(),vec.end());
  vecSize vid = size/2;
  return size % 2 == 0 ? (vec[vid] + vec[vid-1]) / 2 : vec[vid];
}
