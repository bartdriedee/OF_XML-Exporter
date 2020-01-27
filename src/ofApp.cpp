#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	#ifdef __APPLE__
		ofSetDataPathRoot("../Resources/Data/");
	#endif

	ofSetWindowTitle("XLM-exporter");
    ofSetEscapeQuitsApp(false);
    
	fullWidth = ofGetWidth();
	ofLog(OF_LOG_NOTICE) << fullWidth;
	HD = true;
	MCA = false;
	LL = false;
	title = "";
	product = "";
	aspectOptions = { "12F12", "14L12", "16L12", "16F16", "14P16", "12P16" };
	aspect = "16F16";
	tcIn = "00:00:00:00";
	tcOut = "00:00:00:00";
	prodCom = "My Production Company";
	comments = "nvt";
	email = "info@Company.com; xml@company.com;";
	length = "0";
	version = 1;
	additionalFile = "nvt";
	buffer = "";

	header.load("Header.jpg");

	button = new ofxDatGuiButton("Create XML");
	button->setTheme(new ofxDatGuiThemeSmoke());
	button->setWidth(fullWidth/3);
	button->setPosition(fullWidth / 3, 425);
	button->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	button->onButtonEvent(this, &ofApp::onButtonEvent);

	toggleHD = new ofxDatGuiToggle("HD", HD);
	toggleHD->setTheme(new ofxDatGuiThemeSmoke());
	toggleHD->setWidth(fullWidth/3);
	toggleHD->setPosition(0, 325);
	toggleHD->onButtonEvent(this, &ofApp::onButtonEvent);

	toggleMCA = new ofxDatGuiToggle("MultiChannelAudio", MCA);
	toggleMCA->setTheme(new ofxDatGuiThemeSmoke());
	toggleMCA->setWidth(fullWidth/3);
	toggleMCA->setPosition(fullWidth/3, 325);
	toggleMCA->onButtonEvent(this, &ofApp::onButtonEvent);
	
	toggleLL = new ofxDatGuiToggle("LowLoudness", LL);
	toggleLL->setTheme(new ofxDatGuiThemeSmoke());
	toggleLL->setWidth(fullWidth/3);
	toggleLL->setPosition((fullWidth/3)*2, 325);
	toggleLL->onButtonEvent(this, &ofApp::onButtonEvent);

	txtTitle = new ofxDatGuiTextInput("Title", "Type title here");
	txtTitle->setTextUpperCase(false);
	txtTitle->setTheme(new ofxDatGuiThemeSmoke());
	txtTitle->setWidth(fullWidth, fullWidth / 3);
	txtTitle->setPosition(0, 50);
	txtTitle->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtAdvertiser = new ofxDatGuiTextInput("Advertiser", "Type advertiser here");
	txtAdvertiser->setTheme(new ofxDatGuiThemeSmoke());
	txtAdvertiser->setWidth(fullWidth, fullWidth / 3);
	txtAdvertiser->setPosition(0, 100);
	txtAdvertiser->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtProduct = new ofxDatGuiTextInput("Product", "Type productname here");
	txtProduct->setTheme(new ofxDatGuiThemeSmoke());
	txtProduct->setWidth(fullWidth, fullWidth / 3);
	txtProduct->setPosition(0, 75);
	txtProduct->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtAdditionalFile = new ofxDatGuiTextInput("Additional file", additionalFile);
	txtAdditionalFile->setTheme(new ofxDatGuiThemeSmoke());
	txtAdditionalFile->setWidth(fullWidth, fullWidth / 3);
	txtAdditionalFile->setPosition(0, 350);
	txtAdditionalFile->onTextInputEvent(this, &ofApp::onTextInputEvent);

	mtxVersion = new ofxDatGuiMatrix("Version", 12, true);
	mtxVersion->setTheme(new ofxDatGuiThemeSmoke());
	mtxVersion->setWidth(fullWidth, fullWidth / 3);
	mtxVersion->setPosition(0, 300);
	mtxVersion->setRadioMode(true);
	mtxVersion->onMatrixEvent(this, &ofApp::onMatrixEvent);

	lblAspect = new ofxDatGuiLabel("Aspect      (default = 16F16)   ");
	lblAspect->setTheme(new ofxDatGuiThemeSmoke());
	lblAspect->setWidth(fullWidth / 3);
	lblAspect->setPosition(0, 225);

	ddAspect = new ofxDatGuiDropdown("Please select",aspectOptions);
	ddAspect->setTheme(new ofxDatGuiThemeSmoke());
	ddAspect->setWidth((fullWidth/3)*2);
	ddAspect->setPosition(fullWidth / 3, 225);
	ddAspect->onDropdownEvent(this, &ofApp::onDropdownEvent);

	//txtTcIn = new ofxDatGuiTextInput("TcIn", tcIn);
	//txtTcIn->setWidth(fullWidth, fullWidth / 3);
	//txtTcIn->setPosition(0, 200);
	//txtTcIn->onTextInputEvent(this, &ofApp::onTextInputEvent);
	lblTcIn = new ofxDatGuiLabel("TC In = " + tcIn);
	lblTcIn->setTheme(new ofxDatGuiThemeSmoke());
	lblTcIn->setWidth(fullWidth/3);
	lblTcIn->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	lblTcIn->setPosition(fullWidth / 3, 275);

	//txtTcOut = new ofxDatGuiTextInput("TcOut", tcOut);
	//txtTcOut->setWidth(fullWidth, fullWidth / 3);
	//txtTcOut->setPosition(0, 225);
	//txtTcOut->onTextInputEvent(this, &ofApp::onTextInputEvent);
	lblTcOut = new ofxDatGuiLabel("TC Out = " + tcOut);
	lblTcOut->setTheme(new ofxDatGuiThemeSmoke());
	lblTcOut->setWidth(fullWidth / 3);
	//lblTcOut->setLabelAlignment(ofxDatGuiAlignment::CENTER);
	lblTcOut->setPosition((fullWidth / 3)*2, 275);

	txtAgency = new ofxDatGuiTextInput("Agency", "Type Agency name here");
	txtAgency->setTheme(new ofxDatGuiThemeSmoke());
	txtAgency->setWidth(fullWidth, fullWidth / 3);
	txtAgency->setPosition(0, 125);
	txtAgency->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtComments = new ofxDatGuiTextInput("Comments", comments);
	txtComments->setTheme(new ofxDatGuiThemeSmoke());
	txtComments->setWidth(fullWidth, fullWidth / 3);
	txtComments->setPosition(0, 375);
	txtComments->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtProdCom = new ofxDatGuiTextInput("Production Company", prodCom);
	txtProdCom->setTheme(new ofxDatGuiThemeSmoke());
	txtProdCom->setWidth(fullWidth, fullWidth / 3);
	txtProdCom->setPosition(0, 150);
	txtProdCom->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtEmail = new ofxDatGuiTextInput("Email Confirmation", email);
	txtEmail->setTheme(new ofxDatGuiThemeSmoke());
	txtEmail->setWidth(fullWidth, fullWidth / 3);
	txtEmail->setPosition(0, 175);
	txtEmail->onTextInputEvent(this, &ofApp::onTextInputEvent);

	txtLength = new ofxDatGuiTextInput("Length", length);
	txtLength->setTheme(new ofxDatGuiThemeSmoke());
	txtLength->setWidth(fullWidth, fullWidth / 3);
	txtLength->setPosition(0, 250);
	txtLength->setInputType(ofxDatGuiInputType::NUMERIC);
	txtLength->onTextInputEvent(this, &ofApp::onTextInputEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
	button->update();
	toggleHD->update();
	toggleMCA->update();
	toggleLL->update();
	txtTitle->update();
	txtAdvertiser->update();
	txtProduct->update();
	mtxVersion->update();
	ddAspect->update();
	//txtTcIn->update();
	//txtTcOut->update();
	txtProdCom->update();
	txtAgency->update();
	txtComments->update();
	txtLength->update();
	txtEmail->update();
	txtAdditionalFile->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(52, 59, 65);
	header.draw(0, 0);
	button->draw();
	toggleHD->draw();
	toggleMCA->draw();
	toggleLL->draw();
	txtTitle->draw();
	txtAdvertiser->draw();
	txtProduct->draw();
	mtxVersion->draw();
	//txtTcIn->draw();
	//txtTcOut->draw();
	lblTcIn->draw();
	lblTcOut->draw();
	lblAspect->draw();
	txtAgency->draw();
	txtProdCom->draw();
	txtLength->draw();
	txtComments->draw();
	txtEmail->draw();
	txtAdditionalFile->draw();
	ddAspect->draw();
}

