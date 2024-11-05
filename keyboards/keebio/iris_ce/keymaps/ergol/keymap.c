// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "info_config.h"
#include "quantum_keycodes.h"
#include "quantum_keycodes_legacy.h"
#include QMK_KEYBOARD_H

#include <stdint.h>
#include "color.h"
#include "keycodes.h"
#include "rgb_matrix.h"

#define KC_NEXT KC_MEDIA_NEXT_TRACK
#define KC_PREV KC_MEDIA_PREV_TRACK
#define KC_PLAY KC_MEDIA_PLAY_PAUSE
#define KC_VOL_UP KC_AUDIO_VOL_UP
#define KC_VOL_DOWN KC_AUDIO_VOL_DOWN

const HSV PURPLE = {HSV_PURPLE};
const HSV BLUE = {HSV_BLUE};
const HSV ORANGE = {HSV_ORANGE};
const HSV CYAN = {HSV_CYAN};
const HSV GREEN = {HSV_GREEN};
const HSV OFF = {HSV_OFF};
const HSV TRNS = {-1, -1, -1};

// BAD : this was copied from a generated file. Necessary because the LAYOUT macro uses KC_NO, which cannot be mapped to a color.
#define LIGHTING(k0A, k0B, k0C, k0D, k0E, k0F, k5F, k5E, k5D, k5C, k5B, k5A, k1A, k1B, k1C, k1D, k1E, k1F, k6F, k6E, k6D, k6C, k6B, k6A, k2A, k2B, k2C, k2D, k2E, k2F, k7F, k7E, k7D, k7C, k7B, k7A, k3A, k3B, k3C, k3D, k3E, k3F, k4F, k9F, k8F, k8E, k8D, k8C, k8B, k8A, k4C, k4D, k4E, k9E, k9D, k9C) { \
	 {k0A, k0B, k0C, k0D, k0E, k0F}, \
	 {k1A, k1B, k1C, k1D, k1E, k1F}, \
	 {k2A, k2B, k2C, k2D, k2E, k2F}, \
	 {k3A, k3B, k3C, k3D, k3E, k3F}, \
	 {TRNS, TRNS, k4C, k4D, k4E, k4F}, \
	 {k5A, k5B, k5C, k5D, k5E, k5F}, \
	 {k6A, k6B, k6C, k6D, k6E, k6F}, \
	 {k7A, k7B, k7C, k7D, k7E, k7F}, \
	 {k8A, k8B, k8C, k8D, k8E, k8F}, \
	 {TRNS, TRNS, k9C, k9D, k9E, k9F} \
}

enum custom_layers {
     _QWERTY,
     _ERGOL,
     _ERGOL_SHIFT,
     _ERGOL_DEAD,
     _ERGOL_ALT,
     _MEDIA
};

