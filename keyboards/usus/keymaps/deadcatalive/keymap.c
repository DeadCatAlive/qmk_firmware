#include "usus.h"
#include "keymap_german.h"
#include <print.h>
#include QMK_KEYBOARD_H

#define ____ KC_TRANSPARENT
#define KC_RESET RESET
#define MY_ESC LT(_NAVIGATION, KC_ESC)
#define MY_SPC LT(_SYMBOLS, KC_SPACE)
#define MY_ENT LT(_NUMPAD, KC_ENTER)
#define MY_BSPC LT(_SYMBOLS, KC_BSPC)
#define MY_DEL LT(_NUMPAD, KC_DEL)

bool sarcasm_active = false;

enum usus_layers {
  _BASE,
  _SYMBOLS,
  _NUMPAD,
  _NAVIGATION,
  _GAMING,
  _SARCASM,
};

enum my_keycodes {
  MY_GAME = SAFE_RANGE,
  MY_SARC
};
 

enum combo_events {
  COMBO_Q1 = 0,
  COMBO_W2,
  COMBO_E3,
  COMBO_R4,
  COMBO_T5,
  COMBO_Y6,
  COMBO_U7,
  COMBO_I8,
  COMBO_O9,
  COMBO_P0,
  COMBO_12,
  COMBO_90,
  COMBO_UE,
  COMBO_OE,
  COMBO_AE,
  COMBO_SS,
  COMBO_GAMING
};

