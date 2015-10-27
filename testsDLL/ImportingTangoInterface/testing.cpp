#include "stdafx.h"
#include "testing.h"
#include <sstream>

testing::testing(void)
{
}
testing::~testing(void)
{
}
void testing::ErrorMessage(void)
{
	cout << "-------------TESTING GetErrorMessage-------------------" << endl;
	//printf("-------------TESTING GetErrorMessage-------------------\n");

	//CString strMotorIdentifier = "motor/DummyMtrCtrl/1";
	CString strErrorMessage;
	interf.GetErrorMessage(strErrorMessage);
	//printf("%s\n", strErrorMessage);
	cout << "Error message: " << strErrorMessage << endl ;
	cout << "-------------------------------------------------------" << endl;
	//printf("-------------------------------------------------------\n");
}
void testing::MotorSpeed(CString strMotorIdentifier, float fValue)
{
	//printf("-------------TESTING GET/SET MOTOR SPEED---------------\n");
	cout << "-------------TESTING GET/SET MOTOR SPEED---------------\n";
	//CString strMotorIdentifier = "motor/DummyMtrCtrl/1";
	CString	str = strMotorIdentifier + CString("/Velocity");
	//CString strMotorIdentifier = "motor01";
	//CString str = "motor01/Velocity";
	//float fValue = 1000;
	//strMotorIdentifier += "/Velocity";
	float readValue = 0;

	//printf("readValue before executing functions: %f\n", readValue);
	cout << "readValue before executing functions:\n" << readValue << endl;
	cout << "MotorIdentifier: " << strMotorIdentifier << " Value to set: "<< fValue << endl;
	//printf("MotorIdentifier: %s, Value to set: %f\n", strMotorIdentifier, fValue);
	interf.SetMotorSpeed(strMotorIdentifier, fValue);
	interf.GetVariableFloat(str, readValue);
	//printf("readValue after executing functions: %f\n", readValue);
	cout << "readValue after executing functions: \n"<< readValue << endl;
	cout << "-------------------------------------------------------" << endl;
	//printf("-------------------------------------------------------\n");
}
void testing::MotorPosition(CString strMotorIdentifier, float fValue)
{
	cout << "-------------TESTING GET/SET MOVE & READ POSITION-------------" << endl;
	//printf("-------------TESTING GET/SET MOVE & READ POSITION-------------\n");

	//CString strMotorIdentifier = "motor/DummyMtrCtrl/1";
	//strMotorIdentifier = "motor/SimuMotor_Ctrl/1";
	//float fValue = 0;
	//printf("Position before executing functions: %f \n", fValue);
	cout << "Position before executing functions: " << fValue << endl;
	//printf("Value to set: %f\n", fValue);
	cout << "Value to set: " << fValue << endl;
	interf.MoveMotor(strMotorIdentifier, fValue);
	interf.GetMotorPosition(strMotorIdentifier, fValue);
	//printf("Position after executing functions: %f \n", fValue);
	cout << "Position after executing functions: " << fValue << endl;
	//printf("--------------------------------------------------------------\n");
	cout << "--------------------------------------------------------------" << endl;
}
void testing::EnableMotor(void)
{
	cout << "-------------TESTING GET/SET ENABLE MOTOR--------------" << endl;
	//printf("-------------TESTING GET/SET ENABLE MOTOR--------------\n");
	
	cout << "IMPOSIBLE TO TEST IN SIMULATORS, PowerOn attribute is needed. " << endl;
	//printf("IMPOSIBLE TO TEST IN SIMULATORS, PowerOn attribute is needed.\n");
	//CString strMotorIdentifier = "motor/amilansimmotorctrl/1";//"motor/DummyMtrCtrl/1";
	//float fValue = 0;
	////printf("Position before executing functions: %f \n", fValue);
	//interf.EnableMotor(strMotorIdentifier, false);
	////interf.GetMotorPosition(strMotorIdentifier, fValue);
	////printf("Position after executing functions: %f \n", fValue);
	//printf("-------------------------------------------------------\n");
	cout << "-------------------------------------------------------" << endl;
}
void testing::JogMotor(CString strMotorIdentifier, bool direction)
{
	cout << "-------------TESTING GET/SET JOG MOTOR-----------------" << endl;
	//printf("-------------TESTING GET/SET JOG MOTOR-----------------\n");
	//CString strMotorIdentifier = "motor/amilansimmotorctrl/1";//"motor/DummyMtrCtrl/1";
	float fValue = 0;
	
	cout << "Position before executing functions: " << fValue << endl;
	//printf("Position before executing functions: %f \n", fValue);

	interf.JogMotor(strMotorIdentifier, direction); 
	
	interf.GetMotorPosition(strMotorIdentifier, fValue);
	
	cout << "\nPosition after executing functions: " << fValue << endl;
	//printf("\nPosition after executing functions: %f \n", fValue);
	//printf("-------------------------------------------------------\n");
	cout << "-------------------------------------------------------" << endl;
}
void testing::GetHomingStatus(void)
{
	//printf("-------------TESTING GET/SET HOMING STATUS-------------\n");
	//printf("-------------------------------------------------------\n");
	cout << "-------------TESTING GET/SET HOMING STATUS-------------" << endl;
	cout << "-------------------------------------------------------" << endl;
}
void testing::Home(void)
{
	/*printf("-------------TESTING GET/SET HOME----------------------\n");
	printf("-------------------------------------------------------\n");*/
	cout << "-------------TESTING GET/SET HOME----------------------" << endl;
	cout << "-------------------------------------------------------" << endl;
}
void testing::VariableStr(CString strVarIdentifier, CString attr )
{
	cout <<  "-------------TESTING GET/SET STR VARIABLES-------------" << endl;
	//printf("-------------TESTING GET/SET STR VARIABLES-------------\n");

	//CString attrStr = "motor/DummyMtrCtrl/1/Status";
	CString str;
	strVarIdentifier += CString("/") + attr;
	interf.GetVariableString(strVarIdentifier, str);
	//printf("String read: %s\n", str);
	cout << "String read: " << str << endl;
	cout << "-------------------------------------------------------" << endl;
	//printf("-------------------------------------------------------\n");
}
void testing::VariableInt(CString strVarIdentifier, int nValue)
{
	cout << "-------------TESTING GET/SET INT VARIABLES-------------" << endl;
	//printf("-------------TESTING GET/SET INT VARIABLES-------------\n");

	//CString strVariableName = "motor/DummyMtrCtrl/1/Backlash";
	//int nValue = 12;
	int nValue2 = 0;

	//printf("nValue2 before executing functions: %d\n", nValue2);
	//printf("Value to set: %d\n", nValue);
	cout << "nValue2 before executing functions: " << nValue2 << endl;
	cout << "Value to set: " << nValue << endl;
	interf.SetVariable(strVarIdentifier, nValue);
	interf.GetVariableInt(strVarIdentifier, nValue2);
	cout << "nValue2 after executing functions: " << nValue2 << endl;
	//printf("nValue2 after executing functions: %d\n", nValue2);
	cout << "-------------------------------------------------------" << endl;
	//printf("-------------------------------------------------------\n");
}
void testing::VariableFloat(CString strVarIdentifier, float fval)
{
	cout << "-------------TESTING GET/SET FLOAT VARIABLES-----------" << endl;
	//printf("-------------TESTING GET/SET FLOAT VARIABLES-----------\n");

	//CString strVariableName = "motor/DummyMtrCtrl/1/Acceleration";
	float fValue = 0;
	//float fval = 0.25;

	//printf("fValue before executing functions: %f\n", fValue);
	//printf("Value to set: %f\n", fval);
	cout << "fValue before executing functions: " << fValue << endl;
	cout << "Value to set: " << fval << endl;
	interf.SetVariable(strVarIdentifier, fval);
	interf.GetVariableFloat(strVarIdentifier, fValue);
	//printf("fValue after executing functions: %f\n", fValue);
	cout << "fValue after executing functions: " << fValue << endl;

	//printf("-------------------------------------------------------\n");
	cout << "-------------------------------------------------------" << endl;
}
void testing::VariableBool(CString strVarIdentifier, bool bval)
{
	//printf("-------------TESTING GET/SET BOOL VARIABLES------------\n");
	cout << "-------------TESTING GET/SET BOOL VARIABLES------------" << endl;

	//CString strVariableName = "motor/DummyMtrCtrl/1/SimulationMode";
	bool bValue = false;

	//printf("bValue before executing functions: %s\n", (bValue)?"true":"false");
	//printf("Value to set: true \n");
	cout << "bValue before executing functions: " << bValue << endl;
	cout << "Value to set: " << bval;
	interf.SetVariable(strVarIdentifier, bval);
	interf.GetVariableBool(strVarIdentifier, bValue);
	//printf("bValue after executing functions: %s\n", (bValue)?"true":"false");
	cout << "bValue after executing functions: " << bValue << endl;

	//printf("-------------------------------------------------------\n");
	cout << "-------------------------------------------------------" << endl;
}
void testing::MotorVariableFloat(CString strMotorAttr, CString strAttr, float fval)
{
	//printf("-------------TESTING GET/SET FLOAT MOTOR VARIABLES-------------\n");
	cout << "-------------TESTING GET/SET FLOAT MOTOR VARIABLES-------------" << endl;
	
	//CString strMotorAttr = "motor/DummyMtrCtrl/1/Acceleration";
	CString strVariableName = strMotorAttr + CString("/") + strAttr ;
	float fValue = 0;

	/*printf("fValue before executing functions: %f\n", fValue);
	printf("Value to set: %f\n", fval);*/
	cout << "fValue before executing functions: " << fValue << endl;
	cout << "Value to set: " << fval << endl;
	interf.SetVariable(strVariableName, fval);
	interf.GetMotorVariableFloat(strMotorAttr, strAttr, fValue);
	//printf("fValue after executing functions: %f\n", fValue);
	cout << "fValue after executing functions: " << fValue << endl;

	//printf("---------------------------------------------------------------\n");
	cout << "---------------------------------------------------------------" << endl;
}
void testing::MotorVariableInt(CString strMotorAttr, CString strAttr, int ival)
{
	//printf("-------------TESTING GET/SET INT MOTOR VARIABLES-------------\n");
	cout << "-------------TESTING GET/SET INT MOTOR VARIABLES-------------" << endl;

	//CString strMotorAttr = "motor/DummyMtrCtrl/1/Backlash";
	CString strVariableName = strMotorAttr + CString("/") + strAttr;
	int Value = 0;
	//int val = 3;

	/*printf("Value before executing functions: %d\n", Value);
	printf("Value to set: %d\n", val);*/
	cout << "Value before executing functions: " << Value << endl;
	cout << "Value to set: " << ival << endl;
	interf.SetVariable(strVariableName, ival );
	interf.GetMotorVariableInt(strMotorAttr, strAttr, Value);
	//printf("Value after executing functions: %d\n", Value);
	cout << "Value after executing functions: " << Value << endl;

	//printf("-------------------------------------------------------------\n");
	cout << "-------------------------------------------------------------" << endl;
}
void testing::MotorVariableString(CString strMotorAttr, CString strAttr)
{
	//printf("-------------TESTING GET/SET STR MOTOR VARIABLES-------------\n");
	cout << "-------------TESTING GET/SET STR MOTOR VARIABLES-------------" << endl;

	//CString attrStr = "motor/DummyMtrCtrl/1";
	CString str;
	interf.GetMotorVariableString(strMotorAttr, strAttr, str);
	//printf("String read: %s\n", str);
	cout << "String read: " << str << endl;

	//printf("-------------------------------------------------------------\n");
	cout << "-------------------------------------------------------------" << endl;
}
void testing::MotorVariableBool(CString strMotorAttr, CString strAttr, bool bval)
{
	//printf("-------------TESTING GET/SET BOOL MOTOR VARIABLES-------------\n");
	cout << "-------------TESTING GET/SET BOOL MOTOR VARIABLES-------------" << endl;

	//"motor/DummyMtrCtrl/1/SimulationMode";
	CString strVariableName = strMotorAttr + CString("/") + strAttr;
	//CString strMotor = "motor/DummyMtrCtrl/1";
	bool bValue = false;

	/*printf("bValue before executing functions: %s\n", (bValue)?"true":"false");
	printf("Value to set: true \n");*/
	cout << "bValue before executing functions: " << bValue << endl;
	cout << "Value to set: " << bval << endl;
	interf.SetVariable(strVariableName, bval);
	interf.GetMotorVariableBool(strMotorAttr, strAttr, bValue);
	printf("bValue after executing functions: %s\n", (bValue)?"true":"false");

	printf("--------------------------------------------------------------\n");
}
void testing::MotorAttrStr(void)
{
	printf("-------------TESTING MOTOR ATTRIBUTE STRING------------\n");
	printf("-------------------------------------------------------\n");
}