enum custom_keycodes {
    M_CIRCA = SAFE_RANGE,
    M_OE,
    M_CIRCO,
    M_CIRCU,
    M_CIRCE,
    M_CIRCI,
    M_TREMI,
    M_TREME,
    M_CIRC,
    MACRO_9,
    MACRO_10,
    MACRO_11,
    MACRO_12,
    MACRO_13,
    MACRO_14,
    MACRO_15,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    TO(_ERGOL),      MO(_MEDIA),KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LGUI, TL_LOWR, KC_ENT,                    KC_SPC,  TL_UPPR, KC_RALT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ERGOL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5),                            S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_DEL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_A,    KC_C,    KC_O,    KC_P,    KC_Z,                               KC_J,    KC_SCLN, KC_D,  OSL(_ERGOL_DEAD),KC_Y, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_Q,    KC_S,    KC_E,    KC_N,    KC_F,                               KC_L,    KC_R,    KC_T,    KC_I,    KC_U,    KC_4,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_W,    KC_X,    KC_6,    KC_V,    KC_B,    TO(_QWERTY),      MO(_MEDIA), S(KC_COMM),KC_H,  KC_G,    KC_M,    KC_K,    S(KC_DOT),
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                KC_LALT,LT(_ERGOL_ALT,KC_BSPC),MO(_ERGOL_SHIFT),  KC_SPC,  KC_ENT, KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ERGOL_SHIFT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GESC, RALT(KC_E),KC_3,  KC_4,    KC_RBRC, S(KC_QUOT),                         S(KC_6), KC_1,   KC_BSLS,RALT(KC_3),RALT(KC_0),KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  S(KC_A), S(KC_C), S(KC_O), S(KC_P), S(KC_Z),                            S(KC_J), S(KC_SCLN), S(KC_D), KC_SLSH, S(KC_Y),S(KC_EQL),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, S(KC_Q), S(KC_S), S(KC_E), S(KC_N), S(KC_F),                            S(KC_L), S(KC_R), S(KC_T), S(KC_I), S(KC_U), KC_3,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     S(KC_LCTL), S(KC_W), S(KC_X), S(KC_M), S(KC_V), S(KC_B), TO(_QWERTY),      KC_TRNS, KC_DOT,  S(KC_H), S(KC_G), KC_COMM, S(KC_K), KC_8,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                   S(KC_LALT), KC_BSPC, KC_TRNS,                   KC_SPC,  S(KC_ENT), KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ERGOL_DEAD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     TO(_ERGOL), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, M_CIRCA, KC_9,    M_OE   , M_CIRCO ,KC_TRNS,                            KC_TRNS, KC_TRNS, KC_8,   TO(_ERGOL),M_CIRCU, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_0,    KC_2,    KC_7,    M_CIRCE, M_TREME,                            KC_5,    KC_MINS, M_CIRCI, M_TREMI, KC_QUOT, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_TRNS, KC_6,    KC_TRNS, KC_TRNS, QK_BOOT,          QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘

  ),

  [_ERGOL_ALT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, M_CIRC,  KC_NUBS,S(KC_NUBS),KC_RBRC,S(KC_QUOT),                         RALT(KC_0),KC_1,  KC_BSLS, KC_4,    RALT(KC_7),KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, RALT(KC_4),KC_5,  KC_MINS, RALT(KC_EQL),KC_EQL,                         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_3,   KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
    KC_TRNS,KC_TRNS,RALT(KC_5),RALT(KC_MINS),KC_8, RALT(KC_3), RGB_VAD,     RGB_VAD,RALT(KC_6), KC_SLSH, KC_COMM, KC_M,   S(KC_M), KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, KC_BSPC, MO(_ERGOL_SHIFT),          KC_SPC,  KC_ENT,  KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MEDIA] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_TRNS, KC_VOL_DOWN,KC_VOL_UP,KC_TRNS,                        KC_TRNS, RGB_HUD, RGB_HUI, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_PREV, KC_PLAY, KC_NEXT, KC_TRNS,                            KC_TRNS, RGB_VAD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_TRNS, KC_TRNS,  KC_TRNS,                  KC_TRNS,  KC_TRNS, KC_TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case M_CIRCA:
                SEND_STRING("[q");
                return false;
            case M_CIRCI:
                SEND_STRING("[i");
                return false;
            case M_CIRCO:
                SEND_STRING("[o");
                return false;
            case M_CIRCE:
                SEND_STRING("[e");
                return false;
            case M_CIRCU:
                SEND_STRING("[u");
                return false;
            case M_TREMI:
                SEND_STRING("{i");
                return false;
            case M_TREME:
                SEND_STRING("{e");
                return false;
            case M_OE:
                SEND_STRING(SS_LALT(SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P5) SS_TAP(X_P6)));
                return false;
            case M_CIRC:
                SEND_STRING("[ ");
                return false;
        }
    }
    return true;
};

