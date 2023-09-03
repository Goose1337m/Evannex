[] spawn {
    while {true} do {
        sleep 2500;
        [2] remoteExec ["BIS_fnc_earthquake"];
    };
};

