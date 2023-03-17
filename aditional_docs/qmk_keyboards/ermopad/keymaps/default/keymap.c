#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*					
     * ┌───┬───┬───┐
     * │ 1 │ 2 │ 3 │
     * ├───┼───┼───┤
     * │ 4 │ 5 │ 6 │
     * ├───┼───┼───┤
     * │ 7 │ 8 │ 9 │
     * ├───┼───┼───┤
     * │ 0 │ ^ │ MO│
     * ├───┼───┼───┤
     * │ < │ v │ > │
     * └───┴───┴───┘
     *
     * ┌───┬───┬───┐
     * │   │   │   │
     * ├───┼───┼───┤
     * │   │   │   │
     * ├───┼───┼───┤
     * │   │   │   │
     * ├───┼───┼───┤
     * │ g │ENT│   │
     * ├───┼───┼───┤
     * │CTL│BSP│ q │
     * └───┴───┴───┘
     *
     */
    [0] = LAYOUT_ortho_5x3(
        KC_1,   KC_2,   KC_3,
        KC_4,   KC_5,   KC_6,
        KC_7,   KC_8,   KC_9,
        KC_0,   KC_UP,   MO(1),
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [1] = LAYOUT_ortho_5x3(
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_G,    KC_ENT,  KC_NO,
    	KC_LCTL, KC_BSPC, KC_Q
    )
};
