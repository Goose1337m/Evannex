

class SelectConfirmDialog
{
idd=1001;
movingenable=false;
class controlsBackground 
{
	class Background
		{
		idc = 1900;
		type = CT_STATIC;
		style = ST_LEFT;
		x = safeZoneX + (safeZoneW / 2) - ((safezoneW*0.15)/2);
		y = safeZoneY + (safeZoneH / 2) - ((0.05*safezoneH));
		w = 0.15 * safezoneW;
		h = 0.14 * safezoneH;
		colorBackground[] = {0.1,0.1,0.1,0.7};
		colorText[] = {0,0,0,0};
		font = GUI_FONT_NORMAL;
		sizeEx = 0.04;
		text = "";
		moving = 0;
	};
	
};
class controls 
{
	
class Text_1901: RscText
{
	idc = 1901;
	text = "Do you want to travel here?";
	x = safeZoneX + (safeZoneW / 2) - ((safezoneW*0.12)/2);
	y = safeZoneY + (safeZoneH / 2) - ((0.055*safezoneH));
	w = 0.2 * safezoneW;
	h = 0.055 * safezoneH;
};


class RscButton_1902: RscButton
{
	idc = 1902;
	x = safeZoneX + (safeZoneW / 2) - ((safezoneW*0.05) + (((safezoneW*0.05))/2));
	y = safeZoneY + (safeZoneH / 2) + (2*(0.03*safezoneH));
	w = safezoneW*0.05;
	h = 0.03*safezoneH;
	text = "YES";
	action = "[(ctrlText 1904)] execVM 'Scripts\Fex_FastTravel\confirm.sqf'";
};

class RscButton_1903: RscButton
{
	idc = 1903;
	x = safeZoneX + (safeZoneW / 2) + ((safezoneW*0.05)/2);
	y = safeZoneY + (safeZoneH / 2) + (2*(0.03*safezoneH));
	w = safezoneW*0.05;
	h = 0.03*safezoneH;
	text = "NO";
	action = "closedialog 0";
};
class InternalText_1904: RscText
{
	idc = 1904;
	text = "Internal";
	x = safeZoneW*2;
	y = safeZoneH*2;
	w = 0.2 * safezoneW;
	h = 0.055 * safezoneH;
};

};
};