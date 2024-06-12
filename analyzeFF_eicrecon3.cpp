#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

void analyzeFF_eicrecon3(){
    
        TString fileList = "olaiya_file_list.list";
        //TString fileList = "newlist.list";
        
        
        TString outputName = "ab_test_00mrad_hepmc_";
        
        TString date = "6_11_2024_";
        
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
    
        TLorentzVector JPsi1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi22(10.0, 20.0, 30.0, 40.0);
        TLorentzVector JPsi222(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector gsumifp(10.0, 20.0, 30.0, 40.0);
        TLorentzVector gsumifpt(10.0, 20.0, 30.0, 40.0);
        TLorentzVector gsumifp1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rsumifp(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rsumifpt(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rsumifp1(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector rcpv1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv11(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv22(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv4(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv5(10.0, 20.0, 30.0, 40.0);
        TLorentzVector scte(10.0, 20.0, 30.0, 40.0);
        TLorentzVector rcpv7(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector eq1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector eq4(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector genv1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector genv2(10.0, 20.0, 30.0, 40.0);
        TLorentzVector genv3(10.0, 20.0, 30.0, 40.0);
        TLorentzVector mctrk1(10.0, 20.0, 30.0, 40.0);
        TLorentzVector mctrk2(10.0, 20.0, 30.0, 40.0);
    
        TLorentzVector mctrue(10.0, 20.0, 30.0, 40.0);
        
        TH1D *fElectron = new TH1D("fElectron","fe", 100, -10, 10);
        TH1D *fProton= new TH1D("fProton","Final Proton", 100, 4, 12);
        TH1D *fPositron= new TH1D("fPositron","fp+", 100, -10, 10);
        TH1D *B0fProton= new TH1D("B0fProton","B0fp", 100, 4, 12);
        TH1D *RPfProton= new TH1D("RPfProton","RPfp", 100, 4, 12);
        TH1D *OMDfProton= new TH1D("OMDfProton","OMDfp", 100, 4, 12);
    
        TH1D *rcElectron= new TH1D("rcElectron","rcElectron", 200, -50, 12);
        TH1D *rcPositron= new TH1D("rcPositron","rcPositron", 200, -50, 12);
        
        TH1D *JPsiMass1 = new TH1D("JPsiMass1","J/#psi-Mass", 500, 3.0, 3.14);
        TH1D *rcJPsiMass1 = new TH1D("rcJPsiMass1","rcJ/#psi-Mass", 500, -10, 30);
        TH1D *rcJPsiMass11 = new TH1D("rcJPsiMass1","rcJ/#psi-Mass", 500, -10, 30);
        TH1D *rcJPsiMass111 = new TH1D("rcJPsiMass1","rcJ/#psi-Mass", 500, -10, 30);
    
        TH1D *mtg = new TH1D("mtg","mtg", 1000, 0, 100);
        TH1D *mtgt = new TH1D("mtg","mtg", 1000, 0, 100);
        TH1D *mtr = new TH1D("mtr","mtr", 1000, 0, 100);
        TH1D *mtrt = new TH1D("mtr","mtr", 1000, 0, 100);
        TH1D *rat = new TH1D("rat","rat", 1000, 0, 100);
    
        TH1D *mQg = new TH1D("mQg","mQg", 200, -10, 10);
        TH1D *mQr = new TH1D("mQr","mQr", 200, -10, 10);
        
        TH1D *ElectfJpsi = new TH1D("ElectfJpsi","ElectfJpsi", 200, -10, 10);
        TH1D *PositfJpsi = new TH1D("PositfJpsi","PositfJpsi", 200, -10, 10);
    
        TH1D *eff = new TH1D("eff","eff", 200, -10, 10000);
        TH1D *eff21 = new TH1D("eff2","eff2", 200, -10, 10000);
        TH1D *ene = new TH1D("ene","ene", 200, -10, 10000);
    
        //--------------------------------------------------------------------------
        
        //histograms -- only a few for now
        
        //MC information
        //fProton
        TH1D* h6_eta_MC = new TH1D("h6_eta",";Pseudorapidity, #eta",200,0.0,15.0);
        TH1D* h6_px_MC = new TH1D("px6_MC", ";p_{x} [GeV/c]", 200, -8.5, 10);
        TH1D* h6_py_MC = new TH1D("py6_MC", ";p_{y} [GeV/c]", 200, -2.0, 2.0);
        TH1D* h6_pt_MC = new TH1D("pt6_MC", ";p_{t} [GeV/c]", 200, -1, 2);
        TH1D* h6_pz_MC = new TH1D("pz6_MC", ";p_{z} [GeV/c]", 200, 0.0, 320.0);
        TH1D* h6_e_MC = new TH1D("e6_MC", ";E [GeV]", 200, 0.0, 320.0);
    
        //generated
        TH1D* in_pt_MC = new TH1D("in_pt_MC", ";p_{t} [GeV/c]", 100, -1, 2);
        TH1D* fi_pt_gen = new TH1D("fi_pt_gen", ";p_{t} [GeV/c]", 100, -1, 2);
        
        //fPositron
        TH1D* h7_eta_MC = new TH1D("h7_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h7_px_MC = new TH1D("px7_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h7_py_MC = new TH1D("py7_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h7_pt_MC = new TH1D("pt7_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h7_pz_MC = new TH1D("pz7_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h7_e_MC = new TH1D("e7_MC", ";E [GeV]", 100, 0.0, 320.0);
        
        //fElectron
        TH1D* h8_eta_MC = new TH1D("h8_eta",";Pseudorapidity, #eta",100,0.0,15.0);
        TH1D* h8_px_MC = new TH1D("px8_MC", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h8_py_MC = new TH1D("py8_MC", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h8_pt_MC = new TH1D("pt8_MC", ";p_{t} [GeV/c]", 100, 0.0, 10.0);
        TH1D* h8_pz_MC = new TH1D("pz8_MC", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h8_e_MC = new TH1D("e8_MC", ";E [GeV]", 100, 0.0, 320.0);
        
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
        
        //Roman pots
        TH1D* h_px_RomanPots = new TH1D("px_RomanPots", ";p_{x} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_py_RomanPots = new TH1D("py_RomanPots", ";p_{y} [GeV/c]", 100, -10.0, 10.0);
        TH1D* h_pt_RomanPots = new TH1D("pt_RomanPots", ";p_{t} [GeV/c]", 100, -1, 2.0);
        TH1D* h_pz_RomanPots = new TH1D("pz_RomanPots", ";p_{z} [GeV/c]", 100, 0.0, 320.0);
        TH1D* h_e_RomanPots = new TH1D("e_RomanPots", ";E [GeV]", 100, 0.0, 320.0);
        TH2D* h_rp_occupancy_map = new TH2D("Roman_pots_occupancy_map", "hit y [mm];hit x [mm]", 100, -150, 150, 100, -70, 70);
        
        //OMD
        TH1D* h_px_OMD = new TH1D("px_OMD", ";p_{x} [GeV/c]", 200, -10.0, 10.0);
        TH1D* h_py_OMD = new TH1D("py_OMD", ";p_{y} [GeV/c]", 200, -10.0, 10.0);
        TH1D* h_pt_OMD = new TH1D("pt_OMD", ";p_{t} [GeV/c]", 200, -1, 2.0);
        TH1D* h_pz_OMD = new TH1D("pz_OMD", ";p_{z} [GeV/c]", 200, 0.0, 320.0);
        TH1D* h_e_OMD = new TH1D("e_OMD", ";E [GeV]", 200, 0.0, 320.0);
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
    double totalCrossSection = 0.0;
    TString caseStr = "";


    //sstream stream;
    string line;

    string a1, a2, a3, a4, a5;

    string firstStr;
    //for particle listing
    int particleIdx[300];
    int motherIdx[300];
    int pdgCode[300];
    double px[300], py[300], pz[300], E[300], mass[300]; int status[300];

    string lineIdentifier = "";
    double vtx_x, vtx_y, vtx_z;
    

    int evLineCounter = 0;
    int particleCounter = 0;
    int numParticlesInEvent = -999;
    int eventCounter = 0;
    int globalLineCounter = 0;
    int lundIdx = 1;

    bool foundInternalPhoton = false;
    bool foundScatteredElectron = false;
        
    int internalPhotonIdx = -999;
    int scatteredElectronIdx = -999;
    int beamElectronIdx = -999;
    int beamProtonIdx = -999;
    int beamfProtonIdx = -999;

    TH1D * qSquared_gammaStar = new TH1D("qSquared_gammaStar", "qSquared_gammaStar", 1000, 1.0, 100.0);
    TH1D * qSquared_ScatElectron = new TH1D("qSquared_ScatElectron", "qSquared_ScatElectron", 1000, 1.0, 100.0);
    TH2D * eta_vs_qSquared_reco = new TH2D("eta_vs_qSquared_reco", "eta_vs_qSquared_reco", 100, 1.0, 10.0, 500, -4.0, 1.0);
    TH1D * x_bjorken = new TH1D("x_bjorken", "x_bjorken", 1000, -4.0, 1.0);
    TH2D * qSquare_vs_x = new TH2D("Q2_vs_x", "Q2_vs_x", 200, -5.0, 1.0, 200, 0.0, 100.0);
    
    //double tBins[29] = {0.0, 0.01, 0.02, 0.03, 0.04, 0.05, 0.06, 0.07, 0.08, 0.09, 0.1, 0.12, 0.14, 0.16, 0.18, 0.2, 0.23, 0.26, 0.29, 0.32, 0.36, 0.4, 0.5, 0.6, 0.7, 0.8, 1.0, 1.2, 1.4};
    double tBins[28];// = {0.0, 0.028, 0.033, 0.038, 0.044, 0.05, 0.057, 0.066, 0.076, 0.087, 0.1, 0.13, 0.15, 0.175, 0.20, 0.23, 0.27, 0.31, 0.35, 0.40, 0.46, 0.54, 0.61, 0.71, 0.81, 1.1, 1.3, 1.6};
    
    double binWidths[27] = {0.028, 0.005, 0.005, 0.006, 0.006, 0.007, 0.009, 0.009, 0.011, 0.013, 0.015, 0.020, 0.025, 0.03, 0.04, 0.04, 0.04, 0.05, 0.06, 0.08, 0.08, 0.1, 0.13, 0.15, 0.18, 0.21, 0.25};
    
    double tVal = 0.0;
    
    for(int i = 0; i < 27; i++){
    
        tBins[i] = tVal;
        tVal += binWidths[i];
        tBins[i+1] = tVal;
        cout << "t-binning --> t = " << tVal << endl;
    }
    
    TH1D * t_distribution = new TH1D("proton_pt_squared", "proton_pt_squared", 27, tBins);
        
    for(int ihepmcFile = 1; ihepmcFile < numHEPMCFiles+1; ihepmcFile++){
    
            //ifstream inputTextFile(Form("lager-vmp-00mrad.jpsi-18on275.4pi.disp-jpsi-00-electron.run00001-lumi1.hepmc", ihepmcFile));
            ifstream inputTextFile(Form("lager-vmp-00mrad.jpsi-18on275.4pi.disp-jpsi-00-electron.run00001-lumi1.hepmc"));
    
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
                    
                    for(int idx = 0; idx < particleCounter; idx++){
                        
                        //cout << "Number of Iterations: " << idx << " Particle: " << pdgCode[idx] << endl;
                        mctrue.SetXYZM(px[3], py[3], pz[3], E[3]);
                
                        if(status[idx] == 1 && pdgCode[idx] == 2212){

                            TLorentzVector gammaStar(px[internalPhotonIdx], py[internalPhotonIdx], pz[internalPhotonIdx], E[internalPhotonIdx]);
                            TLorentzVector beamProton(px[beamProtonIdx], py[beamProtonIdx], pz[beamProtonIdx], E[beamProtonIdx]);

                            double qSquared = -1*gammaStar.Mag2();
                            double denom = beamProton.Dot(gammaStar);
                            double bjorkX = qSquared/(2*denom);

                            TLorentzVector scatProton(px[idx], py[idx], pz[idx], E[idx]);
                            double t = scatProton.Pt()*scatProton.Pt();
                            
                            TLorentzVector diff = beamProton - scatProton;
                            t = -1*diff.Dot(diff);

                            t_distribution->Fill(t);

                        }
                        
                        if(status[idx] == 13 && idx == internalPhotonIdx && E[idx] != -1){

                            TLorentzVector gammaStar(px[idx], py[idx], pz[idx], E[idx]);
                            TLorentzVector beamProton(px[beamProtonIdx], py[beamProtonIdx], pz[beamProtonIdx], E[beamProtonIdx]);

                            double qSquared = -1*gammaStar.Mag2();
                            //cout << "E_scattered_e = " << E[idx] << " scattering angle = " << theta << " radians. " << endl;
                            //cout << "Q2 = " << qSquared << " GeV2 " << endl;
                            if(qSquared > qSquaredMin && qSquared < qSquaredMax){ qSquared_gammaStar->Fill(qSquared); }
                            
                            double denom = beamProton.Dot(gammaStar);
                            double bjorkX = qSquared/(2*denom);

                            if(bjorkX > bjorkXMin && bjorkX < bjorkXMax) { x_bjorken->Fill(TMath::Log10(bjorkX)); }
                            
                            //if(bjorkX > bjorkXMin && bjorkX < bjorkXMax && qSquared > qSquaredMin && qSquared < qSquaredMax){
                                qSquare_vs_x->Fill(TMath::Log10(bjorkX), qSquared);
                                //}
                        }
                        /*
                        if(status[idx] == 1 && idx == scatteredElectronIdx && E[idx] != -1){
                        
                            TLorentzVector scatElectron(px[idx], py[idx], pz[idx], E[idx]);

                            double electronEnergy = elecE;

                            double theta = scatElectron.Theta();
                            theta = theta - TMath::Pi();
                            double qSquared = 2*electronEnergy*E[idx]*(1 - TMath::Cos(theta));

                            qSquared_ScatElectron->Fill(qSquared);

                            eta_vs_qSquared_reco->Fill(qSquared, scatElectron.Eta());

                        }
                        */
                    }
            
                
                    internalPhotonIdx = -999;
                    scatteredElectronIdx = -999;
                    beamElectronIdx = -999;
                    beamProtonIdx = -999;
                
                    eventCounter++; particleCounter = 0; numParticlesInEvent = -999;
                    if(eventCounter > 102000){break;}
                }


            } //while loop to read event

        inputTextFile.close();

    }//loop for number of input HEMPC files

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

    // end of reading HEPMC file
        
        int fileCounter = 0;
        int iEvent = 0;
        float eff1[102000];
        float eff2[102000];
        float ene1[102000];
        int uu = 0;
        
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
            
            //generated
            TTreeReaderArray<float> gen_px = {tree_reader, "GeneratedParticles.momentum.x"};
            TTreeReaderArray<float> gen_py = {tree_reader, "GeneratedParticles.momentum.y"};
            TTreeReaderArray<float> gen_pz = {tree_reader, "GeneratedParticles.momentum.z"};
            TTreeReaderArray<float> gen_e = {tree_reader, "GeneratedParticles.energy"};
            TTreeReaderArray<float> gen_m = {tree_reader, "GeneratedParticles.mass"};
            TTreeReaderArray<float> gen_c = {tree_reader, "GeneratedParticles.charge"};
            TTreeReaderArray<int> gen_pdg = {tree_reader, "GeneratedParticles.PDG"};
            
            TTreeReaderArray<float> EcalNPhi_x = {tree_reader, "EcalEndcapNClusters.position.x"};
            TTreeReaderArray<float> EcalNPhi_y = {tree_reader, "EcalEndcapNClusters.position.y"};
            TTreeReaderArray<float> EcalNPhi_z = {tree_reader, "EcalEndcapNClusters.position.z"};
            TTreeReaderArray<float> EcalPPhi_x = {tree_reader, "EcalEndcapPClusters.position.x"};
            TTreeReaderArray<float> EcalPPhi_y = {tree_reader, "EcalEndcapPClusters.position.y"};
            TTreeReaderArray<float> EcalPPhi_z = {tree_reader, "EcalEndcapPClusters.position.z"};
            TTreeReaderArray<float> EcalPPhi_e = {tree_reader, "EcalEndcapPClusters.energy"};
            TTreeReaderArray<float> EcalPPhi_t = {tree_reader, "EcalEndcapPClusters.time"};
            
            
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
                //TVector3 mctrk;\\previous
                TVector3 rptrk;
                TVector3 rcpv6;
                
                TLorentzVector mctrk;
                TLorentzVector vec11;
                
                double maxPt=-99.;
                for(int imc=0;imc<mc_px_array.GetSize();imc++){
                    mctrk.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                    //mctrk.SetXYZ(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc]);//previous
                    
                    //cout <<"Number of Iterations: "<< imc <<" -> Partilcles: " << mc_pdg_array[imc] << endl;
                    //cout << "imc: " << imc << endl;
                    
                    //if(mc_pdg_array[6] == 2212){ //only checking for protons here -- change as desired
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
                    
                    //if(mc_pdg_array[7] == -11){ //only checking for positron here -- change as desired
                    if (imc == 7){
                        
                        //mctrk.RotateY(0.025);
                        
                        h7_eta_MC->Fill(mctrk.Eta());
                        
                        h7_px_MC->Fill(mctrk.Px());
                        h7_py_MC->Fill(mctrk.Py());
                        h7_pt_MC->Fill(mctrk.Pt());
                        h7_pz_MC->Fill(mctrk.Pz());
                        h7_e_MC->Fill(mctrk.E());
                        
                        vec2.SetXYZM(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc],mc_mass_array[imc]);
                        fPositron->Fill(vec2.Eta());
                        
                    }
                    
                    //if(mc_pdg_array[8] == 11){ //only checking for electron here -- change as desired
                    if (imc == 8){
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
                    //if(mc_pdg_array[4] == 2212){ //only checking for protons here -- change as desired
                    if (imc == 4){
                        
                        mctrk.RotateY(0.025);
                        
                        h4_eta_MC->Fill(mctrk.Eta());
                        
                        h4_px_MC->Fill(mctrk.Px());
                        h4_py_MC->Fill(mctrk.Py());
                        h4_pt_MC->Fill(mctrk.Pt());
                        h4_pz_MC->Fill(mctrk.Pz());
                        h4_e_MC->Fill(mctrk.E());
                        
                    }
                    //if(mc_pdg_array[3] == 2212){ //only checking for protons here -- change as desired
                    if (imc == 3){
                        
                        mctrk.RotateY(0.025);
                        
                        h3_eta_MC->Fill(mctrk.Eta());
                        
                        h3_px_MC->Fill(mctrk.Px());
                        h3_py_MC->Fill(mctrk.Py());
                        h3_pt_MC->Fill(mctrk.Pt());
                        h3_pz_MC->Fill(mctrk.Pz());
                        h3_e_MC->Fill(mctrk.E());
                    }
                    
                }
                
                vec11.SetXYZM(mc_px_array[6], mc_py_array[6], mc_pz_array[6],mc_mass_array[6]);
                
                
                //roman pots reco tracks
                for(int iRPPart = 0; iRPPart < reco_RP_px.GetSize(); iRPPart++){
                    
                    TLorentzVector prec_romanpots(reco_RP_px[iRPPart], reco_RP_py[iRPPart], reco_RP_pz[iRPPart], reco_RP_e[iRPPart]);
                    
                    vec5.SetXYZM(reco_RP_px[iRPPart], reco_RP_py[iRPPart], reco_RP_pz[iRPPart], reco_RP_m[iRPPart]);
                    
                    //if (prec_romanpots.Eta()>4){
                    if (reco_RP_pdg[iRPPart] == 2212){
                        RPfProton->Fill(vec5.Eta());
                        
                        h_px_RomanPots->Fill(prec_romanpots.Px());
                        h_py_RomanPots->Fill(prec_romanpots.Py());
                        h_pt_RomanPots->Fill(prec_romanpots.Perp());
                        h_pz_RomanPots->Fill(prec_romanpots.Pz());
                        h_e_RomanPots->Fill(prec_romanpots.E());
                        
                        h_rp_occupancy_map->Fill(global_hit_RP_x[iRPPart], global_hit_RP_y[iRPPart]);
                    }
                }
                
                //OMD reco tracks
                for(int iOMDPart = 0; iOMDPart < reco_OMD_px.GetSize(); iOMDPart++){
                    
                    TLorentzVector prec_omd(reco_OMD_px[iOMDPart], reco_OMD_py[iOMDPart], reco_OMD_pz[iOMDPart], reco_OMD_e[iOMDPart]);
                    
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
                
                JPsi1 = vec2 + vec3;
                
                JPsiMass1->Fill(JPsi1.M());
                
                iEvent++;
                
                flag1 = 0;
                int flag2 = 0;
                int flag3 = 0;
                int flag4 = 0;
                
                for(int rcp=0;rcp<reco_track_x.GetSize();rcp++){
                    /*if (reco_track_x.GetSize() > 2){
                        cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << recop_pdg[rcp] << endl;}*/
                    
                    //mctrk.SetXYZ(mc_px_array[imc], mc_py_array[imc], mc_pz_array[imc]);//previous
                    /*if(reco_track_x.GetSize()>4){
                        cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << reco_track_pdg[rcp] << endl;}*/
                    
                    if(reco_track_x.GetSize() == 3){
                        //cout <<"Number of Iterations: "<< rcp <<" -> Partilcles: " << reco_track_pdg[rcp] << endl;
                        //cout << "imc: " << imc << endl;
                        if(reco_track_pdg[0] != reco_track_pdg[1] && reco_track_pdg[0] != reco_track_pdg[2] && reco_track_pdg[1] != reco_track_pdg[2]){
                            
                            if(reco_track_pdg[0] == 11 && (reco_track_pdg[1] == -11 || reco_track_pdg[2] == -11)){
                                rcpv1.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                
                                rcElectron->Fill(rcpv1.Eta());
                                flag2++;
                            }
                            if(reco_track_pdg[1] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[2] == -11)){
                                rcpv1.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                
                                rcElectron->Fill(rcpv1.Eta());
                                flag2++;
                            }
                            if(reco_track_pdg[2] == 11 && (reco_track_pdg[0] == -11 || reco_track_pdg[1] == -11)){
                                rcpv1.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                
                                rcElectron->Fill(rcpv1.Eta());
                                flag2++;
                            }
                            if(reco_track_pdg[0] == -11 && (reco_track_pdg[1] == 11 || reco_track_pdg[2] == 11)){
                                rcpv2.SetXYZM(reco_track_x[0], reco_track_y[0], reco_track_z[0],reco_track_m[0]);
                                
                                rcPositron->Fill(rcpv2.Eta());
                                flag2++;
                            }
                            if(reco_track_pdg[1] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[2] == 11)){
                                rcpv2.SetXYZM(reco_track_x[1], reco_track_y[1], reco_track_z[1],reco_track_m[1]);
                                
                                rcPositron->Fill(rcpv2.Eta());
                                flag2++;
                            }
                            if(reco_track_pdg[2] == -11 && (reco_track_pdg[0] == 11 || reco_track_pdg[1] == 11)){
                                rcpv2.SetXYZM(reco_track_x[2], reco_track_y[2], reco_track_z[2],reco_track_m[2]);
                                
                                rcPositron->Fill(rcpv2.Eta());
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
                    
                    if(reco_track_x.GetSize() == 2){
                        if(reco_track_pdg[rcp] == 11 && reco_track_c[rcp] == -1){
                            rcpv1.SetXYZM(reco_track_x[rcp], reco_track_y[rcp], reco_track_z[rcp],reco_track_m[rcp]);
                            
                            rcElectron->Fill(rcpv1.Eta());
                            flag1++;
                            
                        }
                        if(reco_track_pdg[rcp] == -11 && reco_track_c[rcp] == 1){
                            rcpv2.SetXYZM(reco_track_x[rcp], reco_track_y[rcp], reco_track_z[rcp],reco_track_m[rcp]);
                            
                            rcPositron->Fill(rcpv2.Eta());
                            flag1++;
                            
                        }
                    }
                
                   
                }
                /*if (flag4 == 1){
                    JPsi2 = eq4 + rcpv2;
                    
                    rcJPsiMass1->Fill(JPsi2.M());
                }*/
                
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
                }
                
                if(flag1 == 2 && flag2 == 0 && flag3 == 0){
                    JPsi2 = rcpv1 + rcpv2;
                    
                    rcJPsiMass1->Fill(JPsi2.M());
                }
                
                int chk1 = 0;
                int chk2 = 0;
                for(int igen=0;igen<recop_px.GetSize();igen++){
                        //cout <<"Number of Iterations: "<< igen <<" -> Partilcles: " << recop_pdg[igen] << endl;
                        
                        //rcElectron->Fill(rcpv1.Eta());
                        
                        if(mc_pdg_array[3] == 2212){
                            
                            //mctrk1.RotateY(0.025);
                            mctrk1.SetXYZM(mc_px_array[3], mc_py_array[3], mc_pz_array[3],mc_mass_array[3]);
                            mctrue.SetXYZM(px[3], py[3], pz[3], E[3]);
                            chk2++;
                        }
                        
                        if(mc_pdg_array[0] == 11){
                            
                            //mctrk1.RotateY(0.025);
                            mctrk2.SetXYZM(mc_px_array[0], mc_py_array[0], mc_pz_array[0],mc_mass_array[0]);
                            
                        }
                    //if(recop_px.GetSize() == 2){cout <<"Number of Iterations: "<< igen <<" -> Partilcles: " << gen_pdg[igen] << endl;}
                        
                    //if(recop_px.GetSize() == 2){
                        if (gen_pdg[igen] == 2212){
                            
                            //genv1.RotateY(0.025);
                            genv1.SetXYZM(gen_px[igen], gen_py[igen], gen_pz[igen], gen_m[igen]);
                            chk1++;
                            
                        }
                        if (gen_pdg[igen] == 11){
                            
                            //genv1.RotateY(0.025);
                            genv3.SetXYZM(gen_px[igen], gen_py[igen], gen_pz[igen], gen_m[igen]);
                            chk1++;
                        }
                        
                        /*if(reco_RP_pdg[0] == 2212){
                            
                            //rcpv3.RotateY(0.025);
                            rcpv3.SetXYZM(reco_RP_px[0], reco_RP_py[0], reco_RP_pz[0],reco_RP_m[0]);
                            
                        }*/
                        
                        if(reco_track_pdg[igen] == 11){
                            
                            //rcpv4.RotateY(0.025);
                            rcpv4.SetXYZM(reco_track_x[igen], reco_track_y[igen], reco_track_z[igen],reco_track_m[igen]);
                            
                        }
                        
                        if(recop_pdg[igen] == -11){
                            
                            //rcpv5.RotateY(0.025);
                            rcpv5.SetXYZM(recop_px[igen], recop_py[igen], recop_pz[igen],recop_m[igen]);
                            
                        }
                    //}
                    
                }
                
                for(int inum=0;inum<EcalPPhi_x.GetSize();inum++){
                    vec7.SetXYZT(EcalPPhi_x[inum], EcalPPhi_y[inum], EcalPPhi_z[inum],EcalPPhi_t[inum]);
                }
                
                
                
                for(int iepjpsi=0;iepjpsi<EcalNPhi_x.GetSize();iepjpsi++){
                    
                    rcpv6.SetXYZ(EcalNPhi_x[iepjpsi], EcalNPhi_y[iepjpsi], EcalNPhi_z[iepjpsi]);
                    
                    ElectfJpsi->Fill(rcpv6.Phi());
                    
                }
                
                for(int iepjpsi=0;iepjpsi<EcalPPhi_x.GetSize();iepjpsi++){
                    
                    rcpv7.SetXYZT(EcalPPhi_x[iepjpsi], EcalPPhi_y[iepjpsi], EcalPPhi_z[iepjpsi], EcalPPhi_t[iepjpsi]);
                    
                    PositfJpsi->Fill(rcpv7.Phi());
                }
                
                eff->Fill((vec5.E() - mctrk.E())/mctrk.E());
                eff21->Fill((rcpv7.E() -  mctrk.E())/ mctrk.E());
                eff1[uu] = (vec5.E() - vec11.E())/vec11.E();
                ene1[uu] = vec11.E();
                eff2[uu] = (rcpv7.E() - vec11.E())/vec11.E();
                //cout << eff1[uu] <<" : " << uu << endl;
                uu++;
                
                /*if(chk1 == 2){
                    gsumifp = (mctrk1 - genv1); //sum of the initial anf final momentum
                    rsumifp = (mctrk2 - rcpv4);
                }*/
                if(chk2 == 2){
                    gsumifp = (mctrk1 - genv1); //sum of the initial anf final momentum
                    gsumifpt = (mctrue - genv1); //sum of the initial anf final momentum
                    //gsumifpt = (mctrue); //sum of the initial anf final momentum
                    rsumifp = (mctrk1 - vec5);
                    //rsumifp = (vec5);
                    rsumifpt = (mctrue - vec5);
                    
                    mtg->Fill(gsumifp.Pt()*gsumifp.Pt());
                    mtgt->Fill(gsumifpt.Pt()*gsumifpt.Pt());
                    mtr->Fill(rsumifp.Pt()*rsumifp.Pt());
                    mtrt->Fill(rsumifpt.Pt()*rsumifpt.Pt());
                    //rat->Fill((gsumifp.Pt()*gsumifp.Pt())/(gsumifp.Pt()*gsumifp.Pt()));
                }
                
                gsumifp1 = (mctrk2 - genv3);
                rsumifp1 = (mctrk2 - rcpv4);
                mQg->Fill(gsumifp1.Px()*gsumifp1.Px());
                mQr->Fill(rsumifp1.Px()*rsumifp1.Px());
                
                
                //PositfJpsi->Fill(EcalPPhi());
                
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
    cout << "uu: " << uu << endl;
    int neff1 = sizeof(eff1) / sizeof(eff1[0]);
    sort(eff1, eff1 + neff1);
    int neff2 = sizeof(eff2) / sizeof(eff2[0]);
    sort(eff2, eff2 + neff2);
    int nene1 = sizeof(ene1) / sizeof(ene1[0]);
    sort(ene1, ene1 + nene1);

    TCanvas *c1 = new TCanvas("c1","c1",800,800);
    fProton->GetXaxis()->SetTitle("#eta");
    fProton->GetXaxis()->SetRangeUser(-10,20);
    fProton->SetStats(0);
    fProton->GetYaxis()->SetTitleSize(0.03);
    //fProton->GetYaxis()->SetTitle("Final Proton");
    fProton->SetLineColor(2);//red plot
    fProton->SetLineWidth(6);
    fProton->Draw();
    
    RPfProton->SetLineColor(1);//black plot
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
    fProton->SetLineColor(2);//red plot
    fProton->SetLineWidth(6);
    fProton->Draw();
    
    RPfProton->SetLineColor(1);//black plot
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
    rcElectron->SetLineColor(2);//red plot
    rcElectron->SetLineWidth(6);
    rcElectron->Draw();
    
    TCanvas *c4 = new TCanvas("c4","c4",1000,800);
    c4->Divide(2,1);
    c4->cd(1);
    rcJPsiMass11->GetXaxis()->SetTitle("Finding");
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
    
    TCanvas *c5 = new TCanvas("c5","c5",1200,1200);
    c5->Divide(2,2);
    c5->cd(1);
    mtg->GetXaxis()->SetTitle("-t");
    mtg->GetXaxis()->SetRangeUser(0,2);
    mtg->SetStats(0);
    mtg->GetYaxis()->SetTitleSize(0.03);
    mtg->SetLineColor(1);//black plot
    //mtg->SetFillColor(kRed-9);
    mtg->SetLineWidth(6);
    mtg->Draw();
    
    mtr->SetLineColor(2);//red plot
    mtr->SetLineWidth(6);
    mtr->Draw("SAME");
    
    mtgt->SetLineColor(4);
    mtgt->SetLineWidth(6);
    mtgt->Draw("SAME");
    
    mtrt->SetLineColor(3);
    mtrt->SetLineWidth(6);
    mtrt->Draw("SAME");
    
    TLegend *leg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    leg2->AddEntry(mtg,"Generated - sm", "l");
    leg2->AddEntry(mtgt,"Generated - tr", "l");
    leg2->AddEntry(mtr, "Reconstructed - sm", "l");
    leg2->AddEntry(mtrt, "Reconstructed - tr", "l");
    leg2->Draw();
    
    c5->cd(2);
    mtg->GetXaxis()->SetTitle("-t");
    //mtg->GetXaxis()->SetRangeUser(0,2);
    mtg->SetStats(0);
    mtg->GetYaxis()->SetTitleSize(0.03);
    mtg->SetLineColor(1);//black plot
    mtg->SetLineWidth(6);
    mtg->Draw();
    
    mtgt->SetLineColor(4);
    mtgt->SetLineWidth(6);
    mtgt->Draw("SAME");
    
    TLegend *gleg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    gleg2->AddEntry(mtg,"Generated - sm", "l");
    gleg2->AddEntry(mtgt,"Generated - tr", "l");
    gleg2->Draw();
    
    c5->cd(3);
    mtr->GetXaxis()->SetTitle("-t");
    //mtr->GetXaxis()->SetRangeUser(0,2);
    mtr->SetStats(0);
    mtr->GetYaxis()->SetTitleSize(0.03);
    mtr->SetLineColor(2);//black plot
    mtr->SetLineWidth(6);
    mtr->Draw();
    
    mtrt->SetLineColor(3);
    mtrt->SetLineWidth(6);
    mtrt->Draw("SAME");
    
    TLegend *rleg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    rleg2->AddEntry(mtr, "Reconstructed - sm", "l");
    rleg2->AddEntry(mtrt, "Reconstructed - tr", "l");
    rleg2->Draw();
    
    c5->cd(4);
    mtgt->GetXaxis()->SetTitle("-t");
    //mtgt->GetXaxis()->SetRangeUser(0,2);
    mtgt->SetStats(0);
    mtgt->GetYaxis()->SetTitleSize(0.03);
    mtgt->SetLineColor(4);//black plot
    mtgt->SetLineWidth(6);
    mtgt->Draw();
    
    mtrt->SetLineColor(3);
    mtrt->SetLineWidth(6);
    mtrt->Draw("SAME");
    
    TLegend *tleg2 = new TLegend(0.6, 0.8, 0.9, 0.9);
    tleg2->AddEntry(mtgt,"Generated - tr", "l");
    tleg2->AddEntry(mtrt, "Reconstructed - tr", "l");
    tleg2->Draw();
    
    TCanvas *c7 = new TCanvas("c7","c7",800,800);
    mQg->GetXaxis()->SetTitle("Q^{2}");
    mQg->GetXaxis()->SetRangeUser(0,2);
    mQg->SetStats(0);
    mQg->GetYaxis()->SetTitleSize(0.03);
    mQg->SetLineColor(1);//black plot
    //mQg->SetFillColor(kGreen-5);
    mQg->SetLineWidth(6);
    mQg->Draw();
    
    mQr->SetLineColor(2);//red plot
    mQr->SetLineWidth(6);
    mQr->Draw("SAME");
    
    TLegend *leg3 = new TLegend(0.6, 0.8, 0.9, 0.9);
    leg3->AddEntry(mQg,"Generated - sm", "l");
    leg3->AddEntry(mQr, "Reconstructed - sm", "l");
    leg3->Draw();
    
    /*TCanvas *c6 = new TCanvas("c6","c6",800,800);
    rat->GetXaxis()->SetTitle("Ratio");
    rat->GetXaxis()->SetRangeUser(0,2);
    rat->SetStats(0);
    rat->GetYaxis()->SetTitleSize(0.03);
    rat->SetLineColor(2);//red plot
    rat->SetLineWidth(6);
    rat->Draw();*/
    
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
    h6_e_MC->GetXaxis()->SetRangeUser(220,280);
    h6_e_MC->SetStats(0);
    h6_e_MC->GetYaxis()->SetTitleSize(0.03);
    h6_e_MC->GetYaxis()->SetTitle("Energy");
    h6_e_MC->SetLineColor(2);//red plot
    h6_e_MC->SetLineWidth(6);
    h6_e_MC->Draw();
    
    h_e_OMD->SetLineColor(1);//black plot
    h_e_OMD->SetLineWidth(6);
    h_e_OMD->Draw("SAME");
    
    TLegend *leg4 = new TLegend(0.2, 0.8, 0.3, 0.9);
    leg4->AddEntry(h6_e_MC,"MC", "l");
    leg4->AddEntry(h_e_OMD, "OMD", "l");
    leg4->Draw();
    
    TCanvas *c10 = new TCanvas("c10","c10",800,800);
    h6_pt_MC->GetXaxis()->SetTitle("p_{t} [GeV/c]");
    //h6_pt_MC->GetXaxis()->SetRangeUser(220,280);
    h6_pt_MC->SetStats(0);
    h6_pt_MC->GetYaxis()->SetTitleSize(0.03);
    h6_pt_MC->GetYaxis()->SetTitle("Momentum");
    h6_pt_MC->SetLineColor(2);//red plot
    h6_pt_MC->SetLineWidth(6);
    h6_pt_MC->Draw();
    
    h_pt_OMD->SetLineColor(1);//black plot
    h_pt_OMD->SetLineWidth(6);
    h_pt_OMD->Draw("SAME");
    
    TLegend *leg5 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg5->AddEntry(h6_pt_MC,"MC", "l");
    leg5->AddEntry(h_pt_OMD, "OMD", "l");
    leg5->Draw();
    
    //cout << ene1 << endl;
    TGraph *gr = new TGraph(102000,ene1,eff1);
    TCanvas *c11 = new TCanvas("c11","c11",800,800);
    gr->SetLineColor(1);
    //gr->SetMarkerSize(1);
    //gr->GetXaxis()->SetRangeUser(200,250);
    gr->SetStats(0);
    /*gr->GetYaxis()->SetTitleSize(0.03);
    gr->GetYaxis()->SetTitle("anything");
    gr->SetLineColor(2);//red plot
    gr->SetLineWidth(6);*/
    gr->Draw("AC");
    
    TGraph *gr1 = new TGraph(102000,ene1,eff2);
    //gr1->GetXaxis()->SetRangeUser(200,250);
    gr1->SetLineColor(2);
    //gr1->SetMarkerSize(1);
    gr1->Draw("AC SAME");
    
    TLegend *leg6 = new TLegend(0.8, 0.8, 0.9, 0.9);
    leg6->AddEntry(gr,"eff1", "l");
    leg6->AddEntry(gr1, "eff2", "l");
    leg6->Draw();
    
    TCanvas *c12 = new TCanvas("c12","c12",800,800);
    eff->GetXaxis()->SetTitle();
    //eff->GetXaxis()->SetRangeUser(0,300);
    eff->SetLineColor(2);//red plot
    eff->SetLineWidth(6);
    eff->Draw();
    
    eff21->SetLineColor(1);//black plot
    eff21->SetLineWidth(6);
    eff21->Draw("SAME");
        
        return;
        


}

