/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _SDL_CTX_H
#define _SDL_CTX_H

#include "SDL.h"
#include "SDL_version.h"

#if SDL_VERSION_ATLEAST(1, 3, 0)
#define SDL_MODERN 1
#else
#define SDL_MODERN 0
#endif

// Not legal to cast (void*) to fn-pointer. Need workaround to be compliant.
#define SDL_SYM_WRAP(sym, symbol) { \
   rarch_assert(sizeof(void*) == sizeof(void (*)(void))); \
   void *sym__ = SDL_GL_GetProcAddress(symbol); \
   memcpy(&(sym), &sym__, sizeof(void*)); \
}

#endif
