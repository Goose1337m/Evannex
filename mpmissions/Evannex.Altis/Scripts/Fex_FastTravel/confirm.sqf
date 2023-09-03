_markerPos = _this select 0;
_internal = _markerPos select [1,((count _markerPos) -1)];
_numbers = _internal splitString ",";
_selMrkPos = [];
{_selMrkPos append [parseNumber _x]} forEach _numbers;
//hint format ["%1",str _selMrkPos];
closedialog 1;
cutText ["","black out",0.5];
titleText ["Loading...","PLAIN",1];
sleep 0.5;

//VEHICLE TYPE - SWITCH - DEFAULT IS WALK
/*
switch (typeOf (vehicle player)) do {
case :


};
*/
_time = ((position player) distance _selMrkPos)/3.96;
//time = distance / speed
//speed = 14.27 km/h -> 3.96 m/s
_time = _time / 3600;
//skipTime takes in hours, therefore seconds / 3600
//skipping time is not necessary (in most cases) > leave commented out
//if you want to skip time travelling, uncomment the next line
//skipTime _time;
waitUntil {preloadCamera _selMrkPos};
cutText ['','black in',1];
titleText ["","PLAIN",0.1];
openMap [false, false];
player setVelocity [0,0,0];
player setPos _selMrkPos;

