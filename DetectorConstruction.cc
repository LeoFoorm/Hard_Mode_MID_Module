//  DETECTOR CONSTRCTION SOURCE


#include "DetectorConstruction.hh"
#include "G4SystemOfUnits.hh"
#include <fstream>
#include <vector>
#include <iostream>
#include <tuple>


DetectorConstruction::DetectorConstruction()
{
  fMessenger = new G4GenericMessenger(this, "/detector/", "Detector Construction");
  fMessenger->DeclareProperty("MID_Module", MID_Module, "Construct MID module detector");
  fMessenger->DeclareProperty("distance_modules", distance_modules, "The distance between both modules");
  
  DefineMaterials();

  env_sizeX = 5*m;
  env_sizeY = 5*m;
  env_sizeZ = 5*m;

  distance_modules = 20*cm + 1.04*cm;

  MID_Module = true; 
}


DetectorConstruction::~DetectorConstruction()
{}


void DetectorConstruction::DefineMaterials()
{
  
  std::vector<G4double> wavelength = {499.83,496.62,491.92,487.22,482.51,477.81,473.10,468.40,463.69,458.99,454.28,449.58,445.30,441.45,438.03,434.18,429.69,425.20,417.03,415.36,414.08,413.22,412.53,411.60,410.66,409.80, 408.53,405.80,402.75,400.18,399.32,397.27,396.33,395.48,394.62,394.28,392.91,392.27,391.41,390.34,389.70,388.42,386.63,384.57,381.58,380.31};
  std::vector<G4double> lightOutput = {2.55,2.56,2.97,3.59,4.40,5.49,6.93,8.52,10.68,13.38,17.07,21.41,26.21,31.27,36.04,40.53,45.23,49.04,53.41,58.78,63.62,68.61,73.05,78.28,83.01,88.07,92.45,96.07,99.46,96.00,91.32,86.66,80.18,73.98,69.53,64.76,58.40,50.56,44.59,38.14,33.28,29.14,23.55,17.68,12.13,6.27,4.06};
  std::vector<G4double> energy;
  std::vector<G4double> RI;
  std::vector<G4double> fraction;
  std::vector<G4double> absSC;
  std::vector<G4double> rindexWorld;
  std::vector<G4double> reflectivity;
  std::vector<G4double> rindexmylar;

  G4double RefIndex=1.58;
  G4double AbsSC = 160.*cm;
  G4double RIWorld = 1.0;
  G4double Reflectivity = 0.9999;
  G4double Rindexmylar = 1.655;


  for (size_t i = 0; i < wavelength.size(); ++i) {

    G4double Energy = 1.239841939 * eV / (wavelength[i] / 1000);

    G4double normalizedLightOutput = lightOutput[i] / 100;

    energy.push_back(Energy);

    fraction.push_back(normalizedLightOutput);

    RI.push_back(RefIndex);

    absSC.push_back(AbsSC);

    rindexWorld.push_back(RIWorld);

    reflectivity.push_back(Reflectivity);

    rindexmylar.push_back(Rindexmylar);
    }
  
  G4int numberOfEntries = energy.size();


 G4OpticalParameters::Instance()->SetScintFiniteRiseTime(true); 

 G4NistManager *nist = G4NistManager::Instance();
 worldMaterial = nist->FindOrBuildMaterial("G4_AIR");
 plastic = nist->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
 mylarMaterial = nist->FindOrBuildMaterial("G4_MYLAR");
 steel = nist->FindOrBuildMaterial("G4_Fe");
 mirrorsurface = new G4OpticalSurface("mirrorsurface");

 mirrorsurface->SetType(dielectric_dielectric);
 mirrorsurface->SetFinish(polishedfrontpainted);
 mirrorsurface->SetModel(unified);

 G4MaterialPropertiesTable *mirror=new G4MaterialPropertiesTable();
 G4MaterialPropertiesTable *prop=new G4MaterialPropertiesTable();
 G4MaterialPropertiesTable *propworld=new G4MaterialPropertiesTable();
 G4MaterialPropertiesTable *propmylar=new G4MaterialPropertiesTable();
 

 propworld->AddProperty("RINDEX",energy, rindexWorld,numberOfEntries);
 prop->AddProperty("RINDEX",energy, RI,numberOfEntries);
 prop->AddProperty("SCINTILLATIONCOMPONENT1",energy,fraction,numberOfEntries);
 prop->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 1.8*ns);
 prop->AddConstProperty("SCINTILLATIONRISETIME1", 0.7*ns); //decay time of the scintillator
 prop->AddConstProperty("SCINTILLATIONYIELD", 10.666666/keV);//amount of photons per (in this case) KeV        
 prop->AddConstProperty("RESOLUTIONSCALE", 1.);
 prop->AddProperty("ABSLENGTH",energy,absSC,numberOfEntries);
 mirror->AddProperty("REFLECTIVITY", energy, reflectivity);
 propmylar->AddProperty("RINDEX",energy, rindexmylar,numberOfEntries);


 G4double density = steel->GetDensity(); // Densidad en unidades de Geant4
        std::cout << "Material: " << steel->GetName() << std::endl;
        std::cout << "Densidad: " << density/ (kg/m3)  << " kg/m^3" << std::endl;


 worldMaterial->SetMaterialPropertiesTable(propworld);
 plastic->SetMaterialPropertiesTable(prop);
 mirrorsurface->SetMaterialPropertiesTable(mirror);
 mylarMaterial->SetMaterialPropertiesTable(propmylar);
}


