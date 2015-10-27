#include "TangoInterface.h"


class testing
{
public:
	TangoInterface interf;

	testing(void);
	~testing(void);

	void ErrorMessage(void);
	void MotorSpeed(CString strMotorIdentifier, float fValue);	
	void MotorPosition(CString strMotorIdentifier, float fValue);
	void EnableMotor(void);
	void JogMotor(CString strMotorIdentifier, bool direction);
	void GetHomingStatus(void);
	void Home(void);
	void VariableStr(CString strVarIdentifier, CString attr);
	void VariableInt(CString strVarIdentifier, int nValue);
	void VariableFloat(CString strVarIdentifier, float fval);
	void VariableBool(CString strVarIdentifier, bool bval);
	void MotorVariableFloat(CString strMotorAttr, CString strAttr, float fval);
	void MotorVariableInt(CString strMotorAttr, CString strAttr, int ival);
	void MotorVariableString(CString strMotorAttr, CString strAttr);
	void MotorVariableBool(CString strMotorAttr, CString strAttr, bool bval);
	void MotorAttrStr(void);
	void GetMotorAttributeStrings(CString strMotor);
	void PrintMenu(void);
	void PrintExit(void);
	void PrintJogInfo(void);
	int ReciveInt(string input);
	float ReciveFloat(string input);
	double ReciveDouble(string input);
	bool ReciveBoolean(string input);
};
