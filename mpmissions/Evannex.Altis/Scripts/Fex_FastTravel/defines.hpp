// Control types
#define CT_STATIC           0
#define CT_BUTTON           1
#define CT_EDIT             2
#define CT_SLIDER           3
#define CT_COMBO            4
#define CT_LISTBOX          5
#define CT_TOOLBOX          6
#define CT_CHECKBOXES       7
#define CT_PROGRESS         8
#define CT_HTML             9
#define CT_STATIC_SKEW      10
#define CT_ACTIVETEXT       11
#define CT_TREE             12
#define CT_STRUCTURED_TEXT  13
#define CT_CONTEXT_MENU     14
#define CT_CONTROLS_GROUP   15
#define CT_SHORTCUTBUTTON   16
#define CT_XKEYDESC         40
#define CT_XBUTTON          41
#define CT_XLISTBOX         42
#define CT_XSLIDER          43
#define CT_XCOMBO           44
#define CT_ANIMATED_TEXTURE 45
#define CT_OBJECT           80
#define CT_OBJECT_ZOOM      81
#define CT_OBJECT_CONTAINER 82
#define CT_OBJECT_CONT_ANIM 83
#define CT_LINEBREAK        98
#define CT_USER             99
#define CT_MAP              100
#define CT_MAP_MAIN         101
#define CT_LISTNBOX         102

// Static styles
#define ST_POS            0x0F
#define ST_HPOS           0x03
#define ST_VPOS           0x0C
#define ST_LEFT           0x00
#define ST_RIGHT          0x01
#define ST_CENTER         0x02
#define ST_DOWN           0x04
#define ST_UP             0x08
#define ST_VCENTER        0x0C
#define ST_GROUP_BOX       96
#define ST_GROUP_BOX2      112
#define ST_ROUNDED_CORNER  ST_GROUP_BOX + ST_CENTER
#define ST_ROUNDED_CORNER2 ST_GROUP_BOX2 + ST_CENTER

#define ST_TYPE           0xF0
#define ST_SINGLE         0x00
#define ST_MULTI          0x10
#define ST_TITLE_BAR      0x20
#define ST_PICTURE        0x30
#define ST_FRAME          0x40
#define ST_BACKGROUND     0x50
#define ST_GROUP_BOX      0x60
#define ST_GROUP_BOX2     0x70
#define ST_HUD_BACKGROUND 0x80
#define ST_TILE_PICTURE   0x90
#define ST_WITH_RECT      0xA0
#define ST_LINE           0xB0

#define ST_SHADOW         0x100
#define ST_NO_RECT        0x200
#define ST_KEEP_ASPECT_RATIO  0x800

#define ST_TITLE          ST_TITLE_BAR + ST_CENTER

// Slider styles
#define SL_DIR            0x400
#define SL_VERT           0
#define SL_HORZ           0x400

#define SL_TEXTURES       0x10

// progress bar 
#define ST_VERTICAL       0x01
#define ST_HORIZONTAL     0

// Listbox styles
#define LB_TEXTURES       0x10
#define LB_MULTI          0x20

// Tree styles
#define TR_SHOWROOT       1
#define TR_AUTOCOLLAPSE   2

// MessageBox styles
#define MB_BUTTON_OK      1
#define MB_BUTTON_CANCEL  2
#define MB_BUTTON_USER    4
// Fonts
#define GUI_FONT_NORMAL			PuristaMedium
#define GUI_FONT_BOLD			PuristaSemibold
#define GUI_FONT_THIN			PuristaLight
#define GUI_FONT_MONO			EtelkaMonospacePro
#define GUI_FONT_NARROW			EtelkaNarrowMediumPro
#define GUI_FONT_CODE			LucidaConsoleB
#define GUI_FONT_SYSTEM			TahomaB



class _CT_SLIDER_Value // Slider value (see below)
		{
			access = 0;
			idc = 1200;
			type = CT_STATIC
			style = ST_CENTER;
			blinkingPeriod = 0;
			x = 8 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 6.75 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = 3 * GUI_GRID_CENTER_W; // Width
			h = 1 * GUI_GRID_CENTER_H; // Height
			colorBackground[] = {0,0,0,0};
			fixedWidth = 0;
		};
