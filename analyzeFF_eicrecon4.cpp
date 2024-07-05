#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void analyzeFF_eicrecon4(){
    
        TString fileList = "q2_1-10.list";
        //TString fileList = "newlist.list";
        
        
        TString outputName = "ab_test_00mrad_hepmc_";
        
        TString date = "6_27_2024_";
        
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
        
        TLorentzVector vec1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec4(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec5(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec6(10.0, 20.0, 30.0, 40.0);
        TLorentzVector vec7(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector vecjpsi(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector JPsi1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi22(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi222(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector rcpv1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv11(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv22(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv4(10.0, 20.0, 30.0, 40.0);
        TLorentzVector scte(10.0, 20.0, 30.0, 40.0);
        TLorentzVector incbeam(10.0, 20.0, 30.0, 40.0); //proton
        TLorentzVector incbeame(10.0, 20.0, 30.0, 40.0);//electron
        TLorentzVector beamProton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector mcProton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector scatProton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector scatElectron(10.0, 20.0, 30.0, 40.0);
    
    
        TLorentzVector eq1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq4(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector mctrk1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector mctrk2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector iphoton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector iproton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector jproton(10.0, 20.0, 30.0, 40.0);
        TLorentzVector ijpsi(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector mctrue(10.0, 20.0, 30.0, 40.0);
        TLorentzVector afburn(10.0, 20.0, 30.0, 40.0);
        
        TH1D *fElectron = new TH1D("fElectron","fe", 100, -10, 10);
        TH1D *jpsiElectron = new TH1D("jpsiElectron","jpsie", 100, -10, 10);
        TH1D *fProton= new TH1D("fProton","Final Proton", 100, 4, 12);
        TH1D *fPositron= new TH1D("fPositron","fp+", 100, -10, 10);
        TH1D *B0fProton= new TH1D("B0fProton","B0fp", 100, 4, 12);
        TH1D *RPfProton= new TH1D("RPfProton","RPfp", 100, 4, 12);
        TH1D *OMDfProton= new TH1D("OMDfProton","OMDfp", 100, 4, 12);
    
        TH1D *rcElectron= new TH1D("rcElectron","rcElectron", 100, -10, 10);
        TH1D *rcPositron= new TH1D("rcPositron","rcPositron", 100, -10, 10);
        
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
        TH1D* h8_eta_MC = new TH1D("h8_eta",";Pseudorapidity, #eta",100,0.0,15.0);
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
        TH1D* hs_e_hepmc = new TH1D("e_hepmc", ";E [GeV]", 1000, 0.0, 320.0);
        TH1D* hs_eta_hepmc = new TH1D("hs_eta_hepmc",";Pseudorapidity, #eta",100,-15,10.0);
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
    

    //reading in HEPMC file to account for the true MC begins
    
    int whichCase = 0; //0 - DVCS; 1 - ALL; 2 - BH

    TString dateString = "5_30_2024";

    double qSquaredMin = 2.47028; //2.0 nominal
    double qSquaredMax = 3.16228; //10.0 nominal 3.16228
    //BH testing
    //double bjorkXMin = 0.0005;
    //double bjorkXMax = 0.0008;
    double bjorkXMin = 0.01;
    double bjorkXMax = 0.0129245;

    double kin = 0;

    double deltaQ = qSquaredMax - qSquaredMin;
    double deltaX = bjorkXMax - bjorkXMin;
    
    double convFactor = 389379.0; //for dSigma/dt in nb/GeV^2
    double alphaEM = 1.0/137.036;
    double L_int = 0.0;

    int numHEPMCFiles = 1;
    int numafHEPMCFiles = 1;
    double totalCrossSection = 0.0;
    TString caseStr = "";


    //sstream stream;
    string line;

    string a1, a2, a3, a4, a5;
    string a1af, a2af, a3af, a4af, a5af;

    string firstStr;
    int tot_event = 102000;
    //for particle listing
    int particleIdx[tot_event];
    int afparticleIdx[tot_event];
    int motherIdx[tot_event];
    int afmotherIdx[tot_event];
    int pdgCode[tot_event];
    int afpdgCode[tot_event];
    double px[tot_event], py[tot_event], pz[tot_event], E[tot_event], mass[tot_event]; int status[tot_event];
    double af_px[tot_event], af_py[tot_event], af_pz[tot_event], af_E[tot_event], af_mass[tot_event]; int af_status[tot_event];

    string lineIdentifier = "";
    string aflineIdentifier = "";
    double vtx_x, vtx_y, vtx_z;
    double vtx_xaf, vtx_yaf, vtx_zaf;

    int evLineCounter = 0;
    int particleCounter = 0;
    int afparticleCounter = 0;
    int numParticlesInEvent = -999;
    int numafParticlesInEvent = -999;
    int eventCounter = 0;
    int globalLineCounter = 0;
    int lundIdx = 1;
    int aflundIdx = 1;

    bool foundInternalPhoton = false;
    bool foundScatteredElectron = false;
        
    int internalPhotonIdx = -999;
    int afinternalPhotonIdx = -999;
    int scatteredElectronIdx = -999;
    int afscatteredElectronIdx = -999;
    int beamElectronIdx = -999;
    int afbeamElectronIdx = -999;
    int beamProtonIdx = -999;
    int mcProtonIdx = -999;
    int afbeamProtonIdx = -999;
    int beamfProtonIdx = -999;
    int afbeamfProtonIdx = -999;
    
    incbeame.SetXYZM(0,0,-17.999999992746666,.00051099904266560590);
    incbeam.SetXYZM(0,0, 274.99839935073504,0.93827210000933003);

    TH1D * qSquared_gammaStar = new TH1D("qSquared_gammaStar", "qSquared_gammaStar", 1000, 1.0, 100.0);
    TH1D * qSquared_ScatElectron = new TH1D("qSquared_ScatElectron", "qSquared_ScatElectron", 1000, 1.0, 100.0);
    TH2D * eta_vs_qSquared_reco = new TH2D("eta_vs_qSquared_reco", "eta_vs_qSquared_reco", 100, 1.0, 10.0, 500, -4.0, 1.0);
    TH1D * x_bjorken = new TH1D("x_bjorken", "x_bjorken", 1000, -4.0, 1.0);
    TH2D * qSquare_vs_x = new TH2D("Q2_vs_x", "Q2_vs_x", 1000, -5.0, 1.0, 200, 0.0, 100.0);
    
    //double tBins[29] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2, 0.23, 0.26, 0.29, 0.32, 0.36, 0.4, 0.5, 0.6, 0.7, 0.8, 1.0, 1.2, 1.4};
    double tBins[28];// = {0.0, 0.028, 0.033, 0.038, 0.044, 0.05, 0.057, 0.066, 0.076, 0.087, 0.1, 0.13, 0.15, 0.175, 0.20, 0.23, 0.27, 0.31, 0.35, 0.40, 0.46, 0.54, 0.61, 0.71, 0.81, 1.1, 1.3, 1.6};
    
    double binWidths[27] = {0.028, 0.005, 0.005, 0.006, 0.006, 0.007, 0.009, 0.009, 0.011, 0.013, 0.015, 0.020, 0.025, 0.03, 0.04, 0.04, 0.04, 0.05, 0.06, 0.08, 0.08, 0.1, 0.13, 0.15, 0.18, 0.21, 0.25};
    
    double tVal = 0.0;
    
    for(int i = 0; i < 27; i++){
    
        tBins[i] = tVal;
        tVal += binWidths[i];
        tBins[i+1] = tVal;
        //cout << "t-binning --> t = " << tVal << endl;
    }
    
    //TH1D * t_distribution = new TH1D("proton_pt_squared", "proton_pt_squared", 27, tBins);// previously
    TH1D * t_distribution = new TH1D("proton_pt_squared", "proton_pt_squared", 1000, 0, 100);
        
    int iflagproton = 0;
    
    for(int ihepmcFile = 1; ihepmcFile < numHEPMCFiles+1; ihepmcFile++){
    
            //ifstream inputTextFile(Form("lager-vmp-00mrad.jpsi-18on275.4pi.disp-jpsi-00-electron.run00001-lumi1.hepmc"));
            ifstream inputTextFile(Form("ab_q2_Rng_1_10.hepmc"));
    
            if(!inputTextFile){ cout << "cannot open file!!!!" << endl; return;}
        
            particleCounter = 0;
            numParticlesInEvent = -999;
            lundIdx = 1;

            while (getline(inputTextFile, line) ){
               
                istringstream ss(line);
        
                ss >> lineIdentifier;
                
                if(lineIdentifier == "E"){

                    //E 0 9 15 @ -5.0868376913709906e-02 -2.5795220595253325e-03 7.7078711664698085e+00 -1.0678171802415379e+01

                    ss >> a1 >> a2 >> numParticlesInEvent >> a4;
                    ss >> vtx_x >> vtx_y >> vtx_z;

                    //cout << "Event: " << eventCounter << " has " << numParticlesInEvent << " particles and V(x,y,z) = " << vtx_x << " " << vtx_y << " " << vtx_z << endl;

                    vtx_x = 0.0;
                    vtx_y = 0.0;
                    vtx_z = 0.0;
                }
                

                if(lineIdentifier == "P"){

                    ss >> particleIdx[particleCounter] >> motherIdx[particleCounter] >> pdgCode[particleCounter]
                       >> px[particleCounter] >> py[particleCounter] >> pz[particleCounter] >> E[particleCounter] >> mass[particleCounter] >> status[particleCounter];

                    if(status[particleCounter] == 4 && pdgCode[particleCounter] == 11){beamElectronIdx = particleCounter;}
                    if(status[particleCounter] == 4 && pdgCode[particleCounter] == 2212){beamProtonIdx = particleCounter;}
                    if(status[particleCounter] == 6 && pdgCode[particleCounter] == 2212){beamfProtonIdx = particleCounter;}
                    if(status[particleCounter] == 1 && pdgCode[particleCounter] == 11){scatteredElectronIdx = particleCounter;}
                    if(status[particleCounter] == 13 && pdgCode[particleCounter] == 22){internalPhotonIdx = particleCounter;}

                    particleCounter++;
                }
                
                if(particleCounter == numParticlesInEvent){
                    
                    //cout << "--------------" << endl;
                    TLorentzVector hepmcv;
                    
                    for(int idx = 0; idx < particleCounter; idx++){
                        
                        mctrue.RotateY(0.025);
                        //mctrue.SetPxPyPzE(px[3], py[3], pz[3], E[3]);
                        mctrue.SetXYZM(px[3], py[3], pz[3], mass[3]);
                        double bjorkX;
                        
                        if(status[idx] == 1 && pdgCode[idx] == 2212){
                            //cout << "internalPhotonIdx: " << beamProtonIdx << endl;
                           
                            TLorentzVector gammaStar(px[internalPhotonIdx], py[internalPhotonIdx], pz[internalPhotonIdx], E[internalPhotonIdx]);
                            beamProton.SetPxPyPzE(px[beamProtonIdx], py[beamProtonIdx], pz[beamProtonIdx], E[beamProtonIdx]);

                            double qSquared = -1*gammaStar.Mag2();
                            double denom = beamProton.Dot(gammaStar);
                            bjorkX = qSquared/(2*denom);
                            
                            scatProton.RotateY(0.025);
                            scatProton.SetPxPyPzE(px[idx], py[idx], pz[idx], E[idx]);
                            double t = scatProton.Pt()*scatProton.Pt();
                            
                            TLorentzVector diff = beamProton - scatProton;
                            t = -1*diff.Dot(diff);

                            t_distribution->Fill(t);
                            
                            double t2;
                           
                            TLorentzVector diff2 = beamProton - scatProton;
                            t2 = -1*diff2.Dot(diff2);
                            
                            mta->Fill(t2);
                            
                        }
                        
                        if(status[idx] == 13 && idx == internalPhotonIdx && E[idx] != -1){

                            TLorentzVector gammaStar(px[idx], py[idx], pz[idx], E[idx]);
                            TLorentzVector beamProton(px[beamProtonIdx], py[beamProtonIdx], pz[beamProtonIdx], E[beamProtonIdx]);

                            double qSquared = -1*gammaStar.Mag2();
                            //cout << "E_scattered_e = " << E[idx] << " scattering angle = " << theta << " radians. " << endl;
                            //cout << "Q2 = " << qSquared << " GeV2 " << endl;
                            if(qSquared > qSquaredMin && qSquared < qSquaredMax){ qSquared_gammaStar->Fill(qSquared); }
                            
                            double denom = beamProton.Dot(gammaStar);
                            bjorkX = qSquared/(2*denom);

                            if(bjorkX > bjorkXMin && bjorkX < bjorkXMax) { x_bjorken->Fill(TMath::Log10(bjorkX)); }
                            
                            //if(bjorkX > bjorkXMin && bjorkX < bjorkXMax && qSquared > qSquaredMin && qSquared < qSquaredMax){
                                qSquare_vs_x->Fill(TMath::Log10(bjorkX), qSquared);
                                //}
                        }
                        
                        if(status[idx] == 1 && pdgCode[idx] == 11 && motherIdx[idx] == 1){
                            
                            //cout << "Iteration: " << idx << " Particle: " << pdgCode[idx] << endl;
                            
                            hepmcv.SetXYZM(px[idx], py[idx], pz[idx], mass[idx]);
                            hs_e_hepmc->Fill(hepmcv.E());
                            hs_eta_hepmc->Fill(hepmcv.Eta());
                            
                        }
                        x_bjk->Fill(TMath::Log10(bjorkX));
                        //
                        /*if(status[idx] == 1 && idx == scatteredElectronIdx && E[idx] != -1){
                        
                            TLorentzVector scatElectron(px[idx], py[idx], pz[idx], mass[idx]);
                            
                            hs_e_hepmc->Fill(scatElectron.E());

                            double electronEnergy = elecE;

                            double theta = scatElectron.Theta();
                            theta = theta - TMath::Pi();
                            double qSquared = 2*electronEnergy*E[idx]*(1 - TMath::Cos(theta));

                            qSquared_ScatElectron->Fill(qSquared);

                            eta_vs_qSquared_reco->Fill(qSquared, scatElectron.Eta());

                        }//*/
                        
                    }
                    
                    internalPhotonIdx = -999;
                    scatteredElectronIdx = -999;
                    beamElectronIdx = -999;
                    beamProtonIdx = -999;
                
                    eventCounter++; particleCounter = 0; numParticlesInEvent = -999;
                    if(eventCounter > tot_event){break;}
                }


            } //while loop to read event

        inputTextFile.close();

    }//loop for number of input HEMPC files
    
    // second hempc starts

    cout << "total events = " << eventCounter << endl;

    TCanvas * canvas1 = new TCanvas("can1", "can1", 1600, 400);
    canvas1->Divide(4,1);

    canvas1->cd(1)->SetLogy();
    canvas1->cd(1)->SetLogx();

    qSquared_gammaStar->SetLineColor(kBlack);
    qSquared_ScatElectron->SetLineColor(kRed);

    qSquared_gammaStar->GetXaxis()->SetTitle("Q^{2} [GeV^{2}]");
    qSquared_ScatElectron->GetXaxis()->SetTitle("Q^{2} [GeV^{2}]");

    //qSquared_gammaStar->SetStats(0);
    qSquared_ScatElectron->SetStats(0);
    qSquared_gammaStar->Draw();
    //qSquared_ScatElectron->Draw("SAME");

    canvas1->cd(2);
    //canvas1->cd(2)->SetLogx();
    canvas1->cd(2)->SetLogy();
    //canvas1->cd(2)->SetLogz();
    canvas1->cd(2)->SetLeftMargin(0.15);
    canvas1->cd(2)->SetRightMargin(0.15);

    //x_bjorken->SetStats(0);
    x_bjorken->GetXaxis()->SetTitle("x_{bjorken}");
    x_bjorken->Draw();

    //eta_vs_qSquared_reco->SetStats(0);
    //eta_vs_qSquared_reco->GetXaxis()->SetTitle("Q^{2} [GeV^{2}]");
    //eta_vs_qSquared_reco->GetYaxis()->SetTitle("Scat. Electron Pseudorapidity, #eta");
    //eta_vs_qSquared_reco->Draw("COLZ");

    canvas1->cd(3);
    canvas1->cd(3)->SetLogy();
    canvas1->cd(3)->SetLeftMargin(0.15);
    canvas1->cd(3)->SetRightMargin(0.15);
    
    t_distribution->GetXaxis()->SetRangeUser(0,5);
    t_distribution->GetXaxis()->SetTitle("-t [GeV^{2}]");

    t_distribution->GetXaxis()->SetTitle("-t [GeV^{2}]");
    t_distribution->GetYaxis()->SetTitle("d#sigma/dt pb/GeV^{2}");


    //t_distribution->Fit("expo", "E");

    t_distribution->Draw("E P");
    
    canvas1->cd(4);
    //canvas1->cd(4)->SetLogx();
    canvas1->cd(4)->SetLogy();
    canvas1->cd(4)->SetLogz();
    canvas1->cd(4)->SetLeftMargin(0.15);
    canvas1->cd(4)->SetRightMargin(0.15);

    qSquare_vs_x->SetStats(0);
    qSquare_vs_x->GetXaxis()->SetTitle("x_{Bj}");
    qSquare_vs_x->GetYaxis()->SetTitle("Q^{2} [GeV^{2}]");

    qSquare_vs_x->Draw("COLZ");

    //TFile * outputFile = new TFile("olaiya.root", "RECREATE");

    qSquared_gammaStar->Write();
    qSquared_ScatElectron->Write();
    eta_vs_qSquared_reco->Write();
    x_bjorken->Write();
    t_distribution->Write();
    qSquare_vs_x->Write();
    int icoutn = 0;
    // end of reading HEPMC file
    
    /*for(int iafhepmcFile = 1; iafhepmcFile < numafHEPMCFiles+1; iafhepmcFile++){

            ifstream inputTextFile(Form("ab_test_00mrad.hepmc"));
    
            if(!inputTextFile){ cout << "cannot open file!!!!" << endl; return;}
        
            afparticleCounter = 0;
            numafParticlesInEvent = -999;
            aflundIdx = 1;

        while (getline(inputTextFile, line) ){
            
            istringstream ssaf(line);
            
            ssaf >> aflineIdentifier;
            
            if(aflineIdentifier == "E"){
                
                //E 0 9 15 @ -5.0868376913709906e-02 -2.5795220595253325e-03 7.7078711664698085e+00 -1.0678171802415379e+01
                
                ssaf >> a1af >> a2af >> numafParticlesInEvent >> a4af;
                ssaf >> vtx_xaf >> vtx_yaf >> vtx_zaf;
                
                
                vtx_xaf = 0.0;
                vtx_yaf = 0.0;
                vtx_zaf = 0.0;
            }
            
            
            if(lineIdentifier == "P"){
                
                ssaf >> afparticleIdx[afparticleCounter] >> afmotherIdx[afparticleCounter] >> afpdgCode[afparticleCounter]
                >> af_px[afparticleCounter] >> af_py[afparticleCounter] >> af_pz[afparticleCounter] >> af_E[afparticleCounter] >> af_mass[afparticleCounter] >> af_status[afparticleCounter];
                
                if(af_status[afparticleCounter] == 4 && afpdgCode[afparticleCounter] == 11){afbeamElectronIdx = afparticleCounter;}
                if(af_status[afparticleCounter] == 4 && afpdgCode[afparticleCounter] == 2212){afbeamProtonIdx = afparticleCounter;}
                if(af_status[afparticleCounter] == 6 && afpdgCode[afparticleCounter] == 2212){afbeamfProtonIdx = afparticleCounter;}
                if(af_status[afparticleCounter] == 1 && afpdgCode[afparticleCounter] == 11){afscatteredElectronIdx = afparticleCounter;}
                if(af_status[afparticleCounter] == 13 && afpdgCode[afparticleCounter] == 22){afinternalPhotonIdx = afparticleCounter;}
                
                afparticleCounter++;
            }
            
            if(afparticleCounter == numafParticlesInEvent){
                
                for(int idxaf = 0; idxaf < afparticleCounter; idxaf++){
                    afburn.SetPxPyPzE(af_px[idxaf], af_py[idxaf], af_pz[idxaf], af_E[idxaf]);
                    cout <<"---------------------" << endl;
                    cout << "afburn: " << afburn.P() << " Px: " << afburn.Px() << " Py: " << afburn.Py() << " Pz: " << afburn.Pz() << endl;
                    
                }
            }
        }

        inputTextFile.close();

    }//loop for number of input HEMPC files

    //second hepmc ends*/
    
        
        int fileCounter = 0;
        int iEvent = 0;
        
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
            
            TTreeReaderArray<int> recop_pdg = {tree_reader, "ReconstructedChargedParticles.PDG"};
            TTreeReaderArray<float> recop_px = {tree_reader, "ReconstructedChargedParticles.momentum.x"};
            TTreeReaderArray<float> recop_py = {tree_reader, "ReconstructedChargedParticles.momentum.y"};
            TTreeReaderArray<float> recop_pz = {tree_reader, "ReconstructedChargedParticles.momentum.z"};
            TTreeReaderArray<float> recop_m = {tree_reader, "ReconstructedChargedParticles.mass"};
            
            
            //ZDC EMCAL
            /*TTreeReaderArray<float> zdc_ecal_cluster_x = {tree_reader, "ZDCEcalClusters.position.x"};
             TTreeReaderArray<float> zdc_ecal_cluster_y = {tree_reader, "ZDCEcalClusters.position.y"};
             TTreeReaderArray<float> zdc_ecal_cluster_z = {tree_reader, "ZDCEcalClusters.position.z"};
             TTreeReaderArray<float>  zdc_ecal_cluster_energy = {tree_reader, "ZDCEcalClusters.energy"}; //deposited energy in cluster*/
            
            
            cout << "file has " << evtTree->GetEntries() <<  " events..." << endl;
            
            tree_reader.SetEntriesRange(0, evtTree->GetEntries());// allow computer to get the number of events
            //tree_reader.SetEntriesRange(0, 10); //imposed specific number of events
            int flag1 = 0;
            
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
                
                double t1;
                double t3;
                double thetaMC;
                double thetaChPct;
                double q2;
                double q2_1;
                double scatElecEnergMC;
                double scatElecEnergChPct;
                
                int flag1 = 0;
                int flag2 = 0;
                int flag3 = 0;
                
                double maxPt=-99.;
                iflagproton = 0;
                
                int ic = 2;//for the MC scattered electron
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
                    
                    for(int imc=0;imc<mc_px_array.GetSize();imc++){
                        mctrk.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                        
                        if (imc == 6){
                            
                            mctrk.RotateY(0.025);
                            
                            h6_eta_MC->Fill(mctrk.Eta());
                            
                            h6_px_MC->Fill(mctrk.Px());
                            h6_py_MC->Fill(mctrk.Py());
                            h6_pt_MC->Fill(mctrk.Pt());
                            h6_pz_MC->Fill(mctrk.Pz());
                            h6_e_MC->Fill(mctrk.E());
                            
                            vec1.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                            fProton->Fill(mctrk.Eta());
                            
                        }
                        
                        //finding the jpsi positron
                        if (imc == 7){
                            
                            h7_eta_MC->Fill(mctrk.Eta());
                            
                            h7_px_MC->Fill(mctrk.Px());
                            h7_py_MC->Fill(mctrk.Py());
                            h7_pt_MC->Fill(mctrk.Pt());
                            h7_pz_MC->Fill(mctrk.Pz());
                            h7_e_MC->Fill(mctrk.E());
                            
                            vec2.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                            fPositron->Fill(vec2.Eta());
                            
                        }
                        
                        ///finding the jpsi electron
                        if (imc == 8){
                            
                            hjpsi_eta_MC->Fill(mctrk.Eta());
                            
                            hjpsi_px_MC->Fill(mctrk.Px());
                            hjpsi_py_MC->Fill(mctrk.Py());
                            hjpsi_pt_MC->Fill(mctrk.Pt());
                            hjpsi_pz_MC->Fill(mctrk.Pz());
                            hjpsi_e_MC->Fill(mctrk.E());
                            
                            vecjpsi.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                            jpsiElectron->Fill(vecjpsi.Eta());
                            
                        }
                        
                        //finding the scattered electron
                        if (imc == 2){
                            //mctrk.RotateY(0.025);
                            
                            h8_eta_MC->Fill(mctrk.Eta());
                            
                            h8_px_MC->Fill(mctrk.Px());
                            h8_py_MC->Fill(mctrk.Py());
                            h8_pt_MC->Fill(mctrk.Pt());
                            h8_pz_MC->Fill(mctrk.Pz());
                            h8_e_MC->Fill(mctrk.E());
                            
                            vec3.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                            fElectron->Fill(vec3.Eta());
                            
                        }
                        
                        //finding the proton at position 4
                        if (imc == 4){
                            
                            mctrk.RotateY(0.025);
                            
                            h4_eta_MC->Fill(mctrk.Eta());
                            
                            h4_px_MC->Fill(mctrk.Px());
                            h4_py_MC->Fill(mctrk.Py());
                            h4_pt_MC->Fill(mctrk.Pt());
                            h4_pz_MC->Fill(mctrk.Pz());
                            h4_e_MC->Fill(mctrk.E());
                            
                        }
                        
                        //finding the initial incoming proton
                        if (imc == 3){
                            
                            mctrk.RotateY(0.025);
                            
                            h3_eta_MC->Fill(mctrk.Eta());
                            
                            h3_px_MC->Fill(mctrk.Px());
                            h3_py_MC->Fill(mctrk.Py());
                            h3_pt_MC->Fill(mctrk.Pt());
                            h3_pz_MC->Fill(mctrk.Pz());
                            h3_e_MC->Fill(mctrk.E());
                            iproton.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                            
                            //pT cut at 200MeV
                            if (iproton.Pt() >= 0.2){
                                jproton.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                                
                            }
                        }
                        
                        //finding mediating photon
                        if (imc == 1){
                            
                            h1_eta_MC->Fill(mctrk.Eta());
                            
                            h1_px_MC->Fill(mctrk.Px());
                            h1_py_MC->Fill(mctrk.Py());
                            h1_pt_MC->Fill(mctrk.Pt());
                            h1_pz_MC->Fill(mctrk.Pz());
                            h1_e_MC->Fill(mctrk.E());
                            iphoton.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                        }
                        
                        //finding the jpsi
                        if (imc == 5){
                            
                            h5_eta_MC->Fill(mctrk.Eta());
                            
                            h5_px_MC->Fill(mctrk.Px());
                            h5_py_MC->Fill(mctrk.Py());
                            h5_pt_MC->Fill(mctrk.Pt());
                            h5_pz_MC->Fill(mctrk.Pz());
                            h5_e_MC->Fill(mctrk.E());
                            ijpsi.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                        }
                        
                    }
                    
                    // scattered proton
                    mctrk1.SetXYZM(mc_px_array[6], mc_py_array[6], mc_pz_array[6],mc_mass_array[6]);
                    mctrk1.RotateY(0.025);
                    
                    // Incident electron
                    mctrk2.SetXYZM(mc_px_array[0], mc_py_array[0], mc_pz_array[0],mc_mass_array[0]);
                    
                    //roman pots reco tracks
                    for(int iRPPart = 0; iRPPart < reco_RP_px.GetSize(); iRPPart++){
                        
                        if (reco_RP_pdg[iRPPart] == 2212){
                            
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
                            //}
                        }
                        break;
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
                    
                    JPsi1 = vec2 + vecjpsi;
                    
                    JPsiMass1->Fill(JPsi1.M());
                    
                    iEvent++;
                    
                    flag1 = 0;
                    flag2 = 0;
                    flag3 = 0;
                    
                    for(int rcp=0;rcp<reco_track_x.GetSize();rcp++){
                        /*if (reco_track_x.GetSize() > 2){
                         cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << recop_pdg[rcp] << endl;}*/
                        
                        //mctrk.SetXYZ(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc]);//previous
                        /*if(reco_track_x.GetSize()>4){
                         cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << reco_track_pdg[rcp] << endl;}*/
                        
                        if(reco_track_x.GetSize() == 3){
                            
                            if(reco_track_pdg[0] != reco_track_pdg[1] && reco_track_pdg[0] != reco_track_pdg[2] && reco_track_pdg[1] != reco_track_pdg[2]){
                                
                                if(reco_track_pdg[0] == 11 && (reco_track_pdg[1] == -11 || reco_track_pdg[2] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                    rcElectronjpsieta->Fill(rcpv1.Eta());
                                    rcElectronjpsipt->Fill(rcpv1.Pt());
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[1] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[2] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                    rcElectronjpsieta->Fill(rcpv1.Eta());
                                    rcElectronjpsipt->Fill(rcpv1.Pt());
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[2] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[1] == -11)){
                                    rcpv1.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                    rcElectronjpsieta->Fill(rcpv1.Eta());
                                    rcElectronjpsipt->Fill(rcpv1.Pt());
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[0] == -11 && (reco_track_pdg[1] == 11 || reco_track_pdg[2] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                    rcPositron->Fill(rcpv2.Eta());
                                    rcPositronpt->Fill(rcpv2.Pt());
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[1] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[2] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                    rcPositron->Fill(rcpv2.Eta());
                                    rcPositronpt->Fill(rcpv2.Pt());
                                    
                                    flag2++;
                                }
                                if(reco_track_pdg[2] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[1] == 11)){
                                    rcpv2.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                    rcPositron->Fill(rcpv2.Eta());
                                    rcPositronpt->Fill(rcpv2.Pt());
                                    
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
                                        
                                        rcElectron->Fill(eq1.Eta());
                                        rcElectronpt->Fill(eq1.Pt());
                                        rcPositron->Fill(rcpv2.Eta());
                                        rcPositronpt->Fill(rcpv2.Pt());
                                        rcElectronjpsieta->Fill(rcpv1.Eta());
                                        rcElectronjpsipt->Fill(rcpv1.Pt());
                                        
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
                                        
                                        rcElectron->Fill(eq1.Eta());
                                        rcPositron->Fill(rcpv2.Eta());
                                        rcPositronpt->Fill(rcpv2.Pt());
                                        rcElectronpt->Fill(eq1.Pt());
                                        rcElectronjpsieta->Fill(rcpv1.Eta());
                                        rcElectronjpsipt->Fill(rcpv1.Pt());
                                        
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
                                        
                                        rcElectron->Fill(eq1.Eta());
                                        rcPositron->Fill(rcpv2.Eta());
                                        rcPositronpt->Fill(rcpv2.Pt());
                                        rcElectronpt->Fill(eq1.Pt());
                                        rcElectronjpsieta->Fill(rcpv1.Eta());
                                        rcElectronjpsipt->Fill(rcpv1.Pt());
                                    }
                                    flag3++;
                                }
                                
                                
                            }
                            
                        }
                        
                        if(reco_track_x.GetSize() == 2){
                            if(reco_track_pdg[0] == 11 && reco_track_pdg[1] == -11){
                                rcpv1.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                rcpv2.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                rcElectronjpsieta->Fill(rcpv1.Eta());
                                rcElectronjpsipt->Fill(rcpv1.Pt());
                                
                                flag1++;
                            }
                            if(reco_track_pdg[0] == -11 && reco_track_pdg[1] == 11){
                                rcpv1.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                rcpv2.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                rcElectronjpsieta->Fill(rcpv1.Eta());
                                rcElectronjpsipt->Fill(rcpv1.Pt());
                                
                                flag1++;
                            }
                            if(reco_track_pdg[0] == 11 && reco_track_pdg[1] == 11){
                               rcpv1.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                eq1.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                rcElectron->Fill(eq1.Eta());
                                rcElectronpt->Fill(eq1.Pt());
                                rcElectronjpsieta->Fill(rcpv1.Eta());
                                rcElectronjpsipt->Fill(rcpv1.Pt());
                                
                                flag1++;
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
                    }
                    
                    TLorentzVector diff1 = incbeam - vec5;
                    TLorentzVector diff3 = incbeam - mctrk1;
                    t1 = -1*diff1.Dot(diff1);//for RP
                    
                    t3 = -1*diff3.Dot(diff3);//for MC
                    
                    if (iflagproton == 1){
                        mtg->Fill(t1);
                    }
                    //black plot
                    mtgg->Fill(t3);//
                    
                    //PositfJpsi->Fill(EcalPPhi());
            
                    //calculate x_Bjorken here
                    double ixb = q2/(2.0 * iproton.Dot(iphoton));//mc
                    double ixb1 = q2_1/(2.0 * jproton.Dot(iphoton));//recon
                    
                    xb->Fill(ixb);
                    if (iflagproton == 1){
                        xb1->Fill(ixb1);
                    }
                    
                    double ixv = (q2 + ijpsi.M()*ijpsi.M())/(2.0 * iproton.Dot(iphoton));
                    double ixv1 = (q2_1 + ijpsi.M()*ijpsi.M())/(2.0 * jproton.Dot(iphoton));
                    
                    xv->Fill(ixv);
                    if (iflagproton == 1){
                        xv1->Fill(ixv1);
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
    
    /*TCanvas *fPos = new TCanvas("fPos","fPos",800,800);
    fPositron->GetXaxis()->SetTitle("#eta");
    fPositron->GetXaxis()->SetRangeUser(-7,7);
    fPositron->SetStats(0);
    fPositron->GetYaxis()->SetTitleSize(0.03);
    fPositron->SetLineColor(1);//red plot
    fPositron->SetLineWidth(6);
    fPositron->Draw();
    
    rcPositron->SetLineColor(2);//red plot
    rcPositron->SetLineWidth(6);
    rcPositron->Draw("SAME");
    
    TLegend *leg3 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg3->AddEntry(fPositron,"MC e^{+}", "l");
    leg3->AddEntry(rcPositron,"Recon e^{+}", "l");
    leg3->Draw();*/
    
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
    rcJPsiMass1->GetXaxis()->SetTitle("Mass e^{-}e^{+} [GeV]");
    rcJPsiMass1->GetXaxis()->SetRangeUser(2,3.6);
    rcJPsiMass1->SetStats(0);
    rcJPsiMass1->GetYaxis()->SetTitleSize(0.03);
    rcJPsiMass1->SetLineColor(2);//red plot
    rcJPsiMass1->SetLineWidth(6);
    rcJPsiMass1->Draw();
    
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
    
    /*mta->SetMarkerStyle(8);
    mta->SetMarkerColor(3);
    mta->SetMarkerSize(1);
    mta->SetLineColor(3);//red plot
    mta->SetLineWidth(6);
    mta->Draw("AP SAME");*/

    mtgg->SetMarkerStyle(8);
    mtgg->SetMarkerColor(1);
    mtgg->SetLineColor(1);
    mtgg->SetLineWidth(6);
    mtgg->Draw("SAME");
    
    TRatioPlot* rp4 = new TRatioPlot(mtg, mtgg);
    rp4->Draw();
    rp4->GetLowerRefYaxis()->SetTitle("ratio");
    rp4->GetLowerRefGraph()->SetMinimum(0);
    rp4->GetLowerRefGraph()->SetMaximum(3.5);
    rp4->SetSeparationMargin(0.0);
    rp4->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp4->GetUpperPad()->cd();
    TLegend *leg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    leg2->AddEntry(mtgg, "MC Particles", "p");
    leg2->AddEntry(mtg,"RP - reconstructed", "l");
    //leg2->AddEntry(mta,"Afterburned", "l");
    leg2->Draw();
    
    /*TCanvas *c55 = new TCanvas("c55","c55",800,800);
    //c55->SetLogy();
    //c5->Divide(3,2);
    //c5->cd(1);
    mtg->GetXaxis()->SetTitle("-t");
    mtg->GetXaxis()->SetRangeUser(0,2);
    mtg->SetStats(0);
    mtg->GetYaxis()->SetTitleSize(0.03);
    mtg->SetLineColor(1);//black plot
    mtg->SetFillColor(kGreen-9);
    mtg->SetLineWidth(6);
    mtg->Draw();
    
    mta->SetLineColor(2);//red plot
    mta->SetLineWidth(6);
    mta->Draw("SAME");
    
    auto rp = new TRatioPlot(mtg, mta);
    rp->Draw();
    c55->Update();*/
    
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
    fppt->Divide(2,2);
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
    hjpsi_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    //hjpsi_pt_MC->GetXaxis()->SetRangeUser(-0.1,3);
    hjpsi_pt_MC->SetStats(0);
    hjpsi_pt_MC->GetYaxis()->SetTitleSize(0.03);
    hjpsi_pt_MC->SetLineColor(1);//red plot
    hjpsi_pt_MC->SetLineWidth(6);
    hjpsi_pt_MC->Draw();
    
    rcElectronjpsipt->SetLineColor(2);//black plot
    rcElectronjpsipt->SetLineWidth(6);
    rcElectronjpsipt->Draw("SAME");
    
    TLegend *leg92= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg92->AddEntry(hjpsi_pt_MC,"MC e", "l");
    leg92->AddEntry(rcElectronjpsipt, "Recon. e", "l");
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
    hjpsi_eta_MC->GetXaxis()->SetTitle("#eta");
    //hjpsi_eta_MC->GetXaxis()->SetRangeUser(-0.1,3);
    hjpsi_eta_MC->SetStats(0);
    hjpsi_eta_MC->GetYaxis()->SetTitleSize(0.03);
    hjpsi_eta_MC->SetLineColor(1);//red plot
    hjpsi_eta_MC->SetLineWidth(6);
    hjpsi_eta_MC->Draw();
    
    rcElectronjpsieta->SetLineColor(2);//black plot
    rcElectronjpsieta->SetLineWidth(6);
    rcElectronjpsieta->Draw("SAME");
    
    TLegend *leg94= new TLegend(0.8, 0.8, 0.9, 0.9);
    leg94->AddEntry(hjpsi_eta_MC,"MC e", "l");
    leg94->AddEntry(rcElectronjpsieta, "Recon. e", "l");
    leg94->Draw();
    
    TCanvas *q_sq = new TCanvas("q_sq","q_sq",800,800);
    //q_sq->SetLogy();
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
    rp3->GetLowerRefGraph()->SetMaximum(1.5);
    rp3->SetSeparationMargin(0.0);
    rp3->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp3->GetUpperPad()->cd();
    TLegend *qq2= new TLegend(0.8, 0.8, 0.9, 0.9);
    qq2->AddEntry(mtq,"MC", "p");
    qq2->AddEntry(mtqq, "Recon.", "l");
    qq2->Draw();
    
    TCanvas *sc = new TCanvas("sc","sc",1200,600);
    sc->Divide(4,1);
    sc->cd(1);
    //2_eta_MC->SetStats(0);
    h2_eta_MC->GetXaxis()->SetRangeUser(-5,2);
    h2_eta_MC->Draw();
    sc->cd(2);
    //h2_e_MC->SetStats(0);
    h2_e_MC->GetXaxis()->SetRangeUser(-0,20);
    h2_e_MC->Draw();
    sc->cd(3);
    //h2_e_MC->SetStats(0);
    hs_e_hepmc->GetXaxis()->SetRangeUser(-0,20);
    hs_e_hepmc->Draw();
    sc->cd(4);
    //h2_e_MC->SetStats(0);
    hs_eta_hepmc->GetXaxis()->SetRangeUser(-5,2);
    hs_eta_hepmc->Draw();
    
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
    rp1->GetLowerRefGraph()->SetMaximum(2.5);
    rp1->SetSeparationMargin(0.0);
    rp1->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp1->GetUpperPad()->cd();
    TLegend *xbjok= new TLegend(0.8, 0.8, 0.9, 0.9);
    xbjok->AddEntry(xb,"MC", "p");
    xbjok->AddEntry(xb1, "Recon.", "l");
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
    rp2->GetLowerRefGraph()->SetMaximum(1.5);
    rp2->SetSeparationMargin(0.0);
    rp2->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rp2->GetUpperPad()->cd();
    TLegend *x_vv= new TLegend(0.8, 0.8, 0.9, 0.9);
    x_vv->AddEntry(xv,"MC", "p");
    x_vv->AddEntry(xv1, "Recon.", "l");
    x_vv->Draw();
    
    /*TCanvas *xx_v = new TCanvas("xx_v","xx_v",800,800);
    xx_v->SetLogy();
    xv1->GetXaxis()->SetTitle("x_{v}");
    xv1->GetXaxis()->SetRangeUser(0,0.1);
    xv1->SetStats(0);
    xv1->GetYaxis()->SetTitleSize(0.03);
    xv1->SetLineColor(2);//red plot
    xv1->SetLineWidth(6);
    xv1->Draw();
    
    xv->SetMarkerStyle(8);
    xv->SetMarkerColor(1);
    xv->Draw("SAME");
        
    TRatioPlot* rrp2 = new TRatioPlot(xv1, xv);
    rrp2->Draw();
    rrp2->GetLowerRefYaxis()->SetTitle("ratio");
    rrp2->GetLowerRefGraph()->SetMinimum(0);
    rrp2->GetLowerRefGraph()->SetMaximum(1.5);
    rrp2->SetSeparationMargin(0.0);
    rrp2->GetLowerRefGraph()->SetMarkerStyle(8);
    
    rrp2->GetUpperPad()->cd();
    TLegend *xx_vv= new TLegend(0.8, 0.8, 0.9, 0.9);
    xx_vv->AddEntry(xv,"MC", "l");
    xx_vv->AddEntry(xv1, "Recon.", "p");
    xx_vv->Draw();*/
        
        return;
        


}

