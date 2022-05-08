/* Copyright 2021 weteor
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
#include <keymap_german.h>

enum layers
{
    _ALPHA_QWERTY = 0,
    _SYM,
    _NAV,
    _NUM,
};

const uint16_t PROGMEM combo_ue[] = {KC_U, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ae[] = {KC_A, KC_E, COMBO_END};
const uint16_t PROGMEM combo_oe[] = {KC_O, KC_E, COMBO_END};
const uint16_t PROGMEM combo_ss[] = {LALT_T(KC_S), LCTL_T(KC_D), COMBO_END};

const uint16_t PROGMEM combo_esc[] = {LSFT_T(KC_F), KC_G, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_V,         KC_B, COMBO_END};

const uint16_t PROGMEM combo_F1 [] = {KC_Q, KC_A, COMBO_END};
const uint16_t PROGMEM combo_F2 [] = {KC_W, LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM combo_F3 [] = {KC_E, LCTL_T(KC_D), COMBO_END};
const uint16_t PROGMEM combo_F4 [] = {KC_R, LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_F5 [] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM combo_F6 [] = {DE_Y, KC_H, COMBO_END};
const uint16_t PROGMEM combo_F7 [] = {KC_U, RSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combo_F8 [] = {KC_I, RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combo_F9 [] = {KC_O, RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM combo_F10[] = {KC_P, KC_DEL, COMBO_END};
const uint16_t PROGMEM combo_F11[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_F12[] = {KC_O, KC_P, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ue, DE_UDIA),
    COMBO(combo_ae, DE_ADIA),
    COMBO(combo_oe, DE_ODIA),
    COMBO(combo_ss, DE_SS),
    COMBO(combo_esc, KC_ESC),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_F1 , KC_F1),
    COMBO(combo_F2 , KC_F2),
    COMBO(combo_F3 , KC_F3),
    COMBO(combo_F4 , KC_F4),
    COMBO(combo_F5 , KC_F5),
    COMBO(combo_F6 , KC_F6),
    COMBO(combo_F7 , KC_F7),
    COMBO(combo_F8 , KC_F8),
    COMBO(combo_F9 , KC_F9),
    COMBO(combo_F10, KC_F10),
    COMBO(combo_F11, KC_F11),
    COMBO(combo_F12, KC_F12),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    
    [_ALPHA_QWERTY] = LAYOUT(
        KC_Q,         KC_W,         KC_E,         KC_R,         KC_T,                      DE_Y,    KC_U,         KC_I,         KC_O,         KC_P,  
        KC_A,         LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                      KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_DEL,
        LGUI_T(DE_Z), KC_X,         KC_C,         KC_V,         KC_B,                      KC_N,    KC_M,         DE_COMM,      DE_DOT,       RGUI_T(DE_MINS),
            
                              LT(_NAV, KC_ESC), LT(_NUM,KC_ENT), LT(_SYM, KC_SPC),    LT(_NUM, KC_BSPC), LT(_SYM, KC_DEL), LT(_NAV, KC_ESC)         
    ),
    [_SYM] = LAYOUT(
        DE_RABK, DE_RBRC, DE_RCBR, DE_RPRN, DE_BSLS,                                DE_CIRC, DE_EQL,  _______, _______, DE_PLUS,
        DE_LABK, DE_LBRC, DE_LCBR, DE_LPRN, DE_SLSH,                                DE_ACUT, _______, _______, _______, DE_HASH, 
        DE_PIPE, DE_PERC, DE_DLR , DE_AT  , DE_AMPR,                                DE_EXLM, _______, _______, _______, DE_DQUO,
                                        _______, _______, _______,     _______, _______, _______         
    ),
    [_NAV] = LAYOUT(
        KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_BSPC,                                KC_VOLU, _______, _______, _______, _______,
        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL ,                                KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______,
        _______, _______, _______, _______, _______,                                _______, _______, _______, _______, _______,
                                        _______, _______, _______,      _______, _______, _______         
    ),
    [_NUM] = LAYOUT(
        KC_PAST, KC_P9, KC_P8, KC_P7, DE_COMM,                               DE_COMM, KC_P7, KC_P8, KC_P9, KC_PAST,
        KC_PPLS, KC_P6, KC_P5, KC_P4, DE_DOT,                                DE_DOT,  KC_P4, KC_P5, KC_P6, KC_PPLS,
        KC_PMNS, KC_P3, KC_P2, KC_P1, KC_P0,                                 KC_P0,   KC_P1, KC_P2, KC_P3, KC_PMNS,
                                        _______, _______, _______,      _______, _______, KC_NLCK         
    ),
};