const uint16_t PROGMEM combo_Q1[] = {DE_Q, DE_1, COMBO_END};
const uint16_t PROGMEM combo_W2[] = {DE_W, DE_2, COMBO_END};
const uint16_t PROGMEM combo_E3[] = {DE_E, DE_3, COMBO_END};
const uint16_t PROGMEM combo_R4[] = {DE_R, DE_4, COMBO_END};
const uint16_t PROGMEM combo_T5[] = {DE_T, DE_5, COMBO_END};
const uint16_t PROGMEM combo_Y6[] = {DE_Y, DE_6, COMBO_END};
const uint16_t PROGMEM combo_U7[] = {DE_U, DE_7, COMBO_END};
const uint16_t PROGMEM combo_I8[] = {DE_I, DE_8, COMBO_END};
const uint16_t PROGMEM combo_O9[] = {DE_O, DE_9, COMBO_END};
const uint16_t PROGMEM combo_P0[] = {DE_P, DE_0, COMBO_END};
const uint16_t PROGMEM combo_12[] = {DE_1, DE_2, COMBO_END};
const uint16_t PROGMEM combo_90[] = {DE_0, DE_9, COMBO_END};
const uint16_t PROGMEM combo_UE[] = {DE_U, DE_E, COMBO_END};
const uint16_t PROGMEM combo_OE[] = {DE_O, DE_E, COMBO_END};
const uint16_t PROGMEM combo_AE[] = {DE_A, DE_E, COMBO_END};
const uint16_t PROGMEM combo_SS[] = {DE_S, DE_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_Q1] = COMBO(combo_Q1, KC_F1),      
  [COMBO_W2] = COMBO(combo_W2, KC_F2),     
  [COMBO_E3] = COMBO(combo_E3, KC_F3),     
  [COMBO_R4] = COMBO(combo_R4, KC_F4),     
  [COMBO_T5] = COMBO(combo_T5, KC_F5),    
  [COMBO_Y6] = COMBO(combo_Y6, KC_F6),     
  [COMBO_U7] = COMBO(combo_U7, KC_F7),    
  [COMBO_I8] = COMBO(combo_I8, KC_F8),    
  [COMBO_O9] = COMBO(combo_O9, KC_F9),     
  [COMBO_P0] = COMBO(combo_P0, KC_F10),
  [COMBO_12] = COMBO(combo_12, KC_F11),
  [COMBO_90] = COMBO(combo_90, KC_F12),
  [COMBO_UE] = COMBO(combo_UE, DE_UDIA),
  [COMBO_OE] = COMBO(combo_OE, DE_ODIA),
  [COMBO_AE] = COMBO(combo_AE, DE_ADIA),
  [COMBO_SS] = COMBO(combo_SS, DE_SS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( 
  RALT_T(DE_CIRC), DE_1,         DE_2,     DE_3,  DE_4,  DE_5,                        DE_6,    DE_7,    DE_8,    DE_9,   DE_0,            RALT_T(DE_SS), 
  LALT_T(KC_TAB),  DE_Q,         DE_W,     DE_E,  DE_R,  DE_T,                        DE_Y,    DE_U,    DE_I,    DE_O,   DE_P,            LALT_T(DE_ACUT), 
  KC_LSFT       ,  DE_A,         DE_S,     DE_D,  DE_F,  DE_G,                        DE_H,    DE_J,    DE_K,    DE_L,   DE_HASH,         RSFT_T(DE_PLUS), 
  KC_LCTRL,        LGUI_T(DE_Z), DE_X,     DE_C,  DE_V,  DE_B,  KC__MUTE,  KC_MS_BTN1, DE_N,    DE_M,    DE_COMM, DE_DOT, RGUI_T(DE_MINS), MY_SARC, 
                                 ____,     ____,  ____,  MY_ESC,   MY_SPC,   MY_BSPC,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, 
                                                                MY_ENT,   MY_DEL
),

[_SYMBOLS] = LAYOUT(

  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_PAUS, DE_RABK, DE_RBRC, DE_RCBR, DE_RPRN, DE_BSLS,             DE_SLSH, DE_LPRN, DE_LCBR, DE_LBRC, DE_LABK, KC_PAUSE,
  ____,    DE_LABK, DE_LBRC, DE_LCBR, DE_LPRN, DE_SLSH,             DE_BSLS, DE_RPRN, DE_RCBR, DE_RBRC, DE_RABK, ____,
  ____,    DE_DLR,  DE_PERC, DE_PIPE, DE_AT,   DE_AMPR, ____, ____, DE_AMPR, DE_AT,   DE_PIPE, DE_PERC, DE_DLR,  ____,
                    ____,    ____,    ____,    ____,    ____, ____, ____,    ____,    ____,    ____, 
                                                        ____, ____             

),

[_NUMPAD] = LAYOUT(

  RESET, KC_PMNS, KC_PAST, KC_PSLS, KC_NUMLOCK, ____,              ____,  KC_NUMLOCK, KC_PSLS, KC_PAST, KC_PMNS, RESET,
  ____,  KC_PPLS, KC_P9,   KC_P8,   KC_P7,      ____,              ____,  KC_P7,      KC_P8,   KC_P9,   KC_PPLS, ____,
  ____,  KC_PPLS, KC_P6,   KC_P5,   KC_P4,      ____,              ____,  KC_P4,      KC_P5,   KC_P6,   KC_PPLS, ____,
  ____,  KC_PENT, KC_P3,   KC_P2,   KC_P1,      ____,  ____, ____, ____,  KC_P1,      KC_P2,   KC_P3,   KC_PENT, ____,
                  ____,    KC_PENT, KC_PDOT,    KC_P0, ____, ____, KC_P0, KC_PDOT,    KC_PENT, ____,
                                                       ____, ____

),

[_NAVIGATION] = LAYOUT( 
  ____, ____,    ____,    ____,    ____,     ____,                ____,    ____,    ____,    ____,     ____,    MY_GAME,
  ____, KC_PGUP, KC_HOME,  KC_UP,   KC_END,  KC_BSPC,             KC_BSPC, KC_HOME,  KC_UP,   KC_END,  KC_PGUP, ____,
  ____, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DEL,              KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, ____,
  ____, ____,    ____,    ____,    ____,     ____,    ____, ____, ____,    ____,    ____,    ____,     ____,    ____,
                 ____,    ____,    ____,     ____,    ____, ____, ____,    ____,    ____,    ____,
                                                      ____, ____

),

[_GAMING] = LAYOUT( 
  DE_CIRC,  DE_1, DE_2,    DE_3,  DE_4,  DE_5,                    DE_6,    DE_7,    DE_8,    DE_9,     DE_0,    MY_GAME, 
  KC_TAB,   DE_Q, DE_W,    DE_E,  DE_R,  DE_T,                    DE_Y,    DE_U,    DE_I,    DE_O,     DE_P,    DE_ACUT, 
  KC_LSFT,  DE_A, DE_S,    DE_D,  DE_F,  DE_G,                    DE_H,    DE_J,    DE_K,    DE_L,     DE_HASH, DE_PLUS, 
  KC_LCTRL, DE_Z, DE_X,    DE_C,  DE_V,  DE_B,   ____,   ____,    DE_N,    DE_M,    DE_COMM, DE_DOT,   DE_MINS, KC_RSHIFT, 
                  DE_LABK, DE_ADIA, DE_ODIA, KC_ESC, KC_SPC, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, 
                                                 KC_ENT, KC_DEL 
),

[_SARCASM] = LAYOUT( 
  DE_CIRC,  DE_1, DE_2,    DE_3,  DE_4,  DE_5,                    DE_6,    DE_7,    DE_8,    DE_9,     DE_0,    DE_SS, 
  KC_TAB,   DE_Q, DE_W,    DE_E,  DE_R,  DE_T,                    DE_Y,    DE_U,    DE_I,    DE_O,     DE_P,    DE_ACUT, 
  KC_LSFT,  DE_A, DE_S,    DE_D,  DE_F,  DE_G,                    DE_H,    DE_J,    DE_K,    DE_L,     DE_HASH, DE_PLUS, 
  KC_LCTRL, DE_Z, DE_X,    DE_C,  DE_V,  DE_B,   ____,   ____,    DE_N,    DE_M,    DE_COMM, DE_DOT,   DE_MINS, MY_SARC, 
                  DE_LABK, DE_ADIA, DE_ODIA, KC_ESC, KC_SPC, KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, 
                                                 KC_ENT, KC_DEL 
),


};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  //debug_mouse=true;
}