void DetectorConstruction::ConstructMIDModule()
{
  //                     BAR 
  G4double bar_X = 2.5*cm;
  G4double bar_Y = 0.5*cm;
  G4double bar_Z = 50*cm;
  
  Solidbar = new G4Box("Solidbar", bar_X, bar_Y, bar_Z );

  Logicbar_0 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_0");
  Logicbar_1 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_1");
  Logicbar_2 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_2");
  Logicbar_3 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_3");
  Logicbar_4 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_4");
  Logicbar_5 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_5");
  Logicbar_6 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_6");
  Logicbar_7 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_7");
  Logicbar_8 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_8");
  Logicbar_9 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_9");
  Logicbar_10 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_10");
  Logicbar_11 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_11");
  Logicbar_12 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_12");
  Logicbar_13 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_13");
  Logicbar_14 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_14");
  Logicbar_15 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_15");
  Logicbar_16 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_16");
  Logicbar_17 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_17");
  Logicbar_18 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_18");
  Logicbar_19 = new G4LogicalVolume(Solidbar, plastic, "Logicbar_19");

fScoringVolume_0 = Logicbar_0;
fScoringVolume_1 = Logicbar_1;
fScoringVolume_2 = Logicbar_2;
fScoringVolume_3 = Logicbar_3;
fScoringVolume_4 = Logicbar_4;
fScoringVolume_5 = Logicbar_5;
fScoringVolume_6 = Logicbar_6;
fScoringVolume_7 = Logicbar_7;
fScoringVolume_8 = Logicbar_8;
fScoringVolume_9 = Logicbar_9;
fScoringVolume_10 = Logicbar_10;
fScoringVolume_11 = Logicbar_11;
fScoringVolume_12 = Logicbar_12;
fScoringVolume_13 = Logicbar_13;
fScoringVolume_14 = Logicbar_14;
fScoringVolume_15 = Logicbar_15;
fScoringVolume_16 = Logicbar_16;
fScoringVolume_17 = Logicbar_17;
fScoringVolume_18 = Logicbar_18;
fScoringVolume_19 = Logicbar_19;
//                        SiPM 
  G4double sipm_X = 0.3*cm;
  G4double sipm_Y = 0.3*cm;
  G4double sipm_Z = 0.01*cm;
  
  Solidsipm = new G4Box("Solidsipm", sipm_X, sipm_Y, sipm_Z );


//                        MYLAR
  G4double mylar_x = 2.52*cm;
  G4double mylar_y = 0.52*cm;
  G4double mylar_z = 50.08*cm;
 Solidmylar = new G4Box("Solidmylar", mylar_x, mylar_y, mylar_z);
 SolidInnermylar = new G4Box("SolidInnermylar", mylar_x-0.01*cm, mylar_y-0.01*cm, mylar_z-0.01*cm);
 G4SubtractionSolid* hollowMylarBox = new G4SubtractionSolid("HollowMylarBox", Solidmylar, SolidInnermylar);
 Logicmylar = new G4LogicalVolume(hollowMylarBox, mylarMaterial, "Logicmylar");
 G4LogicalSkinSurface *skin= new G4LogicalSkinSurface("skin", Logicmylar, mirrorsurface); 


//              PHYSICAL BARS (A)

Phys_Bar_0 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*0) * cm, 0, 0), Logicbar_0, "Phys_Bar_Zero", LogicWorld, false, 0, true);
Phys_Bar_1 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*1) * cm, 0, 0), Logicbar_1, "Phys_Bar_One", LogicWorld, false, 1, true);
Phys_Bar_2 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*2) * cm, 0, 0), Logicbar_2, "Phys_Bar_Two", LogicWorld, false, 2, true);
Phys_Bar_3 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*3) * cm, 0, 0), Logicbar_3, "Phys_Bar_Three", LogicWorld, false, 3, true);
Phys_Bar_4 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 4) * cm, 0, 0), Logicbar_4, "Phys_Bar_Four", LogicWorld, false, 4, true);
Phys_Bar_5 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 5) * cm, 0, 0), Logicbar_5, "Phys_Bar_Five", LogicWorld, false, 5, true);
Phys_Bar_6 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 6) * cm, 0, 0), Logicbar_6, "Phys_Bar_Six", LogicWorld, false, 6, true);
Phys_Bar_7 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 7) * cm, 0, 0), Logicbar_7, "Phys_Bar_Seven", LogicWorld, false, 7, true);
Phys_Bar_8 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 8) * cm, 0, 0), Logicbar_8, "Phys_Bar_Eight", LogicWorld, false, 8, true);
Phys_Bar_9 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 9) * cm, 0, 0), Logicbar_9, "Phys_Bar_Nine", LogicWorld, false, 9, true);
Phys_Bar_10 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 10) * cm, 0, 0), Logicbar_10, "Phys_Bar_Ten", LogicWorld, false, 10, true);
Phys_Bar_11 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 11) * cm, 0, 0), Logicbar_11, "Phys_Bar_Eleven", LogicWorld, false, 11, true);
Phys_Bar_12 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 12) * cm, 0, 0), Logicbar_12, "Phys_Bar_Twelve", LogicWorld, false, 12, true);
Phys_Bar_13 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 13) * cm, 0, 0), Logicbar_13, "Phys_Bar_Thirteen", LogicWorld, false, 13, true);
Phys_Bar_14 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 14) * cm, 0, 0), Logicbar_14, "Phys_Bar_Fourteen", LogicWorld, false, 14, true);
Phys_Bar_15 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 15) * cm, 0, 0), Logicbar_15, "Phys_Bar_Fifteen", LogicWorld, false, 15, true);
Phys_Bar_16 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 16) * cm, 0, 0), Logicbar_16, "Phys_Bar_Sixteen", LogicWorld, false, 16, true);
Phys_Bar_17 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 17) * cm, 0, 0), Logicbar_17, "Phys_Bar_Seventeen", LogicWorld, false, 17, true);
Phys_Bar_18 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 18) * cm, 0, 0), Logicbar_18, "Phys_Bar_Eighteen", LogicWorld, false, 18, true);
Phys_Bar_19 = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 19) * cm, 0, 0), Logicbar_19, "Phys_Bar_Nineteen", LogicWorld, false, 19, true);


