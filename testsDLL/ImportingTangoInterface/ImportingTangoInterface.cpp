// ImportingTangoInterface.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ImportingTangoInterface.h"
#include "TangoInterface.h"
#include <afxstr.h>
#include "cstringt.h"
#include "testing.h"
#include "string.h"
#include "stdio.h"
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.

		testing test;
		char option;
		int direction;
		string input;
		string motor, attrib, vars;
		double posit;
		int vari;
		double varf;
		bool varb;

		test.PrintMenu();
		getline(cin, input);
		option = input[0];
		
		while(option != 'q')
		{
			switch(option)
			{
			case 'a': 
				test.ErrorMessage(); 
				cout << "Press any key to continue ..." << endl;
				break;
			case 'b': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid speed for the motor:\n";
				getline(cin, input);
				posit = test.ReciveDouble(input);
				cout << "Setting motor: " << motor.c_str() << ", to velocity: " << posit << endl;
				test.MotorSpeed(CString(motor.c_str()), posit);
				cout << endl;
				break;
			case 'c': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid position to move:\n";
				getline(cin, input);
				posit = test.ReciveDouble(input);
				cout << "Move motor: " << motor.c_str() << ", to pos: " << posit << endl;
				//printf("Move motor: %s, to pos: %d\n", motor.c_str(), posit);
				test.MotorPosition(CString(motor.c_str()),posit);
				cout << endl;
				break;
			case 'd': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				test.PrintJogInfo();
				getline(cin, input);
				varb = test.ReciveBoolean(input);
				test.JogMotor(CString(motor.c_str()),varb);
				cout << endl;
				break;
			case 'e': 
				test.EnableMotor();
				cout << endl;
				break;
			case 'f': 
				test.GetHomingStatus();
				cout << endl;
				break;
			case 'g': 
				test.Home();
				cout << endl;
				break;
			case 'h': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid variable:\n";
				getline(cin, vars);
				cout << "Motor: " << motor.c_str() << ", Variable: " << vars.c_str() ;
				
				//printf("Motor: %s, variable: %s\n", motor.c_str(), vars.c_str());
				test.VariableStr(CString(motor.c_str()), CString(vars.c_str()));
				cout << endl;
				break;
			case 'i': 
				cout << "Please enter a valid variable name (deviceserver/attr):\n";
				getline(cin, motor);
				cout << "Please enter a value:\n";
				getline(cin, input);
				vari = test.ReciveInt(input);
				cout << "Variable: " << motor.c_str() << ", value: " << vari << endl;
				//printf("Variable: %s, value: %d\n", motor.c_str(), vari);
				test.VariableInt(CString(motor.c_str()), vari);
				cout << endl;
				break;
			case 'j': 
				cout << "Please enter a valid motor name (deviceserver/attr):\n";
				getline(cin, motor);
				cout << "Please enter a value:\n";
				getline(cin, input);
				varf = test.ReciveDouble(input);
				cout << "Value: " << motor.c_str() << ", value: " << varf << endl;
				//printf("Value: %s, value: %f\n", motor.c_str(), varf);
				test.VariableFloat(CString(motor.c_str()), varf);
				cout << endl;
				break;
			case 'k': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a value:\n";
				getline(cin, input);
				varb = test.ReciveBoolean(input);
				cout << "Motor: " << motor.c_str() << ", variable: " << varb << endl;
				//printf("Motor: %s, variable: %s\n", motor.c_str(), (varb)?"true":"false");
				test.VariableBool(CString(motor.c_str()), varb);
				cout << endl;
				break;
			case 'l': 
				cout << "Please enter a valid motor name: \n";
				getline(cin, motor);
				cout << "Please enter a valid attribute: \n";
				getline(cin, attrib);
				cout << "Please enter a value:\n";
				getline(cin, input);
				varf = test.ReciveDouble(input);
				cout << "Motor: " << motor.c_str() << ", Attribute: " << attrib.c_str() << ", value: " << varf << endl;
				test.MotorVariableFloat(CString(motor.c_str()), CString(attrib.c_str()), varf);
				cout << endl;
				break;
			case 'm': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid attribute: \n";
				getline(cin, attrib);
				cout << "Please enter a value:\n";
				getline(cin, input);
				vari = test.ReciveInt(input);
				cout << "Motor: " << motor.c_str() << ", Attribute: " << attrib.c_str() << ", value: " << vari << endl;
				test.MotorVariableInt(CString(motor.c_str()), CString(attrib.c_str()) , vari);
				cout << endl;
				break;
			case 'n': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid attribute: \n";
				getline(cin, attrib);
				cout << "Motor: " << motor.c_str() << ", Attribute: " << attrib.c_str() << endl;
				//printf("Value: %s, value: %f\n", motor.c_str(), varf);
				test.MotorVariableString(CString(motor.c_str()), CString(attrib.c_str()));
				cout << endl;
				break;
			case 'o': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				cout << "Please enter a valid attribute: \n";
				getline(cin, attrib);
				cout << "Please enter a value:\n";
				getline(cin, input);
				varb = test.ReciveBoolean(input);
				cout << "Motor: " << motor.c_str() << ", Attribute: " << attrib.c_str() << ", value: " << varb << endl;
				//printf("Value: %s, value: %f\n", motor.c_str(), varf);
				test.MotorVariableBool(CString(motor.c_str()), CString(attrib.c_str()), varb);
				cout << endl;
				break;
			case 'p': 
				cout << "Please enter a valid motor name:\n";
				getline(cin, motor);
				test.GetMotorAttributeStrings(CString(motor.c_str()));
				cout << endl;
				break;
			case 'q': 
				test.PrintExit();
				cout << endl;
				break;
			case 'r':
				//cin >> input;
				//cin >> varb;
				int myNumber;
				cout << "Please introduce a number:\n" << endl;
				getline(cin, input);
				myNumber = test.ReciveInt(input);
				cout << "Your number is:" << myNumber << endl;
				//stringstream myStream(input);
				//if (myStream >> myNumber) cout << "The value introduced is:" << myNumber << endl;
				//else break;

				//printf("Molto beneee!!\n");
				//printf("Value introduced: %s", (varb)?"true":"false");
				//printf("This is the value: %s\n", input.c_str());
				//input +="/Velocity";
				//printf("This is the SECOND value: %s\n", input.c_str());
				//getchar();
				break;
			default: 
				cout << "Please select a valid option.\n" << endl;
			}
			cout << "Please press RETURN to continue ..." << endl;
			getline(cin, input);
			test.PrintMenu();
			getline(cin, input);
			option = input[0];
		}
	}

	return nRetCode;
}
