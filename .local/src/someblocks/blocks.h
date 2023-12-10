// Modify this file to change what commands output to your statusbar, and recompile using the make command.
// https://glyphsearch.com
// https://www.nerdfonts.com/cheat-sheet
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"󰒍 ", "ip addr | grep 'inet ' | cut -d ' ' -f6 | sed -n 2p | cut -f1 -d'/' ",	60,		0},
	{"󰍛 ", "echo \"$[100-$(vmstat 1 2|tail -1|awk '{print $15}')]\"%",	3,		0},
	{"󰘚 ", "free -h | awk '/^Mem/ { print $3 }' | sed s/i//g",	3,		0},
	{"", "cat /tmp/dwl-keymap",					0,		10},
	{"", "date '+%d/%m %H:%M'",					15,		0},
};

// sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 3;