Phys_Bar_0_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*0) * cm, 0, 0), Logicmylar, "Phys_Bar_0_Mylar", LogicWorld, false, 0, true);
Phys_Bar_1_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*1) * cm, 0, 0), Logicmylar, "Phys_Bar_1_Mylar", LogicWorld, false, 1, true);
Phys_Bar_2_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*2) * cm, 0, 0), Logicmylar, "Phys_Bar_2_Mylar", LogicWorld, false, 2, true);
Phys_Bar_3_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 3) * cm, 0, 0), Logicmylar, "Phys_Bar_3_Mylar", LogicWorld, false, 3, true);
Phys_Bar_4_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 4) * cm, 0, 0), Logicmylar, "Phys_Bar_4_Mylar", LogicWorld, false, 4, true);
Phys_Bar_5_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 5) * cm, 0, 0), Logicmylar, "Phys_Bar_5_Mylar", LogicWorld, false, 5, true);
Phys_Bar_6_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 6) * cm, 0, 0), Logicmylar, "Phys_Bar_6_Mylar", LogicWorld, false, 6, true);
Phys_Bar_7_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 7) * cm, 0, 0), Logicmylar, "Phys_Bar_7_Mylar", LogicWorld, false, 7, true);
Phys_Bar_8_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 8) * cm, 0, 0), Logicmylar, "Phys_Bar_8_Mylar", LogicWorld, false, 8, true);
Phys_Bar_9_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 9) * cm, 0, 0), Logicmylar, "Phys_Bar_9_Mylar", LogicWorld, false, 9, true);
Phys_Bar_10_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 10) * cm, 0, 0), Logicmylar, "Phys_Bar_10_Mylar", LogicWorld, false, 10, true);
Phys_Bar_11_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 11) * cm, 0, 0), Logicmylar, "Phys_Bar_11_Mylar", LogicWorld, false, 11, true);
Phys_Bar_12_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 12) * cm, 0, 0), Logicmylar, "Phys_Bar_12_Mylar", LogicWorld, false, 12, true);
Phys_Bar_13_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 13) * cm, 0, 0), Logicmylar, "Phys_Bar_13_Mylar", LogicWorld, false, 13, true);
Phys_Bar_14_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 14) * cm, 0, 0), Logicmylar, "Phys_Bar_14_Mylar", LogicWorld, false, 14, true);
Phys_Bar_15_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 15) * cm, 0, 0), Logicmylar, "Phys_Bar_15_Mylar", LogicWorld, false, 15, true);
Phys_Bar_16_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 16) * cm, 0, 0), Logicmylar, "Phys_Bar_16_Mylar", LogicWorld, false, 16, true);
Phys_Bar_17_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 17) * cm, 0, 0), Logicmylar, "Phys_Bar_17_Mylar", LogicWorld, false, 17, true);
Phys_Bar_18_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 18) * cm, 0, 0), Logicmylar, "Phys_Bar_18_Mylar", LogicWorld, false, 18, true);
Phys_Bar_19_Mylar = new G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04 * 19) * cm, 0, 0), Logicmylar, "Phys_Bar_19_Mylar", LogicWorld, false, 19, true);

