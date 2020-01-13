/*******************************************************************************

   This file is part of TangoInterface

   (copyleft) CELLS / ALBA Synchrotron, Cerdanyola del Vallès, Spain
  
   This is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.
  
   This software is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
  
   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
   
*******************************************************************************/

#include "stdafx.h"
#include "TangoInterface.h"
#include <vector>
#include <tango.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_STRINGS 7

using namespace Tango;

TangoInterface::TangoInterface(void)
{
	this->w_pos = 0;
	this->Error_Msg = "";
}

TangoInterface::~TangoInterface(void)
{
}

bool TangoInterface::GetErrorMessage(CString &strErrorMsg)
{
	strErrorMsg = this->Error_Msg.c_str();
	return true;
}

bool TangoInterface::SetMotorSpeed(CString strMotorIdentifier,float fSpeed)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute wspeed;
		DevDouble velocity = fSpeed;

		wspeed.name = "Velocity";
		wspeed << velocity;

		motor.write_attribute(wspeed);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute SetMotorSpeed\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetMotorPosition(CString strMotorIdentifier, float &fValue)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute pos;
		DevDouble posR;
        
		pos = motor.read_attribute("Position");
        pos >> posR;
		fValue = float(posR);
		
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetMotorPosition\n";
        return false;
    }
    return true;
}

bool TangoInterface::EnableMotor(CString strMotorIdentifier,bool bEnable)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute enable("PowerOn", bEnable);
		DeviceAttribute powerOn;
		bool power;
		
		powerOn = motor.read_attribute("PowerOn");
		powerOn >> power;

		if(power != bEnable)
		{	
			if (bEnable){ 
            motor.write_attribute(enable);
			}
			else{
				if (motor.state() == Tango::MOVING){
					motor.command_inout("Abort");
				}
				motor.write_attribute(enable);
			}
		}
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute EnableMotor\n";
        return false;
    }
    return true;
}

bool TangoInterface::JogMotor(CString strMotorIdentifier,bool nDirection)
{   
    try{
		DeviceProxy motor(strMotorIdentifier);
		AttributeInfoEx attrInfo;
		DevDouble position;
		
		attrInfo = motor.attribute_query("Position");
		if(nDirection)
		{
			position = strtod(attrInfo.max_value.c_str(), NULL);
		}
		else
		{
			position = strtod(attrInfo.min_value.c_str(), NULL);
		}

		this->w_pos = position;
		DeviceAttribute wPos("Position", position);
        motor.write_attribute(wPos);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute JogMotor\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetHomingStatus(CString strMotorIdentifier, int &nHomingStatus)
{
    nHomingStatus = 15;
	return true;
}

bool TangoInterface::MoveMotor(CString strMotorIdentifier,float fPosition)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DevDouble pos = fPosition;
		DeviceAttribute wPos("Position", pos);

		this->w_pos = fPosition;

        motor.write_attribute(wPos);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute MoveMotor\n";
        return false;
    }
    return true;
}

bool TangoInterface::SetVariable(CString strCommand, CString strValue)
{
    try{
		AttributeProxy attr(strCommand);
		DeviceAttribute da;
		std::string stringValue(strValue);
		da << stringValue;
        attr.write(da);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute SetVariable\n";
        return false;
    }
    return true;
}

bool TangoInterface::SetVariable(CString strCommand, int nValue)
{
    try{
		AttributeProxy attr(strCommand);
		DeviceAttribute da;

		da << DevLong(nValue);
        attr.write(da);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute SetVariable\n";
        return false;
    }
    return true;
}

