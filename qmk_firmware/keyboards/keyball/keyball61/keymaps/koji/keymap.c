/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

#include "keymap_jp.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  JP = SAFE_RANGE,
  US,
  SHIFT,
  CSTM_0, CSTM_1, CSTM_2, CSTM_3, CSTM_4, CSTM_5, CSTM_6, CSTM_7, CSTM_8, CSTM_9,
  CIRC, AT, LBRC, RBRC, BSLS, AMPR, QUOT, LPRN, RPRN, EQL, TILD, PIPE, GRV, LCBR,
  PLUS, ASTR, RCBR, UNDS, MINS, SCLN, COMM, DOT, SLSH, EXLM, HASH, DLR, PERC, DEL,
  CUT,
  PASTE,
  KLLN, // Kill-line
  MARK
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_universal(
    KC_ESC   , CSTM_1   , CSTM_2   , CSTM_3   , CSTM_4   , CSTM_5   ,                                  CSTM_6   , CSTM_7   , CSTM_8   , CSTM_9   , CSTM_0   , MINS     ,
    KC_TAB   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , EQL      ,
    KC_LCTL  , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , SCLN     , QUOT     ,
    SHIFT    , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , LBRC     ,              RBRC   , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , SHIFT    ,
  MO(_ADJUST), KC_LALT  , KC_LGUI  , GRV      , MO(_LOWER),MO(_LOWER),KC_SPC   ,             KC_ENT   , KC_ENT   , _______  ,_______   , _______  , BSLS     , MO(_RAISE)
  ),

  [_LOWER] = LAYOUT_universal(
    KC_TRNS  , KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    KC_TRNS  , KC_TRNS  , CUT      , KC_END   , KC_TRNS  , KC_TRNS  ,                                  PASTE    , KC_TRNS  , KC_INS   , KC_TRNS  , KC_UP    , KC_F12   ,
    KC_TRNS  , KC_HOME  , KC_TRNS  , KC_DEL   , KC_RGHT  , KC_TRNS  ,                                  KC_BSPC  , KC_TRNS  , KLLN     , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_LSFT  , KC_TRNS  , KC_PSCR  , KC_TRNS  , KC_LEFT  , KC_TRNS  ,             KC_TRNS , KC_DOWN  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , MARK     ,             KC_TRNS , KC_TRNS  , _______  , _______  , _______  , KC_TRNS  , KC_TRNS
  ),

  [_RAISE] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_PGUP  , KC_BTN1  , KC_BTN3  , KC_BTN2  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             _______ , KC_PGDN  , CPI_D100 , CPI_I100  , _______  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             _______ , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [_ADJUST] = LAYOUT_universal(
    RGB_TOG  , _______  , _______  , _______  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , US       , _______  ,                                  CPI_D1K  , JP       , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EEP_RST  ,            EEP_RST  , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    _______  , _______  , KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , _______  ,            _______  , KC_BSPC  , _______  , _______  , _______  , _______  , _______
  ),
};
// clang-format on
/*
layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is _LOWER
    keyball_set_scroll_mode(get_highest_layer(state) == _LOWER);
    return state;
}
*/

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
}
#endif

/*
Right
1-7 -> 0-6 UG  7
8-34 -> 7-33 BL 27

Left
1-29 -> 0-28 BL 29
30-37 -> 29-36 UG 8
*/


