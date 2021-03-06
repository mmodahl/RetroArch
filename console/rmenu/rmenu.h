/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
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

#ifndef _RMENU_H_
#define _RMENU_H_

#if defined(__CELLOS_LV2__)
#define DEVICE_CAST gl_t*
#define input_ptr input_ps3
#define video_ptr video_gl

#elif defined(_XBOX1)
#define DEVICE_CAST xdk_d3d_video_t*
#define input_ptr input_xinput
#define video_ptr video_xdk_d3d

#endif

typedef struct
{
   unsigned char enum_id;		/* enum ID of item				*/
   char text[64];			/* item label					*/
   char setting_text[64];		/* setting label				*/
   char comment[192];			/* item comment					*/
   unsigned char page;			/* page						*/
} item;

typedef struct rmenu_position
{
   float x;
   float y;
   float width;
   float height;
} rmenu_position_t;

typedef struct rmenu_default_positions
{
   float x_position;
   float x_position_center;
   float y_position;
   float comment_y_position;
   float y_position_increment;
   float starting_y_position;
   float comment_two_y_position;
   float font_size;
   float msg_queue_x_position;
   float msg_queue_y_position;
   float msg_queue_font_size;
   float msg_prev_next_y_position;
   float current_path_font_size;
   float current_path_y_position;
   float variable_font_size;
   float core_msg_x_position;
   float core_msg_y_position;
   float core_msg_font_size;
   unsigned entries_per_page;
} rmenu_default_positions_t;

typedef struct rmenu_context
{
   void (*clear)(void); 
   void (*blend)(bool enable);
   void (*free_textures)(void);
   void (*init_textures)(void);
   void (*render_selection_panel)(rmenu_position_t *position);
   void (*render_bg)(rmenu_position_t *position);
   void (*render_menu_enable)(bool enable);
   void (*render_msg)(float xpos, float ypos, float scale, unsigned color, const char *msg, ...);
   void (*screenshot_enable)(bool enable);
   void (*screenshot_dump)(void *data);
   void (*swap_buffers)(void);
   void (*set_default_pos)(rmenu_default_positions_t *position);
   const char * (*drive_mapping_prev)(void);
   const char * (*drive_mapping_next)(void);
} rmenu_context_t;

enum
{
   CATEGORY_FILEBROWSER,
   CATEGORY_SETTINGS,
   CATEGORY_INGAME_MENU
};

enum
{
   FILE_BROWSER_MENU,
   GENERAL_VIDEO_MENU,
   GENERAL_AUDIO_MENU,
   EMU_GENERAL_MENU,
   EMU_VIDEO_MENU,
   EMU_AUDIO_MENU,
   PATH_MENU,
   CONTROLS_MENU,
   SHADER_CHOICE,
   PRESET_CHOICE,
   BORDER_CHOICE,
   LIBRETRO_CHOICE,
   PATH_SAVESTATES_DIR_CHOICE,
   PATH_DEFAULT_ROM_DIR_CHOICE,
#ifdef HAVE_XML
   PATH_CHEATS_DIR_CHOICE,
#endif
   PATH_SRAM_DIR_CHOICE,
   PATH_SYSTEM_DIR_CHOICE,
   INPUT_PRESET_CHOICE,
   INGAME_MENU,
   INGAME_MENU_RESIZE,
   INGAME_MENU_SCREENSHOT
};