#ifdef OLED_DRIVER_ENABLE
// static void render_logo(void) {
//   static const char PROGMEM qmk_logo[] = {
//     0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//     0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//     0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

//   oled_write_P(qmk_logo, false);
// }

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}


static void print_status_narrow(void) { 
  // Print current mode
  oled_write_P(PSTR("\n\n"), false);
  oled_write_ln_P(PSTR("MODE"), false);
  oled_write_ln_P(PSTR(""), false);
  switch (biton32(default_layer_state)) {
  case _BASE:
    oled_write_P(PSTR("QWRTY\n"), false);
    break;
  default:
    oled_write_P(PSTR("Undefined\n"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
  // Print current layer
  oled_write_ln_P(PSTR("LAYER"), false);
  switch (biton32(layer_state)) {
    case _BASE:
      oled_write_P(PSTR("Base\n"), false);
      break;
    case _SYMBOLS:
      oled_write_P(PSTR("$ymb1\n"), false);
      break;
    case _NUMPAD:
      oled_write_P(PSTR("Num\n"), false);
      break;
    case _NAVIGATION:
      oled_write_P(PSTR("Nav\n"), false);
      break;
    case _GAMING:
      oled_write_P(PSTR("Gayms\n"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Undef"), false);
  }
  oled_write_P(PSTR("\n\n"), false);
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_ln_P(led_usb_state & (1<<USB_LED_CAPS_LOCK) ? PSTR("CPSLK") : PSTR("     "), false);
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master()) {
    return OLED_ROTATION_270;
  }
  return rotation;
}

void oled_task_user(void) {
  #ifdef CONSOLE_ENABLE
    print("oled_task_user");
#endif 
  if (is_keyboard_master()) {
    print_status_narrow();
  } else {
    render_logo();
  }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

#if CONSOLE_ENABLE
    uprintf("KL: kc: %u, col: %u, row: %u, pressed: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed);
#endif 
  switch (keycode) {
    case MY_GAME:
      if (record->event.pressed)
      {
        if (biton32(layer_state) == _GAMING)
        {
          layer_off(_GAMING);
          combo_enable();
          return false;
        }
        else
        {
          layer_on(_GAMING);
          combo_disable();
          return false;
        }
      }

    case MY_SARC:
      if (record->event.pressed)
      {
        if (biton32(layer_state) == _SARCASM)
        {
          layer_off(_SARCASM);  
          combo_enable();
          return false;
        }
        else
        {
          layer_on(_SARCASM);
          combo_disable();
          return false;
        }
      }
  }

  if (biton32(layer_state) == _SARCASM && keycode >= KC_A && keycode <= KC_Z && record->event.pressed)
  {
    if (rand() % 2)
      tap_code16(S(keycode));
    else 
      tap_code(keycode);
      
    return false;
  }
  return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  // dprintf("%u index, clockwise=%u\n", index, clockwise);
  if (index == 0) { /* First encoder */
    switch(get_highest_layer(layer_state)) {
        case _BASE:
          clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
          // clockwise ? tap_code(KC_MS_WH_UP) : tap_code(KC_MS_WH_DOWN);
          break;
        case _SYMBOLS:
          clockwise ? tap_code16(C(DE_Z)) : tap_code16(C(DE_Y));
        case _NAVIGATION:
          clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
          break;
        case _GAMING:
          clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
    }
  }
  if (index == 1) {
    switch(get_highest_layer(layer_state)) {
        case _BASE:
          // clockwise ? tap_code(KC_MS_WH_UP) : tap_code(KC_MS_WH_DOWN);
          clockwise ? tap_code(KC_MS_WH_LEFT) : tap_code(KC_MS_WH_RIGHT);
          break;
    }
  }
  return false;
}
#endif

