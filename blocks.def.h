//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"Volume: ", "awk -F\"[][]\" '/Mono:/ { print $2 }' <(amixer sget Master)", 0, 		1},
	
	{"Mem: ", "free -h | awk '/^Mem/ { print $3\" / \"$2 }' | sed s/i//g",	30,		0},

	{"", "date '+%a, %b %d %I:%M %p'",					60,		0},

	{"Battery: ", "upower -i /org/freedesktop/UPower/devices/battery_BAT0 |  awk '/percentage/ {print $2}'", 60, 0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
