diag_log format ["############## %1 ############## - AIS init started", missionName];

if (isServer) then {
	ais_ace_shutDown = false;
	if ((isClass (configFile >> "CfgPatches" >> "ace_medical")) or (isClass (configFile >> "CfgPatches" >> "PiR"))) then {
		ais_ace_shutDown = true;
		["AIS Shutdown - ACE or PIR running."] call BIS_fnc_logFormat;
	};
	publicVariable "ais_ace_shutDown";
};

if (!isNil "AIS_Core_3DEHId") then {
	removeMissionEventHandler ["Draw3D", AIS_Core_3DEHId];
};

if (!isNil "AIS_Core_eachFrameHandlerId") then {
	removeMissionEventHandler ["EachFrame", AIS_Core_eachFrameHandlerId];
};

call AIS_Core_fnc_initEvents;
AIS_Core_Interaction_Actions = [];