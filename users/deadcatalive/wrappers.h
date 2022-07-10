#pragma once

#include <keymap_german.h>

#define _BAS 0
#define _SYM 1
#define _NUM 2
#define _NAV 3

#define __________________3THUMB_EMPTY_____________ _______, _______, _______
#define ____________________3x5____________________ _______, _______, _______, _______, _______

/*
#define __________________3THUMB_L_________________ LT(_NAV, KC_ESC), LT(_NUM,KC_ENT), LT(_SYM, KC_SPC)
#define __________________3THUMB_R_________________ LT(_NUM, KC_BSPC), LT(_SYM, KC_DEL), LT(_NAV, KC_ESC)

#define __________________2THUMB_L_________________ LT(_NUM,KC_ENT), LT(_SYM, KC_SPC)
#define __2THUMB_L__                                __________________2THUMB_L_________________
#define __________________2THUMB_R_________________ LT(_NUM, KC_BSPC), LT(_SYM, KC_DEL)
#define __2THUMB_R__                                __________________2THUMB_R_________________


#define _______________QWERTY_3x5_L1_______________ KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
#define _______________QWERTY_3x5_L2_______________ KC_A,         LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define _______________QWERTY_3x5_L3_______________ LGUI_T(DE_Z), KC_X,         KC_C,         KC_V,         KC_B

#define _______________QWERTY_3x5_R1_______________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _______________QWERTY_3x5_R2_______________ KC_H,    RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L), KC_DEL
#define _______________QWERTY_3x5_R3_______________ KC_N,    KC_M,         DE_COMM,      DE_DOT,       RGUI_T(DE_MINS)

#define _______________SYMBOL_3x5_L1_______________ DE_RABK, DE_RBRC, DE_RCBR, DE_RPRN, DE_BSLS
#define _______________SYMBOL_3x5_L2_______________ DE_LABK, DE_LBRC, DE_LCBR, DE_LPRN, DE_SLSH
#define _______________SYMBOL_3x5_L3_______________ DE_PIPE, DE_PERC, DE_DLR , DE_AT  , DE_AMPR

#define _______________SYMBOL_3x5_R1_______________ DE_CIRC, DE_EQL,  _______, _______, DE_PLUS
#define _______________SYMBOL_3x5_R2_______________ DE_ACUT, _______, _______, _______, DE_HASH
#define _______________SYMBOL_3x5_R3_______________ DE_EXLM, _______, _______, _______, DE_DQUO

#define _______________NUMBER_3x5_L1_______________ KC_PAST, KC_P9, KC_P8, KC_P7, DE_COMM
#define _______________NUMBER_3x5_L2_______________ KC_PPLS, KC_P6, KC_P5, KC_P4, DE_DOT
#define _______________NUMBER_3x5_L3_______________ KC_PMNS, KC_P3, KC_P2, KC_P1, KC_P0

#define _______________NUMBER_3x5_R1_______________ DE_COMM, KC_P7, KC_P8, KC_P9, KC_PAST
#define _______________NUMBER_3x5_R2_______________ DE_DOT,  KC_P4, KC_P5, KC_P6, KC_PPLS
#define _______________NUMBER_3x5_R3_______________ KC_P0,   KC_P1, KC_P2, KC_P3, KC_PMNS

#define ________________NAV_3x5_L1_________________ KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_BSPC
#define ________________NAV_3x5_L2_________________ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL
#define ________________NAV_3x5_L3_________________ ____________________3x5____________________

#define ________________NAV_3x5_R1_________________ KC_VOLU, _______, _______, _______, _______
#define ________________NAV_3x5_R2_________________ KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______
#define ________________NAV_3x5_R3_________________ ____________________3x5____________________
*/

/* Adalyn */
#define LAYOUT_wrapper_adalyn(...) LAYOUT(__VA_ARGS__)


#define QWERTY \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________

#define SYMBOLS \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________

#define NUMBERS \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________

#define NAVIGATION \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
____________________3x5____________________, ____________________3x5____________________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________


/*
#define QWERTY \
_______________QWERTY_3x5_L1_______________, _______________QWERTY_3x5_R1_______________, \
_______________QWERTY_3x5_L2_______________, _______________QWERTY_3x5_R2_______________, \
_______________QWERTY_3x5_L3_______________, _______________QWERTY_3x5_R3_______________, \
__________________3THUMB_L_________________, __________________3THUMB_R_________________

#define SYMBOLS \
_______________SYMBOL_3x5_L1_______________, _______________SYMBOL_3x5_R1_______________, \
_______________SYMBOL_3x5_L2_______________, _______________SYMBOL_3x5_R2_______________, \
_______________SYMBOL_3x5_L3_______________, _______________SYMBOL_3x5_R3_______________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________

#define NUMBERS \
_______________NUMBER_3x5_L1_______________, _______________NUMBER_3x5_R1_______________, \
_______________NUMBER_3x5_L2_______________, _______________NUMBER_3x5_R2_______________, \
_______________NUMBER_3x5_L3_______________, _______________NUMBER_3x5_R3_______________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________

#define NAVIGATION \
________________NAV_3x5_L1_________________, ________________NAV_3x5_R1_________________, \
________________NAV_3x5_L2_________________, ________________NAV_3x5_R2_________________, \
________________NAV_3x5_L3_________________, ________________NAV_3x5_R3_________________, \
__________________3THUMB_EMPTY_____________, __________________3THUMB_EMPTY_____________
*/