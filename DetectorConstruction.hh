//    DETECTOR CONSTRUCTION HEADER

#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalPhysics.hh"
#include "SensitiveDetector.hh"
#include "G4GenericMessenger.hh" 
#include "G4OpticalSurface.hh"
#include "G4LogicalSkinSurface.hh" 
#include "G4SubtractionSolid.hh"

#include "G4FieldManager.hh"
#include "G4UniformMagField.hh"
#include "G4TransportationManager.hh"
#include "G4MagneticField.hh"


class G4VPhysicalVolume;
class G4LogicalVolume;




class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction();
    ~DetectorConstruction();
  
    virtual G4VPhysicalVolume *Construct(); 

    void ConstructMIDModule();     


    // TO RETRIEVE THE fScoringVolumes FOR STEPPING ACTION
    const std::vector<G4LogicalVolume*>& GetScoringVolumesA() const {
    return fScoringVolumes_A;
    }

    const std::vector<G4LogicalVolume*>& GetScoringVolumesB() const {
    return fScoringVolumes_B;
    }

    G4LogicalVolume *GetScoringVolume0() const {return fScoringVolume_0;} 
    G4LogicalVolume *GetScoringVolume1() const {return fScoringVolume_1;} 
    G4LogicalVolume *GetScoringVolume2() const {return fScoringVolume_2;}
    G4LogicalVolume *GetScoringVolume3() const {return fScoringVolume_3;}
    G4LogicalVolume *GetScoringVolume4() const {return fScoringVolume_4;}
    G4LogicalVolume *GetScoringVolume5() const {return fScoringVolume_5;}
    G4LogicalVolume *GetScoringVolume6() const {return fScoringVolume_6;}
    G4LogicalVolume *GetScoringVolume7() const {return fScoringVolume_7;}
    G4LogicalVolume *GetScoringVolume8() const {return fScoringVolume_8;}
    G4LogicalVolume *GetScoringVolume9() const {return fScoringVolume_9;}
    G4LogicalVolume *GetScoringVolume10() const {return fScoringVolume_10;}
    G4LogicalVolume *GetScoringVolume11() const {return fScoringVolume_11;}
    G4LogicalVolume *GetScoringVolume12() const {return fScoringVolume_12;}
    G4LogicalVolume *GetScoringVolume13() const {return fScoringVolume_13;}
    G4LogicalVolume *GetScoringVolume14() const {return fScoringVolume_14;}
    G4LogicalVolume *GetScoringVolume15() const {return fScoringVolume_15;}
    G4LogicalVolume *GetScoringVolume16() const {return fScoringVolume_16;}
    G4LogicalVolume *GetScoringVolume17() const {return fScoringVolume_17;}
    G4LogicalVolume *GetScoringVolume18() const {return fScoringVolume_18;}
    G4LogicalVolume *GetScoringVolume19() const {return fScoringVolume_19;}



   std::vector<G4LogicalVolume*> LogicBars_A; //<----
   std::vector<G4LogicalVolume*> LogicSiPMs_A;//<----
   std::vector<G4LogicalVolume*> fScoringVolumes_A;//<----

   std::vector<G4LogicalVolume*> LogicBars_B; //<----
   std::vector<G4LogicalVolume*> LogicSiPMs_B;//<----
   std::vector<G4LogicalVolume*> fScoringVolumes_B;//<----

    G4double wavelength, lightOutput;
    G4bool MID_Module; 
    G4double distance_modules; 
    
  
  private: 

    virtual void ConstructSDandField();

    G4double env_sizeX, env_sizeY, env_sizeZ; 

    G4GenericMessenger *fMessenger;  


    G4Box  *SolidWorld, *Solidbar, *Solidsipm, *SolidCube,
           *SolidSA, *Solidmylar, *SolidInnermylar;

    G4LogicalVolume *LogicWorld, *Logicbar, *Logicmylar, *Logicsipm, *LogicalSA,
                    *LogicCube, *Logicbar_A, *Logicbar_B, *Logicsipm_A, *Logicsipm_B;//<----

    G4VPhysicalVolume *PhysicalWorld, *Physicalbar, *Physicalsipm, *Physicalmylar, *PhysicalSA, *PhysicalCube,
                      *Physical_MID_A, *Physical_SiPM_MID_A, *Physical_Mylar_MID_A, //<----
                      *Physical_MID_B, *Physical_SiPM_MID_B, *Physical_Mylar_MID_B; //<----

    G4LogicalVolume *Logicbar_0, *Logicbar_1, *Logicbar_2, *Logicbar_3, *Logicbar_4, *Logicbar_5,
                     *Logicbar_6, *Logicbar_7, *Logicbar_8, *Logicbar_9, *Logicbar_10,
                     *Logicbar_11, *Logicbar_12, *Logicbar_13, *Logicbar_14, *Logicbar_15,
                     *Logicbar_16, *Logicbar_17, *Logicbar_18, *Logicbar_19;

    G4VPhysicalVolume *Phys_Bar_0, *Phys_Bar_1, *Phys_Bar_2, *Phys_Bar_3, *Phys_Bar_4, *Phys_Bar_5,
                      *Phys_Bar_6, *Phys_Bar_7, *Phys_Bar_8, *Phys_Bar_9, *Phys_Bar_10, *Phys_Bar_11,
                      *Phys_Bar_12, *Phys_Bar_13, *Phys_Bar_14, *Phys_Bar_15, *Phys_Bar_16, *Phys_Bar_17,
                      *Phys_Bar_18, *Phys_Bar_19;

    G4VPhysicalVolume *Phys_Bar_0_Mylar, *Phys_Bar_1_Mylar, *Phys_Bar_2_Mylar, *Phys_Bar_3_Mylar,  *Phys_Bar_4_Mylar,
                       *Phys_Bar_5_Mylar,  *Phys_Bar_6_Mylar, *Phys_Bar_7_Mylar, *Phys_Bar_8_Mylar, *Phys_Bar_9_Mylar,
                        *Phys_Bar_10_Mylar,  *Phys_Bar_11_Mylar, *Phys_Bar_12_Mylar, *Phys_Bar_13_Mylar, *Phys_Bar_14_Mylar,
                         *Phys_Bar_15_Mylar, *Phys_Bar_16_Mylar, *Phys_Bar_17_Mylar, *Phys_Bar_18_Mylar, *Phys_Bar_19_Mylar;

    void DefineMaterials();

    G4Material *plastic, *worldMaterial, *steel, *mylarMaterial;
   
    G4OpticalSurface *mirrorsurface; 

    G4LogicalVolume *fScoringVolume_0; 
    G4LogicalVolume *fScoringVolume_1; 
    G4LogicalVolume *fScoringVolume_2;
    G4LogicalVolume *fScoringVolume_3;
    G4LogicalVolume *fScoringVolume_4;
    G4LogicalVolume *fScoringVolume_5;
    G4LogicalVolume *fScoringVolume_6;
    G4LogicalVolume *fScoringVolume_7;
    G4LogicalVolume *fScoringVolume_8;
    G4LogicalVolume *fScoringVolume_9;
    G4LogicalVolume *fScoringVolume_10;
    G4LogicalVolume *fScoringVolume_11;
    G4LogicalVolume *fScoringVolume_12;
    G4LogicalVolume *fScoringVolume_13;
    G4LogicalVolume *fScoringVolume_14;
    G4LogicalVolume *fScoringVolume_15;
    G4LogicalVolume *fScoringVolume_16;
    G4LogicalVolume *fScoringVolume_17;
    G4LogicalVolume *fScoringVolume_18;
    G4LogicalVolume *fScoringVolume_19;
  
};

#endif