//--------------------------------------------------------------
void ofApp::onButtonEvent(ofxDatGuiButtonEvent b) {
	if (b.target == button) {
		ofLog(OF_LOG_NOTICE) << "Export button pressed";
		//doSomething
		if ((title != "") && (product!="") && (advertiser != "") && (agency != "") && (std::stoi(length)>0)){
			string path = ofFilePath::getUserHomeDir();
			myXML.loadFile("CleanXML.xml");
			myXML.setValue("COMMERCIAL_DETAILS:TITLE", title);
			myXML.setValue("COMMERCIAL_DETAILS:PRODUCT", product);
			myXML.setValue("COMMERCIAL_DETAILS:VERSION", version);
			myXML.setValue("COMMERCIAL_DETAILS:ADVERTISER", advertiser);
			myXML.setValue("COMMERCIAL_DETAILS:LENGTH", length);
			myXML.setValue("COMMERCIAL_DETAILS:TC_IN", tcIn);
			myXML.setValue("COMMERCIAL_DETAILS:TC_OUT", tcOut);
			myXML.setValue("COMMERCIAL_DETAILS:ASPECT_RATIO", aspect);
			myXML.setValue("COMMERCIAL_DETAILS:AGENCY", agency);
			myXML.setValue("COMMERCIAL_DETAILS:PRODUCTION_COMPANY", prodCom);
			myXML.setValue("COMMERCIAL_DETAILS:ADDITIONAL_FILE_001", additionalFile);
			myXML.setValue("COMMERCIAL_DETAILS:COMMENTS", comments);
			myXML.setValue("COMMERCIAL_DETAILS:EMAIL_CONFIRMATION", email);
			string sHD;
			if (HD) { sHD = "TRUE"; }
			else { sHD = "FALSE"; }
			string sMCA;
			if (MCA) { sMCA = "TRUE"; }
			else { sMCA = "FALSE"; }
			string sLL;
			if (LL) { sLL = "TRUE"; }
			else { sLL = "FALSE"; }
			myXML.setValue("COMMERCIAL_DETAILS:HD", sHD);
			myXML.setValue("COMMERCIAL_DETAILS:MULTI_CHANNEL_AUDIO", sMCA);
			myXML.setValue("COMMERCIAL_DETAILS:LOW_LOUDNESS_LEVEL", sLL);
			myXML.save(path + "/Desktop/myXML.xml");
			ofLog(OF_LOG_NOTICE) << "XML exported to:  " << path<<"/Desktop"<<endl;
		}
	}
	else if (b.target == toggleHD) {
		HD = !HD;
		ofLog(OF_LOG_NOTICE) << "Toggle switched. HD is now " << HD ;
	}
	else if (b.target == toggleMCA) {
		MCA = !MCA;
		ofLog(OF_LOG_NOTICE) << "Toggle switched. MCA is now " << MCA;
	}
	else if (b.target == toggleLL) {
		LL = !LL;
		ofLog(OF_LOG_NOTICE) << "Toggle switched. LL is now " << LL;;

	}
}

