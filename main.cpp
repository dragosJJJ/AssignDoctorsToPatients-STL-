#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct problema {
    string idProblema, specializare;
}problems[10000];

struct doctor {
    string idDoctor, specializare;
}doctors[10000];

vector<problema> p;
vector<doctor> d;
vector<pair<string, string>> solution;

int main()
{
    ifstream inFile("input.txt");
    int n;

    inFile >> n;
    for (int i = 0; i < n; i++) {
        string idproblema, specializare;
        inFile >> idproblema >> specializare;
        problems[i].idProblema = idproblema;
        problems[i].specializare = specializare;
        p.push_back(problems[i]);  
    }
    inFile >> n;
    for (int i = 0; i < n; i++) {
        string iddoctor, specializare;
        inFile >> iddoctor >> specializare;
        doctors[i].idDoctor = iddoctor;
        doctors[i].specializare = specializare;
        d.push_back(doctors[i]);
    }


    for (vector<problema>::iterator i = p.begin(); i != p.end(); i++) {
        auto it = find_if(d.begin(), d.end(), [&](const doctor& doc) { return doc.specializare == i->specializare; });
        if (it != d.end()) {
            solution.push_back(make_pair(it->idDoctor, it->specializare));
            d.erase(it);
        }
    }
    for (vector<pair<string, string>>::iterator i = solution.begin(); i != solution.end(); i++) {
        cout << "Doctor ID: " << i->first << ", Specialization: " << i->second << endl;
    }
    
    
    return 0;
}