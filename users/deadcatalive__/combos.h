#pragma once

#include <keymap_german.h>

#undef COMBO_COUNT
#define COMBO_COUNT 18

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