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

#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*

    // Example layer with momentary layer toggle MO(_FL)
    [_BL] = LAYOUT(
        MO(_FL) , KC_F13 , KC_MUTE,
        KC_F14  , KC_F15 , KC_F16
    ),

    // Layout for testing switches
    [_BL] = LAYOUT(
        KC_A, KC_B, KC_C,
        KC_D, KC_E, KC_F
    ),

     */

    /*
    https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes

        |                  |              |  Knob : Vol Up/Dn  |
        |       F13        |      F14     |      Mute          |
        |  Previous Track  |  Next Track  |    Play/Pause      |

    */
    [_BL] = LAYOUT(
        KC_F13  , KC_F14   , KC_MUTE,
        KC_MPRV , KC_MNXT  , KC_MPLY
    ),

    /*
        |               |   Increase Brightness  |     Mute   |
        |    RGB Cycle  |   Decrease Brightness  |  Hue Cycle |
    [_FL] = LAYOUT(
        _______  , RGB_VAI, KC_MUTE,
        RGB_MOD, RGB_VAD, RGB_HUI
    ),
     */

};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGUP);
        } else {
            tap_code(KC_PGDN);
        }
    }
    return true;
}

void keyboard_post_init_user(void) {
    // Light up the red LEDs on the pro micro
    writePinLow(B0);
    writePinLow(D5);
}

uint32_t default_layer_state_set_rgb(uint32_t state) {
    // Light up the red LEDs on the pro micro
    writePinLow(B0);
    writePinLow(D5);
    return state;
}

void suspend_power_down_user(void) {
    // code will run multiple times while keyboard is suspended
    writePinHigh(B0);
    writePinHigh(D5);
}

void suspend_wakeup_init_user(void) {
    // code will run on keyboard wakeup
    writePinLow(B0);
    writePinLow(D5);
}
