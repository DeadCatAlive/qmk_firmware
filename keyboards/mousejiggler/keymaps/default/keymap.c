#include "mousejiggler.h" 

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  MOUSEJIGGLERMACRO
};


static uint16_t key_timer;

bool mouse_jiggle_mode = true;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	KEYMAP(
		MOUSEJIGGLERMACRO)

};

void keyboard_post_init_user(void) {
  key_timer = timer_read();
}
void matrix_scan_user(void) {
  if (timer_elapsed(key_timer) > 10000)
  {
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
    key_timer = timer_read();
  }  
}