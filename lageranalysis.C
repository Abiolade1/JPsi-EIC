
void lageranalysis(){
	
	//read teh lAger tree
	TChain *T = new TChain("lAger");
	T->Add("lager-vmp-00mrad.jpsi-18on275.4pi.disp-jpsi-00-electron.run00001-lumi1.root");

	//Read different variables
	Int_t evgen;
	Float_t W, Q2, nu, x, y, epsilon, R, t, xv;
	Short_t n_part;
	Int_t size1 = 20;
	Double_t fPx[size1],fPy[size1],fPz[size1], fE[size1];
	Int_t PDG[size1];

	T->SetBranchAddress("evgen",&evgen);
	T->SetBranchAddress("W",&W);
	T->SetBranchAddress("Q2",&Q2);
	T->SetBranchAddress("nu",&nu);
	T->SetBranchAddress("x",&x);
	T->SetBranchAddress("y",&y);
	T->SetBranchAddress("epsilon",&epsilon);
	T->SetBranchAddress("R",&R);
	T->SetBranchAddress("t",&t);
	T->SetBranchAddress("xv",&xv);

	//Reading variables in particles
	T->SetBranchAddress("n_part", &n_part);
	T->SetBranchAddress("particles.fPdgCode", &PDG[n_part]);
	T->SetBranchAddress("particles.fPx", &fPx[n_part]);
	T->SetBranchAddress("particles.fPy", &fPy[n_part]);
	T->SetBranchAddress("particles.fPz", &fPz[n_part]);
	T->SetBranchAddress("particles.fE", &fE[n_part]);
    
	Int_t Nevents = T->GetEntries();
    //cout << "Nevents = " << Nevents << endl;
	TLorentzVector vec1(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec2(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec3(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec4(10.0, 20.0, 30.0, 40.0);
    TLorentzVector vec5(10.0, 20.0, 30.0, 40.0);
    
    TLorentzVector JPsi1(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi2(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi3(10.0, 20.0, 30.0, 40.0);
    TLorentzVector JPsi4(10.0, 20.0, 30.0, 40.0);

    //TH1D *Jpsieta = new TH1D("Jpsieta","Jpsieta", 100, -5, 5);
    TH1F *Electroneta = new TH1F("Electroneta","e", 1000, -7, 7);
    TH1F *Protoneta = new TH1F("Protoneta","p'", 1000, -50, 50);
    TH1F *Positroneta = new TH1F("Positroneta","e^{+}", 1000, -7, 7);
    TH1F *fElectron = new TH1F("fElectron","e'", 1000, -20, 2);
    TH1F *iProtoneta = new TH1F("iProtoneta","p", 1000, -10, 10);
    
    TH1F *JPsiMass1 = new TH1F("JPsiMass1","J/#psi-Mass", 1000, 2.5, 3.5);
    TH1F *JPsiMass2 = new TH1F("JPsiMass2","J/#psi-Mass", 1000, -1, 200);
    TH1F *JPsiMass3 = new TH1F("JPsiMass3","J/#psi-Mass", 1000, -1,200);
    TH1F *JPsiMass4 = new TH1F("JPsiMass4","J/#psi-Mass", 1000, -1, 200);
    
    TH1F *tElectron = new TH1F("tElectron","Transverse Momentum of e", 200, -25, 25);
    TH1F *tPositron = new TH1F("tPositron","Transverse Momentum of e^{+}", 200, -25, 25);
    TH1F *tProton = new TH1F("tProton","Transverse Momentum of p'", 200, -100, 100);
    TH1F *tfElectron = new TH1F("tfElectron","Transverse Momentum of e'", 200, -25, 25);
    
    TH1F *lElectron = new TH1F("lElectron","Z Momentum of e", 200, -250, 250);
    TH1F *lPositron = new TH1F("lPositron","Z Momentum of e^{+}", 200, -250, 250);
    TH1F *lProton = new TH1F("lProton","Z Momentum of p'", 200, -275, 500);
    TH1F *lfElectron = new TH1F("lfElectron","Z Momentum of e'", 200, -250, 250);
    
    TH1F *tt = new TH1F("tt","-t", 500, -10, 10);
    TH1F *QQ2 = new TH1F("QQ2","Q^{2}", 500, -5, 10);
    TH1F *xxv = new TH1F("xxv","x_{v}", 500, -0.1, 0.3);

	//loop in events of lAger
	for(int l=0; l < Nevents; l++){
		T->GetEntry(l);
		
		//cout << "====================================================" << endl;
		// PDF numbers http://pdg.ge.infn.it/2020/reviews/rpp2020-rev-monte-carlo-numbering.pdf
		// 2212 -> Proton
		// 11 -> Electron
		// 22 -> Photon
		// 4 -> Charm quark
		// -11 -> positron
		// 443 -> J/Psi
		// 0 -> 
		//cout << "Number particles in this event: " << n_part << endl;
		//cout<< "Type of Particles in this event:" << endl;
        //cout<< "Momentum_particles(0): " << fPx[0] << " " << fPy[0] << " " << fPz[0] << endl;
		for (Int_t j = 0; j < n_part; j++)
        {
			//cout << "Particle " << j << ": "  << PDG[j]<< endl ;
            //eta restriction to calculate eta
			//if (PDG[j] == 443)
            //{
				//vec1.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
				//Jpsieta->Fill(vec1.Eta());
			//}
            if (j == 8)
            {
                vec1.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
                Electroneta->Fill(vec1.Eta());
            }
            if (j == 6)
            {
                vec2.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
                Protoneta->Fill(vec2.Eta());
            }
            if (j == 7)
            {
                vec3.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
                Positroneta->Fill(vec3.Eta());
            }
            if (j == 4)
            {
                vec4.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
                fElectron->Fill(vec4.Eta());
            }
            if (j == 1)
            {
                vec4.SetPxPyPzE(fPx[j], fPy[j], fPz[j], fE[j]);
                iProtoneta->Fill(vec5.Eta());
            }
		}
        
        JPsi1 = vec1 + vec3;
        JPsi2 = vec1 + vec4;
        JPsi3 = vec1 + vec2;
        JPsi4 = vec2 + vec4;
        
        JPsiMass1->Fill(JPsi1.M());
        JPsiMass2->Fill(JPsi2.M());
        JPsiMass3->Fill(JPsi3.M());
        JPsiMass4->Fill(JPsi4.M());
        
        //For the transverse components of the mementum
        tElectron->Fill(vec1.Pt());
        tPositron->Fill(vec3.Pt());
        tProton->Fill(vec2.Pt());
        tfElectron->Fill(vec4.Pt());
        
        //For the longitudinal components of the mementum
        lElectron->Fill(vec1.Pz());
        lPositron->Fill(vec3.Pz());
        lProton->Fill(vec2.Pz());
        lfElectron->Fill(vec4.Pz());
        
        tt->Fill(t*(-1));
        QQ2->Fill(Q2);
        xxv->Fill(xv);

	}
    
	TCanvas *c1 = new TCanvas("c1","c1",800,800);
    c1->Divide(2,2);
    c1->cd(1); Electroneta->GetXaxis()->SetTitle("#eta");
    Electroneta->GetYaxis()->SetTitleSize(0.03);
    //Electroneta->GetYaxis()->SetTitle("Count");
    Electroneta->SetStats(0);
    Electroneta->Draw();
    c1->cd(2); Positroneta->GetXaxis()->SetTitle("#eta");
    Positroneta->GetYaxis()->SetTitleSize(0.03);
    //Positroneta->GetYaxis()->SetTitle("Count");
    //c1->cd(2); Protoneta->GetXaxis()->SetRangeUser(4.1,4.7);
    Positroneta->SetStats(0);
    Positroneta->Draw();
    //c1->cd(3); Positroneta->GetXaxis()->SetTitle("#eta");
    //Positroneta->Draw();
    c1->cd(3); Protoneta->GetXaxis()->SetTitle("#eta");
    Protoneta->GetYaxis()->SetTitleSize(0.03);
    //Protoneta->GetYaxis()->SetTitle("Count");
    c1->cd(3); Protoneta->GetXaxis()->SetRangeUser(5,12);
    Protoneta->SetStats(0);
    Protoneta->Draw();
    c1->cd(4); fElectron->GetXaxis()->SetTitle("#eta");
    fElectron->GetYaxis()->SetTitleSize(0.03);
    //fElectron->GetYaxis()->SetTitle("Count");
    fElectron->SetStats(0);
    fElectron->Draw();
    
    TCanvas *c2 = new TCanvas("c2","c2",800,800);
    c2->Divide(1,1);
    c2->cd(1);
    JPsiMass1->GetYaxis()->SetTitleSize(0.03);
    //JPsiMass1->GetYaxis()->SetTitle("v1+v3-Count");
    JPsiMass1->GetXaxis()->SetRangeUser(2.8,3.3);
    JPsiMass1->SetStats(0);
    JPsiMass1->Draw();
    c2->cd(2);
    JPsiMass2->GetYaxis()->SetTitleSize(0.03);
    JPsiMass2->GetYaxis()->SetTitle("v1+v4-(GeV)");
    JPsiMass2->GetXaxis()->SetRangeUser(-0.1,75);
    JPsiMass2->SetStats(0);
    //JPsiMass2->Draw();
    c2->cd(3);
    JPsiMass3->GetYaxis()->SetTitleSize(0.03);
    JPsiMass3->GetYaxis()->SetTitle("v1+v2-Count");
    JPsiMass3->GetXaxis()->SetRangeUser(-0.1,150);
    JPsiMass3->SetStats(0);
    //JPsiMass3->Draw();
    c2->cd(4);
    JPsiMass4->GetYaxis()->SetTitleSize(0.03);
    JPsiMass4->GetYaxis()->SetTitle("v2+v4-Count");
    JPsiMass4->GetXaxis()->SetRangeUser(25,150);
    JPsiMass4->SetStats(0);
    //JPsiMass4->Draw();
    
    TCanvas *c3 = new TCanvas("c3","c3",800,800);
    iProtoneta->GetXaxis()->SetTitle("#eta");
    iProtoneta->GetXaxis()->SetRangeUser(0,2);
    iProtoneta->SetStats(0);
    iProtoneta->GetYaxis()->SetTitleSize(0.03);
    iProtoneta->GetYaxis()->SetTitle("Count");
    iProtoneta->Draw();
    
    TCanvas *c4 = new TCanvas("c4","c4",800,800);
    c4->Divide(2,2);
    c4->cd(1);
    tElectron->GetXaxis()->SetTitle("P_{T}");
    tElectron->GetXaxis()->SetRangeUser(-1,5);
    tElectron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    tElectron->Draw();
    c4->cd(2);
    tPositron->GetXaxis()->SetTitle("P_{T}");
    tPositron->GetXaxis()->SetRangeUser(-1,5);
    tPositron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    tPositron->Draw();
    c4->cd(3);
    tProton->GetXaxis()->SetTitle("P_{T}");
    tProton->GetXaxis()->SetRangeUser(-1,3);
    tProton->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    tProton->Draw();
    c4->cd(4);
    tfElectron->GetXaxis()->SetTitle("P_{T}");
    tfElectron->GetXaxis()->SetRangeUser(-1,5);
    tfElectron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    tfElectron->Draw();
    
    TCanvas *c5 = new TCanvas("c5","c5",800,800);
    c5->Divide(2,2);
    c5->cd(1);
    lElectron->GetXaxis()->SetTitle("P_{Z}");
    lElectron->GetXaxis()->SetRangeUser(-25,60);
    lElectron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    lElectron->Draw();
    c5->cd(2);
    lPositron->GetXaxis()->SetTitle("P_{Z}");
    lPositron->GetXaxis()->SetRangeUser(-25,60);
    lPositron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    lPositron->Draw();
    c5->cd(3);
    lProton->GetXaxis()->SetTitle("P_{Z}");
    lProton->GetXaxis()->SetRangeUser(190,290);
    lProton->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    lProton->Draw();
    c5->cd(4);
    lfElectron->GetXaxis()->SetTitle("P_{Z}");
    lfElectron->GetXaxis()->SetRangeUser(-25,5);
    lfElectron->SetStats(0);
    //Protoneta->GetYaxis()->SetTitleSize(0.03);
    //iProtoneta->GetYaxis()->SetTitle("Count");
    lfElectron->Draw();
    
	//Jpsieta ->GetXaxis()->SetTitle("#eta");
	//Jpsieta ->Draw();
    
    //TFile *input = new TFile("lager-vmp-25mrad.jpsi-18on275.4pi.disp-jpsi-00-electron-lumi1.root", "read");
    //TTree *lAger = (TTree*)input->Get("lAger");
    TCanvas *c6 = new TCanvas("c6","c6",800,800);
    c6->Divide(2,2);
    c6->cd(1);
    tt->SetStats(0);
    tt->GetXaxis()->SetRangeUser(-0.1,1.7);
    tt->Draw();
    c6->cd(2);
    QQ2->SetStats(0);
    QQ2->GetXaxis()->SetRangeUser(-0.1,1);
    QQ2->Draw();
    c6->cd(3);
    xxv->SetStats(0);
    xxv->GetXaxis()->SetRangeUser(-0.01,0.15);
    xxv->Draw();
	
}

