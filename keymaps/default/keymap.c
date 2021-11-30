/* Copyright 2020 Dennis Nguyen <u/nguyedt>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _BL 0 // Base Layer

enum custom_keycodes {
    KIWI,
    FIRE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
    https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes

        |                  |              |  Knob : Vol Up/Dn  |
        |     :kiwi:       |    :fire:    |      Mute          |
        |  Previous Track  |  Next Track  |    Play/Pause      |

    */

    [_BL] = LAYOUT(
        KIWI, FIRE, KC_MUTE,
        KC_MPRV   , KC_MNXT   , KC_MPLY
    ),

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KIWI:
            if (record->event.pressed) {
                SEND_STRING(":kiwi:");
            } else {
            }
            break;
        case FIRE:
            if (record->event.pressed) {
                SEND_STRING(":fire:");
            } else {
            }
            break;
        }
    return true;
};
