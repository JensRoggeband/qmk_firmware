#include QMK_KEYBOARD_H
#include "keymap.h"

#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#define SCRN_CPTR LGUI(LSFT(KC_S))
#define WARZONE TG(_WARZONE)
#define QWERTY TG(_QWERTY)
#define COLEMAK TG(_COLEMAK)
#define MOUSE TG(_MOUSE)

enum layer_number {
  _QWERTY = 0,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _MOUSE,
  _WARZONE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  |BackSP| RAISE| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_QWERTY] = LAYOUT(
    KC_ESC   , KC_1   , KC_2    , KC_3    , KC_4       , KC_5    ,                          KC_6    , KC_7       , KC_8    , KC_9   , KC_0    , KC_GRV  ,
    KC_TAB   , KC_Q   , KC_W    , KC_E    , KC_R       , KC_T    ,                          KC_Y    , KC_U       , KC_I    , KC_O   , KC_P    , KC_MINS ,
    KC_LCTRL , KC_A   , KC_S    , KC_D    , KC_F       , KC_G    ,                          KC_H    , KC_J       , KC_K    , KC_L   , KC_SCLN , KC_QUOT ,
    KC_LSFT  , KC_Z   , KC_X    , KC_C    , KC_V       , KC_B    , KC_LBRC ,      KC_RBRC , KC_N    , KC_M       , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT ,
                                  KC_LGUI , TT(_LOWER) , KC_LALT , KC_SPC  ,      KC_ENT  , KC_BSPC , TT(_RAISE) , KC_RALT
  ),
/* COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  |BackSP| RAISE| RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_COLEMAK] = LAYOUT(
    KC_ESC   , KC_1    , KC_2    , KC_3    , KC_4       , KC_5    ,                          KC_6    , KC_7       , KC_8    , KC_9    , KC_0    , KC_GRV  ,
    KC_TAB   , KC_Q    , KC_W    , KC_F    , KC_P       , KC_B    ,                          KC_J    , KC_L       , KC_U    , KC_Y    , KC_SCLN , KC_MINS ,
    KC_LCTRL , KC_A    , KC_R    , KC_S    , KC_T       , KC_G    ,                          KC_M    , KC_N       , KC_E    , KC_I    , KC_O    , KC_QUOT ,
    KC_LSFT  , KC_Z    , KC_X    , KC_C    , KC_D       , KC_V    , KC_LBRC ,      KC_RBRC , KC_K    , KC_H       , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT ,
                                   KC_LGUI , TT(_LOWER) , KC_LALT , KC_SPC  ,      KC_ENT  , KC_BSPC , TT(_RAISE) , KC_RALT
  ),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |  UP  |      |      |      |                    |      |   7  |   8  |   9  |   -  |   *  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LEFT | DOWN | RIGHT|      |      |-------.    ,-------|      |   4  |   5  |   6  |   +  |   /  |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |CAPS  |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |   =  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  |BackSP |RAISE |   0  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_LOWER] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    XXXXXXX , XXXXXXX , KC_UP   , XXXXXXX , XXXXXXX , XXXXXXX ,                          XXXXXXX , KC_7    , KC_8    , KC_9    , KC_MINS , KC_ASTR ,
    XXXXXXX , KC_LEFT , KC_DOWN , KC_RGHT , XXXXXXX , XXXXXXX ,                          XXXXXXX , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_SLSH ,
    KC_CAPS , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,      _______ , XXXXXXX , KC_1    , KC_2    , KC_3    , KC_EQL  , _______ ,
                                  _______ , _______ , _______ , _______ ,      _______ , KC_BSPC , _______ , KC_0
  ),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |   !  |   @  |   #  |   $  |   %  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |  =   |
 * |------+------+------+------+------+------|   [   |    |   ]   |------+------+------+------+------+------|
 * |LShift|      |      |      |      |      |-------|    |-------|   [  |   ]  |   {  |   }  |   \  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  | DEL  |RAISE | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_RAISE] = LAYOUT(
    _______ , _______ , _______ , _______ , _______ , _______ ,                          _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   ,                          KC_EXLM , KC_AT   , KC_HASH , KC_DLR  , KC_PERC , KC_PLUS ,
    KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , KC_F12  ,                          KC_CIRC , KC_AMPR , KC_ASTR , KC_LPRN , KC_RPRN , KC_EQL  ,
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , _______ ,      _______ , KC_LBRC , KC_RBRC , KC_LCBR , KC_RCBR , KC_BSLS , _______ ,
                                  _______ , _______ , _______ , _______ ,      _______ , KC_DEL  , _______ , _______
  ),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |      |      |      |      |      |                    |WRZONE|COLMAK|QWERTY|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |  V+  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | STOP | PREV | PLAY | NEXT |  V-  |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      | Mute |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  | DEL  |RAISE | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
    _______ , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                          WARZONE , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_VOLU ,                          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , KC_MSTP , KC_MPRV , KC_MPLY , KC_MNXT , KC_VOLD ,                          XXXXXXX , XXXXXXX , RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_MUTE , XXXXXXX ,      XXXXXXX , XXXXXXX , XXXXXXX , RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD ,
                                  _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______
  ),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |WRZONE|COLMAK|QWERTY|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |MWHUp |MClckL|                    |MClckR|MWHDwn|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | GUI  |LOWER |LAlt  | /Space  /       \Enter \  | DEL  |RAISE | RAlt |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_MOUSE] = LAYOUT(
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                          XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , KC_WH_U , KC_BTN1 ,                          KC_BTN2 , KC_WH_D , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,                          XXXXXXX , XXXXXXX , RGB_TOG , RGB_HUI , RGB_SAI , RGB_VAI ,
    XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX ,      XXXXXXX , XXXXXXX , XXXXXXX , RGB_MOD , RGB_HUD , RGB_SAD , RGB_VAD ,
                                  _______ , _______ , _______ , _______ ,      _______ , _______ , _______ , _______
  ),
/* COD WARZONE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |WRZONE|COLMAK|QWERTY|      |      |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   I   |    |  SS   |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | PTT  |  M   | Space | /LvmAlt  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_WARZONE] = LAYOUT(
    KC_ESC , KC_1  , KC_2 , KC_3 , KC_4 , KC_5    ,                         XXXXXXX , _______ , _______ , _______ , _______ , WARZONE ,
    KC_TAB , KC_Q  , KC_W , KC_E , KC_R , KC_T    ,                         _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_LSFT, KC_A  , KC_S , KC_D , KC_F , KC_G    ,                         _______ , _______ , _______ , _______ , _______ , _______ ,
    KC_LCTL, KC_Z  , KC_X , KC_C , KC_V , KC_B    , KC_I   ,      _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                            KC_V , KC_M , KC_SPC  , KC_LALT,      _______ , _______ , _______ , _______
  ),
};

int RGB_current_mode;

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

void animate_luna(void);
const char *read_logo(void);

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // oled_write(read_logo(), false);
        // oled_write_P(PSTR("\n\n    "), false);
        // Host Keyboard Layer Status
        oled_write_P(PSTR("    Layer: "), false);
        switch (get_highest_layer(layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _LOWER:
                oled_write_P(PSTR("Lower\n"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("Raise\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            case _WARZONE:
                oled_write_P(PSTR("WARZONE\n"), false);
                break;
            case _COLEMAK:
                oled_write_P(PSTR("COLEMAK\n"), false);
                break;
            case _MOUSE:
                oled_write_P(PSTR("Navi\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }
        led_t led_state = host_keyboard_led_state();
        oled_write_P(led_state.num_lock ? PSTR("    NUM ") : PSTR("    "), false);
        oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
        oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
        oled_write_P(PSTR("\n\n"), false);

        char hue[4];
        char sat[4];
        char val[4];
        char wpm[4];

        sprintf(hue, "%d", rgblight_get_hue());
        sprintf(sat, "%d", rgblight_get_sat());
        sprintf(val, "%d", rgblight_get_val());
        sprintf(wpm, "%d", get_current_wpm());

        oled_write_P(PSTR("    Hue:  "), false);
        oled_write_ln(hue, false);
        oled_write_P(PSTR("    Sat:  "), false);
        oled_write_ln(sat, false);
        oled_write_P(PSTR("    Val:  "), false);
        oled_write_ln(val, false);
        oled_write_P(PSTR("    WPM:  "), false);
        oled_write_ln(wpm, false);
    } else {
        oled_write(read_logo(), false);
        animate_luna();
    }
}
#endif // OLED_DRIVER_ENABLE

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) { // Left
        switch (biton32(layer_state)) {
            case _QWERTY:
                // Move whole words. Hold shift to select while moving.
                if (clockwise) {
                    tap_code16(C(KC_RGHT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
                break;
            case _MOUSE:
                // Move mouse up and down
                if (clockwise) {
                    tap_code16(C(KC_MS_D));
                } else {
                    tap_code16(C(KC_MS_U));
                }
                break;
            default:
                // History scrubbing. For Adobe products, hold shift while moving
                // backward to go forward instead.
                if (clockwise) {
                    tap_code16(C(KC_Z));
                } else {
                    tap_code16(C(KC_Y));
                }
                break;
        }
    } else if (index == 1) { // Right
        switch (biton32(layer_state)) {
            case _QWERTY:
                // Scrolling with PageUp and PgDn.
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _MOUSE:
                // Move mouse left and right
                if (clockwise) {
                    tap_code16(C(KC_MS_R));
                } else {
                    tap_code16(C(KC_MS_L));
                }
                break;
            default:
                // Scroll through tabs
                if (clockwise) {
                    tap_code16(C(KC_TAB));
                } else {
                    tap_code16(S(C(KC_TAB)));
                }
                break;
        }
    }
}
#endif
