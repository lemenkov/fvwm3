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

#ifndef ADD_WINDOW_H
#define ADD_WINDOW_H

extern char NoName[];
extern char NoClass[];
extern char NoResource[];

void setup_focus_policy(FvwmWindow *tmp_win);
void setup_style_and_decor(FvwmWindow *tmp_win, window_style *pstyle);
void setup_auxiliary_windows(FvwmWindow *tmp_win, Bool setup_frame_and_parent);
void setup_key_and_button_grabs(FvwmWindow *tmp_win);
void setup_frame_geometry(FvwmWindow *tmp_win);
void destroy_auxiliary_windows(
  FvwmWindow *Tmp_win, Bool destroy_frame_and_parent);

void FetchWmProtocols(FvwmWindow *);
FvwmWindow *AddWindow(Window w, FvwmWindow *ReuseWin);
void GetWindowSizeHints(FvwmWindow *);
void free_window_names (FvwmWindow *tmp, Bool nukename, Bool nukeicon);
void destroy_window(FvwmWindow *);
void RestoreWithdrawnLocation(FvwmWindow *, Bool);

#endif /* ADD_WINDOW_H */