/*
//             20 SCINTILLATION BARS A 

  for (G4int i = 0; i <20; i++)
  {

  Logicbar_A = new G4LogicalVolume(Solidbar, plastic, "Logicbar_A_"+std::to_string(i));
  LogicBars_A.push_back(Logicbar_A);
  fScoringVolumes_A.push_back(Logicbar_A);


  Physical_MID_A = new  G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*i) * cm, 0, 0),
                                    Logicbar_A, "Physical_MID_A", LogicWorld, false, i, true);
  }


//             20 SiPM A 

 for (G4int j = 0; j<20; j++)
 {
  Logicsipm_A= new G4LogicalVolume(Solidsipm, worldMaterial, "Logicsipm_A_"+std::to_string(j));
  LogicSiPMs_A.push_back(Logicsipm_A);

  Physical_SiPM_MID_A = new  G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*j) * cm, 0, 50.03*cm),
                                    Logicsipm_A, "Physical_SiPM_MID_A", LogicWorld, false, j, true);
 }


//             20 MYLAR A 
  for(G4int k = 0; k<20; k++)
  {
  Physical_Mylar_MID_A = new  G4PVPlacement(0, G4ThreeVector(-47.88 * cm + (5.04*k) * cm, 0, 0),
                                    Logicmylar, "Physical_Mylar_MID_A", LogicWorld, false, k, true);
  }


//---------------- 20 SCINTILLATION BARS B  -----------------------------
  G4RotationMatrix* rotationY = new G4RotationMatrix(); 
  rotationY->rotateY(90*deg);

  for (G4int l = 0; l <20; l++)
  {
  Logicbar_B = new G4LogicalVolume(Solidbar, plastic, "Logicbar_B_"+std::to_string(l));
  LogicBars_B.push_back(Logicbar_B);
  fScoringVolumes_B.push_back(Logicbar_B);

  Physical_MID_B = new  G4PVPlacement(rotationY, G4ThreeVector( 0, distance_modules, -47.88 * cm + (5.04*l) * cm),
                                    Logicbar_B, "Physical_MID_B", LogicWorld, false, l+20, true);
  }


//             20 SiPM B 
 for (G4int m = 0; m<20; m++)
 {
  Logicsipm_B= new G4LogicalVolume(Solidsipm, worldMaterial, "Logicsipm_B_"+std::to_string(m));
  LogicSiPMs_B.push_back(Logicsipm_B);
  
  Physical_SiPM_MID_B = new  G4PVPlacement(rotationY, G4ThreeVector(50.03*cm, distance_modules,  -47.88 * cm + (5.04*m) * cm),
                                    Logicsipm_B, "Physical_SiPM_MID_B", LogicWorld, false, m+20, true);
 }


//             20 MYLAR B  
  for(G4int n = 0; n<20; n++)
  {
  Physical_Mylar_MID_B = new  G4PVPlacement(rotationY, G4ThreeVector(0, distance_modules, -47.88 * cm + (5.04*n) * cm),
                                    Logicmylar, "Physical_Mylar_MID_B", LogicWorld, false, n+20, true);
  }
*/

  //---------------  STEEL-ABSORBER  ---------------

  G4double SA_X = 50*cm;
  G4double SA_Y = 35*cm;
  G4double SA_Z =50*cm;

  G4ThreeVector  positionSA = G4ThreeVector(0, 66.56*cm, 0);

  SolidSA = new G4Box("SolidSA", SA_X, SA_Y, SA_Z );
 LogicalSA = new G4LogicalVolume(SolidSA, steel, "LogicSA");
 PhysicalSA = new G4PVPlacement(0, positionSA, LogicalSA, "PhysicalSA", LogicWorld, false, 0, true);



