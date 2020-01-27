#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ofxXmlSettings.h"

class ofApp : public ofBaseApp{

	public:
		ofxXmlSettings myXML;
		ofImage header;
		ofxDatGui* myGui;
		ofxDatGuiButton* button;
		ofxDatGuiButton* toggleHD;
		ofxDatGuiButton* toggleMCA;
		ofxDatGuiButton* toggleLL;
		ofxDatGuiTextInput* txtTitle;
		ofxDatGuiTextInput* txtProduct;
		//ofxDatGuiTextInput* txtTcIn;
		//ofxDatGuiTextInput* txtTcOut;
		ofxDatGuiTextInput* txtAgency;
		ofxDatGuiTextInput* txtProdCom;
		ofxDatGuiTextInput* txtLength;
		ofxDatGuiTextInput* txtAdvertiser;
		ofxDatGuiTextInput* txtComments;
		ofxDatGuiTextInput* txtEmail;
		ofxDatGuiTextInput* txtAdditionalFile;
		ofxDatGuiLabel* lblTcIn;
		ofxDatGuiLabel* lblTcOut;
		ofxDatGuiLabel* lblAspect;
		ofxDatGuiMatrix* mtxVersion;
		ofxDatGuiDropdown* ddAspect; 

		bool HD;
		bool MCA;
		bool LL;
		string title;
		string product;
		string aspect;
		string tcIn;
		string tcOut;
		string agency;
		string prodCom;
		string length;
		string advertiser;
		string comments;
		string email;
		string additionalFile;
		string buffer;
		int version;
		int fullWidth;
		vector<string> aspectOptions;


		void setup();
		void update();
		void draw();
		void onButtonEvent(ofxDatGuiButtonEvent b);
		void onTextInputEvent(ofxDatGuiTextInputEvent t);
		void onMatrixEvent(ofxDatGuiMatrixEvent m);
		void onDropdownEvent(ofxDatGuiDropdownEvent e);
		void keyPressed(int key);
};