class _CT_SLIDER
		{
			access = 0; // Control access (0 - ReadAndWrite, 1 - ReadAndCreate, 2 - ReadOnly, 3 - ReadOnlyVerified)
			idc = CT_SLIDER; // Control identification (without it, the control won't be displayed)
			type = CT_SLIDER; // Type
			style = SL_HORZ; // Style
			default = 0; // Control selected by default (only one within a display can be used)
			blinkingPeriod = 0; // Time in which control will fade out and back in. Use 0 to disable the effect.

			x = 1 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X; // Horizontal coordinates
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y; // Vertical coordinates
			w = SAFEZONEW - 0.2; // Width
			h = 0.1; // Height

			color[] = {0,0,0,1}; // Text color
			colorDisabled[] = {0,0,0,1}; // Disabled text color
			colorActive[] = {0,0,0,1}; // Text selection color

			tooltip = ""; // Tooltip text
			tooltipColorShade[] = {0,0,0,1}; // Tooltip background color
			tooltipColorText[] = {0,0,0,1}; // Tooltip text color
			tooltipColorBox[] = {0,0,0,1}; // Tooltip frame color

			class Title // Link to a title (obsolete?)
			{
				idc = -1; // Control IDC (has to be defined ABOVE the slider control)
				colorBase[] = {1,1,1,1}; // Text color
				colorActive[] = {1,0.5,0,1}; // Text color when the slider is active
			};
			class Value // Link to a control which will show slider value
			{
				idc = 1200; // Control IDC (has to be defined ABOVE the slider control)
				format = "%g"; // Text format, value is represented by variable %g (float) or %.f (integer)
				type = SPTPercents; // Format, can be SPTPlain or SPTPercents (multiplies the value by 100)
				colorBase[] = {0,0,0,1}; // Text color
				colorActive[] = {0,0,0,1}; // Text color when the slider is active
			};

			onDestroy = "systemChat str ['onDestroy',_this]; false";
			

			onSliderPosChanged = "FQ = _this select 1;interFQ = FQ; if ((oldFQ > 4 && oldFQ < 5)&& (interFQ > 4 && interFQ < 5)) then {systemchat 'bingo you fucker.'};oldFQ = interFQ;";
		};

		
class RscButton
{

  access = 0;
   type = CT_BUTTON;
   text = "";
   colorText[] = {1,1,1,1};
   colorDisabled[] = {1,1,1,0.85};
   colorBackground[] = {0.2,0,0,0.5};
   colorBackgroundDisabled[] = {0.2,0,0,0.5};
   colorBackgroundActive[] = {0.4,0,0,0.65};
   colorFocused[] = {0.2,0,0,0.5};
   colorShadow[] = {0.023529,0,0.0313725,1};
   colorBorder[] = {0.023529,0,0.0313725,0.39};
   soundEnter[] = {"\A3\ui_f\data\Sound\RscButtonMenu\soundEnter", 0.09, 1};
   soundPush[] = {"\A3\ui_f\data\Sound\RscButtonMenu\soundPush", 0.0, 0};
   soundClick[] = {"\A3\ui_f\data\Sound\RscButtonMenu\soundClick", 0.07, 1};
   soundEscape[] = {"\A3\ui_f\data\Sound\RscButtonMenu\soundEscape", 0.09, 1};
   style = 2 + ST_BACKGROUND + ST_SHADOW + ST_KEEP_ASPECT_RATIO;
   x = 0;
   y = 0;
   w = 0.055589;
   h = 0.039216;
   shadow = 0;
   font = "puristaMedium";
   sizeEx = 0.03921;
   offsetX = 0.000;
   offsetY = 0.000;
   offsetPressedX = 0.002;
   offsetPressedY = 0.002;
   borderSize = 0;
};

class RscText
{
 access = 0;
 type = CT_STATIC;
 idc = -1;
 style = ST_LEFT;
 w = 0.1; h = 0.05;
 //x and y are not part of a global class since each rsctext will be positioned 'somewhere'
 font = "puristaMedium";
 sizeEx = 0.035;
 colorBackground[] = {0,0,0,0};
 colorText[] = {1,1,1,1};
 text = "";
 fixedWidth = 0;
 shadow = 0;
};