//              CUBE TO B FIELD
  G4double BcubeX = 4.9 * m;
  G4double BcubeY = 1.9921 * m;
  G4double BcubeZ = 4.9 * m;

  G4ThreeVector positioncube = G4ThreeVector(0, 3.0077 * m, 0);
  SolidCube = new G4Box("SolidCube", BcubeX, BcubeY, BcubeZ);
  LogicCube = new G4LogicalVolume(SolidCube, worldMaterial, "LogicCube");
 PhysicalCube = new G4PVPlacement(0, positioncube, LogicCube, "PhysicalCube", LogicWorld, false, 0, true);

}



G4VPhysicalVolume *DetectorConstruction::Construct()
{
  // Solid world
  SolidWorld = new G4Box("SolidWorld", env_sizeX, env_sizeY, env_sizeZ);
  
  //logical
  LogicWorld = new G4LogicalVolume(SolidWorld, worldMaterial, "LogicWorld");

  //Physical
  PhysicalWorld = new G4PVPlacement(0, G4ThreeVector(), LogicWorld, "PhysicalWorld", 0, false, 0, true);


  if (MID_Module)
   ConstructMIDModule(); 

  return PhysicalWorld; 
}


void DetectorConstruction::ConstructSDandField()
{
 SensitiveDetector *sensDet = new SensitiveDetector("SensitiveDetector");
 // Assign sensitive detector to all SiPMs in Set A
    for (auto& logicSiPM_aasignment_a : LogicSiPMs_A) {
        logicSiPM_aasignment_a->SetSensitiveDetector(sensDet);
    }

    // Assign sensitive detector to all SiPMs in Set B
    for (auto& logicSiPM_aasignment_b : LogicSiPMs_B) {
        logicSiPM_aasignment_b->SetSensitiveDetector(sensDet);
    }
  

  G4MagneticField *magField;
  G4ThreeVector BField = G4ThreeVector(0., 0., 5.0 *kilogauss);
  magField = new G4UniformMagField(BField);

  G4FieldManager* FieldMngr = new G4FieldManager(magField);
  FieldMngr->SetDetectorField(magField);
  FieldMngr->CreateChordFinder(magField);
  LogicCube->SetFieldManager(FieldMngr,true); 
  
}