const rgblight_segment_t PROGMEM qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // undergrow
    //{29,  8, HSV_OFF},
    //{63,  8, HSV_OFF},
    // backlight
    {0,  71, HSV_PURPLE}
    //{34, 29, HSV_WHITE}
);
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // undergrow
    //{29,   8, HSV_OFF},
    //{63,  8, HSV_OFF},
    // backlight
    {0,  71, HSV_GOLD}
    //{34, 29, HSV_GOLD}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // undergrow
    //{29,   8, HSV_OFF},
    //{63,  8, HSV_OFF},
    // backlight
    {0,  71, HSV_SPRINGGREEN}
    //{34, 29, HSV_SPRINGGREEN}
);
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    // undergrow
    //{29,   8, HSV_OFF},
    //{63,  8, HSV_OFF},
    // backlight
    {0,  71, HSV_AZURE}
    //{34, 29, HSV_AZURE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    qwerty_layer,
    lower_layer,
    raise_layer,
    adjust_layer
);
void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_QWERTY, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(_LOWER, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(_RAISE, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(_ADJUST, layer_state_cmp(state, _ADJUST));
    keyball_set_scroll_mode(get_highest_layer(state) == _LOWER);
    return state;
}

/*
https://github.com/m47ch4n/qmk_firmware/blob/add-m47ch4ns-keymap/keyboards/ergodash/rev1/keymaps/m47ch4n/keymap.c
*/

#define JP_LAYOUT true
#define US_LAYOUT false
bool LAYOUT_STATUS = JP_LAYOUT;
bool SHIFT_PRESSED = false;

#define SEND_STRING_RESTORE(STR) (SHIFT_PRESSED ? SEND_STRING(STR SS_DOWN(X_LSHIFT)) : SEND_STRING(STR SS_UP(X_LSHIFT)))

#define KEY(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_SHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_DOWN(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define KEY_UPSHIFT(CODE) (record->event.pressed ? SEND_STRING(SS_UP(X_LSHIFT) SS_DOWN(X_##CODE)) : SEND_STRING_RESTORE(SS_UP(X_##CODE)))

#define SHIFT_DU(CODE_DOWN, CODE_UP) (SHIFT_PRESSED ? CODE_DOWN : CODE_UP)
#define CASE_US(CODE, US, JP)                   \
    case CODE:                                  \
        (LAYOUT_STATUS == JP_LAYOUT ? JP : US); \
        return false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    CASE_US(CSTM_0, KEY(0), SHIFT_DU(KEY_SHIFT(9), KEY(0)));
    CASE_US(CSTM_1, KEY(1), KEY(1));
    CASE_US(CSTM_2, KEY(2), SHIFT_DU(KEY_UPSHIFT(LBRACKET), KEY(2)));
    CASE_US(CSTM_3, KEY(3), KEY(3));
    CASE_US(CSTM_4, KEY(4), KEY(4));
    CASE_US(CSTM_5, KEY(5), KEY(5));
    CASE_US(CSTM_6, KEY(6), SHIFT_DU(KEY_UPSHIFT(EQUAL), KEY(6)));
    CASE_US(CSTM_7, KEY(7), SHIFT_DU(KEY_SHIFT(6), KEY(7)));
    CASE_US(CSTM_8, KEY(8), SHIFT_DU(KEY_SHIFT(QUOTE), KEY(8)));
    CASE_US(CSTM_9, KEY(9), SHIFT_DU(KEY_SHIFT(8), KEY(9)));
    CASE_US(DEL, KEY(DELETE), KEY_UPSHIFT(BSPACE));
    CASE_US(TILD, KEY_SHIFT(GRAVE), KEY_SHIFT(EQUAL));
    CASE_US(EXLM, KEY_SHIFT(1), KEY_SHIFT(1));
    CASE_US(AT, KEY_SHIFT(2), KEY(LBRACKET));
    CASE_US(HASH, KEY_SHIFT(3), KEY_SHIFT(3));
    CASE_US(DLR, KEY_SHIFT(4), KEY_SHIFT(4));
    CASE_US(PERC, KEY_SHIFT(5), KEY_SHIFT(5));
    CASE_US(CIRC, KEY_SHIFT(6), KEY(EQUAL));
    CASE_US(AMPR, KEY_SHIFT(7), KEY_SHIFT(6));
    CASE_US(ASTR, KEY_SHIFT(8), KEY_SHIFT(QUOTE));
    CASE_US(LPRN, KEY_SHIFT(9), KEY_SHIFT(8));
    CASE_US(RPRN, KEY_SHIFT(0), KEY_SHIFT(9));
    CASE_US(LBRC, KEY(LBRACKET), SHIFT_DU(KEY_SHIFT(RBRACKET), KEY(RBRACKET)));
    CASE_US(RBRC, KEY(RBRACKET), SHIFT_DU(KEY_SHIFT(NONUS_HASH), KEY(NONUS_HASH)));
    CASE_US(LCBR, KEY_SHIFT(LBRACKET), KEY_SHIFT(RBRACKET));
    CASE_US(RCBR, KEY_SHIFT(RBRACKET), KEY_SHIFT(NONUS_HASH));
    CASE_US(GRV, KEY(GRAVE), SHIFT_DU(KEY_SHIFT(EQUAL), KEY_SHIFT(LBRACKET)));
    CASE_US(BSLS, KEY(BSLASH), SHIFT_DU(KEY_SHIFT(INT3), KEY(INT3)));
    CASE_US(PIPE, KEY_SHIFT(BSLASH), KEY_SHIFT(INT3));
    CASE_US(MINS, KEY(MINUS), SHIFT_DU(KEY_SHIFT(INT1), KEY(MINUS)));
    CASE_US(UNDS, KEY_SHIFT(MINUS), KEY_SHIFT(INT1));
    CASE_US(EQL, KEY(EQUAL), SHIFT_DU(KEY_SHIFT(SCOLON), KEY_SHIFT(MINUS)));
    CASE_US(PLUS, KEY_SHIFT(EQUAL), KEY_SHIFT(SCOLON));
    CASE_US(SCLN, KEY(SCOLON), SHIFT_DU(KEY_UPSHIFT(QUOTE), KEY(SCOLON)));
    CASE_US(QUOT, KEY(QUOTE), SHIFT_DU(KEY_SHIFT(2), KEY_SHIFT(7)));
    case JP:
      if (record->event.pressed) {
        LAYOUT_STATUS = JP_LAYOUT;
      }
      return false;
      break;
    case US:
      if (record->event.pressed) {
        LAYOUT_STATUS = US_LAYOUT;
      }
      return false;
      break;
    case SHIFT:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SHIFT_PRESSED = true;
      } else {
        SEND_STRING(SS_UP(X_LSHIFT));
        SHIFT_PRESSED = false;
      }
      return false;
      break;	  
    case CUT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("x"));
        SEND_STRING(SS_UP(X_LSHIFT));
      }
      return false;
      break;
    case PASTE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("v"));
      }
      return false;
      break;
    case KLLN:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT));
        SEND_STRING(SS_TAP(X_END));
        SEND_STRING(SS_UP(X_LSHIFT));
        SEND_STRING(SS_LCTRL("x"));
      }
      return false;
      break;
    case MARK:
      if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_LSHIFT));
      }
      return false;
      break;
  }
  return true;
}
