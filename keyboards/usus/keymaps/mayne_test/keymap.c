#include "usus.h"
#include "keymap_german.h"
#include <sendstring_german.h>
#include <print.h>
#include QMK_KEYBOARD_H

#define _____ KC_NO

#define layer_switch_time 500

enum custom_keycodes {
  KC_MCR1 = SAFE_RANGE,
  KC_MCR2,
  KC_MCR3,
  KC_MCR4,
  KC_MCR5
};

enum layers {
  _LAYER0,
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9
};

uint16_t layer_switch_timer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_LAYER0] = LAYOUT( 
  RESET, _____, KC_P7, KC_P8, KC_P9, _____,               _____, KC_P7, KC_P8, KC_P9, _____, RESET, 
  _____, _____, KC_P4, KC_P5, KC_P6, _____,               _____, KC_P4, KC_P5, KC_P6, _____, _____, 
  _____, _____, KC_P1, KC_P2, KC_P3, _____,               _____, KC_P1, KC_P2, KC_P3, _____, _____, 
  _____, _____, _____, _____, KC_P0, _____, _____, _____, _____, _____, _____, KC_P0, _____, _____, 
                _____, _____, _____, _____, _____, _____, _____, _____, _____, _____, 
                                            _____, _____
),

[_LAYER1] = LAYOUT( 
  RESET, _____, KC_MCR4, KC_MCR5, KC_PENT, _____,               _____, KC_MCR4, KC_MCR5, KC_PENT, _____, _____, 
  _____, _____, KC_MCR2, KC_LALT, KC_MCR1, _____,               _____, KC_MCR2, KC_LALT, KC_MCR1, _____, _____, 
  _____, _____, KC_MINS, KC_BSPC, KC_PLUS, _____,               _____, KC_MINS, KC_BSPC, KC_PLUS, _____, _____, 
  _____, _____, _____,   _____,   KC_SPC,  _____, _____, _____, _____, _____,   _____,   KC_SPC,  _____, _____, 
                _____,   _____,   _____,   _____, _____, _____, _____, _____,   _____,   _____, 
                                                  _____, _____
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
static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

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
  // switch (biton32(layer_state)) {
  //   case _BASE:
  //     oled_write_P(PSTR("Base\n"), false);
  //     break;
  //   case _SYMBOLS:
  //     oled_write_P(PSTR("$ymb1\n"), false);
  //     break;
  //   case _NUMPAD:
  //     oled_write_P(PSTR("Num\n"), false);
  //     break;
  //   case _NAVIGATION:
  //     oled_write_P(PSTR("Nav\n"), false);
  //     break;
  //   case _GAMING:
  //     oled_write_P(PSTR("Gayms\n"), false);
  //     break;
  //   default:
  //     oled_write_ln_P(PSTR("Undef"), false);
  // }
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
    case KC_P0:
      {
        if (record->event.pressed) {
          uprint("P0 pressed\n");
          layer_switch_timer = timer_read();
        } else {
          uprintf("P0 pressed else, Timer: \n", layer_switch_timer);
          if (timer_elapsed(layer_switch_timer) > layer_switch_time) {
            layer_move(_LAYER1);
          } else {
            tap_code16(KC_P0);
          }
        }
      }
      return false;
      break;
    case KC_SPC:
      {
        if (record->event.pressed) {
          uprint("SPC pressed\n");
          layer_switch_timer = timer_read();
        } else {
          uprintf("SPC pressed else, Timer: \n", layer_switch_timer);
          if (timer_elapsed(layer_switch_timer) > layer_switch_time) {
            layer_move(_LAYER0);
          } else {
            tap_code16(KC_SPC);
          }
        }
      }
      return false;
      break;
    case KC_MCR1:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("w"));
            return false;
        }
        break;
    case KC_MCR2:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT("q"));
            return false;
        }
        break;
    case KC_MCR3:
 
        break;
    case KC_MCR4:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL("z"));
            return false;
        }
        break;
    case KC_MCR5:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTRL(SS_LSFT("z")));
            return false;
        }
        break;
    }
  return true;
}