// Mapping of led ids on the layout
const uint16_t PROGMEM leds[MATRIX_ROWS][MATRIX_COLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
        0,       2,       3,       5,       6,       8,                                  42,     40,      39,      37,      36,       34,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        14,      13,     12,      11,      10,       9,                                 43,      44,      45,      46,     47,       48,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
        15,      16,     17,      18,      19,       20,                                 54,      53,      52,      51,     50,       49,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
        26,    25,      24,      23,      22,       21,       33,               67,     55,      56,      57,      58,      59,       60,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                       29,      30,     32,                        66,       64,    63
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  );

// Define specific lighting for each layer. Use TRNS to fallback to default animation for a specific key
const HSV lighting[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      BLUE,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    BLUE,     BLUE,    BLUE,                      BLUE,    BLUE,   BLUE
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ERGOL] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      PURPLE,  TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TRNS ,    TRNS ,   TRNS ,                     TRNS ,   TRNS ,   TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_ERGOL_SHIFT] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      PURPLE,  TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    ORANGE,  TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TRNS ,    TRNS ,   TRNS ,                     TRNS ,   TRNS ,   TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_ERGOL_DEAD] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      GREEN,   TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    PURPLE,  TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TRNS ,    TRNS ,   TRNS ,                     TRNS ,   TRNS ,   TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_ERGOL_ALT] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      CYAN,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    BLUE,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TRNS ,    TRNS ,   TRNS ,                     TRNS ,   TRNS ,   TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_MEDIA] = LIGHTING(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      ORANGE,  TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    BLUE,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,                               TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,             TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                     TRNS ,    TRNS ,   TRNS ,                     TRNS ,   TRNS ,   TRNS
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};


void keyboard_post_init_user(void) {
    /*rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);*/
    /*rgb_matrix_sethsv_noeeprom(HSV_BLACK);*/
}

bool is_transparent(const HSV color) {
    return (color.h == TRNS.h) && (color.s == TRNS.s) && (color.v == TRNS.v);
}

bool is_off(const HSV color) {
    return (color.h == OFF.h) && (color.s == OFF.s) && (color.v == OFF.v);
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
        static int current_val = RGB_MATRIX_MAXIMUM_BRIGHTNESS;
        if(rgb_matrix_get_val() != 0) {
            current_val = rgb_matrix_get_val();
        } else {
            current_val = RGB_MATRIX_MAXIMUM_BRIGHTNESS ;
        }

        uint8_t highest_layer = get_highest_layer(layer_state|default_layer_state);

        for (int row = 0; row<MATRIX_ROWS; row++) {
            for(int col=0; col<MATRIX_COLS; col++) {
            uint16_t kc = keymaps[highest_layer][row][col];
            HSV desiredColor = TRNS;

            switch(highest_layer) {
                case _ERGOL_DEAD:
                case _ERGOL_ALT:
                case _MEDIA:
                    if(kc != KC_TRNS) {
                        desiredColor = lighting[highest_layer][0][0];
                    } else {
                        desiredColor = (HSV){HSV_OFF};
                    }
                    //FALLTHROUGH
                case _QWERTY:
                case _ERGOL:
                case _ERGOL_SHIFT:
                    if(kc == QK_BOOT) {
                        desiredColor = (HSV){HSV_RED};
                    } else if(IS_QK_TO(kc)) {
                       desiredColor = lighting[QK_TO_GET_LAYER(kc)][0][0];
                    } else if(IS_QK_ONE_SHOT_LAYER(kc)) {
                       desiredColor = lighting[QK_ONE_SHOT_LAYER_GET_LAYER(kc)][0][0];
                    } else if(!is_transparent(lighting[highest_layer][row][col])){
                       desiredColor = lighting[highest_layer][row][col];
                    }

                    break;
                default:
                    break;
            }
            if(!is_transparent(desiredColor)) {
                RGB color = hsv_to_rgb((HSV){desiredColor.h, desiredColor.s, is_off(desiredColor) ? 0 : MAX(MIN(current_val * 1.5, RGB_MATRIX_MAXIMUM_BRIGHTNESS ), 50)});
                rgb_matrix_set_color(leds[row][col], color.r, color.g, color.b);
            }
        }
    }
    return true;
}


