/*
Copyright 2017 Balz Guenat

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

////////////////////////////////////////////////////////////////////////////////
// Layer Declarations
////////////////////////////////////////////////////////////////////////////////

enum {
  L_PRIM = 0,
  L_SEC,
  L_NUM
};

////////////////////////////////////////////////////////////////////////////////
// Aliases
////////////////////////////////////////////////////////////////////////////////

#define _        KC_NO             // Map _ to KC_NO
#define A_ROFI  LALT(KC_D)         // Open rofi

////////////////////////////////////////////////////////////////////////////////
// Keymaps
////////////////////////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_PRIM] = LAYOUT (
        KC_ESC,     KC_1,       KC_2,        KC_3,        KC_4,     KC_5,       KC_6,     KC_7,    KC_8,    KC_9,     KC_0,    KC_MINS,    KC_EQL,  KC_BSPC, KC_VOLU,
        KC_TAB,     KC_Q,       KC_W,        KC_E,        KC_R,     KC_T,       KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,    KC_LBRC,    KC_RBRC, KC_BSLS, KC_VOLD,
        TT(L_SEC),  KC_A,       KC_S,        KC_D,        KC_F,     KC_G,       KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN, KC_QUOT,    KC_ENT,
        KC_LSFT,    KC_Z,       KC_X,        KC_C,        KC_V,     KC_B,       KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH, TO(L_NUM),  KC_UP,
        KC_LCTL,    KC_LGUI,    KC_LALT,     KC_SPC,      A_ROFI,   TO(L_SEC),  KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

  [L_SEC] = LAYOUT (
        KC_GRV,     KC_F1,      KC_F2,       KC_F3,       KC_F4,    KC_F5,      KC_F6,    KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,     KC_F12,  KC_DEL,  KC_PGUP,
        _______,    KC_MPRV,    KC_MPLY,     KC_MNXT,     _,        _______,    KC_CALC,  KC_PGUP, KC_UP,   KC_PGDN,  KC_PSCR, KC_SLCK,    KC_PAUS, RESET,   KC_PGDN,
        _______,    _______,    KC_VOLD,     KC_VOLU,     KC_MUTE,  _______,    KC_HOME,  KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,  KC_DEL,     _______,
        _______,    KC_APP,     KC_DEL,      _______,     KC_BTN2,  KC_SPC,     KC_END,   _______, _______, _______,  _______, TO(L_PRIM), KC_PGUP,
        _______,    _______,    _______,     KC_CAPS,     KC_F12,   _______,    _______,  _______, KC_PGDN, _______
    ),

  [L_NUM] = LAYOUT(
        _______,    _,          _,           _,           _,        _,          _,        _,       KC_PSLS, KC_PAST,  KC_PMNS, KC_PMNS,    _______, _______, KC_NLCK,
        _______,    _,          _,           _,           _,        _,          _,        KC_P7,   KC_P8,   KC_P9,    _,       _,          _,       _,       _,
        _,          _,          _,           _,           _,        _,          _,        KC_P4,   KC_P5,   KC_P6,    KC_PPLS, _,          _______,
        _,          _,          _,           _,           _,        KC_SPC,     KC_SPC,   KC_P1,   KC_P2,   KC_P3,    KC_PENT, TO(L_PRIM), KC_PGUP,
        _,          _,          _,           KC_P0,       KC_PDOT,  _,          _,        _,       KC_PGDN,       _
    ),

};

////////////////////////////////////////////////////////////////////////////////
// Other
////////////////////////////////////////////////////////////////////////////////

layer_state_t layer_state_set_user(layer_state_t state)
{

    // If the Secondary or Numpad layers are on light the Insert LED
    if (state & (1L<<L_SEC)) {
        PORTB &= ~(1<<5);
    } else if (state & (1L<<L_NUM)) {
        PORTB &= ~(1<<5);
    } else {
        PORTB |=  (1<<5);
    }

    return state;

}