bool TangoInterface::SetVariable(CString strCommand, float fValue)
{
    try{
	    AttributeProxy attr(strCommand);
	    DeviceAttribute da;
		DevDouble val;

		val = fValue;
		da << val;
        attr.write(da);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute SetVariable\n";
        return false;
    }
    return true;
}
bool TangoInterface::SetVariable(CString strVariableName, bool bValue)
{
	try{
		AttributeProxy attr(strVariableName);
		DeviceAttribute da;

		da << bValue;
        attr.write(da);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute SetVariable\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetVariableFloat(CString strInput, float &fValue)
{
    try{
		AttributeProxy attr(strInput);
		DeviceAttribute da;
		DevDouble readAttr;
	
        da = attr.read();
        da >> readAttr;
		fValue = readAttr;
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetVariableFloat\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetVariableInt(CString strInput, int &nValue)
{
    try{
		AttributeProxy attr(strInput);
		DeviceAttribute da;
		DevLong nAttr;
		
		da = attr.read();
        da >> nAttr;
		nValue = nAttr;
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetVariableInt\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetVariableString(CString strInput, CString &strReturn)
{
    try{
		AttributeProxy attr(strInput);
		DeviceAttribute da;
		string str_read;
		
		da = attr.read();
        da >> str_read;
        strReturn = str_read.c_str();
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetVariableString\n";
        return false;
    }
	return true;
}

bool TangoInterface::GetVariableBool(CString strVariableName, bool &bValue)
{
    try{
		AttributeProxy attr(strVariableName);
		DeviceAttribute da;
		bool bAttr;
		
		da = attr.read();
        da >> bAttr;
		bValue = bAttr;
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetVariableBool\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetMotorVariableFloat(CString strMotorIdentifier, CString strAttribute, float &fValue)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute attr;
		DevDouble floatAttr;
		
		attr = motor.read_attribute(strAttribute);
        attr >> floatAttr;
		fValue = float(floatAttr);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetMotorVariableFloat\n";
        return false;
    }
	return true;
}

bool TangoInterface::GetMotorVariableInt(CString strMotorIdentifier, CString strAttribute, int &nValue)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute attr;
		DevLong intAttr;
				
		attr = motor.read_attribute(strAttribute);
        attr >> intAttr;
		nValue = int(intAttr);
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetMotorVariableInt\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetMotorVariableBool(CString strMotorIdentifier, CString strVariableName, bool &bValue)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute attr;
		vector<bool> bAttr;
		DevBoolean attrb;
		DevDouble fpos;
		DevState motor_state;
		float r_pos;

		if(strcmp(strVariableName, "Neg_Limit")==0)
		{
			//Checking Neg_Limit
			attr = motor.read_attribute("Limit_Switches");
			attr >> bAttr;
			bValue = bAttr[2];
		}
		else if(strcmp(strVariableName, "Pos_Limit")==0)
		{
			//Checking Pos_Limit
			attr = motor.read_attribute("Limit_Switches");
			attr >> bAttr;
			bValue = bAttr[1];
		}
		else if(strcmp(strVariableName, "In_Position")==0)
		{
			//Checking In_Position
			attr = motor.read_attribute("Position");
			attr >> fpos;
			r_pos = float(fpos);

			if(this->w_pos == r_pos) bValue = true;
			else bValue = false;
		
		}
		else if (strcmp(strVariableName, "Follow_err")==0)
		{
			//Checking Follow_err
			attr = motor.read_attribute("State");
			attr >> motor_state;

			if(motor_state == DevState::ALARM) bValue = true;
			else if(motor_state == DevState::ON || motor_state == DevState::MOVING) {
				bValue = false;
			}
		}
		else{
			attr = motor.read_attribute(strVariableName);
			attr >> attrb;
			bValue = attrb;
		}

    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetMotorVariableBool\n";
        return false;
    }
    return true;
}

bool TangoInterface::GetMotorVariableString(CString strMotorIdentifier, CString strAttribute, CString &strReturn)
{
    try{
		DeviceProxy motor(strMotorIdentifier);
		DeviceAttribute attr;
		string str_read;
			
		attr = motor.read_attribute(strAttribute);
        attr >> str_read;
        strReturn = str_read.c_str();
    }
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute GetMotorVariableString\n";
        return false;
    }
    return true;
}

int TangoInterface::GetMotorAttributeStrings(CString *&pstrAttributes, int nNumAttributes)
{	
	string ps = "Neg_Limit";
	pstrAttributes[NEG_LIMIT] = ps.c_str();

	ps = "Pos_Limit";
	pstrAttributes[POS_LIMIT] = ps.c_str();

	ps = "In_Position";
	pstrAttributes[IN_POS] = ps.c_str();

	ps = "Follow_err";
	pstrAttributes[FOLLOWING_ERROR] = ps.c_str();

	ps = "PowerOn";
	pstrAttributes[ENABLED] = ps.c_str();
	
	ps = "Position";
	pstrAttributes[MOTOR_POSITION] = ps.c_str();
	
	ps = "Velocity";
	pstrAttributes[SET_VELO] = ps.c_str();
	
	return NUM_STRINGS;
}

bool TangoInterface::Home(CString strMotorIdentifier)
{
	return true;	
}
bool TangoInterface::StopMotor(CString strMotorIdentifier)
{
    try{
		DeviceProxy motor(strMotorIdentifier);

		motor.command_inout("Abort");
	}
	catch(Tango::DevFailed &e)
    {
		this->Error_Msg = e.errors[0].desc;
		this->Error_Msg += "\n";
		return false; 
    }
    catch(...)
    {
		this->Error_Msg = "An exception occurs when trying to execute StopMotor\n";
        return false;
    }
    return true;
}