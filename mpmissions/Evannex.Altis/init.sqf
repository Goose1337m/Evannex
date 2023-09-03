// Run evannex gamemode
execVM "core\evannexInit.sqf";
// Enable friendly markers
execVM "core\client\QS_icons.sqf";

if (isServer) then { skipTime (random 24) };
if (isServer) then { 60 setOvercast (random 1) };

/*
TODO
calculate time skip based on distance travelled ----- DONE
make it a bit more flexible (hopefully)   ------ DONE?
consider MP support
a bit more effects and such ----- KINDA DONE (what else could be added?)
pre-load the terrain to avoid ugly texture loading ----- DONE
MULTIPLE CLICKS FUCKUP PREVENTION SYSTEM
-probably a UI - small table - do you want to go here? YES/NO  ----- DONE
consider having discovered and undiscovered markers (necessary?) ----- DONE
make the player's vehicle also teleport, and change the skip accoring to vehicle type ------ NOT NECESSARY
*/
//_variableString = format ["fexInternal_%1_discoveredMarkers", name player];
//missionNamespace setVariable [_variableString, []];
//missionNamespace getVariable _variableString;
FexInternalDiscoveredMarkers = [];
_fexInternalSelectMarker = createMarker ["Fex_Internal_Select",[0,0,0]];
_fexInternalSelectMarker setMarkerShape "ICON";
_fexInternalSelectMarker setMarkerType "Select";
_fexInternalSelectMarker setMarkerColor "ColorOPFOR";
_fexInternalSelectMarker setMarkerSize [0,0];
_handle = addMissionEventHandler ["Map",{
_handling = [_this,"Fex_Internal_Select"] execVM "Scripts\Fex_FastTravel\markers.sqf";
}];

[] execVM "Scripts\MagRepack\MagRepack_init_sv.sqf";

[] execVM "Scripts\SA_AdvancedTowing\functions\fn_advancedTowingInit.sqf";

[] execVM "Scripts\GF_Earplugs\GF_Earplugs.sqf";

0 = [] execVM "Scripts\improvements\VEH_autoflip.sqf";

call compile preprocessFileLineNumbers "Scripts\EPD\VirtualJTAC\init.sqf";
enableSaving[false,false];










