/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define MASTER_LEFT

#define MOUSE_INITIAL_SPEED     1500 // 1000 before
#define MOUSEKEY_BASE_SPEED     1500
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_WHEEL_DELAY    0
#define MOUSEKEY_MAX_SPEED      3
#define MOUSEKEY_TIME_TO_MAX    48 // 64 before

#define MK_COMBINED

#define MK_C_OFFSET_0           1
#define MK_C_OFFSET_1           2
#define MK_C_OFFSET_2           3

#define MK_C_INTERVAL_0         32
#define MK_C_INTERVAL_1         16
#define MK_C_INTERVAL_2         16

// Pick good defaults for enabling homerow modifiers
#define TAPPING_TERM 250
#define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD
#define COMBO_COUNT 2
#define COMBO_TERM 40
#define COMBO_SHOULD_TRIGGER
// #define COMBO_TERM_PER_COMBO
// #define CAPS_WORD_IDLE_TIMEOUT 5000
// #define COMBO_ONLY_FROM_LAYER 0