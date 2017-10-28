#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _CSGO 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _FN1 5
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  CSGO,
  DVORAK,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// My actions
#define KC_FNET LT(_FN1, KC_ENT)
#define KC_SFTE MT(MOD_LSFT, KC_ENT)
#define KC_PRTA LGUI(LSFT(KC_3))        // Capture whole screen
#define KC_PRTP LGUI(LSFT(KC_4))        // Capture portion of screen
#define KC_CPRTA LGUI(LSFT(LCTL(KC_3)))  // Copy whole screen
#define KC_CPRTP LGUI(LSFT(LCTL(KC_4)))  // Copy portion of screen

// Mouse config
#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          0
#define MOUSEKEY_MAX_SPEED         10
#define MOUSEKEY_TIME_TO_MAX       5
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  //.--------+--------+--------+--------+--------+--------. .--------+--------+--------+--------+--------+--------.
      KC_GRV ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   KC_Y   ,  KC_U  , KC_I   ,  KC_O  , KC_P   , KC_MINS,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_TAB ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,   KC_H   ,  KC_J  , KC_K   ,  KC_L  , KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z   ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,   KC_N   ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_SFTE,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_FNET, KC_LCTL, KC_LALT,  LOWER , KC_LGUI, KC_SPC ,   KC_BSPC,  RAISE , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  //'--------+--------+--------+--------+--------+--------' '--------+--------+--------+--------+--------+--------'
),

/* Lower
 * ,-----------------------------------------. .-----------------------------------------.
 * |  ESC |   !  |   @  |   #  |   $  |   %  | |   ^  |   &  |   *  |   (  |   )  |  +   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   _  |   +  |     |    \  |  |   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |  Del |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------' '-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_ESC, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------. .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  | |   6  |   7  |   8  |   9  |   0  |  =   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  | |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 | |  F12 |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------| |------+------+------+------+------+------|
 * |      |      |      |      |      |      | |  Del |      | Play | Vol- | Vol+ | Next |
 * `-----------------------------------------' '-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT \
),

/* CS:GO */
[_CSGO] = KEYMAP( \
  //.--------+--------+--------+--------+--------+--------. .--------+--------+--------+--------+--------+--------.
      KC_1 ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,   KC_Y   ,  KC_U  , KC_I   ,  KC_O  , KC_P   , KC_MINS,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_TAB ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,   KC_H   ,  KC_J  , KC_K   ,  KC_L  , KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_Z   ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,   KC_LGUI,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_SFTE,
  //|--------+--------+--------+--------+--------+--------| |--------+--------+--------+--------+--------+--------|
      KC_LCTL, KC_Y   , KC_5   ,  KC_4 , KC_2   , KC_SPC ,   RAISE   ,  LOWER , KC_LEFT, KC_DOWN, KC_UP  , KC_FNET
  //'--------+--------+--------+--------+--------+--------' '--------+--------+--------+--------+--------+--------'
),

/* Dvorak */
[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_ADJUST] =  KEYMAP( \
  _______,  QWERTY, _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, DVORAK , _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, CSGO, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_FN1] =  KEYMAP( \
  _______, KC_F1  , KC_F2  , _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_PRTA, KC_PRTP, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
  KC_CAPS,KC_CPRTA,KC_CPRTP, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_DEL,  _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R \
),


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(CSGO_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case CSGO:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_CSGO);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
