/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MISC_H
#define MISC_H

#include <ctype.h>
#include "defaults.h"
#include "functions.h"
#include <libs/fvwmlib.h>


/************************************************************************
 * ReapChildren - wait() for all dead child processes
 ************************************************************************/
#include <sys/types.h>
#include <sys/wait.h>

/* MB stuff: rename XmbTextEscapement() and XFreeFont() */
#ifdef I18N_MB
#ifdef __STDC__
#define XTextWidth(x,y,z)	XmbTextEscapement(x ## set,y,z)
#define XFreeFont(x,y)		XFreeFontSet(x,y ## set)
#else
#define XTextWidth(x,y,z)	XmbTextEscapement(x/**/set,y,z)
#define XFreeFont(x,y)		XFreeFontSet(x,y/**/set)
#endif
#endif

extern XGCValues Globalgcv;
extern unsigned long Globalgcm;
extern Time lastTimestamp;
extern XEvent Event;

/* Start of function prototype area.
   I wonder if there is any sequence to this stuff.

   Fvwm trivia: There were 97 commands in the fvwm command table
   when the F_CMD_ARGS macro was written.
   dje 12/19/98.
   */

/* Macro for args passed to fvwm commands... */
#define F_CMD_ARGS XEvent *eventp, Window w, FvwmWindow *tmp_win,\
unsigned long context,char *action, int *Module

void ReapChildren(void);

/* bits for GrabPointerState */
#define GRAB_NONE 0           /* the cursor is not grabed */
#define GRAB_NORMAL (1<<0)    /* DeferExecution, Move, Resize, ... */
#define GRAB_BUSY (1<<1)      /* BusyCursor stuff */
#define GRAB_MENU (1<<2)      /* a menus.c grabing */
#define GRAB_BUSYMENU (1<<3)  /* Allows menus.c to regrab the cursor */
#define GRAB_STARTUP (1<<4)   /* Startup busy cursor */

Bool GrabEm(int cursor, int grab_context);
void UngrabEm(int ungrab_context);

int flush_expose(Window w);
void WaitForButtonsUp(Bool do_handle_expose);
Bool StashEventTime (XEvent *ev);
int GetTwoArguments(char *action, int *val1, int *val2, int *val1_unit,
		    int *val2_unit);
void CoerceEnterNotifyOnCurrentWindow(void);
void NewFontAndColor(Font newfont, Pixel color, Pixel backcolor);
Bool IsRectangleOnThisPage(rectangle *rec, int desk);
void Keyboard_shortcuts(XEvent *, FvwmWindow*, int);
Bool check_if_fvwm_window_exists(FvwmWindow *fw);
int ButtonPosition(int context, FvwmWindow * t);
int truncate_to_multiple (int x, int m);

/*
** message levels for fvwm_msg:
*/
#define DBG  -1
#define INFO 0
#define WARN 1
#define ERR  2
void fvwm_msg(int type,char *id,char *msg,...);

/* needed in misc.h */
typedef enum {
  ADDED_NONE = 0,
  ADDED_MENU,
#ifdef USEDECOR
  ADDED_DECOR,
#endif
  ADDED_FUNCTION
} last_added_item_type;
void set_last_added_item(last_added_item_type type, void *item);

#endif /* MISC_H */
