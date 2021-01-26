#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define MAC  1 // mac
#define SYMB 2 // symbols
#define MDIA 3 // media keys
#define CSOR 4 // cusor keys

/*
 * Alias
 */
#define KC_RCLC KC_APP  // 右クリック
#define KC_WIN  KC_LGUI // Windows

/*
 * JIS Keymap
 */
#define JP_COLN KC_QUOT  // : shift *
#define JP_AT   KC_LBRC  // @ shift `
#define JP_HAT  KC_EQL   // ^ shift ~
#define JP_BSLS KC_RO    // \ (Back Slash) shift _
#define JP_YEN  KC_JYEN  // \ (YEN) shift |
#define JP_LBRC KC_RBRC  // [ shift {
#define JP_RBRC KC_BSLS  // ] shift }
#define JP_ZKHK KC_GRV   // 半角/全角
#define JP_HNKN KC_HENK  // 変換
#define JP_MHKN KC_MHEN  // 無変換

#define JP_QUOT KC_AMPR  // '
#define JP_DQOT KC_AT    // "
#define JP_BQOT KC_LCBR  // `
#define JP_TILD KC_PLUS  // ~
#define JP_LPRN KC_ASTR  // (
#define JP_RPRN KC_LPRN  // )
#define JP_LCBR KC_RCBR  // {
#define JP_RCBR KC_PIPE  // }
#define JP_EXLM KC_EXLM  // !
#define JP_HASH KC_HASH  // #
#define JP_PERC KC_PERC  // %
#define JP_DLR  KC_DLR   // $
#define JP_AMPR KC_CIRC  // &
#define JP_PIPE LSFT(KC_JYEN) // |

/*
 * mac
 */

#define KC_MCMD KC_LGUI   // command
#define KC_MOPT KC_LALT   // option
#define KC_MEIS KC_LANG2  // 英数
#define KC_MKAN KC_LANG1  // かな

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  ESC   |   1! |   2" |   3# |   4$ |   5% |Insert|           |  ^~  |   6& |   7' |   8( |   9) |   0  |   -=   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  TAB   |   Q  |   W  |   E  |   R  |   T  |  DEL |           | NONE |   Y  |   U  |   I  |   O  |   P  |   @`   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | RCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;+ |   :*   |
 * |--------+------+------+------+------+------|  L1  |           |  BS  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /? |   \_   |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |LCtrl |  Win | LAlt | Left |  MHK |                                       |  HK  |   [  |   ]  |   \| |  RS  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  |  mac |       | Print Screen | Scroll Lock |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space| LCtrl|------|       |------|  Enter |  L1  |
 *                                 | Shift|      | LAlt |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,    KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,    KC_E,   KC_R,   KC_T,   KC_DELT,
        KC_RCTL,        KC_A,         KC_S,    KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,    KC_C,   KC_V,   KC_B,   TG(SYMB),
        KC_LCTL,        KC_WIN,       KC_LALT, KC_LEFT,JP_MHKN,
                                                    TG(MDIA), TG(MAC),
                                                              KC_HOME,
                                      SFT_T(KC_SPC), KC_LCTL, KC_LALT,
        // right hand
             JP_HAT,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,         KC_MINS,
             KC_NO,       KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,         JP_AT,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,      JP_COLN,
             KC_BSPC,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,     JP_BSLS,
                                  JP_HNKN, JP_LBRC,JP_RBRC,JP_YEN,     KC_RSFT,
             KC_PSCR, KC_SLCK,
             KC_PGUP,
             KC_PGDN, KC_ENT, MO(CSOR)
    ),
[MAC] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,    KC_3,   KC_4,   KC_5,   KC_INS,
        KC_TAB,         KC_Q,         KC_W,    KC_E,   KC_R,   KC_T,   KC_DELT,
        KC_LCTL,        KC_A,         KC_S,    KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,    KC_C,   KC_V,   KC_B,   TG(SYMB),
        KC_MCMD,        KC_MOPT,      KC_LALT, KC_LEFT,KC_MEIS,
                                                    TG(MDIA), TG(MAC),
                                                              KC_HOME,
                                      SFT_T(KC_SPC), KC_LCTL, KC_LALT,
        // right hand
             JP_HAT,      KC_6,   KC_7,  KC_8,   KC_9,   KC_0,         KC_MINS,
             KC_NO,       KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,         JP_AT,
                          KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN,      JP_COLN,
             KC_BSPC,     KC_N,   KC_M,  KC_COMM,KC_DOT, KC_SLSH,     JP_BSLS,
                                  KC_MKAN, JP_LBRC,JP_RBRC,JP_YEN,     KC_RSFT,
             KC_PSCR, KC_SLCK,
             KC_PGUP,
             KC_PGDN, KC_ENT, MO(CSOR)
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   %  |   '  |   "  |   `  |   |  |      |           |      |  YEN | PgDn |  Up  | PgUp |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   $  |   (  |   [  |   {  |   &  |------|           |------|   #  | Left | Down | Right|      |  Enter |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |   ^  | Home | NONE | End  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |      |      |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,JP_PERC,JP_QUOT,JP_DQOT,JP_BQOT,JP_PIPE,KC_TRNS,
       KC_TRNS,JP_DLR, JP_LPRN,JP_LBRC,JP_LCBR,JP_AMPR,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, JP_YEN,  KC_PGDN, KC_UP,   KC_PGUP, KC_TRNS, KC_F12,
                JP_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_ENT,
       KC_TRNS, JP_HAT,  KC_HOME, KC_NO,   KC_END,  KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |Browser back|      |      |      |      |   *  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |   7  |   8  |   9  |   -  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM |      |      | Lclk | Rclk |                                       |   0  |      |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       VRSN,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
          EPRM, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_WBAK,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ASTR, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TRNS,
                 KC_TRNS, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_TRNS,
                          KC_0,    KC_NO,   KC_DOT,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Cusor and Symbol keys Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   "  |   #  |   $  |   %  |      |           |      |      | NONE |  Up  | NONE |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   &  |   '  |   (  |   )  |   |  |------|           |------| HOME | Left | Down | Right| END  |  Enter |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | PgDn | PgUp | NONE |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[CSOR] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, JP_EXLM, JP_DQOT, JP_HASH, JP_DLR,  JP_PERC, KC_TRNS,
       KC_TRNS, JP_AMPR, JP_QUOT, JP_LPRN, JP_RPRN, JP_PIPE,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_TRNS, KC_NO,   KC_UP,   KC_NO,   KC_TRNS, KC_F12,
                KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_ENT,
       KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_NO,   KC_TRNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
