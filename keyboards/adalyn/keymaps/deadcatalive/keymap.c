 /* Copyright TJ Campie
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */
 #include QMK_KEYBOARD_H
 
#include "users/deadcatalive/deadcatalive.h"

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

enum layers{
  _BASE,
  _SYM,
  _NUM,
  _NAV
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________,
    KC_LGUI,                       __2THUMB_L__, __2THUMB_R__,                        KC_RGUI
  ),

  [_SYM] = LAYOUT_wrapper(
    _______________SYMBOL_3x5_L1_______________, _______________SYMBOL_3x5_R1_______________,
    _______________SYMBOL_3x5_L2_______________, _______________SYMBOL_3x5_R2_______________,
    _______________SYMBOL_3x5_L3_______________, _______________SYMBOL_3x5_R3_______________, 
    _______,                   _______, _______, _______, _______,                   _______
  ),

  [_NUM] = LAYOUT_wrapper(
    _______________NUMBER_3x5_L1_______________, _______________NUMBER_3x5_R1_______________,
    _______________NUMBER_3x5_L2_______________, _______________NUMBER_3x5_R2_______________,
    _______________NUMBER_3x5_L3_______________, _______________NUMBER_3x5_R3_______________, 
    _______,                   _______, _______, _______, _______,                   _______
    ),

  [_NAV] = LAYOUT_wrapper(
    ________________NAV_3x5_L1_________________, ________________NAV_3x5_R1_________________,
    ________________NAV_3x5_L2_________________, ________________NAV_3x5_R2_________________,
    ________________NAV_3x5_L3_________________, ________________NAV_3x5_R3_________________, 
    _______,                   _______, _______, _______, _______,                   _______
  )
};