void testing::GetMotorAttributeStrings(CString strMotor)
{
	printf("-------------TESTING MOTOR ATTRIBUTE STRING------------\n");

	int nattrib = 7;
	CString pstring[7];
	CString *pstr;
	//CString strMotor = "motor/amilansimmotorctrl/1";
	bool neg_limit = true;
	bool pos_limit = true;
	bool in_pos = true;
	bool f_error = true;
	float pos = 0;
	float vel = 0;
	
	pstr = pstring;

	interf.GetMotorAttributeStrings(pstr, nattrib);
	
	MotorPosition(strMotor, 50);

	printf("neg_limit before executing functions: %s\n", (neg_limit)?"true":"false");
	interf.GetMotorVariableBool(strMotor, pstr[NEG_LIMIT], neg_limit);
	printf("neg_limit after executing functions: %s\n", (neg_limit)?"true":"false");

	printf("pos_limit before executing functions: %s\n", (pos_limit)?"true":"false");
	interf.GetMotorVariableBool(strMotor, pstr[POS_LIMIT], pos_limit);
	printf("pos_limit after executing functions: %s\n", (pos_limit)?"true":"false");

	printf("pos before executing functions: %f\n", pos);
	interf.GetMotorVariableFloat(strMotor, pstr[MOTOR_POSITION], pos);
	printf("pos after executing functions: %f\n", pos);

	printf("vel before executing functions: %f\n", vel);
	interf.GetMotorVariableFloat(strMotor, pstr[SET_VELO], vel);
	printf("vel after executing functions: %f\n", vel);

	printf("in_pos before executing functions: %s\n", (in_pos)?"true":"false");
	interf.GetMotorVariableBool(strMotor, pstr[IN_POS], in_pos);
	printf("in_pos after executing functions: %s\n", (in_pos)?"true":"false");

	printf("f_error before executing functions: %s\n", (f_error)?"true":"false");
	interf.GetMotorVariableBool(strMotor, pstr[FOLLOWING_ERROR], f_error);
	printf("f_error after executing functions: %s\n", (f_error)?"true":"false");

	printf("-------------------------------------------------------\n");
}

