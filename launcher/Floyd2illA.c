/*
 * Last updated: Oct 12, 2008
 * ~Keripo
 *
 * Copyright (C) 2008 Keripo
 *
 * This program is free software; you can redistribute it and/or modify
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
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "browser-ext.h"

static PzModule *module;

static PzWindow *fastlaunch()
{
	pz_exec_kill("/opt/Zillae/Floyd2illA/Launch/Launch.sh");
	return NULL;
}

static PzWindow *readme()
{
	return pz_new_textview_window(
		"/opt/Zillae/Floyd2illA/ReadMe from Keripo.txt");
}

static void init_launch() 
{
	module = pz_register_module("Floyd2illA", 0);
	pz_menu_add_stub_group("/Zillae/Floyd2illA", "PZ0 Based");
	pz_menu_add_action_group("/Zillae/Floyd2illA/#FastLaunch", "#FastLaunch", fastlaunch);
	pz_menu_add_action_group("/Zillae/Floyd2illA/~ReadMe", "#FastLaunch", readme);
	pz_menu_sort("/Zillae/Floyd2illA");
}

PZ_MOD_INIT (init_launch)