enum
{
#ifdef __CELLOS_LV2__
   SETTING_CHANGE_RESOLUTION,
#endif
#if defined(HAVE_CG) || defined(HAVE_HLSL) || defined(HAVE_GLSL)
   SETTING_SHADER_PRESETS,
   SETTING_SHADER,
   SETTING_SHADER_2,
#endif
   SETTING_FONT_SIZE,
   SETTING_KEEP_ASPECT_RATIO,
   SETTING_HW_TEXTURE_FILTER,
#ifdef HAVE_FBO
   SETTING_HW_TEXTURE_FILTER_2,
   SETTING_SCALE_ENABLED,
   SETTING_SCALE_FACTOR,
#endif
#ifdef _XBOX1
   SETTING_FLICKER_FILTER,
   SETTING_SOFT_DISPLAY_FILTER,
#endif
   SETTING_HW_OVERSCAN_AMOUNT,
   SETTING_THROTTLE_MODE,
   SETTING_TRIPLE_BUFFERING,
   SETTING_ENABLE_SCREENSHOTS,
#if defined(HAVE_CG) || defined(HAVE_HLSL) || defined(HAVE_GLSL)
   SETTING_SAVE_SHADER_PRESET,
   SETTING_APPLY_SHADER_PRESET_ON_STARTUP,
#endif
   SETTING_DEFAULT_VIDEO_ALL,
   SETTING_SOUND_MODE,
#ifdef HAVE_RSOUND
   SETTING_RSOUND_SERVER_IP_ADDRESS,
#endif
   SETTING_ENABLE_CUSTOM_BGM,
   SETTING_DEFAULT_AUDIO_ALL,
   SETTING_EMU_CURRENT_SAVE_STATE_SLOT,
   SETTING_EMU_SHOW_DEBUG_INFO_MSG,
   SETTING_EMU_SHOW_INFO_MSG,
   SETTING_ZIP_EXTRACT,
   SETTING_RARCH_DEFAULT_EMU,
   SETTING_QUIT_RARCH,
   SETTING_EMU_DEFAULT_ALL,
   SETTING_EMU_REWIND_ENABLED,
   SETTING_EMU_VIDEO_DEFAULT_ALL,
#ifdef _XBOX1
   SETTING_EMU_AUDIO_SOUND_VOLUME_LEVEL,
#endif
   SETTING_EMU_AUDIO_MUTE,
   SETTING_EMU_AUDIO_DEFAULT_ALL,
   SETTING_PATH_DEFAULT_ROM_DIRECTORY,
   SETTING_PATH_SAVESTATES_DIRECTORY,
   SETTING_PATH_SRAM_DIRECTORY,
#ifdef HAVE_XML
   SETTING_PATH_CHEATS,
#endif
   SETTING_PATH_SYSTEM,
   SETTING_ENABLE_SRAM_PATH,
   SETTING_ENABLE_STATE_PATH,
   SETTING_PATH_DEFAULT_ALL,
   SETTING_CONTROLS_SCHEME,
   SETTING_CONTROLS_NUMBER,
   SETTING_DPAD_EMULATION,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_Y,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_SELECT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_START,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_UP,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_DOWN,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_LEFT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_RIGHT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_A,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_X,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L3,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R3,
   SETTING_CONTROLS_SAVE_CUSTOM_CONTROLS,
   SETTING_CONTROLS_DEFAULT_ALL
};

#define FIRST_VIDEO_SETTING				0
#define FIRST_AUDIO_SETTING				SETTING_DEFAULT_VIDEO_ALL+1
#define FIRST_EMU_SETTING				SETTING_DEFAULT_AUDIO_ALL+1
#define FIRST_EMU_VIDEO_SETTING				SETTING_EMU_DEFAULT_ALL+1
#define FIRST_EMU_AUDIO_SETTING				SETTING_EMU_VIDEO_DEFAULT_ALL+1
#define FIRST_PATH_SETTING				SETTING_EMU_AUDIO_DEFAULT_ALL+1
#define FIRST_CONTROLS_SETTING_PAGE_1			SETTING_PATH_DEFAULT_ALL+1
#define FIRST_CONTROL_BIND				SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B

#define MAX_NO_OF_VIDEO_SETTINGS			SETTING_DEFAULT_VIDEO_ALL+1
#define MAX_NO_OF_AUDIO_SETTINGS			SETTING_DEFAULT_AUDIO_ALL+1
#define MAX_NO_OF_EMU_SETTINGS				SETTING_EMU_DEFAULT_ALL+1
#define MAX_NO_OF_EMU_VIDEO_SETTINGS			SETTING_EMU_VIDEO_DEFAULT_ALL+1
#define MAX_NO_OF_EMU_AUDIO_SETTINGS			SETTING_EMU_AUDIO_DEFAULT_ALL+1
#define MAX_NO_OF_PATH_SETTINGS				SETTING_PATH_DEFAULT_ALL+1
#define MAX_NO_OF_CONTROLS_SETTINGS			SETTING_CONTROLS_DEFAULT_ALL+1

void menu_init (void);
void menu_loop (void);
void menu_free (void);

#endif /* MENU_H_ */
