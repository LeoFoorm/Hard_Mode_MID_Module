//   EVENT ACTION HEADER

#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "RunAction.hh"
#include "G4SystemOfUnits.hh"
#include "G4ThreeVector.hh"
#include <cmath>
#include <vector>

using namespace std;

class EventAction : public G4UserEventAction
{
public:

 EventAction(RunAction*);
 ~EventAction();

 
 virtual void BeginOfEventAction(const G4Event*);
 virtual void EndOfEventAction(const G4Event*);



void Add_DetectedPhotons_event_A_SiPMs (G4int sipmID_a)
{
    if (sipmID_a >= 0 && sipmID_a < 20 )
    {
        photonHits_event_A[sipmID_a]++;
    }
}
std::vector<G4int> GetPhotonHits_A() const{return photonHits_event_A;}


void Add_DetectedPhotons_event_B_SiPMs (G4int sipmID_b)
{
    if (sipmID_b >= 0 && sipmID_b < 20 )
    {
        photonHits_event_B[sipmID_b]++;
    }
}
std::vector<G4int> GetPhotonHits_B() const{return photonHits_event_B;}
//---------------------------------------------------------
//void AddLocalTime(G4int sipmID, G4double ltime) 
//{
 //   if (sipmID >= 0 && sipmID < 40) 
  //  {
  //      localTimes[sipmID] += ltime;
  //  }
//}
// std::vector<G4double> GetLocalTimes() const {return localTimes;
//---------------------------------------------------------

//____________________________________________________________
void AddEdepZero(G4double edep_0){ fEdep_0 += edep_0; } //
void AddEdepOne(G4double edep_1){ fEdep_1 += edep_1; }
void AddEdepTwo(G4double edep_2){ fEdep_2 += edep_2; }
void AddEdepThree(G4double edep_3){ fEdep_3 += edep_3; }
void AddEdepFour(G4double edep_4){ fEdep_4 += edep_4; }
void AddEdepFive(G4double edep_5){ fEdep_5 += edep_5; }
void AddEdepSix(G4double edep_6){ fEdep_6 += edep_6; }
void AddEdepSeven(G4double edep_7){ fEdep_7 += edep_7; }
void AddEdepEight(G4double edep_8){ fEdep_8 += edep_8; }
void AddEdepNine(G4double edep_9){ fEdep_9 += edep_9; }
void AddEdepTen(G4double edep_10){ fEdep_10 += edep_10; }
void AddEdepEleven(G4double edep_11){ fEdep_11 += edep_11; }
void AddEdepTwelve(G4double edep_12){ fEdep_12 += edep_12; }
void AddEdepThirteen(G4double edep_13){ fEdep_13 += edep_13; }
void AddEdepFourteen(G4double edep_14){ fEdep_14 += edep_14; }
void AddEdepFifteen(G4double edep_15){ fEdep_15 += edep_15; }
void AddEdepSixteen(G4double edep_16){ fEdep_16 += edep_16; }
void AddEdepSeventeen(G4double edep_17){ fEdep_17 += edep_17; }
void AddEdepEighteen(G4double edep_18){ fEdep_18 += edep_18; }
void AddEdepNineteen(G4double edep_19){ fEdep_19 += edep_19; }
/*
void AddEdepA(G4int E_A, G4double edep_A)
{ 
    if (E_A >= 0 && E_A < fEdepA.size()) 
    {
        fEdepA[E_A] += edep_A;
    }
}
std::vector<G4double> GetEdepA() const { return fEdepA; }


void AddEdepB(G4int E_B, G4double edep_B)
{ 
    if (E_B >= 0 && E_B < fEdepB.size()) 
    {
        fEdepB[E_B] += edep_B;
    }
}
std::vector<G4double> GetEdepB() const { return fEdepB; }
*/
//____________________________________________________________

//---------------------------------------------------------


void AccumulatedEdx_A(G4int dEdx_a, G4double dEdxStep_A) 
{
    if (dEdx_a >= 0 && dEdx_a < fTotaldEdx_A.size() )
    {
         fTotaldEdx_A[dEdx_a] += dEdxStep_A;
    }
}
std::vector<G4double> GetdEdx_A() const { return fTotaldEdx_A; }


void AccumulatedEdx_B(G4int dEdx_b, G4double dEdxStep_B) 
{
    if (dEdx_b >= 0 && dEdx_b < fTotaldEdx_B.size() )
    {
         fTotaldEdx_B[dEdx_b] += dEdxStep_B;
    }
}
std::vector<G4double> GetdEdx_B() const { return fTotaldEdx_B; }


//---------------------------------------------------------

void AddPhotonG_UsingEdep_A(G4int PhotonGen_a, G4double generated_photons_A) 
 {
    if (PhotonGen_a >= 0 && PhotonGen_a < fGenerated_photons_A.size())
    {
        fGenerated_photons_A[PhotonGen_a] += generated_photons_A;
    }
 }
 std::vector<G4int> GetPhotonCount_Edep_A() const { return fGenerated_photons_A; }


void AddPhotonG_UsingEdep_B(G4int PhotonGen_b, G4double generated_photons_B)
 {
    if (PhotonGen_b >= 0 && PhotonGen_b <fGenerated_photons_B.size())
    {
        fGenerated_photons_B[PhotonGen_b] += generated_photons_B;
    }
 }
 std::vector<G4int> GetPhotonCount_Edep_B() const { return fGenerated_photons_B; }

//---------------------------------------------------------

void AddTraversedBar_A (G4int barA){

        if (std::find(traversed_Bars_A.begin(), traversed_Bars_A.end(), barA) == traversed_Bars_A.end()) {  
          traversed_Bars_A.push_back(barA);
        }
}
std::vector<G4int> GetTraversedBars_A() const {return traversed_Bars_A;}


void AddTraversedBar_B (G4int barB){
    
        if (std::find(traversed_Bars_B.begin(), traversed_Bars_B.end(), barB) == traversed_Bars_B.end()) {
           traversed_Bars_B.push_back(barB);
        }
}
std::vector<G4int> GetTraversedBars_B() const {return traversed_Bars_B;}

//---------------------------------------------------------
void Particle_Name_Pierced_Layer_A(G4String name_a){
    particles_names_A.push_back(name_a);
}

vector<G4String> Get_particle_names_A() const {return particles_names_A;}



void Particle_Name_Pierced_Layer_B(G4String name_b){
    particles_names_B.push_back(name_b);
}

vector<G4String> Get_particle_names_B() const {return particles_names_B;}

//---------------------------------------------------------


private:

std::vector<G4int> photonHits_event_A;
std::vector<G4int> photonHits_event_B;
std::vector<G4double> localTimes;
 

G4double fEdep_0;
G4double fEdep_1;
G4double fEdep_2;
G4double fEdep_3;
G4double fEdep_4;
G4double fEdep_5;
G4double fEdep_6;
G4double fEdep_7;
G4double fEdep_8;
G4double fEdep_9;
G4double fEdep_10;
G4double fEdep_11;
G4double fEdep_12;
G4double fEdep_13;
G4double fEdep_14;
G4double fEdep_15;
G4double fEdep_16;
G4double fEdep_17;
G4double fEdep_18;
G4double fEdep_19;

G4double fEdep_20;
/*
std::vector<G4double> fEdepA;
std::vector<G4double> fEdepB;
*/


std::vector<G4double> fTotaldEdx_A;
std::vector<G4double> fTotaldEdx_B;

std::vector<G4int> fGenerated_photons_A;
std::vector<G4int> fGenerated_photons_B;

std::vector<G4int> traversed_Bars_A; 
std::vector<G4int> traversed_Bars_B; 

vector<G4String> particles_names_A;
vector<G4String> particles_names_B;

G4double TOTAL_Edep;
G4double TOTAL_dEdx;

G4int TOTAL_Detected_photons;
G4double TOTAL_Generated_photons;

G4double total_edep_A;
G4double total_edep_B;
 

 G4int muonCount;

 G4bool Hit_particle_passed_two_layers = false;
 

 G4int Sumcopies;



};

#endif



