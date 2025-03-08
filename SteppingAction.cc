//  STEPPING ACTION SOURCE

#include "SteppingAction.hh"

using namespace std;

SteppingAction::SteppingAction( EventAction *eventaction)
{
 fEventAction = eventaction;
}


SteppingAction::~SteppingAction()
{}


void SteppingAction::UserSteppingAction(const G4Step *step)
{

const DetectorConstruction *detectorconstruction = static_cast < const DetectorConstruction* > (G4RunManager::GetRunManager()->GetUserDetectorConstruction());
 
const std::vector<G4LogicalVolume*>& scoringVolumesA = detectorconstruction->GetScoringVolumesA(); //<---
const std::vector<G4LogicalVolume*>& scoringVolumesB = detectorconstruction->GetScoringVolumesB(); //<---

G4LogicalVolume *fScoringVolume_0 = detectorconstruction->GetScoringVolume0();
G4LogicalVolume *fScoringVolume_1 = detectorconstruction->GetScoringVolume1();
G4LogicalVolume *fScoringVolume_2 = detectorconstruction->GetScoringVolume2();
G4LogicalVolume *fScoringVolume_3 = detectorconstruction->GetScoringVolume3();
G4LogicalVolume *fScoringVolume_4 = detectorconstruction->GetScoringVolume4();
G4LogicalVolume *fScoringVolume_5 = detectorconstruction->GetScoringVolume5();
G4LogicalVolume *fScoringVolume_6 = detectorconstruction->GetScoringVolume6();
G4LogicalVolume *fScoringVolume_7 = detectorconstruction->GetScoringVolume7();
G4LogicalVolume *fScoringVolume_8 = detectorconstruction->GetScoringVolume8();
G4LogicalVolume *fScoringVolume_9 = detectorconstruction->GetScoringVolume9();
G4LogicalVolume *fScoringVolume_10 = detectorconstruction->GetScoringVolume10();
G4LogicalVolume *fScoringVolume_11 = detectorconstruction->GetScoringVolume11();
G4LogicalVolume *fScoringVolume_12 = detectorconstruction->GetScoringVolume12();
G4LogicalVolume *fScoringVolume_13 = detectorconstruction->GetScoringVolume13();
G4LogicalVolume *fScoringVolume_14 = detectorconstruction->GetScoringVolume14();
G4LogicalVolume *fScoringVolume_15 = detectorconstruction->GetScoringVolume15();
G4LogicalVolume *fScoringVolume_16 = detectorconstruction->GetScoringVolume16();
G4LogicalVolume *fScoringVolume_17 = detectorconstruction->GetScoringVolume17();
G4LogicalVolume *fScoringVolume_18 = detectorconstruction->GetScoringVolume18();
G4LogicalVolume *fScoringVolume_19 = detectorconstruction->GetScoringVolume19();
 
   


G4TouchableHandle touchedbar = step->GetPreStepPoint()->GetTouchableHandle(); 
 G4LogicalVolume* barvolume = touchedbar->GetVolume()->GetLogicalVolume();


 G4double stepLength = step->GetStepLength();
 G4ParticleDefinition* particle = step->GetTrack()->GetDefinition();
 
 
 G4Track* track = step->GetTrack();


G4StepPoint *PreStep = step->GetPreStepPoint();
  
 
if(particle->GetParticleName()== "mu+" ){

   /*
   G4double dEdxStep_A = 0.0; 
   G4double dEdxStep_B = 0.0;
   G4double generated_photons_A = 0.0;
   G4double generated_photons_B = 0.0;
   */

G4double Edep0 = 0.0;
G4double Edep1 = 0.0;
G4double Edep2 = 0.0;
G4double Edep3 = 0.0;
G4double Edep4 = 0.0;
G4double Edep5 = 0.0;
G4double Edep6 = 0.0;
G4double Edep7 = 0.0;
G4double Edep8 = 0.0;
G4double Edep9 = 0.0;
G4double Edep10 = 0.0;
G4double Edep11 = 0.0;
G4double Edep12 = 0.0;
G4double Edep13 = 0.0;
G4double Edep14 = 0.0;
G4double Edep15 = 0.0;
G4double Edep16 = 0.0;
G4double Edep17 = 0.0;
G4double Edep18 = 0.0;
G4double Edep19 = 0.0;

  if (barvolume == fScoringVolume_0) {

        Edep0 = step->GetTotalEnergyDeposit();
        if (Edep0 > 0.&& stepLength > 0.) {

            fEventAction->AddEdepZero(Edep0);

            /*
            dEdxStep_0 = edep_0 / stepLength;

            G4Material *plastic_scin = step->GetPreStepPoint()->GetMaterial(); 
            G4MaterialPropertiesTable *Yield = plastic_scin->GetMaterialPropertiesTable(); 
            G4double Scintillation_Yield = Yield->GetConstProperty("SCINTILLATIONYIELD");

            generated_photons_zero = edep_0 * Scintillation_Yield; 
            generated_photons_zero = G4Poisson(generated_photons_zero); 
            
            fEventAction->AddPhotonG_UsingEdep_0(generated_photons_zero); 
            fEventAction->AccumulatedEdx_zero(dEdxStep_0);
            */
        }
    }

   
    else if (barvolume == fScoringVolume_1) {

         Edep1 = step->GetTotalEnergyDeposit();
        if (Edep1 > 0.) {
            fEventAction->AddEdepOne(Edep1);
        }
    }

    else if (barvolume == fScoringVolume_2) {
    Edep2 = step->GetTotalEnergyDeposit();
    if (Edep2 > 0.) {
        fEventAction->AddEdepTwo(Edep2);
    }
}
else if (barvolume == fScoringVolume_3) {
     Edep3 = step->GetTotalEnergyDeposit();
    if (Edep3 > 0.) {
        fEventAction->AddEdepThree(Edep3);
    }
}
else if (barvolume == fScoringVolume_4) {
     Edep4 = step->GetTotalEnergyDeposit();
    if (Edep4 > 0.) {
        fEventAction->AddEdepFour(Edep4);
    }
}
else if (barvolume == fScoringVolume_5) {
     Edep5 = step->GetTotalEnergyDeposit();
    if (Edep5 > 0.) {
        fEventAction->AddEdepFive(Edep5);
    }
}
else if (barvolume == fScoringVolume_6) {
     Edep6 = step->GetTotalEnergyDeposit();
    if (Edep6 > 0.) {
        fEventAction->AddEdepSix(Edep6);
    }
}
else if (barvolume == fScoringVolume_7) {
     Edep7 = step->GetTotalEnergyDeposit();
    if (Edep7 > 0.) {
        fEventAction->AddEdepSeven(Edep7);
    }
}
else if (barvolume == fScoringVolume_8) {
     Edep8 = step->GetTotalEnergyDeposit();
    if (Edep8 > 0.) {
        fEventAction->AddEdepEight(Edep8);
    }
}
else if (barvolume == fScoringVolume_9) {
     Edep9 = step->GetTotalEnergyDeposit();
    if (Edep9 > 0.) {
        fEventAction->AddEdepNine(Edep9);
    }
}
else if (barvolume == fScoringVolume_10) {
    Edep10 = step->GetTotalEnergyDeposit();
    if (Edep10 > 0.) {
        fEventAction->AddEdepTen(Edep10);
    }
}
else if (barvolume == fScoringVolume_11) {
     Edep11 = step->GetTotalEnergyDeposit();
    if (Edep11 > 0.) {
        fEventAction->AddEdepEleven(Edep11);
    }
}
else if (barvolume == fScoringVolume_12) {
     Edep12 = step->GetTotalEnergyDeposit();
    if (Edep12 > 0.) {
        fEventAction->AddEdepTwelve(Edep12);
    }
}
else if (barvolume == fScoringVolume_13) {
     Edep13 = step->GetTotalEnergyDeposit();
    if (Edep13 > 0.) {
        fEventAction->AddEdepThirteen(Edep13);
    }
}
else if (barvolume == fScoringVolume_14) {
     Edep14 = step->GetTotalEnergyDeposit();
    if (Edep14 > 0.) {
        fEventAction->AddEdepFourteen(Edep14);
    }
}
else if (barvolume == fScoringVolume_15) {
     Edep15 = step->GetTotalEnergyDeposit();
    if (Edep15 > 0.) {
        fEventAction->AddEdepFifteen(Edep15);
    }
}
else if (barvolume == fScoringVolume_16) {
     Edep16 = step->GetTotalEnergyDeposit();
    if (Edep16 > 0.) {
        fEventAction->AddEdepSixteen(Edep16);
    }
}
else if (barvolume == fScoringVolume_17) {
     Edep17 = step->GetTotalEnergyDeposit();
    if (Edep17 > 0.) {
        fEventAction->AddEdepSeventeen(Edep17);
    }
}
else if (barvolume == fScoringVolume_18) {
   Edep18 = step->GetTotalEnergyDeposit();
    if (Edep18 > 0.) {
        fEventAction->AddEdepEighteen(Edep18);
    }
}
else if (barvolume == fScoringVolume_19) {
    Edep19 = step->GetTotalEnergyDeposit();
    if (Edep19 > 0.) {
        fEventAction->AddEdepNineteen(Edep19);
    }
}

   




}

}

   /*
         if (std::find(scoringVolumesA.begin(), scoringVolumesA.end(), barvolume) != scoringVolumesA.end())
        {

         G4int copyNumA = touchedbar->GetCopyNumber(); // Número de copia de la barra
         fEventAction->AddTraversedBar_A(copyNumA);
    
         G4double edep_A = step->GetTotalEnergyDeposit();
         if (edep_A > 0.&& stepLength > 0.)
         {
            G4double dEdxStep_A = edep_A / stepLength ;

            G4Material *plastic_scin = step->GetPreStepPoint()->GetMaterial(); 
            G4MaterialPropertiesTable *Yield = plastic_scin->GetMaterialPropertiesTable(); 
            G4double Scintillation_Yield = Yield->GetConstProperty("SCINTILLATIONYIELD");

            generated_photons_A = edep_A * Scintillation_Yield; 
            generated_photons_A = G4Poisson(generated_photons_A); 

            size_t a = std::distance(scoringVolumesA.begin(),
                                              std::find(scoringVolumesA.begin(), scoringVolumesA.end(), barvolume));
            
            fEventAction->AddPhotonG_UsingEdep_A(a, generated_photons_A);
            fEventAction->AddEdepA(a, edep_A);
            fEventAction->AccumulatedEdx_A(a, dEdxStep_A);    
         }}
      

         if (std::find(scoringVolumesB.begin(), scoringVolumesB.end(), barvolume) != scoringVolumesB.end())
        {

           
                G4int copyNumB = touchedbar->GetCopyNumber(); // Número de copia de la barra
                fEventAction->AddTraversedBar_B(copyNumB);
            

         G4double edep_B = step->GetTotalEnergyDeposit();
         if (edep_B > 0.&& stepLength > 0.)
         {
            G4double dEdxStep_B = edep_B  / stepLength ;

            G4Material *plastic_scin = step->GetPreStepPoint()->GetMaterial(); 
            G4MaterialPropertiesTable *Yield = plastic_scin->GetMaterialPropertiesTable(); 
            G4double Scintillation_Yield = Yield->GetConstProperty("SCINTILLATIONYIELD");

            generated_photons_B = edep_B * Scintillation_Yield; 
            generated_photons_B = G4Poisson(generated_photons_B); 
            
            size_t b = std::distance(scoringVolumesB.begin(),
                                              std::find(scoringVolumesB.begin(), scoringVolumesB.end(), barvolume));
            
            fEventAction->AddPhotonG_UsingEdep_B(b, generated_photons_B); 
            fEventAction->AddEdepB(b, edep_B);
            fEventAction->AccumulatedEdx_B(b, dEdxStep_B);  
        
         }
         }

        // Obtener el número de copia del volumen
        //G4int copynum = step->GetPreStepPoint()->GetTouchableHandle()->GetCopyNumber();
              //fEventAction->WorkingBars(copynum);  
}
*/
// ---------------------------------------------------------------------------------
        


/*
if(particle->GetParticleName()!= "opticalphoton"){
 if (std::find(scoringVolumesA.begin(), scoringVolumesA.end(), barvolume) != scoringVolumesA.end())
        {

         //G4int copyNumA = touchedbar->GetCopyNumber(); 
         
         G4double edep_others_A = step->GetTotalEnergyDeposit();
         if (edep_others_A > 0.&& stepLength > 0.)
         {
            G4String p_name = step->GetTrack()->GetDefinition()->GetParticleName();
           
            fEventAction->Particle_Name_Pierced_Layer_A(p_name);    
         }}
      

 if (std::find(scoringVolumesB.begin(), scoringVolumesB.end(), barvolume) != scoringVolumesB.end())
        {

         //G4int copyNumB = touchedbar->GetCopyNumber(); 
                
         G4double edep_others_B = step->GetTotalEnergyDeposit();
         if (edep_others_B > 0.&& stepLength > 0.)
         {
            G4String p_name = step->GetTrack()->GetDefinition()->GetParticleName();
           
            fEventAction->Particle_Name_Pierced_Layer_B(p_name);  
        
         }
         }
}
  */      


