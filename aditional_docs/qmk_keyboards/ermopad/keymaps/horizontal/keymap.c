#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*					
     * ┌───┬───┬───┬───┬───┐
     * │ 1 │ 2 │ 3 │ 0 │ ^ │
     * ├───┼───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │<- │-> │
     * ├───┼───┼───┼───┼───┤
     * │ 7 │ 8 │ 9 │ MO│ v │
     * └───┴───┴───┴───┴───┘
     *
     * ┌───┬───┬───┬───┬───┐
     * │   │   │   │BSP│ENT│
     * ├───┼───┼───┼───┼───┤
     * │   │   │   │ Q │ G │
     * ├───┼───┼───┼───┼───┤
     * │   │   │   │   │CTL│
     * └───┴───┴───┴───┴───┘
     *
     */
    [0] = LAYOUT_ortho_5x3(
        KC_UP,  KC_RIGHT, KC_DOWN,
        KC_0,   KC_LEFT,  MO(1),
        KC_3,   KC_6,     KC_9,
        KC_2,   KC_5,     KC_8,
        KC_1,   KC_4,     KC_7
    ),
    [1] = LAYOUT_ortho_5x3(
    	KC_ENT,  KC_G,    KC_LCTL,
    	KC_BSPC, KC_Q,    KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO,
    	KC_NO,   KC_NO,   KC_NO
    )
};