void testing::PrintMenu(void)
{
	printf("================================================================");
	printf("\n======================= ALBA DLL TESTING =======================\n");
	printf("================================================================\n\n");
	printf("SELECT THE FUNCTION TO TEST:\n");
	printf("a - ErrorMessage()\n");
	printf("b - MotorSpeed()\n");
	printf("c - MotorPosition()\n");
	printf("d - JogMotor()\n");
	printf("e - EnableMotor()\n");
	printf("f - GetHomingStatus()\n");
	printf("g - Home()\n");
	printf("h - VariableStr()\n");
	printf("i - VariableInt()\n");
	printf("j - VariableFloat()\n");
	printf("k - VariableBool()\n");
	printf("l - MotorVariableFloat()\n");
	printf("m - MotorVariableInt()\n");
	printf("n - MotorVariableString()\n");
	printf("o - MotorVariableBool()\n");
	printf("p - GetMotorAttributeStrings()\n");
	printf("q - QUIT\n\n");
	printf("================================================================\n");
	printf("================================================================\n\n");
}
void testing::PrintExit(void)
{
	printf("================================================================");
	printf("\n======================= End of TESTING =======================\n");
	printf("================================================================\n\n");
}

void testing::PrintJogInfo(void)
{
	printf("Select the direction of the movement: \n");
	printf("0 - go to the negative limit\n");
	printf("1 - go to the positive limit\n");
}
int testing::ReciveInt(string input)
{
	int myNumber;
	stringstream myStream(input);
	if (myStream >> myNumber) cout << "The value introduced is: " << myNumber << endl;
	else return 0;
	return myNumber;
}

float testing::ReciveFloat(string input)
{
	float myNumber;
	stringstream myStream(input);
	if (myStream >> myNumber) cout << "The value introduced is: " << myNumber << endl;
	else return -1;
	return myNumber;
}

double testing::ReciveDouble(string input)
{
	double myNumber;
	stringstream myStream(input);
	if (myStream >> myNumber) cout << "The value introduced is: " << myNumber << endl;
	else return 0;
	return myNumber;
}

bool testing::ReciveBoolean(string input)
{
	bool myNumber;
	stringstream myStream(input);
	if (myStream >> myNumber) cout << "The value introduced is: " << myNumber << endl;
	else return -1;
	return myNumber;
}