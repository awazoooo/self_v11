/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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


/* Define Layers */
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
  //  BACKLIT,
  //  RGBR
};


/* Tap dance configs */
enum tap_dances {
  // once CLEAR, twice RESET
  CLRE_DANCE
  /* // once i, twice * */
  /* ASTR_DANCE, */
  /* // once -, twice _ */
  /* MINS_DANCE, */
  /* // once =, twice + */
  /* EQL_DANCE, */
  /* // once \, twice | */
  /* BSLS_DANCE, */
  /* // once ', twice " */
  /* QUOT_DANCE, */
  /* // once ;, twice : */
  /* SCLN_DANCE, */
  /* // once [, twice {, thrice ( */
  /* LPRN_DANCE, */
  /* // once ], twice }, thrice ) */
  /* RPRN_DANCE */
};

void dance_CLRE_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    // clear Modifiers, Keys, Macros and Layers
    clear_keyboard();
    // clear OSM
    clear_oneshot_mods();
    // clear layer
    layer_clear();
    // toggle RGB light
    #ifdef RGBLIGHT_ENABLE
    rgblight_toggle();
    #endif
    #ifdef RGB_MATRIX_ENABLE
    rgb_matrix_toggle();
    #endif
  } else {
    reset_keyboard();
  }
}

// Double Tap Dance register
/* void dance_DP_register (qk_tap_dance_state_t *state, uint8_t dp1, uint8_t dp2, uint8_t single) { */
/*   if (state->count == 2) { */
/*     register_code(dp1); */
/*     register_code(dp2); */
/*   } else { */
/*     register_code(single); */
/*   } */
/* } */

/* // Double Tap Dance unregister */
/* void dance_DP_unregister (qk_tap_dance_state_t *state, uint8_t dp1, uint8_t dp2, uint8_t single) { */
/*   if (state->count == 2) { */
/*     unregister_code(dp1); */
/*     unregister_code(dp2); */
/*   } else { */
/*     unregister_code(single); */
/*   } */
/* } */

// Double Tap finished
/* void dance_DP_finished (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(ASTR_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_8, KC_I); */
/*     break; */
/*   case TD(MINS_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_MINS, KC_MINS); */
/*     break; */
/*   case TD(EQL_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_EQL, KC_EQL); */
/*     break; */
/*   case TD(BSLS_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_BSLS, KC_BSLS); */
/*     break; */
/*   case TD(QUOT_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_QUOT, KC_QUOT); */
/*     break; */
/*   case TD(SCLN_DANCE): */
/*     dance_DP_register(state, KC_LSFT, KC_SCLN, KC_SCLN); */
/*     break; */
/*   } */
/* } */

