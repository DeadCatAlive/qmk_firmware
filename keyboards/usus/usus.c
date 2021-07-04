#include QMK_KEYBOARD_H
#include "usus.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
  return process_record_user(keycode, record);
}
