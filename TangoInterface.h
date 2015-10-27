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

#pragma once
#include <string>
using namespace std;

// Rpastrick, 7/17/2009

////////////////////////////////////////////////////////////////////////////////////////////////////
/// <summary>	Tango interface. </summary>
///
/// <remarks>	One object will be used for contacting all Tango axes. The primary design of this class 
///				is to communicate with Tango motors. It also has the facility to communicate with any Tango
///				variable for recording external data.
///
///				Units:
///				Assumed in all functions that the units of the passed in values are the same. Xradia software
///				will have a conversion factor that will allow the Xradia software to use Engineering units 
///				(ex. mm, deg, eV) independent of the actual hardware. In all descriptions below, the units 
///				will be referred to generically as "counts".
///
///				Motor Identifier:
///				The motor identifier is a freeform string (configured per motor) that contains all information 
///				necessary to connect to a particular hosted motor. The definition of this string is left to the
///				implementor of this interface. 
///				</remarks>
////////////////////////////////////////////////////////////////////////////////////////////////////

enum TANGO_ATTRIBUTES{
	NEG_LIMIT = 0,
	POS_LIMIT,
	IN_POS,
	FOLLOWING_ERROR,
	ENABLED,
	MOTOR_POSITION,
	SET_VELO,
	CURRENT_SIZE_TANGO_ATTRIBUTES_ENUM
};

class extraLib;

class AFX_EXT_CLASS TangoInterface
{
public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor. </summary>
	///
	/// <remarks>	</remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	TangoInterface(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor. </summary>
	///
	/// <remarks>	</remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	~TangoInterface(void);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets an error message. </summary>
	///
	/// <remarks>	Will return an error string describing the most recent failure.</remarks>
	///
	/// <param name="strErrorMsg">	CString to recieve the error message string. </param>
	///
	///	<returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetErrorMessage(CString &strErrorMsg);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets the motor speed. </summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="fSpeed">				The speed value to set in counts per second. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SetMotorSpeed(CString strMotorIdentifier,float fSpeed);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets the motor position. </summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	///	<param name="fPosition">	        The motor position in counts. </param>
	///
	///	<returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetMotorPosition(CString strMotorIdentifier, float &fPosition);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Enables the motor. </summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="bEnable">				true to enable it, false to disable it. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool EnableMotor(CString strMotorIdentifier,bool bEnable);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Jog motor. </summary>
	///
	/// <remarks>	This will cause the motor of interest to jog continuously in the specified direction.</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="bMovePositive">		Direction to Jog. True for Positive, False for negative. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool JogMotor(CString strMotorIdentifier,bool bMovePositive);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Get the homing status. </summary>
	///
	/// <remarks>	Minimum necessary implemenation requires this function to return values 0 and 15.
	///				These corresponds to "homing not started" and "homing complete". If the motor
	///				does not require or allow homing this function, this function should return 15, home complete. 
	///</remarks>
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	///	<param name="nHomingStatus">		
	/// The homing status defined by the values 0-17 with the following definitions:
	///	HomingRoutineNotStartedYet	= 0,
	///	WaitingforOther = 1,
	///	MovingToLimit = 2,
	///	IsAtLimit = 3,
	///	MovingToCoarseHome = 4,
	///	MovingToFixedOffset = 5,
	///	MovingToFineHome = 6,
	///	IsAtHome = 7,

	///	MovingToAlignedPos = 8,
	///	FollowedoutOnCoarse = 9,
	///	FollowedoutOnFixedOffset = 10,
	///	FollowedoutOnFineHome = 11,
	///	FollowedoutOnAlignedPos = 12,
	///	HitLimitOnFineHome = 13,
	///	HitLimitOnAlignedPos = 14,
	///	HomeComplete = 15,

