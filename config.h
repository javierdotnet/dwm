/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 24;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
// static const char *fonts[]          = { "Ubuntu:size=10", "ubuntu:pixelsize=10:antialias=true:autohint=true"  };
static const char *fonts[]          = { "SFProDisplay-Regular:size=12", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
//
static char dmenufont[]             = "SFProDisplay-Regular:size=14";

//"-*-Ubuntu-r-*-*-16-*-*-*-*-*-*-*";

static const unsigned int transparency = 1;

static const char *rootmenu[] = { "/home/javier/.local/bin/rootmenu.sh", NULL };


static char normbordercolor[] = "#116747";
static char normbgcolor[]     = "#040404";
static char normfgcolor[]     = "#FFFFFF";
static char selbordercolor[]  = "#22E19A";
static char selbgcolor[]      = "#116747";
static char selfgcolor[]      = "#FFFFFF";


static char *colors[][3] = {
                // fg           bg           border   
	[SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
	[SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },

	[SchemeStatus]  = { selfgcolor, normbgcolor,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { normfgcolor, normbordercolor,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { selbordercolor, normbgcolor,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { selfgcolor ,normbgcolor,  "#000000"  }, // infobar middle  selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { selbordercolor, selbgcolor ,  "#000000"  }, // infobar middle  unselected {text,background,not used but cannot be empty}


};


/*
static const char *colors[][3]      = {
    //           fg         bg         border   
    [SchemeNorm] = { col_gray, col_bar, col_gray },
    [SchemeSel]  = { col_white, col_gray,  col_blue4  },
    [SchemeStatus]  = { col_white, col_bar,  "#000000"  }, // Statusbar right {text,background,not used but cannot be empty}
    [SchemeTagsSel]  = { col_blue4, col_bar,  "#000000"  }, // Tagbar left selected {text,background,not used but cannot be empty}
    [SchemeTagsNorm]  = { col_gray4, col_bar,  "#000000"  }, // Tagbar left unselected {text,background,not used but cannot be empty}
    [SchemeInfoSel]  = { col_blue4, col_bar3,  "#000000"  }, // infobar middle selected {text,background,not used but cannot be empty}
    [SchemeInfoNorm]  = { col_bar, col_bar,  "#000000"  }, // infobar middle unselected {text,background,not used but cannot be empty}
};
*/

/*

static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#37474F";
static const char col_border[]        = "#42A5F5";
static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3]      = {
//                     fg         bg         border   
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_border  },
	// [SchemeHid]  = { col_cyan,  col_gray1, col_border  },
};

*/


typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"urxvt", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"urxvt", "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
};

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9","10","11","12","13" };
// static const char *tags[] = { "1:web", "2:term", "3:dev", "4:misc" };
// static const char *tags[] = { "main", "web", "mail", "docs", "media", "rss", "social", "code", "misc" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

#include "rules.h"
#include "maximize.c"


/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
 	{ "[]=",	tile },			/* Default: Master on left, slaves on right */
	{ "TTT",	bstack },		/* Master on top, slaves on bottom */

	{ "[@]",	spiral },		/* Fibonacci spiral */
	{ "[\\]",	dwindle },		/* Decreasing in size right and leftward */

	{ "H[]",	deck },			/* Master on left, slaves in monocle-like mode on right */
 	{ "[M]",	monocle },		/* All windows on top of eachother */

	{ "|M|",	centeredmaster },		/* Master in middle, slaves on sides */
	{ ">M>",	centeredfloatingmaster },	/* Same but master floats */

	{ "><>",	NULL },			/* no layout function means floating behavior */
	{ NULL,		NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define MODKEY2 Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
#define STACKKEYS(MOD,ACTION) \
	{ MOD,	XK_j,	ACTION##stack,	{.i = INC(+1) } }, \
	{ MOD,	XK_k,	ACTION##stack,	{.i = INC(-1) } }, \
	{ MOD,  XK_v,   ACTION##stack,  {.i = 0 } }, \
	/* { MOD, XK_grave, ACTION##stack, {.i = PREVSEL } }, \ */
	/* { MOD, XK_a,     ACTION##stack, {.i = 1 } }, \ */
	/* { MOD, XK_z,     ACTION##stack, {.i = 2 } }, \ */
	/* { MOD, XK_x,     ACTION##stack, {.i = -1 } }, */

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run","-b", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "kitty", NULL };
static const char *browsercmd[]  = { "firefox-developer-edition", NULL };
static const char *screenshotcmd[] = { "flameshot", "gui", NULL };
static const char *instantswitchcmd[] = {"rofi", "-show", "window", "-kb-row-down", "Alt+Tab,Down", "-kb-row-up", "Alt+Ctrl+Tab,Up", "-kb-accept-entry", "!Alt_L,!Alt+Tab,Return", "-me-select-entry", "", "-me-accept-entry", "MousePrimary", NULL};

static const char *playernext[] = {"playerctl", "next", NULL};
static const char *playerprevious[] = {"playerctl", "previous", NULL};
static const char *playerpause[] = {"playerctl", "play-pause", NULL};


#include <X11/XF86keysym.h>
#include "shiftview.c"
#include "keysButtons.c"
