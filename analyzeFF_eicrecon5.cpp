#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void analyzeFF_eicrecon5(){
    
        TString fileList = "q2_1-10.list";
        //TString fileList = "newlist.list";
        
        
        TString outputName = "ab_test_00mrad_hepmc_";
        
        TString date = "7_8_2024_";
        
        TString run  = "run_0";
        
        cout << "Input FileList: " << fileList << endl;
        TString fileType_ROOT = ".root";
        TString outputFileName = outputName + date + run + fileType_ROOT;
        string fileName;
        TFile * inputRootFile;
        TTree * rootTree;
        cout << "Output file: " << outputFileName << endl;
        
        ifstream fileListStream;
        fileListStream.open(fileList);
        if(!fileListStream) { cout << "NO_LIST_FILE " << fileList << endl; return;}
        
    TLorentzVector vec1;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec2;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec3;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec4;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec5;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec6;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec7;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector vecjpsi;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector JPsi1;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi2;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi22;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi222;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector rcpv1;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rcpv11;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rcpv2;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rcpv22;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rcpv3;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rcpv4;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector scte;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector incbeam;//(10.0, 20.0, 30.0, 40.0); //proton
    TLorentzVector incbeame;//(10.0, 20.0, 30.0, 40.0);//electron
    TLorentzVector beamProton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector mcProton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector scatProton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector scatElectron;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector eq1;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector eq2;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector eq3;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector eq4;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector mctrk2;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector iphoton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector iproton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector jproton;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector ijpsi;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector jjpsi;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector mctrue;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector afburn;//(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector mchfs;//(10.0, 20.0, 30.0, 40.0);
    TLorentzVector rchfs;//(10.0, 20.0, 30.0, 40.0);
        
        TH1D *fElectron = new TH1D("fElectron","fe", 100, -10, 10);
        TH1D *jpsiElectron = new TH1D("jpsiElectron","jpsie", 100, -10, 10);
        TH1D *fProton= new TH1D("fProton","Final Proton", 100, 4, 12);
        TH1D *fPositron= new TH1D("fPositron","fp+", 100, -10, 10);
        TH1D *B0fProton= new TH1D("B0fProton","B0fp", 100, 4, 12);
        TH1D *RPfProton= new TH1D("RPfProton","RPfp", 100, 4, 12);
        TH1D *OMDfProton= new TH1D("OMDfProton","OMDfp", 100, 4, 12);
    
        TH1D *rcElectron= new TH1D("rcElectron","rcElectron", 100, -10, 10);
        TH1D *rcPositron= new TH1D("rcPositron","rcPositron", 100, -10, 10);
        
        TH1D *diffjpsimass = new TH1D("diffjpsimass","diffjpsimass", 500, -2, 2);
        TH1D *diffx_v = new TH1D("diffx_v","diffx_v", 500, -0.02, 0.02);
        TH1D *difft = new TH1D("difft","difft", 500, -1, 1);
        TH1D *diffq2 = new TH1D("diffq2","diffq2", 500, -10, 10);
    
        TH1D *JPsiMass1 = new TH1D("JPsiMass1","J/#psi-Mass", 500, -10, 30);
        TH1D *rcJPsiMass1 = new TH1D("rcJPsiMass1","rcJ/#psi-Mass", 500, -10, 30);
        TH1D *rcJPsiMass11 = new TH1D("rcJPsiMass11","rcJ/#psi-Mass", 500, -10, 30);
        TH1D *rcJPsiMass111 = new TH1D("rcJPsiMass111","rcJ/#psi-Mass", 500, -10, 30);
    
        TH1D *mtg = new TH1D("mtg","mtg", 4000, 0, 100);
        TH1D *mtgg = new TH1D("mtgg","mtgg", 4000, 0, 100);
        TH1D *mta = new TH1D("mta","mta", 200, 0, 10);
        TH1D *mtq = new TH1D("mtq","mtq", 50, 1, 10);
        TH1D *mtqq = new TH1D("mtqq","mtqq", 50, 1, 10);
        
        TH1D *ElectfJpsi = new TH1D("ElectfJpsi","ElectfJpsi", 200, -10, 10);
        TH1D *PositfJpsi = new TH1D("PositfJpsi","PositfJpsi", 200, -10, 10);
    
        TH1D *x_bjk = new TH1D("x_bjk","x_bjk", 2000, -100, 100);
        TH1D *xb = new TH1D("xb","xb", 500, 0, 1);
        TH1D *xb1 = new TH1D("xb1","xb1", 500, 0, 1);
        TH1D *xv = new TH1D("xv","xv", 500, 0, 1);
        TH1D *xv1 = new TH1D("xv1","xv1", 500, 0, 1);
    
        TH1D* rcElectronpt = new TH1D("rcElectronpt", ";p_{t} [GeV/c]", 100, -10, 10.0);
        TH1D* rcPositronpt = new TH1D("rcPositronpt", ";p_{t} [GeV/c]", 100, -10, 10.0);
        TH1D* rcElectronjpsipt = new TH1D("rcElectronjpsipt", ";p_{t} [GeV/c]", 100, -10,10.0);
        TH1D* rcElectronjpsieta = new TH1D("rcElectronjpsieta",";Pseudorapidity, #eta",100,-10,10.0);
        TH1D* rcPositroneta = new TH1D("rcPositroneta",";Pseudorapidity, #eta",100,-10,10.0);
    
        TH1D* mcjpsie_e_minus_pz = new TH1D("mcjpsie_e_minus_pz","mcjpsie_e_minus_pz",100, -50, 150.0);
        TH1D* mcjpsipos_e_minus_pz = new TH1D("mcjpsipos_e_minus_pz","mcjpsipos_e_minus_pz",100, -50, 150.0);
        TH1D* rcjpsie_e_minus_pz = new TH1D("rcjpsie_e_minus_pz","rcjpsie_e_minus_pz",100, -50, 150.0);
        TH1D* rcjpsipos_e_minus_pz = new TH1D("rcjpsipos_e_minus_pz","rcjpsipos_e_minus_pz",100, -50, 150.0);
        TH1D* mcsce_e_minus_pz = new TH1D("mcsce_e_minus_pz","mcsce_e_minus_pz",100, -50, 150.0);
        TH1D* rcsce_e_minus_pz = new TH1D("rcsce_e_minus_pz","rcsce_e_minus_pz",100, -50, 150.0);
        TH1D* djpsicheck_e_minus_pz = new TH1D("djpsicheck_e_minus_pz","djpsicheck_e_minus_pz",100, -50, 150.0);
    
        TH1D* mcjpsitwoenergy = new TH1D("mcjpsitwoenergy","mcjpsitwoenergy",100, -50, 150.0);
        TH1D* mcsctwoenergy = new TH1D("mcsctwoenergy","mcsctwoenergy",100, -50, 150.0);
        TH1D* rcjpsitwoenergy = new TH1D("rcjpsitwoenergy","rcjpsitwoenergy",100, -50, 150.0);
        TH1D* rcsctwoenergy = new TH1D("rcsctwoenergy","rcsctwoenergy",100, -50, 150.0);
    
        TH2D* mcjpsie_pt_vs_eta = new TH2D("mcjpsie_pt_vs_eta","mcjpsie_pt_vs_eta",100,-10,10.0,100,0,20.0);
        TH2D* rcjpsie_pt_vs_eta = new TH2D("rcjpsie_pt_vs_eta","rcjpsie_pt_vs_eta",100,-10,10.0,100,0,20.0);
        TH2D* mcjpsie_pz_vs_eta = new TH2D("mcjpsie_pz_vs_eta","mcjpsie_pz_vs_eta",100,-10,10.0,100, -20, 100.0);
        TH2D* rcjpsie_pz_vs_eta = new TH2D("rcjpsie_pz_vs_eta","rcjpsie_pz_vs_eta",100,-10,10.0,100, -20, 100.0);
    
        TH2D* mcjpsie_e_vs_eta = new TH2D("mcjpsie_e_vs_eta","mcjpsie_e_vs_eta",100,-10,10.0,100,-5,100.0);
        TH2D* rcjpsie_e_vs_eta = new TH2D("rcjpsie_e_vs_eta","rcjpsie_e_vs_eta",100,-10,10.0,100,-5,100.0);
        TH2D* mcsce_e_vs_eta = new TH2D("mcsce_e_vs_eta","mcsce_e_vs_eta",100,-10,10.0,100, -5, 100);
        TH2D* rcsce_e_vs_eta = new TH2D("rcsce_e_vs_eta","rcsce_e_vs_eta",100,-10,10.0,100, -5, 100);
        
        TH2D* mcsce_pt_vs_eta = new TH2D("mcsce_pt_vs_eta","mcsce_pt_vs_eta",100,-10,10.0,100,0,20.0);
        TH2D* rcsce_pt_vs_eta = new TH2D("rcsce_pt_vs_eta","rcsce_pt_vs_eta",100,-10,10.0,100,0,20.0);
        TH2D* mcsce_pz_vs_eta = new TH2D("mcsce_pz_vs_eta","mcsce_pz_vs_eta",100,-10,10.0,100, -20, 100.0);
        TH2D* rcsce_pz_vs_eta = new TH2D("rcsce_pz_vs_eta","rcsce_pz_vs_eta",100,-10,10.0,100, -20, 100.0);
        
        TH2D* mcjpsie_e_vs_pz = new TH2D("mcjpsie_e_vs_pz","mcjpsie_e_vs_pz",100, -50, 150.0,100,-20, 150);
        TH2D* mcjpsipos_e_vs_pz = new TH2D("mcjpsipos_e_vs_pz","mcjpsipos_e_vs_pz",100, -50, 150.0,100,-20, 150);
        TH2D* rcjpsie_e_vs_pz = new TH2D("rcjpsie_e_vs_pz","rcjpsie_e_vs_pz",100, -50, 150.0,100,-20, 150);
        TH2D* rcjpsipos_e_vs_pz = new TH2D("rcjpsipos_e_vs_pz","rcjpsipos_e_vs_pz",100, -50, 150.0,100,-20, 150);
        TH2D* mcsce_e_vs_pz = new TH2D("mcsce_e_vs_pz","mcsce_e_vs_pz",100, -50, 150.0,100, -20, 150);
        TH2D* rcsce_e_vs_pz = new TH2D("rcsce_e_vs_pz","rcsce_e_vs_pz",100, -50, 150.0,100, -20, 150);
    
        TH2D* mcjpsie_theta_vs_phi = new TH2D("mcjpsie_theta_vs_phi","mcjpsie_theta_vs_phi",200,-50, 150.0,200,-20, 150);
        TH2D* mcjpsipos_theta_vs_phi = new TH2D("mcjpsipos_theta_vs_phi","mcjpsipos_theta_vs_phi",200,-50, 150.0,200,-20, 150);
        TH2D* mcsce_theta_vs_phi = new TH2D("mcsce_theta_vs_phi","mcsce_theta_vs_phi",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsie_theta_vs_phi = new TH2D("rcjpsie_theta_vs_phi","rcjpsie_theta_vs_phi",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsipos_theta_vs_phi = new TH2D("rcjpsipos_theta_vs_phi","rcjpsipos_theta_vs_phi",200,-50, 150.0,200,-20, 150);
        TH2D* rcsce_theta_vs_phi = new TH2D("rcsce_theta_vs_phi","rcsce_theta_vs_phi",200,-50, 150.0,200,-20, 150);
    
        TH2D* mcjpsie_phi_vs_eta = new TH2D("mcjpsie_phi_vs_eta","mcjpsie_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        TH2D* mcjpsipos_phi_vs_eta = new TH2D("mcjpsipos_phi_vs_eta","mcjpsipos_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        TH2D* mcsce_phi_vs_eta = new TH2D("mcsce_phi_vs_eta","mcsce_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsie_phi_vs_eta = new TH2D("rcjpsie_phi_vs_eta","rcjpsie_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsipos_phi_vs_eta = new TH2D("rcjpsipos_phi_vs_eta","rcjpsipos_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        TH2D* rcsce_phi_vs_eta = new TH2D("rcsce_phi_vs_eta","rcsce_phi_vs_eta",200,-50, 150.0,200,-20, 150);
        
        TH2D* mcjpsie_phi_vs_e = new TH2D("mcjpsie_phi_vs_e","mcjpsie_phi_vs_e",200,-50, 150.0,200,-20, 150);
        TH2D* mcjpsipos_phi_vs_e = new TH2D("mcjpsipos_phi_vs_e","mcjpsipos_phi_vs_e",200,-50, 150.0,200,-20, 150);
        TH2D* mcsce_phi_vs_e = new TH2D("mcsce_phi_vs_e","mcsce_phi_vs_e",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsie_phi_vs_e = new TH2D("rcjpsie_phi_vs_e","rcjpsie_phi_vs_e",200,-50, 150.0,200,-20, 150);
        TH2D* rcjpsipos_phi_vs_e = new TH2D("rcjpsipos_phi_vs_e","rcjpsipos_phi_vs_e",200,-50, 150.0,200,-20, 150);
        TH2D* rcsce_phi_vs_e = new TH2D("rcsce_phi_vs_e","rcsce_phi_vs_e",200,-50, 150.0,200,-20, 150);
    
        //--------------------------------------------------------------------------
        
        //histograms -- only a few for now
        
        //MC information
        //fProton
        TH1D* h6_eta_MC = new TH1D("h6_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h6_px_MC = new TH1D("px6_MC", ";p_{x} [GeV/c]", 100, -8.5, 10);
        TH1D* h6_py_MC = new TH1D("py6_MC", ";p_{y} [GeV/c]", 100, -2.0, 2.0);
        TH1D* h6_pt_MC = new TH1D("pt6_MC", ";p_{t} [GeV/c]", 100, -1, 2);
        TH1D* h6_pz_MC = new TH1D("pz6_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h6_e_MC = new TH1D("e6_MC", ";E [GeV]", 100, 0.0, 320.0);
    
        //generated
        TH1D* in_pt_MC = new TH1D("in_pt_MC", ";p_{t} [GeV/c]", 100, -1, 2);
        TH1D* fi_pt_gen = new TH1D("fi_pt_gen", ";p_{t} [GeV/c]", 100, -1, 2);
        
        //fPositron
        TH1D* h7_eta_MC = new TH1D("h7_eta",";Pseudorapidity, #eta",100,-10,10.0);
        TH1D* h7_px_MC = new TH1D("px7_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h7_py_MC = new TH1D("py7_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h7_pt_MC = new TH1D("pt7_MC", ";p_{t} [GeV/c]", 100, -10, 10.0);
        TH1D* h7_pz_MC = new TH1D("pz7_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h7_e_MC = new TH1D("e7_MC", ";E [GeV]", 100, 0.0, 320.0);
        
        //fElectron
        TH1D* h8_eta_MC = new TH1D("h8_eta",";Pseudorapidity, #eta",100,-10,10.0);
        TH1D* h8_px_MC = new TH1D("px8_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h8_py_MC = new TH1D("py8_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h8_pt_MC = new TH1D("pt8_MC", ";p_{t} [GeV/c]", 100, -10, 10.0);
        TH1D* h8_pz_MC = new TH1D("pz8_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h8_e_MC = new TH1D("e8_MC", ";E [GeV]", 100, 0.0, 320.0);
    
        //jpsi electron
        TH1D* hjpsi_eta_MC = new TH1D("hjpsi_eta",";Pseudorapidity, #eta",100,-10,10.0);
        TH1D* hjpsi_px_MC = new TH1D("pxjpsi_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* hjpsi_py_MC = new TH1D("pyjpsi_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* hjpsi_pt_MC = new TH1D("ptjpsi_MC", ";p_{t} [GeV/c]", 100, -10, 10.0);
        TH1D* hjpsi_pz_MC = new TH1D("pzjpsi_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* hjpsi_e_MC = new TH1D("ejpsi_MC", ";E [GeV]", 100, 0.0, 320.0);
        
        TH1D* h4_eta_MC = new TH1D("h4_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h4_px_MC = new TH1D("px4_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h4_py_MC = new TH1D("py4_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h4_pt_MC = new TH1D("pt4_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h4_pz_MC = new TH1D("pz4_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h4_e_MC = new TH1D("e4_MC", ";E [GeV]", 100, 0.0, 320.0);
        
        TH1D* h3_eta_MC = new TH1D("h3_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h3_px_MC = new TH1D("px3_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h3_py_MC = new TH1D("py3_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h3_pt_MC = new TH1D("pt3_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h3_pz_MC = new TH1D("pz3_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h3_e_MC = new TH1D("e3_MC", ";E [GeV]", 100, 0.0, 320.0);
    
        TH1D* h1_eta_MC = new TH1D("h1_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h1_px_MC = new TH1D("px1_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h1_py_MC = new TH1D("py1_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h1_pt_MC = new TH1D("pt1_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h1_pz_MC = new TH1D("pz1_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h1_e_MC = new TH1D("e1_MC", ";E [GeV]", 100, 0.0, 320.0);
    
        TH1D* h5_eta_MC = new TH1D("h5_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h5_px_MC = new TH1D("px5_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h5_py_MC = new TH1D("py5_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h5_pt_MC = new TH1D("p51_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h5_pz_MC = new TH1D("pz5_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h5_e_MC = new TH1D("e5_MC", ";E [GeV]", 100, 0.0, 320.0);
    
        TH1D* h2_eta_MC = new TH1D("h2_eta",";Pseudorapidity, #eta",100,-15,15.0);
        TH1D* h2_px_MC = new TH1D("px2_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h2_py_MC = new TH1D("py2_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h2_pt_MC = new TH1D("pt2_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h2_e_MC = new TH1D("e2_MC", ";E [GeV]", 1000, 0, 320.0);
        
        //Roman pots
        TH1D* h_px_RomanPots = new TH1D("px_RomanPots", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_py_RomanPots = new TH1D("py_RomanPots", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_pt_RomanPots = new TH1D("pt_RomanPots", ";p_{t} [GeV/c]", 100, -1, 2.0);
        TH1D* h_pz_RomanPots = new TH1D("pz_RomanPots", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h_e_RomanPots = new TH1D("e_RomanPots", ";E [GeV]", 100, 0.0, 320.0);
        TH2D* h_rp_occupancy_map = new TH2D("Roman_pots_occupancy_map", "hit y [mm];hit x [mm]", 100, -150, 150, 100, -70, 70);
        
        //OMD
        TH1D* h_px_OMD = new TH1D("px_OMD", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_py_OMD = new TH1D("py_OMD", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_pt_OMD = new TH1D("pt_OMD", ";p_{t} [GeV/c]", 100, -1, 2.0);
        TH1D* h_pz_OMD = new TH1D("pz_OMD", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h_e_OMD = new TH1D("e_OMD", ";E [GeV]", 100, 0.0, 320.0);
        TH2D* h_omd_occupancy_map = new TH2D("OMD_occupancy_map", "hit y [mm];hit x [mm]", 100, -150, 150, 100, -70, 70);
        
        
        //B0 tracker hits
        TH2D* h_B0_occupancy_map_layer_0 = new TH2D("B0_occupancy_map_0", "B0_occupancy_map_0", 100, -400, 0, 100, -170, 170);
        TH2D* h_B0_occupancy_map_layer_1 = new TH2D("B0_occupancy_map_1", "B0_occupancy_map_1", 100, -400, 0, 100, -170, 170);
        TH2D* h_B0_occupancy_map_layer_2 = new TH2D("B0_occupancy_map_2", "B0_occupancy_map_2", 100, -400, 0, 100, -170, 170);
        TH2D* h_B0_occupancy_map_layer_3 = new TH2D("B0_occupancy_map_3", "B0_occupancy_map_3", 100, -400, 0, 100, -170, 170);
        TH1D* h_B0_hit_energy_deposit = new TH1D("B0_tracker_hit_energy_deposit", ";Deposited Energy [keV]", 100, 0.0, 500.0);
        
        //B0 EMCAL clusters
        TH2D* h_B0_emcal_occupancy_map = new TH2D("B0_emcal_occupancy_map", "B0_emcal_occupancy_map", 100, -400, 0, 100, -170, 170);
        TH1D* h_B0_emcal_cluster_energy = new TH1D("B0_emcal_cluster_energy", ";Cluster Energy [GeV]", 100, 0.0, 100.0);
        
        //Reconstructed tracks (for usage with B0 too!!)
        TH1D* h_px_reco_track = new TH1D("px_reco_track", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_py_reco_track = new TH1D("py_reco_track", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_pt_reco_track = new TH1D("pt_reco_track", ";p_{t} [GeV/c]", 100, -1, 4);
        TH1D* h_pz_reco_track = new TH1D("pz_reco_track", ";p_{z} [GeV/c]", 100, 0.0, 320);
        TH1D* h_e_reco_track = new TH1D("e_reco_track", ";E [GeV]", 100, 0.0, 320);
        
        //ZDC EMCAL clusters
        TH2D* h_ZDC_emcal_occupancy_map = new TH2D("ZDC_emcal_occupancy_map", "ZDC_emcal_occupancy_map", 100, -1150, -1050, 100, -60, 60);
        TH1D* h_ZDC_emcal_cluster_energy = new TH1D("ZDC_emcal_cluster_energy", ";Cluster Energy [GeV]", 100, 0.0, 100.0);
    
        incbeame.SetXYZM(0,0,-17.999999992746666,.00051099904266560590);
        incbeam.SetXYZM(0,0, 274.99839935073504,0.93827210000933003);
    
        
        int fileCounter = 0;
        int iEvent = 0;
        int iflagproton;
        int flag1 = 0;
        int flag2 = 0;
        int flag3 = 0;
        int ic = 2;//for the MC scattered electron
        
        double t1;
        double t3;
        double thetaMC;
        double thetaChPct;
        double q2;
        double q2_1;
        double scatElecEnergMC;
        double scatElecEnergChPct;
        double ixb;
        double ixv;
        double ixb1;
        double ixv1;
    
        while(getline(fileListStream, fileName)){
            
            TString tmp = fileName;
            
            cout << "Input file " << fileCounter << ": " << fileName << endl;
            
            inputRootFile = new TFile(tmp);
            if(!inputRootFile){ cout << "MISSING_ROOT_FILE"<< fileName << endl; continue;}
            
            fileCounter++;
            
            TTree * evtTree = (TTree*)inputRootFile->Get("events");
            
            int numEvents = evtTree->GetEntries();
            
            TTreeReader tree_reader(evtTree);       // !the tree reader
            
            //MC particles
            
            TTreeReaderArray<float> mc_px_array = {tree_reader, "MCParticles.momentum.x"};
            TTreeReaderArray<float> mc_py_array = {tree_reader, "MCParticles.momentum.y"};
            TTreeReaderArray<float> mc_pz_array = {tree_reader, "MCParticles.momentum.z"};
            TTreeReaderArray<double> mc_mass_array = {tree_reader, "MCParticles.mass"};
            TTreeReaderArray<int> mc_pdg_array = {tree_reader, "MCParticles.PDG"};
            
            //Roman pots -- momentum vector
            TTreeReaderArray<float> reco_RP_px = {tree_reader, "ForwardRomanPotRecParticles.momentum.x"};
            TTreeReaderArray<float> reco_RP_py = {tree_reader, "ForwardRomanPotRecParticles.momentum.y"};
            TTreeReaderArray<float> reco_RP_pz = {tree_reader, "ForwardRomanPotRecParticles.momentum.z"};
            TTreeReaderArray<int> reco_RP_pdg = {tree_reader, "ForwardRomanPotRecParticles.PDG"};
            TTreeReaderArray<float> reco_RP_m = {tree_reader, "ForwardRomanPotRecParticles.mass"};
            TTreeReaderArray<float> reco_RP_e = {tree_reader, "ForwardRomanPotRecParticles.energy"};
            
            //Off-Momentum -- momentum vector
            TTreeReaderArray<float> reco_OMD_px = {tree_reader, "ForwardOffMRecParticles.momentum.x"};
            TTreeReaderArray<float> reco_OMD_py = {tree_reader, "ForwardOffMRecParticles.momentum.y"};
            TTreeReaderArray<float> reco_OMD_pz = {tree_reader, "ForwardOffMRecParticles.momentum.z"};
            TTreeReaderArray<int> reco_OMD_pdg = {tree_reader, "ForwardOffMRecParticles.PDG"};
            TTreeReaderArray<float> reco_OMD_m = {tree_reader, "ForwardOffMRecParticles.mass"};
            TTreeReaderArray<float> reco_OMD_e = {tree_reader, "ForwardOffMRecParticles.energy"};
            
            //hit locations (for debugging)
            TTreeReaderArray<float> global_hit_RP_x = {tree_reader, "ForwardRomanPotRecParticles.referencePoint.x"};
            TTreeReaderArray<float> global_hit_RP_y = {tree_reader, "ForwardRomanPotRecParticles.referencePoint.y"};
            TTreeReaderArray<float> global_hit_RP_z = {tree_reader, "ForwardRomanPotRecParticles.referencePoint.z"};
            
            //hit locations (for debugging)
            TTreeReaderArray<float> global_hit_OMD_x = {tree_reader, "ForwardOffMRecParticles.referencePoint.x"};
            TTreeReaderArray<float> global_hit_OMD_y = {tree_reader, "ForwardOffMRecParticles.referencePoint.y"};
            TTreeReaderArray<float> global_hit_OMD_z = {tree_reader, "ForwardOffMRecParticles.referencePoint.z"};
            
            //b0 tracker hits
            TTreeReaderArray<float> b0_hits_x = {tree_reader, "B0TrackerRecHits.position.x"};
            TTreeReaderArray<float> b0_hits_y = {tree_reader, "B0TrackerRecHits.position.y"};
            TTreeReaderArray<float> b0_hits_z = {tree_reader, "B0TrackerRecHits.position.z"};
            TTreeReaderArray<float> b0_hits_eDep = {tree_reader, "B0TrackerRecHits.edep"}; //deposited energy per hit
            
            //b0 EMCAL
            TTreeReaderArray<float> b0_cluster_x = {tree_reader, "B0ECalClusters.position.x"};
            TTreeReaderArray<float> b0_cluster_y = {tree_reader, "B0ECalClusters.position.y"};
            TTreeReaderArray<float> b0_cluster_z = {tree_reader, "B0ECalClusters.position.z"};
            TTreeReaderArray<float>  b0_cluster_energy = {tree_reader, "B0ECalClusters.energy"}; //deposited energy in cluster
            
            //reco tracks (where b0 tracks live!!!)
            TTreeReaderArray<float> reco_track_x = {tree_reader, "ReconstructedChargedParticles.momentum.x"};
            TTreeReaderArray<float> reco_track_y = {tree_reader, "ReconstructedChargedParticles.momentum.y"};
            TTreeReaderArray<float> reco_track_z = {tree_reader, "ReconstructedChargedParticles.momentum.z"};
            TTreeReaderArray<float> reco_track_e = {tree_reader, "ReconstructedChargedParticles.energy"};
            //TTreeReaderArray<float> reco_track_type = {tree_reader, "ReconstructedChargedParticles.type"};
            
            TTreeReaderArray<int> reco_track_pdg = {tree_reader, "ReconstructedChargedParticles.PDG"};
            TTreeReaderArray<float> reco_track_m = {tree_reader, "ReconstructedChargedParticles.mass"};
            TTreeReaderArray<float> reco_track_c = {tree_reader, "ReconstructedChargedParticles.charge"};
            
            TTreeReaderArray<float> recop_p_x = {tree_reader, "ReconstructedParticles.momentum.x"};
            TTreeReaderArray<float> recop_p_y = {tree_reader, "ReconstructedParticles.momentum.y"};
            TTreeReaderArray<float> recop_p_z = {tree_reader, "ReconstructedParticles.momentum.z"};
            TTreeReaderArray<float> recop_p_m = {tree_reader, "ReconstructedParticles.mass"};
            TTreeReaderArray<int> recop_p_pdg = {tree_reader, "ReconstructedParticles.PDG"};
            
            /*TTreeReaderArray<int> recop_pdg = {tree_reader, "ReconstructedChargedParticles.PDG"};
            TTreeReaderArray<float> recop_px = {tree_reader, "ReconstructedChargedParticles.momentum.x"};
            TTreeReaderArray<float> recop_py = {tree_reader, "ReconstructedChargedParticles.momentum.y"};
            TTreeReaderArray<float> recop_pz = {tree_reader, "ReconstructedChargedParticles.momentum.z"};
            TTreeReaderArray<float> recop_m = {tree_reader, "ReconstructedChargedParticles.mass"};*/
            
            
            //ZDC EMCAL
            /*TTreeReaderArray<float> zdc_ecal_cluster_x = {tree_reader, "ZDCEcalClusters.position.x"};
             TTreeReaderArray<float> zdc_ecal_cluster_y = {tree_reader, "ZDCEcalClusters.position.y"};
             TTreeReaderArray<float> zdc_ecal_cluster_z = {tree_reader, "ZDCEcalClusters.position.z"};
             TTreeReaderArray<float>  zdc_ecal_cluster_energy = {tree_reader, "ZDCEcalClusters.energy"}; //deposited energy in cluster*/
            
            
            cout << "file has " << evtTree->GetEntries() <<  " events..." << endl;
            
            tree_reader.SetEntriesRange(0, evtTree->GetEntries());// allow computer to get the number of events
            //tree_reader.SetEntriesRange(0, 10); //imposed specific number of events
            
            while (tree_reader.Next()) {
                
                 /*cout <<"  "<< endl;
                 cout << "Reading event: " << iEvent << endl;
                 cout <<"_____________________________"<< endl;*/
                
                //MCParticles
                //finding the far-forward proton;
                //TLorentzVector scatMC(0,0,0,0);
                TVector3 rptrk;
                TVector3 rcpv6;
                
                TLorentzVector mctrk;
                TLorentzVector mctrk4q2;
                
                double maxPt=-99.;
                iflagproton = 0;
                
                //start of prequesite conditions restricting q2 between 1 and 10
                mctrk4q2.SetXYZM(mc_px_array[ic], mc_py_array[ic],mc_pz_array[ic],mc_mass_array[ic]);
                        
                h2_eta_MC->Fill(mctrk4q2.Eta());//plotted later
                h2_e_MC->Fill(mctrk4q2.E());//plotted later
                        
                scatElecEnergMC = mctrk4q2.E();
                thetaMC = mctrk4q2.Theta();
                thetaMC = thetaMC - TMath::Pi();
                        
                q2 = 4 * incbeame.E() * scatElecEnergMC * TMath::Sin(thetaMC/2.0) * TMath::Sin(thetaMC/2.0);
                
                if (q2 >= 1 && q2 <= 10 ){
                    mtq->Fill(q2);
                    
                    //for the final proton
                    vec1.SetXYZM(mc_px_array[6], mc_py_array[6], mc_pz_array[6],mc_mass_array[6]);
                    vec1.RotateY(0.025);
                    fProton->Fill(vec1.Eta());
                    h6_eta_MC->Fill(vec1.Eta());
                    h6_px_MC->Fill(vec1.Px());
                    h6_py_MC->Fill(vec1.Py());
                    h6_pt_MC->Fill(vec1.Pt());
                    h6_pz_MC->Fill(vec1.Pz());
                    h6_e_MC->Fill(vec1.E());
                    
                    // for the jpsi positron
                    vec2.SetXYZM(mc_px_array[7], mc_py_array[7], mc_pz_array[7],mc_mass_array[7]);
                    fPositron->Fill(vec2.Eta());
                    h7_eta_MC->Fill(vec2.Eta());
                    h7_px_MC->Fill(vec2.Px());
                    h7_py_MC->Fill(vec2.Py());
                    h7_pt_MC->Fill(vec2.Pt());
                    h7_pz_MC->Fill(vec2.Pz());
                    h7_e_MC->Fill(vec2.E());
                    
                    //for the jpsi electron
                    vecjpsi.SetXYZM(mc_px_array[8], mc_py_array[8], mc_pz_array[8],mc_mass_array[8]);
                    jpsiElectron->Fill(vecjpsi.Eta());
                    hjpsi_eta_MC->Fill(vecjpsi.Eta());
                    hjpsi_px_MC->Fill(vecjpsi.Px());
                    hjpsi_py_MC->Fill(vecjpsi.Py());
                    hjpsi_pt_MC->Fill(vecjpsi.Pt());
                    hjpsi_pz_MC->Fill(vecjpsi.Pz());
                    hjpsi_e_MC->Fill(vecjpsi.E());
                    
                    //for the scattered/ final electron
                    vec3.SetXYZM(mc_px_array[2], mc_py_array[2], mc_pz_array[2],mc_mass_array[2]);
                    fElectron->Fill(vec3.Eta());
                    h8_eta_MC->Fill(vec3.Eta());
                    h8_px_MC->Fill(vec3.Px());
                    h8_py_MC->Fill(vec3.Py());
                    h8_pt_MC->Fill(vec3.Pt());
                    h8_pz_MC->Fill(vec3.Pz());
                    h8_e_MC->Fill(vec3.E());
                    
                    //for the proton at position 4
                    vec7.SetXYZM(mc_px_array[4], mc_py_array[4], mc_pz_array[4],mc_mass_array[4]);
                    vec7.RotateY(0.025);
                    h4_eta_MC->Fill(vec7.Eta());
                    h4_px_MC->Fill(vec7.Px());
                    h4_py_MC->Fill(vec7.Py());
                    h4_pt_MC->Fill(vec7.Pt());
                    h4_pz_MC->Fill(vec7.Pz());
                    h4_e_MC->Fill(vec7.E());
                    
                    //for the incoming proton
                    //iproton.SetXYZM(mc_px_array[3], mc_py_array[3], mc_pz_array[3],mc_mass_array[3]);
                    //pT cut at 200MeV
                    //if (iproton.Pt() >= 0.2){
                      //  jproton = iproton;
                    //}
                    h3_eta_MC->Fill(iproton.Eta());
                    h3_px_MC->Fill(iproton.Px());
                    h3_py_MC->Fill(iproton.Py());
                    h3_pt_MC->Fill(iproton.Pt());
                    h3_pz_MC->Fill(iproton.Pz());
                    h3_e_MC->Fill(iproton.E());
                    
                    //for mediating photon
                    iphoton.SetXYZM(mc_px_array[1], mc_py_array[1], mc_pz_array[1],mc_mass_array[1]);
                    h1_px_MC->Fill(iphoton.Px());
                    h1_py_MC->Fill(iphoton.Py());
                    h1_pt_MC->Fill(iphoton.Pt());
                    h1_pz_MC->Fill(iphoton.Pz());
                    h1_e_MC->Fill(iphoton.E());
                    
                    //for the jpsi pdg = 443
                    ijpsi.SetXYZM(mc_px_array[5], mc_py_array[5], mc_pz_array[5],mc_mass_array[5]);
                    h5_eta_MC->Fill(ijpsi.Eta());
                    h5_px_MC->Fill(ijpsi.Px());
                    h5_py_MC->Fill(ijpsi.Py());
                    h5_pt_MC->Fill(ijpsi.Pt());
                    h5_pz_MC->Fill(ijpsi.Pz());
                    h5_e_MC->Fill(ijpsi.E());
                    
                    //cout <<"Electron: " << vec3.E() << "; Proton: " << vec1.E() << "; J/Psi: " << ijpsi.E() << endl;
                    
                    TLorentzVector diff3 = incbeam - vec1;
                    t3 = -1*diff3.Dot(diff3);//for MC
                    mtgg->Fill(t3);
                    ixb = q2/(2.0 * incbeam.Dot(iphoton));//mc
                    xb->Fill(ixb);
                    ixv = (q2 + ijpsi.M()*ijpsi.M())/(2.0 * incbeam.Dot(iphoton));
                    xv->Fill(ixv);
                    
                    JPsi1 = vec2 + vecjpsi;
                    JPsiMass1->Fill(JPsi1.M());
                    
                    mcjpsie_pt_vs_eta->Fill(vecjpsi.Eta(), vecjpsi.Pt());
                    mcjpsie_pz_vs_eta->Fill(vecjpsi.Eta(), vecjpsi.Pz());
                    
                    mcsce_pt_vs_eta->Fill(vec3.Eta(), vec3.Pt());
                    mcsce_pz_vs_eta->Fill(vec3.Eta(), vec3.Pz());
                    
                    mcjpsie_e_vs_eta->Fill(vecjpsi.Eta(), vecjpsi.E());
                    mcsce_e_vs_eta->Fill(vec3.Eta(), vec3.E());
                    
                    mcjpsie_e_vs_pz->Fill(vecjpsi.Pz(), vecjpsi.E());
                    mcjpsipos_e_vs_pz->Fill(vec2.Pz(), vec2.E());
                    mcsce_e_vs_pz->Fill(vec3.Pz(), vec3.E());
                    
                    //applying a cut 20<E-Pz<40 GeV
                    if (((vecjpsi + vec2 + vec3).E() - (vecjpsi + vec2 + vec3).Pz()) > 20 && ((vecjpsi + vec2 + vec3).E() - (vecjpsi + vec2 + vec3).Pz()) < 40){
                        mcjpsie_e_minus_pz->Fill((vecjpsi + vec2 + vec3).E() - (vecjpsi + vec2 + vec3).Pz());
                    }
                    
                    mcjpsie_theta_vs_phi->Fill(vecjpsi.Theta(), vecjpsi.Phi());
                    mcjpsipos_theta_vs_phi->Fill(vec2.Theta(), vec2.Phi());
                    mcsce_theta_vs_phi->Fill(vec3.Theta(), vec3.Phi());
                    
                    mcjpsie_phi_vs_eta->Fill(vecjpsi.Phi(), vecjpsi.Eta());
                    mcjpsipos_phi_vs_eta->Fill(vec2.Phi(), vec2.Eta());
                    mcsce_phi_vs_eta->Fill(vec3.Phi(), vec3.Eta());
                    
                    mcjpsie_phi_vs_e->Fill(vecjpsi.Phi(), vecjpsi.E());
                    mcjpsipos_phi_vs_e->Fill(vec2.Phi(), vec2.E());
                    mcsce_phi_vs_e->Fill(vec3.Phi(), vec3.E());
                    
                    mcjpsitwoenergy->Fill(2*vecjpsi.E());
                    mcsctwoenergy->Fill(2*vec3.E());
                    
                    /*for (int ic = 0; ic < recop_p_x.GetSize(); ic++){
                        ijpsi.SetXYZM(recop_p_x[ic], recop_p_y[ic], recop_p_z[ic], recop_p_m[ic]);
                        //cout <<"Particle: " << recop_p_pdg[ic] << "; Iteration: " << ic << endl;
                        
                    }*/
                    
                    //roman pots reco tracks
                    for(int iRPPart = 0; iRPPart < reco_RP_px.GetSize(); iRPPart++){
                        //reco jpsi
                        
                        if (reco_RP_pdg[iRPPart] == 2212){
                            jjpsi.SetXYZM(reco_RP_px[iRPPart], reco_RP_py[iRPPart], reco_RP_pz[iRPPart], reco_RP_m[iRPPart]);
                            
                            TLorentzVector prec_romanpots(reco_RP_px[iRPPart], reco_RP_py[iRPPart], reco_RP_pz[iRPPart], reco_RP_e[iRPPart]);
                            
                            //place a pT cut on reconstructeed proton
                            if (prec_romanpots.Pt() >= 0.2 && reco_RP_pdg[iRPPart] == 2212){
                                
                                vec5.SetXYZM(reco_RP_px[iRPPart], reco_RP_py[iRPPart], reco_RP_pz[iRPPart], reco_RP_m[iRPPart]);
                                
                                //if (prec_romanpots.Eta()>4){
                               // if (reco_RP_pdg[iRPPart] == 2212){
                                    RPfProton->Fill(vec5.Eta());
                                    
                                    h_px_RomanPots->Fill(prec_romanpots.Px());
                                    h_py_RomanPots->Fill(prec_romanpots.Py());
                                    h_pt_RomanPots->Fill(prec_romanpots.Perp());
                                    h_pz_RomanPots->Fill(prec_romanpots.Pz());
                                    h_e_RomanPots->Fill(prec_romanpots.E());
                                    
                                    h_rp_occupancy_map->Fill(global_hit_RP_x[iRPPart], global_hit_RP_y[iRPPart]);
                                    iflagproton = 1;
                            }
                            if (iflagproton == 0){
                                break;
                            }
                            //}
                        }
                        
                    }
                    
                    //OMD reco tracks
                    for(int iOMDPart = 0; iOMDPart < reco_OMD_px.GetSize(); iOMDPart++){
                        
                        TLorentzVector prec_omd(reco_OMD_px[iOMDPart], reco_OMD_py[iOMDPart], reco_OMD_pz[iOMDPart], reco_OMD_e[iOMDPart]);
                        
                        //place a pT cut on reconstructeed proton
                        //if (prec_omd.Pt() >= 0.5){
                            
                            vec6.SetXYZM(reco_OMD_px[iOMDPart], reco_OMD_py[iOMDPart], reco_OMD_pz[iOMDPart], reco_OMD_m[iOMDPart]);
                            
                            //if (prec_omd.Eta()>4){
                            if (reco_OMD_pdg[iOMDPart] == 2212){
                                OMDfProton->Fill(vec6.Eta());
                                h_px_OMD->Fill(prec_omd.Px());
                                h_py_OMD->Fill(prec_omd.Py());
                                h_pt_OMD->Fill(prec_omd.Perp());
                                h_pz_OMD->Fill(prec_omd.Pz());
                                h_e_OMD->Fill(prec_omd.E());
                                
                                h_omd_occupancy_map->Fill(global_hit_OMD_x[iOMDPart], global_hit_OMD_y[iOMDPart]);
                            }
                        break;
                        //}
                    }
                    
                    
                    
                    double hit_x = -9999.;
                    double hit_y = -9999.;
                    double hit_z = -9999.;
                    double hit_deposited_energy = -9999.;
                    
                    for(int b0cluster = 0; b0cluster < b0_cluster_x.GetSize(); b0cluster++){
                        
                        hit_x = b0_cluster_x[b0cluster];
                        hit_y = b0_cluster_y[b0cluster];
                        hit_z = b0_cluster_z[b0cluster];
                        hit_deposited_energy = b0_cluster_energy[b0cluster]*1.246; //poor man's calibration constant, for now
                        
                        h_B0_emcal_occupancy_map->Fill(hit_x, hit_y);
                        h_B0_emcal_cluster_energy->Fill(hit_deposited_energy);
                        
                    }
                    
                    
                    //b0 tracker hits -- for debugging or external tracking
                    for(int b0hit = 0; b0hit < b0_hits_x.GetSize(); b0hit++){
                        
                        hit_x = b0_hits_x[b0hit];
                        hit_y = b0_hits_y[b0hit];
                        hit_z = b0_hits_z[b0hit];
                        hit_deposited_energy = b0_hits_eDep[b0hit]*1e6; //convert GeV --> keV
                        
                        h_B0_hit_energy_deposit->Fill(hit_deposited_energy);
                        
                        if(hit_deposited_energy < 10.0){ continue; } //threshold value -- 10 keV, arbitrary, for now
                        
                        //ACLGAD layout
                        if(hit_z > 5700 && hit_z < 5990){ h_B0_occupancy_map_layer_0->Fill(hit_x, hit_y); }
                        if(hit_z > 6100 && hit_z < 6200){ h_B0_occupancy_map_layer_1->Fill(hit_x, hit_y); }
                        if(hit_z > 6400 && hit_z < 6500){ h_B0_occupancy_map_layer_2->Fill(hit_x, hit_y); }
                        if(hit_z > 6700 && hit_z < 6750){ h_B0_occupancy_map_layer_3->Fill(hit_x, hit_y); }
                        
                    }
                    
                    
                    //reconstructed tracks with ACTS -- used for B0
                    for(int iRecoTrk = 0; iRecoTrk < reco_track_x.GetSize(); iRecoTrk++){
                        
                        TLorentzVector prec_reco_tracks(reco_track_x[iRecoTrk], reco_track_y[iRecoTrk], reco_track_z[iRecoTrk], reco_track_e[iRecoTrk]);
                        
                        //place a pT cut on reconstructeed proton
                        //if (prec_reco_tracks.Pt() >= 0.5){
                            
                            prec_reco_tracks.RotateY(0.025); //remove crossing angle for B0!!!
                            
                            vec4.SetXYZM(reco_track_x[iRecoTrk], reco_track_y[iRecoTrk], reco_track_z[iRecoTrk], reco_track_m[iRecoTrk]);
                            
                            
                            if (reco_track_pdg[iRecoTrk] == 2212){
                                //if (prec_reco_tracks.Eta()>4){
                                B0fProton->Fill(vec4.Eta());
                                h_px_reco_track->Fill(prec_reco_tracks.Px());
                                h_py_reco_track->Fill(prec_reco_tracks.Py());
                                h_pt_reco_track->Fill(prec_reco_tracks.Perp());
                                h_pz_reco_track->Fill(prec_reco_tracks.Pz());
                                h_e_reco_track->Fill(prec_reco_tracks.E());
                            }
                        break;
                        //}
                        
                    }
                    
                    /*cout << reco_track_x.GetSize() <<" iRecontrk_x " << endl;//iRecontrk_x
                     cout << reco_track_y.GetSize() <<" iRecontrk_y " << endl;//iRecontrk_y
                     cout << reco_track_z.GetSize() <<" iRecontrk_z " << endl;//iRecontrk_z*/
                    
                    /*for(int iZdcEMCALcluster = 0; iZdcEMCALcluster < zdc_ecal_cluster_x.GetSize(); iZdcEMCALcluster++){
                     
                     hit_x = zdc_ecal_cluster_x[iZdcEMCALcluster];
                     hit_y = zdc_ecal_cluster_y[iZdcEMCALcluster];
                     hit_z = zdc_ecal_cluster_z[iZdcEMCALcluster];
                     
                     hit_deposited_energy = zdc_ecal_cluster_energy[iZdcEMCALcluster]*1.246; //poor man's calibration constant, for now
                     
                     h_ZDC_emcal_occupancy_map->Fill(hit_x, hit_y);
                     h_ZDC_emcal_cluster_energy->Fill(hit_deposited_energy);
                     
                     }*/
                    
                    iEvent++;
                    
                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                    
                    for(int rcp=0;rcp<reco_track_x.GetSize();rcp++){
                        /*if (reco_track_x.GetSize() > 2){
                         cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << recop_pdg[rcp] << endl;}*/
                        
                        //mctrk.SetXYZ(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc]);//previous
                        //if(reco_track_x.GetSize()>4){
                        //cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << reco_track_pdg[rcp] << endl;
                        
                        if(reco_track_x.GetSize() == 3){
                            
                            if(reco_track_pdg[0] != reco_track_pdg[1] && reco_track_pdg[0] != reco_track_pdg[2] && reco_track_pdg[1] != reco_track_pdg[2]){
                                
                                if(reco_track_pdg[0] == 11 && (reco_track_pdg[1] == -11 || reco_track_pdg[2] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[1] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[2] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[2] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[1] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[0] == -11 && (reco_track_pdg[1] == 11 || reco_track_pdg[2] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                   
                                    flag2++;
                                }
                                if(reco_track_pdg[1] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[2] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                   
                                    flag2++;
                                }
                                if(reco_track_pdg[2] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[1] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                    
                                    flag2++;
                                }
                                
                            }
                            if ((reco_track_pdg[0] == 11 && reco_track_pdg[1] == 11) ||(reco_track_pdg[0] == 11 && reco_track_pdg[2] == 11) || (reco_track_pdg[1] == 11 && reco_track_pdg[2] == 11)){
                                //cout << " re1: " << reco_track_pdg[0] << " re2: " << reco_track_pdg[1] << " re3: " << reco_track_pdg[2] << endl;
                                if(reco_track_pdg[0] == 11 && reco_track_pdg[1] == 11){
                                    int icheck = 0;
                                    int jcheck = 1;
                                    if(reco_track_pdg[2] == -11){
                                        eq1.SetXYZM(reco_track_x[icheck], reco_track_y[icheck], reco_track_z[icheck],reco_track_m[icheck]);
                                        
                                        rcpv1.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv11.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv2.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                        rcpv22.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                        
                                    }
                                    flag3++;
                                    
                                }
                                if(reco_track_pdg[0] == 11 && reco_track_pdg[2] == 11){
                                    int icheck = 0;
                                    int jcheck = 2;
                                    if(reco_track_pdg[1] == -11){
                                        eq1.SetXYZM(reco_track_x[icheck], reco_track_y[icheck], reco_track_z[icheck],reco_track_m[icheck]);
                                        
                                        rcpv1.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv11.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv2.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                        rcpv22.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                        
                                    }
                                    flag3++;
                                }
                                if(reco_track_pdg[1] == 11 && reco_track_pdg[2] == 11){
                                    int icheck = 1;
                                    int jcheck = 2;
                                    if(reco_track_pdg[0] == -11){
                                        eq1.SetXYZM(reco_track_x[icheck], reco_track_y[icheck], reco_track_z[icheck],reco_track_m[icheck]);
                                        
                                        rcpv1.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv11.SetXYZM(reco_track_x[jcheck], reco_track_y[jcheck], reco_track_z[jcheck],reco_track_m[jcheck]);
                                        rcpv2.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                        rcpv22.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                        
                                    }
                                    flag3++;
                                }
                                
                                
                            }
                            
                        }
                        
                    }
                    
                    scatElecEnergChPct = eq1.E();
                    thetaChPct = eq1.Theta();
                    thetaChPct = thetaChPct - TMath::Pi();
                    q2_1 = 4 * incbeame.E() * scatElecEnergChPct * TMath::Sin(thetaChPct/2.0) * TMath::Sin(thetaChPct/2.0);
                    if (iflagproton == 1){
                        mtqq->Fill(q2_1);
                    }
                    
                    if(flag3 == 0){
                        JPsi22 = rcpv11 + rcpv22;
                        //rcJPsiMass11->Fill(JPsi22.M());
                        
                        JPsi222 = eq1 + rcpv22;
                        //rcJPsiMass111->Fill(JPsi222.M());
                        
                        if ((JPsi22.M() > 2 && JPsi22.M() < 3.6) && (JPsi222.M() > 2 && JPsi222.M() < 3.6)){
                            rcJPsiMass11->Fill(JPsi22.M());
                            scte=eq1;
                        }
                        if ((JPsi222.M() > 2 && JPsi222.M() < 3.6) && (JPsi22.M() > 2 && JPsi22.M() < 3.6)){
                            rcJPsiMass111->Fill(JPsi222.M());
                            scte=rcpv11;
                        }
                        //}
                        
                        JPsi2 = rcpv1 + rcpv2;
                        rcJPsiMass1->Fill(JPsi2.M());
                        diffjpsimass->Fill(JPsi1.M() - JPsi2.M());
                    }
                    
                    TLorentzVector diff1 = incbeam - vec5;
                    t1 = -1*diff1.Dot(diff1);//for RP
                    ixb1 = q2_1/(2.0 * incbeam.Dot(iphoton));//recon
                    ixv1 = (q2_1 + ijpsi.M()*ijpsi.M())/(2.0 * incbeam.Dot(iphoton));
                    
                    if (iflagproton == 1){
                        mtg->Fill(t1);
                        xb1->Fill(ixb1);
                        xv1->Fill(ixv1);
                        
                        difft->Fill(t3 - t1);
                        diffq2->Fill(q2 - q2_1);
                        diffx_v->Fill(ixv - ixv1);
                    }
                    if (flag2 == 0 && flag3 == 0){
                        rcElectron->Fill(eq1.Eta());
                        rcPositron->Fill(rcpv2.Eta());
                        rcPositronpt->Fill(rcpv2.Pt());
                        rcElectronpt->Fill(eq1.Pt());
                        rcElectronjpsieta->Fill(rcpv1.Eta());
                        rcElectronjpsipt->Fill(rcpv1.Pt());
                        rcjpsie_pt_vs_eta->Fill(rcpv1.Eta(), rcpv1.Pt());
                        rcjpsie_pz_vs_eta->Fill(rcpv1.Eta(), rcpv1.Pz());
                        rcsce_pt_vs_eta->Fill(eq1.Eta(), eq1.Pt());
                        rcsce_pz_vs_eta->Fill(eq1.Eta(), eq1.Pz());
                        
                        rcjpsie_e_vs_eta->Fill(rcpv1.Eta(), rcpv1.E());
                        rcsce_e_vs_eta->Fill(eq1.Eta(), eq1.E());
                        
                        rcjpsie_e_vs_pz->Fill(rcpv1.Pz(), rcpv1.E());
                        rcjpsipos_e_vs_pz->Fill(rcpv2.Pz(), rcpv2.E());
                        rcsce_e_vs_pz->Fill(eq1.Pz(), eq1.E());
                        
                        //applying a cut 20<E-pz<40 GeV
                        if (((rcpv1 + rcpv2 + eq1).E() - (rcpv1 + rcpv2 + eq1).Pz()) > 20 && ((rcpv1 + rcpv2 + eq1).E() - (rcpv1 + rcpv2 + eq1).Pz()) < 40){
                            
                            rcjpsie_e_minus_pz->Fill((rcpv1 + rcpv2 + eq1).E() - (rcpv1 + rcpv2 + eq1).Pz());
                        }
                        
                        rcjpsie_theta_vs_phi->Fill(rcpv1.Theta(), rcpv1.Phi());
                        rcjpsipos_theta_vs_phi->Fill(rcpv2.Theta(), rcpv2.Phi());
                        rcsce_theta_vs_phi->Fill(eq1.Theta(), eq1.Phi());
                        
                        rcjpsie_phi_vs_eta->Fill(rcpv1.Phi(), rcpv1.Eta());
                        rcjpsipos_phi_vs_eta->Fill(rcpv2.Phi(), rcpv2.Eta());
                        rcsce_phi_vs_eta->Fill(eq1.Phi(), eq1.Eta());
                        
                        rcjpsie_phi_vs_e->Fill(rcpv1.Phi(), rcpv1.E());
                        rcjpsipos_phi_vs_e->Fill(rcpv2.Phi(), rcpv2.E());
                        rcsce_phi_vs_e->Fill(eq1.Phi(), eq1.E());
                        
                        //cout <<"Electron: " << eq1.E() << "; Proton: " << vec4.E() << "; e+ep: " << (rcpv1+rcpv2).E() <<endl;
                        
                        rcjpsitwoenergy->Fill(2*rcpv1.E());
                        rcsctwoenergy->Fill(2*eq1.E());
                        
                    }
                    
                }// Q2 if
            }// event loop
                
            
            
            inputRootFile->Close();
            
        }// input file loop
    
        
        cout << "Check integrals: " << endl;
        cout << "pt6_mc integral = " << h6_pt_MC->Integral() << endl;
        cout << "pt4_mc integral = " << h4_pt_MC->Integral() << endl;
        cout << "pt3_mc integral = " << h3_pt_MC->Integral() << endl;
        cout << "pt_RP_reco integral = " << h_pt_RomanPots->Integral() << endl;
        
        TFile * outputFile = new TFile(outputFileName, "RECREATE");
        
        h6_px_MC->Write();
        h6_py_MC->Write();
        h6_pt_MC->Write();
        h6_pz_MC->Write();
        h6_e_MC->Write();
    
        h8_pt_MC->Write();
        rcElectronpt->Write();
        rcElectron->Write();
        
        fProton->Write();
        fPositron->Write();
        fElectron->Write();
        
        JPsiMass1->Write();
    
        rcJPsiMass1->Write();
        
        h4_px_MC->Write();
        h4_py_MC->Write();
        h4_pt_MC->Write();
        h4_pz_MC->Write();
        h4_e_MC->Write();
        
        h3_px_MC->Write();
        h3_py_MC->Write();
        h3_pt_MC->Write();
        h3_pz_MC->Write();
        h3_e_MC->Write();
        
        h_px_RomanPots->Write();
        h_py_RomanPots->Write();
        h_pt_RomanPots->Write();
        h_pz_RomanPots->Write();
        h_e_RomanPots->Write();
        RPfProton->Write();
        h_rp_occupancy_map->Write();
        
        h_px_OMD->Write();
        h_py_OMD->Write();
        h_pt_OMD->Write();
        h_pz_OMD->Write();
        h_e_OMD->Write();
        OMDfProton->Write();
        h_omd_occupancy_map->Write();
        
        h_B0_occupancy_map_layer_0->Write();
        h_B0_occupancy_map_layer_1->Write();
        h_B0_occupancy_map_layer_2->Write();
        h_B0_occupancy_map_layer_3->Write();
        h_B0_hit_energy_deposit->Write();
        
        h_B0_emcal_occupancy_map->Write();
        h_B0_emcal_cluster_energy->Write();
        
        h_px_reco_track->Write();
        h_py_reco_track->Write();
        h_pt_reco_track->Write();
        h_pz_reco_track->Write();
        h_e_reco_track->Write();
        B0fProton->Write();
        
        h_ZDC_emcal_occupancy_map->Write();
        h_ZDC_emcal_cluster_energy->Write();
        
        outputFile->Close();

    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    fProton->GetXaxis()->SetTitle("#eta");
    fProton->GetXaxis()->SetRangeUser(-10,20);
    fProton->SetStats(0);
    fProton->GetYaxis()->SetTitleSize(0.03);
    //fProton->GetYaxis()->SetTitle("Final Proton");
    fProton->SetLineColor(1);//red
    fProton->SetLineWidth(6);
    fProton->Draw();
    
    RPfProton->SetLineColor(2);//black plot
    RPfProton->SetLineWidth(6);
    RPfProton->Draw("SAME");
    
    OMDfProton->SetLineColor(3);//green plot
    OMDfProton->SetLineWidth(6);
    OMDfProton->Draw("SAME");
    
    B0fProton->SetLineColor(4);//blue plot
    B0fProton->SetLineWidth(6);
    B0fProton->Draw("SAME");
    
    TLegend *leg = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg->AddEntry(fProton,"MC", "l");
    leg->AddEntry(RPfProton, "RP", "l");
    leg->AddEntry(OMDfProton, "OMD", "l");
    leg->AddEntry(B0fProton, "B0", "l");
    leg->Draw();
    
    TCanvas *c2 = new TCanvas("c2","c2",800,800);
    fProton->GetXaxis()->SetTitle("#eta");
    fProton->GetXaxis()->SetRangeUser(-10,20);
    fProton->SetStats(0);
    fProton->GetYaxis()->SetTitleSize(0.03);
    //fProton->GetYaxis()->SetTitle("Final Proton");
    fProton->SetLineColor(1);//red plot
    fProton->SetLineWidth(6);
    fProton->Draw();
    
    RPfProton->SetLineColor(2);//black plot
    RPfProton->SetLineWidth(6);
    RPfProton->Draw("SAME");
    
    TLegend *leg1 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg1->AddEntry(fProton,"MC", "l");
    leg1->AddEntry(RPfProton, "RP", "l");
    leg1->Draw();
    
    TCanvas *c3 = new TCanvas("c3","c3",800,800);
    rcElectron->GetXaxis()->SetTitle("#eta");
    rcElectron->GetXaxis()->SetRangeUser(-4,4);
    rcElectron->SetStats(0);
    rcElectron->GetYaxis()->SetTitleSize(0.03);
    rcElectron->SetLineColor(1);//red plot
    rcElectron->SetLineWidth(6);
    rcElectron->Draw();
    
    TCanvas *fEle = new TCanvas("fEle","fEle",800,800);
    fElectron->GetXaxis()->SetTitle("#eta");
    fElectron->GetXaxis()->SetRangeUser(-4.5,1);
    fElectron->SetStats(0);
    fElectron->GetYaxis()->SetTitleSize(0.03);
    fElectron->SetLineColor(1);//red plot
    fElectron->SetLineWidth(6);
    fElectron->Draw();
    
    rcElectron->SetLineColor(2);//red plot
    rcElectron->SetLineWidth(6);
    rcElectron->Draw("SAME");
    
    TLegend *leg7 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg7->AddEntry(fElectron,"MC e", "l");
    leg7->AddEntry(rcElectron,"Recon e", "l");
    leg7->Draw();
    
    TCanvas *c4 = new TCanvas("c4","c4",1000,800);
    c4->Divide(2,1);
    c4->cd(1);
    rcJPsiMass11->GetXaxis()->SetTitle("Mass [GeV]");
    rcJPsiMass11->GetXaxis()->SetRangeUser(2,3.6);
    rcJPsiMass11->SetStats(0);
    rcJPsiMass11->GetYaxis()->SetTitleSize(0.03);
    rcJPsiMass11->SetLineColor(1);//black plot
    rcJPsiMass11->SetLineWidth(6);
    rcJPsiMass11->Draw();
    
    rcJPsiMass111->SetLineColor(2);//red plot
    rcJPsiMass111->SetLineWidth(6);
    rcJPsiMass111->Draw("SAME");
    
    TLegend *leg22 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg22->AddEntry(rcJPsiMass11,"ee^{+}", "l");
    leg22->AddEntry(rcJPsiMass111,"e'e^{+}", "l");
    leg22->Draw();
    
    c4->cd(2);
    rcJPsiMass1->GetXaxis()->SetTitle("Mass e^{-}e^{+} [GeV]");
    rcJPsiMass1->GetXaxis()->SetRangeUser(2,4);
    rcJPsiMass1->SetStats(0);
    rcJPsiMass1->GetYaxis()->SetTitleSize(0.03);
    rcJPsiMass1->SetLineColor(2);//red plot
    rcJPsiMass1->SetLineWidth(6);
    rcJPsiMass1->Draw();
    
    TCanvas *jps = new TCanvas("jps","jps",800,800);
    JPsiMass1->GetXaxis()->SetTitle("Mass e^{-}e^{+} [GeV]");
    JPsiMass1->GetXaxis()->SetRangeUser(2,3.6);
    JPsiMass1->SetStats(0);
    JPsiMass1->SetLineColor(1);
    JPsiMass1->SetLineWidth(6);
    JPsiMass1->Draw();
    
    rcJPsiMass1->SetLineColor(2);//red plot
    rcJPsiMass1->SetLineWidth(6);
    rcJPsiMass1->Draw("SAME");
    
    TLegend *jpsi_MCReco = new TLegend(0.6, 0.8, 0.9, 0.9);
    jpsi_MCReco->AddEntry(JPsiMass1, "MC", "l");
    jpsi_MCReco->AddEntry(rcJPsiMass1,"Full Reconstruction", "l");
    jpsi_MCReco->Draw();
    
    TCanvas *c5 = new TCanvas("c5","c5",800,800);
    mtg->GetXaxis()->SetTitle("-t");
    mtg->GetXaxis()->SetRangeUser(0,2);
    mtg->SetStats(0);
    mtg->GetYaxis()->SetTitleSize(0.03);
    mtg->GetYaxis()->SetRangeUser(0,3000);
    mtg->SetLineColor(2);//red plot
    mtg->SetLineWidth(6);
    mtg->SetMarkerStyle(8);
    mtg->SetMarkerColor(2);
    mtg->Draw();

    mtgg->SetMarkerStyle(8);
    mtgg->SetMarkerColor(1);
    mtgg->SetLineColor(1);
    mtgg->SetLineWidth(6);
    mtgg->Draw("SAME");
    
    TRatioPlot* rp4 = new TRatioPlot(mtg, mtgg);
    rp4->Draw();
    rp4->GetLowerRefYaxis()->SetTitle("ratio");
    rp4->GetLowerRefGraph()->SetMinimum(0);
    rp4->GetLowerRefGraph()->SetMaximum(2.5);
    rp4->SetSeparationMargin(0.0);
    rp4->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp4->GetUpperPad()->cd();
    TLegend *leg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    leg2->AddEntry(mtgg, "MC", "p");
    leg2->AddEntry(mtg,"Full Reconstruction", "l");
    //leg2->AddEntry(mta,"Afterburned", "l");
    leg2->Draw();
    
    TCanvas *c8 = new TCanvas("c8","c8",800,800);
    c8->Divide(1,2);
    c8->cd(1);
    ElectfJpsi->SetStats(0);
    ElectfJpsi->GetXaxis()->SetRangeUser(-4,4);
    ElectfJpsi->Draw();
    c8->cd(2);
    PositfJpsi->SetStats(0);
    PositfJpsi->GetXaxis()->SetRangeUser(-4,4);
    PositfJpsi->Draw();
    
    TCanvas *c9 = new TCanvas("c9","c9",800,800);
    h6_e_MC->GetXaxis()->SetTitle("E[GeV]");
    h6_e_MC->GetXaxis()->SetRangeUser(220,290);
    h6_e_MC->SetStats(0);
    h6_e_MC->GetYaxis()->SetTitleSize(0.03);
    h6_e_MC->GetYaxis()->SetTitle("Energy");
    h6_e_MC->SetLineColor(1);//red plot
    h6_e_MC->SetLineWidth(6);
    h6_e_MC->Draw();
    
    h_e_RomanPots->SetLineColor(2);
    h_e_RomanPots->SetLineWidth(6);
    h_e_RomanPots->Draw("SAME");
    
    TLegend *leg4 = new TLegend(0.2, 0.8, 0.3, 0.9);
    leg4->AddEntry(h6_e_MC,"MC", "l");
    leg4->AddEntry(h_e_RomanPots, "RP", "l");
    leg4->Draw();
    
    TCanvas *c10 = new TCanvas("c10","c10",800,800);//pt for final proton in mc and rp
    h6_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    h6_pt_MC->GetXaxis()->SetRangeUser(-0.0001,1.7);
    h6_pt_MC->SetStats(0);
    h6_pt_MC->GetYaxis()->SetTitleSize(0.03);
    h6_pt_MC->GetYaxis()->SetTitle("Momentum");
    h6_pt_MC->SetLineColor(1);//red plot
    h6_pt_MC->SetLineWidth(6);
    h6_pt_MC->Draw();
    
    h_pt_RomanPots->SetLineColor(2);//black plot
    h_pt_RomanPots->SetLineWidth(6);
    h_pt_RomanPots->Draw("SAME");
    
    TLegend *leg5 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg5->AddEntry(h6_pt_MC,"MC", "l");
    leg5->AddEntry(h_pt_RomanPots, "RP", "l");
    leg5->Draw();
    
    TCanvas *fept = new TCanvas("fept","fept",800,800);//final electron P_t
    h8_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    h8_pt_MC->GetXaxis()->SetRangeUser(-0.1,3);
    h8_pt_MC->SetStats(0);
    h8_pt_MC->GetYaxis()->SetTitleSize(0.03);
    h8_pt_MC->SetLineColor(1);//red plot
    h8_pt_MC->SetLineWidth(6);
    h8_pt_MC->Draw();
    
    rcElectronpt->SetLineColor(2);//black plot
    rcElectronpt->SetLineWidth(6);
    rcElectronpt->Draw("SAME");
    
    TLegend *leg8= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg8->AddEntry(h8_pt_MC,"MC e", "l");
    leg8->AddEntry(rcElectronpt, "Recon. e", "l");
    leg8->Draw();
    
    TCanvas *fppt = new TCanvas("fppt","fppt",1200,1200);
    fppt->Divide(4,3);
    fppt->cd(1);//p_t of the positron at the jpsi
    h7_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    //h7_pt_MC->GetXaxis()->SetRangeUser(-0.1,3);
    h7_pt_MC->SetStats(0);
    h7_pt_MC->GetYaxis()->SetTitleSize(0.03);
    h7_pt_MC->SetLineColor(1);//red plot
    h7_pt_MC->SetLineWidth(6);
    h7_pt_MC->Draw();
    
    rcPositronpt->SetLineColor(2);//black plot
    rcPositronpt->SetLineWidth(6);
    rcPositronpt->Draw("SAME");
    
    TLegend *leg91= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg91->AddEntry(h7_pt_MC,"MC e^{+}", "l");
    leg91->AddEntry(rcPositronpt, "Recon. e^{+}", "l");
    leg91->Draw();
    
    fppt->cd(2);//p_t of the electron at the jpsi
    h8_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    h8_pt_MC->GetXaxis()->SetRangeUser(-0.1,4);
    h8_pt_MC->SetStats(0);
    h8_pt_MC->GetYaxis()->SetTitleSize(0.03);
    h8_pt_MC->SetLineColor(4);//red plot
    h8_pt_MC->SetLineWidth(6);
    h8_pt_MC->Draw();
    
    hjpsi_pt_MC->SetLineColor(1);//red plot
    hjpsi_pt_MC->SetLineWidth(6);
    hjpsi_pt_MC->Draw("SAME");
    
    rcElectronjpsipt->SetLineColor(2);//black plot
    rcElectronjpsipt->SetLineWidth(6);
    rcElectronjpsipt->Draw("SAME");
    
    rcElectronpt->SetLineColor(3);//black plot
    rcElectronpt->SetLineWidth(6);
    rcElectronpt->Draw("SAME");
    
    TLegend *leg92= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg92->AddEntry(h8_pt_MC,"MC e SC", "l");
    leg92->AddEntry(hjpsi_pt_MC,"MC e", "l");
    leg92->AddEntry(rcElectronjpsipt, "Recon. e", "l");
    leg92->AddEntry(rcElectronpt, "Recon. e SC", "l");
    leg92->Draw();
    
    fppt->cd(3);//eta of the positron at the jpsi
    h7_eta_MC->GetXaxis()->SetTitle("#eta");
    //h7_eta_MC->GetXaxis()->SetRangeUser(-0.1,3);
    h7_eta_MC->SetStats(0);
    h7_eta_MC->GetYaxis()->SetTitleSize(0.03);
    h7_eta_MC->SetLineColor(1);//red plot
    h7_eta_MC->SetLineWidth(6);
    h7_eta_MC->Draw();
    
    rcPositron->SetLineColor(2);//black plot
    rcPositron->SetLineWidth(6);
    rcPositron->Draw("SAME");
    
    TLegend *leg93= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg93->AddEntry(h7_eta_MC,"MC e^{+}", "l");
    leg93->AddEntry(rcPositron, "Recon. e^{+}", "l");
    leg93->Draw();
    
    fppt->cd(4);//eta of the electron at the jpsi
    h8_eta_MC->GetXaxis()->SetTitle("#eta");
    //h8_eta_MC->GetYaxis()->SetRangeUser(0,3500);
    h8_eta_MC->GetXaxis()->SetRangeUser(-10,10);
    h8_eta_MC->SetStats(0);
    h8_eta_MC->GetYaxis()->SetTitleSize(0.03);
    h8_eta_MC->SetLineColor(4);//red plot
    h8_eta_MC->SetLineWidth(6);
    h8_eta_MC->Draw();
    
    hjpsi_eta_MC->SetLineColor(1);//red plot
    hjpsi_eta_MC->SetLineWidth(6);
    hjpsi_eta_MC->Draw("SAME");
    
    rcElectronjpsieta->SetLineColor(2);//black plot
    rcElectronjpsieta->SetLineWidth(6);
    rcElectronjpsieta->Draw("SAME");
    
    rcElectron->SetLineColor(3);//black plot
    rcElectron->SetLineWidth(6);
    rcElectron->Draw("SAME");
    
    TLegend *leg94= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg94->AddEntry(h8_eta_MC,"MC e SC", "l");
    leg94->AddEntry(hjpsi_eta_MC,"MC e", "l");
    leg94->AddEntry(rcElectronjpsieta, "Recon. e", "l");
    leg94->AddEntry(rcElectron, "Recon. e SC", "l");
    leg94->Draw();
    
    fppt->cd(5);//pt_vs_eta mc
    mcjpsie_pt_vs_eta->GetXaxis()->SetTitle("#eta");
    mcjpsie_pt_vs_eta->GetYaxis()->SetTitle("p_{t}");
    //mcjpsie_pt_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcjpsie_pt_vs_eta->GetYaxis()->SetRangeUser(0,6);
    mcjpsie_pt_vs_eta->SetStats(0);
    mcjpsie_pt_vs_eta->Draw("COLZ");
    
    TLegend *pteta= new TLegend(0.8, 0.8, 0.9, 0.9);
    pteta->AddEntry(mcjpsie_pt_vs_eta,"e at jpsi - MC", "");
    pteta->Draw();
    
    fppt->cd(6);//pz_vs_eta mc
    mcjpsie_pz_vs_eta->GetXaxis()->SetTitle("#eta");
    mcjpsie_pz_vs_eta->GetYaxis()->SetTitle("p_{z}");
    //mcjpsie_pz_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcjpsie_pz_vs_eta->GetYaxis()->SetRangeUser(0,150);
    mcjpsie_pz_vs_eta->SetStats(0);
    mcjpsie_pz_vs_eta->Draw("COLZ");
    
    
    TLegend *pzeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    pzeta->AddEntry(mcjpsie_pz_vs_eta,"e at jpsi - MC", "");
    pzeta->Draw();
    
    fppt->cd(7);//pt_vs_eta recon
    rcjpsie_pt_vs_eta->GetXaxis()->SetTitle("#eta");
    rcjpsie_pt_vs_eta->GetYaxis()->SetTitle("p_{t}");
    //rcjpsie_pt_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcjpsie_pt_vs_eta->GetYaxis()->SetRangeUser(0,6);
    rcjpsie_pt_vs_eta->SetStats(0);
    rcjpsie_pt_vs_eta->Draw("COLZ");
    
    TLegend *rcpteta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcpteta->AddEntry(rcjpsie_pt_vs_eta,"e at jpsi - Recon.", "");
    rcpteta->Draw();
    
    fppt->cd(8);//pz_vs_eta recon
    rcjpsie_pz_vs_eta->GetXaxis()->SetTitle("#eta");
    rcjpsie_pz_vs_eta->GetYaxis()->SetTitle("p_{z}");
    //rcjpsie_pz_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcjpsie_pz_vs_eta->GetYaxis()->SetRangeUser(0,150);
    rcjpsie_pz_vs_eta->SetStats(0);
    rcjpsie_pz_vs_eta->Draw("COLZ");
    
    TLegend *rcpzeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcpzeta->AddEntry(rcjpsie_pz_vs_eta,"e at jpsi Recon.", "");
    rcpzeta->Draw();
    
    fppt->cd(9);//pt_vs_eta mc sc
    mcsce_pt_vs_eta->GetXaxis()->SetTitle("#eta");
    mcsce_pt_vs_eta->GetYaxis()->SetTitle("p_{t}");
    //mcsce_pt_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcsce_pt_vs_eta->GetYaxis()->SetRangeUser(0,6);
    mcsce_pt_vs_eta->SetStats(0);
    mcsce_pt_vs_eta->Draw("COLZ");
    
    TLegend *ptetasc= new TLegend(0.8, 0.8, 0.9, 0.9);
    ptetasc->AddEntry(mcsce_pt_vs_eta,"SC e MC", "");
    ptetasc->Draw();
    
    fppt->cd(10);//pz_vs_eta mc sc
    mcsce_pz_vs_eta->GetXaxis()->SetTitle("#eta");
    mcsce_pz_vs_eta->GetYaxis()->SetTitle("p_{z}");
    //mcsce_pz_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcsce_pz_vs_eta->GetYaxis()->SetRangeUser(0,150);
    mcsce_pz_vs_eta->SetStats(0);
    mcsce_pz_vs_eta->Draw("COLZ");
    
    
    TLegend *pzetasc= new TLegend(0.8, 0.8, 0.9, 0.9);
    pzetasc->AddEntry(mcsce_pz_vs_eta,"SC e MC", "");
    pzetasc->Draw();
    
    fppt->cd(11);//pt_vs_eta rcc sc
    rcsce_pt_vs_eta->GetXaxis()->SetTitle("#eta");
    rcsce_pt_vs_eta->GetYaxis()->SetTitle("p_{t}");
    //rcsce_pt_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcsce_pt_vs_eta->GetYaxis()->SetRangeUser(0,6);
    rcsce_pt_vs_eta->SetStats(0);
    rcsce_pt_vs_eta->Draw("COLZ");
    
    TLegend *rcptetasc= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcptetasc->AddEntry(rcsce_pt_vs_eta,"SC e Recon.", "");
    rcptetasc->Draw();
    
    fppt->cd(12);//pz_vs_eta rcc sc
    rcsce_pz_vs_eta->GetXaxis()->SetTitle("#eta");
    rcsce_pz_vs_eta->GetYaxis()->SetTitle("p_{z}");
    //rcsce_pz_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcsce_pz_vs_eta->GetYaxis()->SetRangeUser(0,150);
    rcsce_pz_vs_eta->SetStats(0);
    rcsce_pz_vs_eta->Draw("COLZ");
    
    TLegend *rcpzetasc= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcpzetasc->AddEntry(rcsce_pz_vs_eta,"SC e Recon.", "");
    rcpzetasc->Draw();
    
    TCanvas *q_sq = new TCanvas("q_sq","q_sq",800,800);
    mtqq->GetXaxis()->SetTitle("Q^{2}");
    mtqq->GetYaxis()->SetRangeUser(0,3250);
    mtqq->SetStats(0);
    mtqq->SetMarkerStyle(8);
    mtqq->SetMarkerColor(2);
    //mtqq->SetMarkerSize(1);
    mtqq->GetYaxis()->SetTitleSize(0.03);
    mtqq->SetLineColor(2);//black plot
    //mtq->SetFillColor(kGreen-9);
    mtqq->SetLineWidth(6);
    mtqq->Draw();
    
    mtq->SetMarkerStyle(8);
    mtq->SetMarkerColor(1);
    mtq->SetLineColor(1);
    //mtqq->SetLineWidth(6);
    mtq->Draw("SAME");
    
    TRatioPlot* rp3 = new TRatioPlot(mtqq, mtq);
    rp3->Draw();
    rp3->GetLowerRefYaxis()->SetTitle("ratio");
    rp3->GetLowerRefGraph()->SetMinimum(0);
    rp3->GetLowerRefGraph()->SetMaximum(1);
    rp3->SetSeparationMargin(0.0);
    rp3->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp3->GetUpperPad()->cd();
    TLegend *qq2= new TLegend(0.8, 0.8, 0.9, 0.9);
    qq2->AddEntry(mtq,"MC", "p");
    qq2->AddEntry(mtqq, "Full Reconstruction", "l");
    qq2->Draw();
    
    TCanvas *sc = new TCanvas("sc","sc",1200,600);
    sc->Divide(2,1);
    sc->cd(1);
    //2_eta_MC->SetStats(0);
    h2_eta_MC->GetXaxis()->SetRangeUser(-5,2);
    h2_eta_MC->Draw();
    sc->cd(2);
    //h2_e_MC->SetStats(0);
    h2_e_MC->GetXaxis()->SetRangeUser(-0,20);
    h2_e_MC->Draw();
    
    TCanvas *xbjk = new TCanvas("xbjk","xbjk",800,800);
    xbjk->SetLogy();
    xb1->GetXaxis()->SetTitle("x_{bj}");
    xb1->GetXaxis()->SetRangeUser(0,0.1);
    //xb1->GetYaxis()->SetRangeUser(0,6000);
    xb1->SetStats(0);
    xb1->GetYaxis()->SetTitleSize(0.03);
    xb1->SetLineColor(2);//red plot
    xb1->SetLineWidth(6);
    xb1->Draw();
    
    xb->SetMarkerStyle(8);
    xb->SetMarkerColor(1);
    //xb->SetLineColor(2);
    //xb1->SetLineWidth(6);
    xb->Draw("SAME");
    
    auto rp1 = new TRatioPlot(xb1, xb);
    rp1->Draw();
    rp1->GetLowerRefYaxis()->SetTitle("ratio");
    rp1->GetLowerRefGraph()->SetMinimum(0);
    rp1->GetLowerRefGraph()->SetMaximum(5);
    rp1->SetSeparationMargin(0.0);
    rp1->GetLowerRefGraph()->SetMarkerStyle(8);
   
    rp1->GetUpperPad()->cd();
    TLegend *xbjok= new TLegend(0.8, 0.8, 0.9, 0.9);
    xbjok->AddEntry(xb,"MC", "p");
    xbjok->AddEntry(xb1, "Full Reconstruction", "l");
    xbjok->Draw();
    
    TCanvas *x_v = new TCanvas("x_v","x_v",800,800);
    x_v->SetLogy();
    xv1->GetXaxis()->SetTitle("x_{v}");
    xv1->GetXaxis()->SetRangeUser(0,0.1);
    //xv1->GetYaxis()->SetRangeUser(0,6000);
    xv1->SetStats(0);
    xv1->GetYaxis()->SetTitleSize(0.03);
    xv1->SetLineColor(2);//red plot
    xv1->SetLineWidth(6);
    xv1->Draw();
    
    xv->SetMarkerStyle(8);
    xv->SetMarkerColor(1);
    xv->Draw("SAME");
    
    TRatioPlot* rp2 = new TRatioPlot(xv1, xv);
    rp2->Draw();
    rp2->GetLowerRefYaxis()->SetTitle("ratio");
    rp2->GetLowerRefGraph()->SetMinimum(0);
    rp2->GetLowerRefGraph()->SetMaximum(1);
    rp2->SetSeparationMargin(0.0);
    rp2->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp2->GetUpperPad()->cd();
    TLegend *x_vv= new TLegend(0.8, 0.8, 0.9, 0.9);
    x_vv->AddEntry(xv,"MC", "p");
    x_vv->AddEntry(xv1, "Full Reconstruction", "l");
    x_vv->Draw();
    
    TCanvas *diff = new TCanvas("diff","diff",1200,1200);
    diff->Divide(2,2);
    diff->cd(1);
    //diffjpsimass->GetXaxis()->SetRangeUser(-5,2);
    diffjpsimass->Draw();
    
    diff->cd(2);
    //diffq2->GetXaxis()->SetRangeUser(-0,20);
    diffq2->Draw();
    
    diff->cd(3);
    //difft->GetXaxis()->SetRangeUser(-5,2);
    difft->Draw();
    
    diff->cd(4);
    //diffx_v->GetXaxis()->SetRangeUser(-5,2);
    diffx_v->Draw();
    
    TCanvas *E_vs_eta = new TCanvas("E_vs_eta","E_vs_eta",1200,1200);
    E_vs_eta->Divide(2,2);
    E_vs_eta->cd(1);
    mcjpsie_e_vs_eta->GetXaxis()->SetTitle("#eta");
    mcjpsie_e_vs_eta->GetYaxis()->SetTitle("E[GeV]");
    //mcjpsie_e_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcjpsie_e_vs_eta->GetYaxis()->SetRangeUser(0,6);
    mcjpsie_e_vs_eta->SetStats(0);
    mcjpsie_e_vs_eta->Draw("COLZ");
    
    TLegend *mceeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    mceeta->AddEntry(mcjpsie_e_vs_eta,"e at jpsi - MC", "");
    mceeta->Draw();
    
    E_vs_eta->cd(2);
    mcsce_e_vs_eta->GetXaxis()->SetTitle("#eta");
    mcsce_e_vs_eta->GetYaxis()->SetTitle("E[GeV]");
    //mcsce_e_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //mcsce_e_vs_eta->GetYaxis()->SetRangeUser(0,6);
    mcsce_e_vs_eta->SetStats(0);
    mcsce_e_vs_eta->Draw("COLZ");
    
    TLegend *mcsceeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcsceeta->AddEntry(mcsce_e_vs_eta,"SC e - MC", "");
    mcsceeta->Draw();
    
    E_vs_eta->cd(3);
    rcjpsie_e_vs_eta->GetXaxis()->SetTitle("#eta");
    rcjpsie_e_vs_eta->GetYaxis()->SetTitle("E[GeV]");
    //rcjpsie_e_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcjpsie_e_vs_eta->GetYaxis()->SetRangeUser(0,6);
    rcjpsie_e_vs_eta->SetStats(0);
    rcjpsie_e_vs_eta->Draw("COLZ");
    
    TLegend *rceeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rceeta->AddEntry(rcjpsie_e_vs_eta,"e at jpsi - Recon.", "");
    rceeta->Draw();
    
    E_vs_eta->cd(4);
    rcsce_e_vs_eta->GetXaxis()->SetTitle("#eta");
    rcsce_e_vs_eta->GetYaxis()->SetTitle("E[GeV]");
    //rcsce_e_vs_eta->GetXaxis()->SetRangeUser(-8,8);
    //rcsce_e_vs_eta->GetYaxis()->SetRangeUser(0,6);
    rcsce_e_vs_eta->SetStats(0);
    rcsce_e_vs_eta->Draw("COLZ");
    
    TLegend *rcsceeta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcsceeta->AddEntry(rcsce_e_vs_eta,"SC e - Recon.", "");
    rcsceeta->Draw();
    
    TCanvas *E_vs_pz = new TCanvas("E_vs_pz","E_vs_pz",1600,1600);
    E_vs_pz->Divide(3,2);
    E_vs_pz->cd(1);
    mcjpsipos_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    mcjpsipos_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    mcjpsipos_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    mcjpsipos_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    mcjpsipos_e_vs_pz->SetStats(0);
    mcjpsipos_e_vs_pz->Draw("COLZ");
    
    TLegend *mcpospz= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcpospz->AddEntry(mcjpsipos_e_vs_pz,"e^{+} at jpsi - MC", "");
    mcpospz->Draw();
    
    E_vs_pz->cd(2);
    mcjpsie_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    mcjpsie_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    mcjpsie_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    mcjpsie_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    mcjpsie_e_vs_pz->SetStats(0);
    mcjpsie_e_vs_pz->Draw("COLZ");
    
    TLegend *mcepz= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcepz->AddEntry(mcjpsie_e_vs_pz,"e at jpsi - MC", "");
    mcepz->Draw();
    
    E_vs_pz->cd(3);
    mcsce_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    mcsce_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    mcsce_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    mcsce_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    mcsce_e_vs_pz->SetStats(0);
    mcsce_e_vs_pz->Draw("COLZ");
    
    TLegend *mcscepz= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcscepz->AddEntry(mcsce_e_vs_pz,"SC e - MC", "");
    mcscepz->Draw();
    
    E_vs_pz->cd(4);
    rcjpsipos_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    rcjpsipos_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    rcjpsipos_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    rcjpsipos_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    rcjpsipos_e_vs_pz->SetStats(0);
    rcjpsipos_e_vs_pz->Draw("COLZ");
    
    TLegend *rcpospz= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcpospz->AddEntry(rcjpsie_e_vs_pz,"e^{+} at jpsi - Recon.", "");
    rcpospz->Draw();
    
    E_vs_pz->cd(5);
    rcjpsie_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    rcjpsie_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    rcjpsie_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    rcjpsie_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    rcjpsie_e_vs_pz->SetStats(0);
    rcjpsie_e_vs_pz->Draw("COLZ");
    
    TLegend *rcepz= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcepz->AddEntry(rcjpsie_e_vs_pz,"e at jpsi - Recon.", "");
    rcepz->Draw();
    
    E_vs_pz->cd(6);
    rcsce_e_vs_pz->GetXaxis()->SetTitle("p_{z}");
    rcsce_e_vs_pz->GetYaxis()->SetTitle("E[GeV]");
    rcsce_e_vs_pz->GetXaxis()->SetRangeUser(-30,20);
    rcsce_e_vs_pz->GetYaxis()->SetRangeUser(-20,30);
    rcsce_e_vs_pz->SetStats(0);
    rcsce_e_vs_pz->Draw("COLZ");
    
    TLegend *rcscepz= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcscepz->AddEntry(rcsce_e_vs_pz,"SC e - Recon.", "");
    rcscepz->Draw();
    
    TCanvas *E_minus_pz = new TCanvas("E_minus_pz","E_minus_pz",800,600);
    E_minus_pz->Divide(2,1);
    
    E_minus_pz->cd(1);
    mcjpsie_e_minus_pz->GetXaxis()->SetTitle("E - P_{z}");
    mcjpsie_e_minus_pz->GetXaxis()->SetRangeUser(20,40);
    mcjpsie_e_minus_pz->SetStats(0);
    mcjpsie_e_minus_pz->GetYaxis()->SetTitleSize(0.03);
    //mcjpsie_e_minus_pz->GetYaxis()->SetTitle("Final Proton");
    mcjpsie_e_minus_pz->SetLineColor(1);//
    mcjpsie_e_minus_pz->SetLineWidth(6);
    mcjpsie_e_minus_pz->Draw();
    
    /*mcjpsipos_e_minus_pz->SetLineColor(7);//
    mcjpsipos_e_minus_pz->SetLineWidth(6);
    mcjpsipos_e_minus_pz->Draw("SAME");
    
    mcsce_e_minus_pz->SetLineColor(2);//
    mcsce_e_minus_pz->SetLineWidth(6);
    mcsce_e_minus_pz->Draw("SAME");
    
    rcjpsie_e_minus_pz->SetLineColor(3);//
    rcjpsie_e_minus_pz->SetLineWidth(6);
    rcjpsie_e_minus_pz->Draw("SAME");
    
    rcjpsipos_e_minus_pz->SetLineColor(6);//
    rcjpsipos_e_minus_pz->SetLineWidth(6);
    rcjpsipos_e_minus_pz->Draw("SAME");
    
    rcsce_e_minus_pz->SetLineColor(4);//
    rcsce_e_minus_pz->SetLineWidth(6);
    rcsce_e_minus_pz->Draw("SAME"); 
    
    djpsicheck_e_minus_pz->SetLineColor(5);//
    djpsicheck_e_minus_pz->SetLineWidth(6);
    djpsicheck_e_minus_pz->Draw("SAME");*/
    
    TLegend *mceminuspz = new TLegend(0.8, 0.8, 0.9, 0.9);
    mceminuspz->AddEntry(mcjpsie_e_minus_pz,"MC JPsi e", "l");
    //mceminuspz->AddEntry(mcjpsipos_e_minus_pz,"MC JPsi e^{+}", "l");
    //mceminuspz->AddEntry(mcsce_e_minus_pz, "MC SC e", "l");
    //mceminuspz->AddEntry(rcjpsie_e_minus_pz, "RC JPsi e", "l");
    //mceminuspz->AddEntry(rcjpsipos_e_minus_pz, "RC JPsi e^{+}", "l");
    //mceminuspz->AddEntry(rcsce_e_minus_pz, "RC SC e", "l");
    //mceminuspz->AddEntry(djpsicheck_e_minus_pz, "jpsi", "l");
    mceminuspz->Draw();
    
    E_minus_pz->cd(2);
    rcjpsie_e_minus_pz->GetXaxis()->SetTitle("E - P_{z}");
    rcjpsie_e_minus_pz->GetXaxis()->SetRangeUser(20,40);
    rcjpsie_e_minus_pz->SetStats(0);
    rcjpsie_e_minus_pz->GetYaxis()->SetTitleSize(0.03);
    //rcjpsie_e_minus_pz->GetYaxis()->SetTitle("Final Proton");
    rcjpsie_e_minus_pz->SetLineColor(1);//
    rcjpsie_e_minus_pz->SetLineWidth(6);
    rcjpsie_e_minus_pz->Draw();
    
    TLegend *rceminuspz = new TLegend(0.8, 0.8, 0.9, 0.9);
    rceminuspz->AddEntry(rcjpsie_e_minus_pz, "RC JPsi e", "l");
    rceminuspz->Draw();
    
    TCanvas *Theta_vs_Phi = new TCanvas("#Theta_vs_#Phi","#Theta_vs_#Phi",1600,1600);
    Theta_vs_Phi->Divide(3,2);
    Theta_vs_Phi->cd(1);
    mcjpsipos_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    mcjpsipos_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    mcjpsipos_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    mcjpsipos_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    mcjpsipos_theta_vs_phi->SetStats(0);
    mcjpsipos_theta_vs_phi->Draw("COLZ");
    
    TLegend *mcposthetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcposthetaphi->AddEntry(mcjpsipos_theta_vs_phi,"e^{+} at jpsi - MC", "");
    mcposthetaphi->Draw();
    
    Theta_vs_Phi->cd(2);
    mcjpsie_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    mcjpsie_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    mcjpsie_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    mcjpsie_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    mcjpsie_theta_vs_phi->SetStats(0);
    mcjpsie_theta_vs_phi->Draw("COLZ");
    
    TLegend *mcethetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcethetaphi->AddEntry(mcjpsie_theta_vs_phi,"e at jpsi - MC", "");
    mcethetaphi->Draw();
    
    Theta_vs_Phi->cd(3);
    mcsce_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    mcsce_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    mcsce_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    mcsce_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    mcsce_theta_vs_phi->SetStats(0);
    mcsce_theta_vs_phi->Draw("COLZ");
    
    TLegend *mcscethetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcscethetaphi->AddEntry(mcsce_theta_vs_phi,"SC e - MC", "");
    mcscethetaphi->Draw();
    
    Theta_vs_Phi->cd(4);
    rcjpsipos_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    rcjpsipos_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    rcjpsipos_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    rcjpsipos_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    rcjpsipos_theta_vs_phi->SetStats(0);
    rcjpsipos_theta_vs_phi->Draw("COLZ");
    
    TLegend *rcposthetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcposthetaphi->AddEntry(rcjpsipos_theta_vs_phi,"e^{+} at jpsi - RC", "");
    rcposthetaphi->Draw();
    
    Theta_vs_Phi->cd(5);
    rcjpsie_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    rcjpsie_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    rcjpsie_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    rcjpsie_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    rcjpsie_theta_vs_phi->SetStats(0);
    rcjpsie_theta_vs_phi->Draw("COLZ");
    
    TLegend *rcethetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcethetaphi->AddEntry(rcjpsie_theta_vs_phi,"e at jpsi - RC", "");
    rcethetaphi->Draw();
    
    Theta_vs_Phi->cd(6);
    rcsce_theta_vs_phi->GetXaxis()->SetTitle("#phi");
    rcsce_theta_vs_phi->GetYaxis()->SetTitle("#theta");
    rcsce_theta_vs_phi->GetXaxis()->SetRangeUser(-2,6);
    rcsce_theta_vs_phi->GetYaxis()->SetRangeUser(-10,10);
    rcsce_theta_vs_phi->SetStats(0);
    rcsce_theta_vs_phi->Draw("COLZ");
    
    TLegend *rcscethetaphi= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcscethetaphi->AddEntry(rcsce_theta_vs_phi,"SC e - RC", "");
    rcscethetaphi->Draw();
    
    TCanvas *Phi_vs_Eta = new TCanvas("#Phi_vs_#Eta","#Phi_vs_#Eta",1600,1600);
    Phi_vs_Eta->Divide(3,2);
    Phi_vs_Eta->cd(1);
    mcjpsipos_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    mcjpsipos_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    mcjpsipos_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    mcjpsipos_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    mcjpsipos_phi_vs_eta->SetStats(0);
    mcjpsipos_phi_vs_eta->Draw("COLZ");
    
    TLegend *mcposphieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcposphieta->AddEntry(mcjpsipos_phi_vs_eta,"e^{+} at jpsi - MC", "");
    mcposphieta->Draw();
    
    Phi_vs_Eta->cd(2);
    mcjpsie_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    mcjpsie_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    mcjpsie_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    mcjpsie_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    mcjpsie_phi_vs_eta->SetStats(0);
    mcjpsie_phi_vs_eta->Draw("COLZ");
    
    TLegend *mcephieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcephieta->AddEntry(mcjpsie_phi_vs_eta,"e at jpsi - MC", "");
    mcephieta->Draw();
    
    Phi_vs_Eta->cd(3);
    mcsce_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    mcsce_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    mcsce_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    mcsce_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    mcsce_phi_vs_eta->SetStats(0);
    mcsce_phi_vs_eta->Draw("COLZ");
    
    TLegend *mcscephieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcscephieta->AddEntry(mcsce_phi_vs_eta,"SC e - MC", "");
    mcscephieta->Draw();
    
    Phi_vs_Eta->cd(4);
    rcjpsipos_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    rcjpsipos_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    rcjpsipos_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    rcjpsipos_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    rcjpsipos_phi_vs_eta->SetStats(0);
    rcjpsipos_phi_vs_eta->Draw("COLZ");
    
    TLegend *rcposphieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcposphieta->AddEntry(rcjpsipos_phi_vs_eta,"e^{+} at jpsi - RC", "");
    rcposphieta->Draw();
    
    Phi_vs_Eta->cd(5);
    rcjpsie_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    rcjpsie_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    rcjpsie_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    rcjpsie_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    rcjpsie_phi_vs_eta->SetStats(0);
    rcjpsie_phi_vs_eta->Draw("COLZ");
    
    TLegend *rcephieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcephieta->AddEntry(rcjpsie_phi_vs_eta,"e at jpsi - RC", "");
    rcephieta->Draw();
    
    Phi_vs_Eta->cd(6);
    rcsce_phi_vs_eta->GetXaxis()->SetTitle("#eta");
    rcsce_phi_vs_eta->GetYaxis()->SetTitle("#phi");
    rcsce_phi_vs_eta->GetXaxis()->SetRangeUser(-6,6);
    rcsce_phi_vs_eta->GetYaxis()->SetRangeUser(-20,20);
    rcsce_phi_vs_eta->SetStats(0);
    rcsce_phi_vs_eta->Draw("COLZ");
    
    TLegend *rcscephieta= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcscephieta->AddEntry(rcsce_phi_vs_eta,"SC e - RC", "");
    rcscephieta->Draw();
    
    TCanvas *Phi_vs_E = new TCanvas("#Phi_vs_#E","#Phi_vs_#E",1600,1600);
    Phi_vs_E->Divide(3,2);
    Phi_vs_E->cd(1);
    mcjpsipos_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    mcjpsipos_phi_vs_e->GetYaxis()->SetTitle("#phi");
    mcjpsipos_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //mcjpsipos_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    mcjpsipos_phi_vs_e->SetStats(0);
    mcjpsipos_phi_vs_e->Draw("COLZ");
    
    TLegend *mcposphie= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcposphie->AddEntry(mcjpsipos_phi_vs_e,"e^{+} at jpsi - MC", "");
    mcposphie->Draw();
    
    Phi_vs_E->cd(2);
    mcjpsie_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    mcjpsie_phi_vs_e->GetYaxis()->SetTitle("#phi");
    mcjpsie_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //mcjpsie_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    mcjpsie_phi_vs_e->SetStats(0);
    mcjpsie_phi_vs_e->Draw("COLZ");
    
    TLegend *mcephie= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcephie->AddEntry(mcjpsie_phi_vs_eta,"e at jpsi - MC", "");
    mcephie->Draw();
    
    Phi_vs_E->cd(3);
    mcsce_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    mcsce_phi_vs_e->GetYaxis()->SetTitle("#phi");
    mcsce_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //mcsce_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    mcsce_phi_vs_e->SetStats(0);
    mcsce_phi_vs_e->Draw("COLZ");
    
    TLegend *mcscephie= new TLegend(0.8, 0.8, 0.9, 0.9);
    mcscephie->AddEntry(mcsce_phi_vs_e,"SC e - MC", "");
    mcscephie->Draw();
    
    Phi_vs_E->cd(4);
    rcjpsipos_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    rcjpsipos_phi_vs_e->GetYaxis()->SetTitle("#phi");
    rcjpsipos_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //rcjpsipos_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    rcjpsipos_phi_vs_e->SetStats(0);
    rcjpsipos_phi_vs_e->Draw("COLZ");
    
    TLegend *rcposphie= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcposphie->AddEntry(rcjpsipos_phi_vs_e,"e^{+} at jpsi - RC", "");
    rcposphie->Draw();
    
    Phi_vs_E->cd(5);
    rcjpsie_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    rcjpsie_phi_vs_e->GetYaxis()->SetTitle("#phi");
    rcjpsie_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //rcjpsie_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    rcjpsie_phi_vs_e->SetStats(0);
    rcjpsie_phi_vs_e->Draw("COLZ");
    
    TLegend *rcephie= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcephie->AddEntry(rcjpsie_phi_vs_e,"e at jpsi - RC", "");
    rcephie->Draw();
    
    Phi_vs_E->cd(6);
    rcsce_phi_vs_e->GetXaxis()->SetTitle("E[GeV]");
    rcsce_phi_vs_e->GetYaxis()->SetTitle("#phi");
    rcsce_phi_vs_e->GetXaxis()->SetRangeUser(-6,6);
    //rcsce_phi_vs_e->GetYaxis()->SetRangeUser(-10,40);
    rcsce_phi_vs_e->SetStats(0);
    rcsce_phi_vs_e->Draw("COLZ");
    
    TLegend *rcscephie= new TLegend(0.8, 0.8, 0.9, 0.9);
    rcscephie->AddEntry(rcsce_phi_vs_e,"SC e - RC", "");
    rcscephie->Draw();
    
    TCanvas *twoenergy = new TCanvas("twoenergy","twoenergy",800,800);
    mcjpsitwoenergy->GetXaxis()->SetTitle("E[GeV]");
    mcjpsitwoenergy->GetXaxis()->SetRangeUser(-5,40);
    mcjpsitwoenergy->SetStats(0);
    mcjpsitwoenergy->GetYaxis()->SetRangeUser(0,16000);
    //mcjpsitwoenergy->GetYaxis()->SetTitleSize(0.03);
    //mcjpsitwoenergy->GetYaxis()->SetTitle("Final Proton");
    mcjpsitwoenergy->SetLineColor(1);//
    mcjpsitwoenergy->SetLineWidth(6);
    mcjpsitwoenergy->Draw();
    
    mcsctwoenergy->SetLineColor(2);//
    mcsctwoenergy->SetLineWidth(6);
    mcsctwoenergy->Draw("SAME");
    
    rcjpsitwoenergy->SetLineColor(3);//
    rcjpsitwoenergy->SetLineWidth(6);
    rcjpsitwoenergy->Draw("SAME");
    
    rcsctwoenergy->SetLineColor(4);//
    rcsctwoenergy->SetLineWidth(6);
    rcsctwoenergy->Draw("SAME");
    
    TLegend *mctwoenergy = new TLegend(0.8, 0.8, 0.9, 0.9);
    mctwoenergy->AddEntry(mcjpsitwoenergy,"MC JPsi e", "l");
    mctwoenergy->AddEntry(mcsctwoenergy,"MC SC e", "l");
    mctwoenergy->AddEntry(rcjpsitwoenergy,"RC JPsi e", "l");
    mctwoenergy->AddEntry(rcsctwoenergy,"RC SC e", "l");
    mctwoenergy->Draw();
    
    
        return;
        


}

