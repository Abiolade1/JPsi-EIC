void generateFileList(){

	ofstream outputFile("olaiya_file_list.list");


	for(int iFile = 0; iFile < 51; iFile++){
         outputFile << Form("reco_LAGER_Olaiya_5_28_2024_file_%d.eicrecon.root", iFile) << endl;
	}


	outputFile.close();




}