	///	GeneralError = 16,
	///	PreconditionNotMet = 17
	/// </param>
	///
	///	<returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetHomingStatus(CString strMotorIdentifier, int &nHomingStatus);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Issues the Home command. </summary>
	///
	/// <remarks>	This command will cause the specified motor to initiate the homing process. If the motor
	///				does not require or allow homing this function, this function should return true.
	///	</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool Home(CString strMotorIdentifier);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Move motor. </summary>
	///
	///	<remarks>	
	/// </remarks>
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="fPosition">			The ABSOLUTE position in counts. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool MoveMotor(CString strMotorIdentifier,float fPosition);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a variable. </summary>
	///
	/// <remarks>	Sets the specified variable to the specified value.</remarks>
	///
	/// <param name="strVariableName">	The variable name. </param>
	/// <param name="strValue">		The value as a string. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SetVariable(CString strVariableName, CString strValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a variable. </summary>
	///
	/// <remarks>	Sets the specified variable to the specified value.</remarks>
	///
	/// <param name="strVariableName">	The variable name. </param>
	/// <param name="strValue">		The value as an integer. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SetVariable(CString strVariableName, int nValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a variable. </summary>
	///
	/// <remarks>	Sets the specified variable to the specified value. </remarks>
	///
	/// <param name="strVariableName">	The variable name. </param>
	/// <param name="strValue">		The value as a float. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SetVariable(CString strVariableName, float fValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Sets a variable. </summary>
	///
	/// <remarks>	Sets the specified variable to the specified value.</remarks>
	///
	/// <param name="strVariableName">	The variable name. </param>
	/// <param name="strValue">		The value as a boolean. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool SetVariable(CString strVariableName, bool bValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a variable (float version) </summary>
	///
	/// <remarks>	Gets the value of the specified variable. </remarks>
	///
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="fValue">	the variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetVariableFloat(CString strVariableName, float &fValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a variable (integer version). </summary>
	///
	/// <remarks>	Gets the value of the specified variable. </remarks>
	///
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="nValue">	the variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetVariableInt(CString strVariableName, int &nValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a variable (string version) </summary>
	///
	/// <remarks>	Gets the value of the specified variable. </remarks>
	///
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="strReturn">			The variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetVariableString(CString strVariableName, CString &strReturn);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a variable (boolean version). </summary>
	///
	/// <remarks>	Gets the value of the specified variable. </remarks>
	///
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="bValue">			The variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetVariableBool(CString strVariableName, bool &bValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Get a motor variable (float version) </summary>
	///
	/// <remarks>	Get the value of the specified variable for the specified motor.</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="fValue">	the variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetMotorVariableFloat(CString strMotorIdentifier, CString strVariableName, float &fValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Get a motor variable (integer version) </summary>
	///
	/// <remarks>	Get the value of the specified variable for the specified motor.</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="nValue">	the variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetMotorVariableInt(CString strMotorIdentifier, CString strVariableName, int &nValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Get a motor variable (string version) </summary>
	///
	/// <remarks>	Get the value of the specified variable for the specified motor.</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="strReturn">			The variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetMotorVariableString(CString strMotorIdentifier, CString strVariableName, CString &strReturn);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Get a motor variable (boolean version) </summary>
	///
	/// <remarks>	Get the value of the specified variable for the specified motor.</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// <param name="strVariableName">		The variable name. </param>
	/// <param name="bValue">	the variable value. </param>
	///
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool GetMotorVariableBool(CString strMotorIdentifier, CString strVariableName, bool &bValue);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Gets a specified list of motor variable names. </summary>
	///
	/// <remarks>	This function is used to retrieve the variable names for a specific list of motor attributes.
	///				This list is as follows, in order:
	///					0. Negative Limit			-- Variable is True when motor is at the negative-most limit
	///					1. Positive Limit			-- Variable is True when motor is at the positive-most limit
	///					2. In Position				-- Variable is True when the motor has stopped moving and it is within an error bound of its last commanded position
	///					3. Following Error Occurred -- Variable is True when the last commanded motion was aborted due to excessive following error 
	///					4. Enabled Status			-- Variable is True when motor is enabled
	///					5. Position					-- Variable contains the current motor position in counts
	///					6. Set Velocity				-- Variable contains the current motor target jog velocity
	///
	///				The pstrVariableNames parameter should be populated with the variable names for these motor attributes.
	///				This allows xradia software to use the GetMotorVariableXXXXX functions to check motor status. 
	///
	///				It is an error to return more or less than the specified number of variables names or to return them in 
	///				the wrong order.
	///				
	///	</remarks>
	///
	/// <param name="pstrVariableNames">	a pointer to an array of CString objects which will recieve the expected data. </param>
	/// <param name="nNumAttributes">		the size of the allocated array. </param>
	///
	/// <returns>	the number of CStrings returned. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int GetMotorAttributeStrings(CString *&pstrVariableNames, int nNumAttributes);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Stop the motor. </summary>
	///
	/// <remarks>	</remarks>
	///
	/// <param name="strMotorIdentifier">	The motor identifier for the motor of interest.</param>
	/// 
	/// <returns>	true if the command succeeds, false if the command fails. </returns>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	bool StopMotor(CString strMotorIdentifier);

private:
	extraLib* d;
	float w_pos;
	string Error_Msg;

};
