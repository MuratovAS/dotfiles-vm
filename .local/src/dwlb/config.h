#include "../theme.h"

// use ipc functionality
static bool ipc = false;
// initially hide all bars
static bool hidden = false;
// initially draw all bars at the bottom
static bool bottom = false;
// hide vacant tags
static bool hide_vacant = false;
// vertical pixel padding above and below text
static uint32_t vertical_padding = 1;
// allow in-line color commands in status text
static bool status_commands = true;
// center title text
static bool center_title = false;
// use title space as status text element
static bool custom_title = false;
// scale
static uint32_t buffer_scale = 1;
// font
static char *fontstr = _fontSize;
// tag names
static char *tags_names[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

// set 16-bit colors for bar
// 8-bit color can be converted to 16-bit color by simply duplicating values e.g
// 0x55 -> 0x5555, 0xf1 -> 0xf1f1
#define COLOR(hex)    { (((hex >> 24) & 0xFF) << 8) + ((hex >> 24) & 0xFF), \
                        (((hex >> 16) & 0xFF) << 8) + ((hex >> 16) & 0xFF), \
                        (((hex >> 8) & 0xFF) << 8) + ((hex >> 8) & 0xFF), \
                        ((hex & 0xFF) << 8) +  ((hex & 0xFF))}
    
// static pixman_color_t active_fg_color           = COLOR(0xeeeeeeff);
// static pixman_color_t active_bg_color           = COLOR(0x005577ff);
// static pixman_color_t occupied_fg_color         = COLOR(0xeeeeeeff);
// static pixman_color_t occupied_bg_color         = COLOR(0x005577ff);
// static pixman_color_t inactive_fg_color         = COLOR(0xbbbbbbff);
// static pixman_color_t inactive_bg_color         = COLOR(0x222222ff);
// static pixman_color_t urgent_fg_color           = COLOR(0x222222ff);
// static pixman_color_t urgent_bg_color           = COLOR(0xeeeeeeff);
// static pixman_color_t middle_bg_color           = COLOR(0x222222ff);
// static pixman_color_t middle_bg_color_selected  = COLOR(0x005577ff);

static pixman_color_t active_fg_color           = COLOR(_activeTextColor);
static pixman_color_t active_bg_color           = COLOR(_activeBgColor);
static pixman_color_t occupied_fg_color         = COLOR(_occupiedTextColor);
static pixman_color_t occupied_bg_color         = COLOR(_occupiedBgColor);
static pixman_color_t inactive_fg_color         = COLOR(_inactiveTextColor);
static pixman_color_t inactive_bg_color         = COLOR(_inactiveBgColor);
static pixman_color_t urgent_fg_color           = COLOR(_urgentTextColor);
static pixman_color_t urgent_bg_color           = COLOR(_urgentBgColor);
static pixman_color_t middle_bg_color           = COLOR(_inactiveBgColor);
static pixman_color_t middle_bg_color_selected  = COLOR(_inactiveBgColor);