// Double Tap reset
/* void dance_DP_reset (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(ASTR_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_8, KC_I); */
/*     break; */
/*   case TD(MINS_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_MINS, KC_MINS); */
/*     break; */
/*   case TD(EQL_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_EQL, KC_EQL); */
/*     break; */
/*   case TD(BSLS_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_BSLS, KC_BSLS); */
/*     break; */
/*   case TD(QUOT_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_QUOT, KC_QUOT); */
/*     break; */
/*   case TD(SCLN_DANCE): */
/*     dance_DP_unregister(state, KC_LSFT, KC_SCLN, KC_SCLN); */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_tapped (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count == 1) { */
/*       // input [ during tapping */
/*       register_code(KC_LBRC); */
/*       unregister_code(KC_LBRC); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count == 1) { */
/*       // input ] during tapping */
/*       register_code(KC_RBRC); */
/*       unregister_code(KC_RBRC); */
/*     } */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_finished (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       // delete [ and input { */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_LBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       // delete [ and input ( */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_9); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       // delete ] and input } */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_RBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       // delete ] and input ) */
/*       register_code (KC_BSPC); */
/*       unregister_code (KC_BSPC); */
/*       register_code(KC_LSFT); */
/*       register_code(KC_0); */
/*     } */
/*     break; */
/*   } */
/* } */

/* void dance_PRN_reset (qk_tap_dance_state_t *state, void *user_data) { */
/*   switch (state->keycode) { */
/*   case TD(LPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_LBRC); */
/*     } else if(state->count % 3 == 0) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_9); */
/*     } */
/*     break; */
/*   case TD(RPRN_DANCE): */
/*     if (state->count % 3 == 2) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_RBRC); */
/*     } else if (state->count % 3 == 0) { */
/*       unregister_code(KC_LSFT); */
/*       unregister_code(KC_0); */
/*     } */
/*     break; */
/*   } */
/*} */

// Define tap dance tapping terms
//#define RARELY_TD_TIME 120
//#define SOMETIMES_TD_TIME 140
//#define OFTEN_TD_TIME 170
#define USUALLY_TD_TIME 200
//#define TRIPLE_TD_TIME 160

// Define tap dance functions
qk_tap_dance_action_t tap_dance_actions[] = {
  // double
  [CLRE_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_CLRE_finished, NULL, USUALLY_TD_TIME)
  /* [ASTR_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, RARELY_TD_TIME), */
  /* [MINS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [EQL_DANCE]  = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [BSLS_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, OFTEN_TD_TIME), */
  /* [QUOT_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */
  /* [SCLN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, dance_DP_finished, dance_DP_reset, SOMETIMES_TD_TIME), */

  // triple
  /* [LPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME), */
  /* [RPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(dance_PRN_tapped, dance_PRN_finished, dance_PRN_reset, TRIPLE_TD_TIME) */
};

// Double tap dance
#define TD_CLRE TD(CLRE_DANCE)
/* #define TD_ASTR TD(ASTR_DANCE) */
/* #define TD_MINS TD(MINS_DANCE) */
/* #define TD_EQL  TD(EQL_DANCE) */
/* #define TD_BSLS TD(BSLS_DANC) */
/* #define TD_QUOT TD(QUOT_DANCE) */
/* #define TD_SCLN TD(SCLN_DANCE) */
/* #define TD_LEFT TD(LEFT_DANCE) */
/* #define TD_DOWN TD(DOWN_DANCE) */
/* #define TD_UP   TD(UP_DANCE) */
/* #define TD_RGHT TD(RGHT_DANCE) */

// Triple tap dance
/* #define TD_LPRN TD(LPRN_DANCE) */
/* #define TD_RPRN TD(RPRN_DANCE) */


/* Key combinations */
//#define SFT_SPC SFT_T(KC_SPC)
#define CTL_SPC CTL_T(KC_SPC)
#define CTL_ENT CTL_T(KC_ENT)
#define OSM_ALT OSM(MOD_LALT)
#define OSM_SFT OSM(MOD_LSFT)
//#define OSM_CTL OSM(MOD_LCTL)
#define OSM_GUI OSM(MOD_LGUI)
#define OSL_LOW OSL(_LOWER)
#define OSL_RAI OSL(_RAISE)
#define OSL_ADJ OSL(_ADJUST)


/* Define keymap */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSM_SFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TD_CLRE,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          OSM_GUI, OSL_LOW, CTL_SPC,    CTL_ENT, OSL_RAI, OSM_ALT \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,    KC_0, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______, \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, OSL_ADJ, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC,  KC_GRV, KC_BSLS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TILD, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, OSL_ADJ, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RGB_TOG, XXXXXXX, XXXXXXX, RGB_M_P, RGB_M_B, RGB_M_R,                     RGB_M_SW,RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, OSL_LOW, _______,    _______, OSL_RAI, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};


/* TAPPING_TERM for each keycode */
// Tap Dances settings are in tap_dance_actions[]
uint16_t get_tapping_term(uint16_t keycode){
  switch(keycode){
  case CTL_ENT:
  case CTL_SPC:
    return 170;
  // 通常キーは80
  default:
    return TAPPING_TERM;
  }
}


#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
  oled_write_P(PSTR("LAYER: "), false);
  switch (layer_state) {
    case L_BASE:
      oled_write_ln_P(PSTR("Default"), false);
      break;
    case L_LOWER:
      oled_write_ln_P(PSTR("Lower"), false);
      break;
    case L_RAISE:
      oled_write_ln_P(PSTR("Raise"), false);
      break;
    case L_ADJUST:
    case L_ADJUST|L_LOWER:
    case L_ADJUST|L_RAISE:
    case L_ADJUST|L_LOWER|L_RAISE:
      oled_write_ln_P(PSTR("Adjust"), false);
      break;
    default:
      oled_write_ln_P(PSTR("Unknown"), false);
  }
}

char keylog_str[24] = {};

const char code_to_name[60] = {
  ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
  'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
  'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
  '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
  'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
  '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
    keycode = keycode & 0xFF;
  }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "KCODE: %dx%d, k%2d : %c",
    record->event.key.row, record->event.key.col, keycode, name);
}

void oled_render_keylog(void) {
  oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
  /* Show Ctrl-Gui Swap options */
  static const char PROGMEM logo[][2][3] = {
    {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
    {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
  };
  if (status) {
    oled_write_ln_P(logo[0][0], false);
    oled_write_ln_P(logo[0][1], false);
  } else {
    oled_write_ln_P(logo[1][0], false);
    oled_write_ln_P(logo[1][1], false);
  }
}

/* void oled_render_logo(void) { */
/*   static const char PROGMEM crkbd_logo[] = { */
/*     0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, */
/*     0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, */
/*     0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, */
/*     0}; */
/*   oled_write_P(crkbd_logo, false); */
/* } */

void oled_task_user(void) {
  if (is_master) {
    oled_render_layer_state();
    oled_render_keylog();
  } else {
    //oled_render_logo();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
    //set_timelog();
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