//--------------------------------------------------------------
void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent t) {
	if (t.target->getLabel() == "Title") {
		title = t.text;
		ofLog(OF_LOG_NOTICE) << "Title = " << title << endl;
	}
	else if (t.target->getLabel() == "Advertiser") {
		advertiser = t.text;
		ofLog(OF_LOG_NOTICE) << "Advertiser = " << advertiser << endl;
	}
	else if (t.target->getLabel() == "Product") {
		product = t.text;
		ofLog(OF_LOG_NOTICE) << "Product = " << product << endl;
	}
	else if (t.target->getLabel() == "Additional file") {
		additionalFile = t.text;
		ofLog(OF_LOG_NOTICE) << "Additional file = " << additionalFile << endl;
	}
	/*
	else if (t.target->getLabel() == "TcIn") {
		tcIn = t.text;
		ofLog(OF_LOG_NOTICE) << "TimeCode In = " << tcIn << endl;
	}
	else if (t.target->getLabel() == "TcOut") {
		tcOut = t.text;
		ofLog(OF_LOG_NOTICE) << "TimeCode Out = " << tcOut << endl;
	}
	*/
	else if (t.target->getLabel() == "Agency") {
		agency = t.text;
		ofLog(OF_LOG_NOTICE) << "The agency = " << agency << endl;
	}
	else if (t.target->getLabel() == "Production Company") {
		prodCom = t.text;
		ofLog(OF_LOG_NOTICE) << "The ProdCom = " << prodCom << endl;
	}
	else if (t.target->getLabel() == "Comments") {
		comments = t.text;
		ofLog(OF_LOG_NOTICE) << "Comments: " << comments << endl;
	}
	else if (t.target->getLabel() == "Email Confirmation") {
		email = t.text;
		ofLog(OF_LOG_NOTICE) << "Email confirmation should be send to: " << email << endl;
	}
	else if (t.target->getLabel() == "Length") {
		length = t.text;
		int iLength = std::stoi(length);
		if (iLength > 0) {
			int hours = (iLength-1) / 3600;
			int mins = ((iLength-1) - (hours * 3600)) / 60;
			int secs = ((iLength -1) - ((hours * 3600) + (mins * 60)));
			string sFrames = "24";
			if (secs < 1) {sFrames = "00"; }

			std::ostringstream oSSHours;
			std::ostringstream oSSMins;
			std::ostringstream oSSSecs;

			oSSHours << setw(2) << setfill('0') << (hours);
			string sHours = oSSHours.str();
			oSSMins << setw(2) << setfill('0') << (mins);
			string sMins = oSSMins.str();
			oSSSecs << setw(2) << setfill('0') << (secs);
			string sSecs = oSSSecs.str();

			tcOut = sHours + ":" + sMins + ":" + sSecs +":"+ sFrames;
			lblTcOut->setLabel("TimeCode Out = " + tcOut);
		}
		ofLog(OF_LOG_NOTICE) << "The length = " << length <<" new TCOut = "<< tcOut << endl;
	}
}

//--------------------------------------------------------------
void ofApp::onMatrixEvent(ofxDatGuiMatrixEvent m) {
	if (m.target->getLabel() == "Version") {
		version = m.child + 1;
		ofLog(OF_LOG_NOTICE) << "the version = " << version << endl;
	}
}

//--------------------------------------------------------------
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e) {
	aspect = aspectOptions[e.child];
	ofLog(OF_LOG_NOTICE) << aspect << " was selected " << endl;
	
}

void ofApp::keyPressed(int key) {
		ofLog(OF_LOG_NOTICE) << key << " was selected " << endl;
}