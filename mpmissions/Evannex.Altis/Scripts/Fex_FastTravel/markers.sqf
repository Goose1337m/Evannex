_FexInternalOpenedMap = ((_this select 0) select 0);
_selectMarker = (_this select 1);

if (! _FexInternalOpenedMap) then 
{
	//hint "Map has been closed";
	if (!(getMarkerPos _selectMarker isEqualTo [0,0,0])) then 
	{
		_selectMarker setMarkerPos [0,0,0];
		_selectMarker setMarkerSize [0,0];
	};
};

if (_FexInternalOpenedMap) then 
{
	//hint "Map has been opened";


	while {visibleMap} do {
		sleep 0.1;
		_myMapObject = ctrlMapMouseOver (findDisplay 12 displayCtrl 51);
		if (count _myMapObject > 0) then 
		{
			if (_myMapObject select 0 == "marker") then 
			{
				if ((toLower(_myMapObject select 1)) find  "travel" >= 0 &&
				(_myMapObject select 1) in FexInternalDiscoveredMarkers) then 
					{
					_myMarker = (_myMapObject select 1);
					_selectMarker setMarkerSize [2,2];
					_selectMarker setMarkerPos getMarkerPos _myMarker;
					[
						"FexClickingID", "onMapSingleClick", 
						{
							_selectedMarker = (_this select 4);
							_selectedMarkerPos = getMarkerPos _selectedMarker;
							if (!dialog &&
							visibleMap &&
							(ctrlMapMouseOver (findDisplay 12 displayCtrl 51) select 0 == "marker") 
							) then {
							_myVar = str _selectedMarkerPos;
							_nula = createDialog "SelectConfirmDialog";
							ctrlSetText [1904, _myVar];
							["FexClickingID", "onMapSingleClick"] call BIS_fnc_RemoveStackedEventHandler
							};

							//hint format ["Teleported %1 to %2",player,_selectedMarkerPos];
						},[_myMarker]
					] call BIS_fnc_addStackedEventHandler;
				};
			};
		} else 
		{
			_selectMarker setMarkerSize [0,0];
		};
	};

};

