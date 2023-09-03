_trigger = _this;
_markerNearest = ([allMapMarkers,_trigger] call BIS_fnc_NearestPosition);
FexInternalDiscoveredMarkers append [_markerNearest];
_markerNearest setMarkerType "mil_marker";
_markerNearest setMarkerColor "colorBlack";
titleText ["New location discovered","plain down",0.6];
playSound3D ["a3\sounds_f\sfx\hint-5.wss", player];
FexInternalHandle = nil;