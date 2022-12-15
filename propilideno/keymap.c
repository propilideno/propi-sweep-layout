#include QMK_KEYBOARD_H
#include "quantum.h"

// Make sure you use the US international layout in every device.
// On Linux, use US, intl., with dead keys.
enum layout_names {
    COLEMAK,
    COLEMAK_MAC,
    QWERTY,
    SYM,
    SYM2,
    EXT,
    EXT_MAC,
    FUNC,
    ACC,
    GAME_MOBA,
    GAME_FPS,
    NAV,
};

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
// #define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
// #define REPEAT LT(SYM, KC_NO)

uint8_t mod_state;
bool mac_state = false;

// Macros definitions for accented characters.
// This is necessary because not every accented character is available with AltGr.
enum custom_keycodes {
    A_TILDE = SAFE_RANGE,
    O_TILDE,
    A_CIRC,
    E_CIRC,
    O_CIRC,
    A_GRV,
    CIRC,
    QUOT,
    DQUO,
    A_ACUTE,
    E_ACUTE,
    I_ACUTE,
    O_ACUTE,
    U_ACUTE,
    C_ACUTE,
    TILDE,
    GRV,
    SWP_MAC,
    P1,
    P2,
    P3,
};

enum combos {
  AR_ESC,
  THUMB_ACC,
};

const uint16_t PROGMEM ar_combo[] = {KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM acc_combo[] = {KC_SPACE, MO(SYM), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [AR_ESC] = COMBO(ar_combo, KC_ESC),
  [THUMB_ACC] = COMBO(acc_combo, MO(ACC)),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_TILDE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_GRV);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_GRV);
                    unregister_code(KC_LSFT);
                    tap_code(KC_A);
                    set_mods(mod_state);
                }
            }
            break;

        case O_TILDE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_GRV);
                    tap_code(KC_O);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_GRV);
                    unregister_code(KC_LSFT);
                    tap_code(KC_O);
                    set_mods(mod_state);
                }
            }
            break;

        case A_CIRC:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    unregister_code(KC_LSFT);
                    tap_code(KC_A);
                    set_mods(mod_state);
                }
            }
            break;

        case E_CIRC:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    tap_code(KC_E);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    unregister_code(KC_LSFT);
                    tap_code(KC_E);
                    set_mods(mod_state);
                }
            }
            break;

        case O_CIRC:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    tap_code(KC_O);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    register_code(KC_LSFT);
                    tap_code(KC_6);
                    unregister_code(KC_LSFT);
                    tap_code(KC_O);
                    set_mods(mod_state);
                }
            }
            break;

        case A_GRV:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_GRV);
                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_GRV);
                    tap_code(KC_A);
                    set_mods(mod_state);
                }
            }
            break;

        case CIRC:
            if (record->event.pressed) {
                clear_mods();
                register_code(KC_LSFT);
                tap_code(KC_6);
                unregister_code(KC_LSFT);
                tap_code(KC_SPC);
                set_mods(mod_state);
            }
            break;

        case QUOT:
            if (record->event.pressed) {
                clear_mods();
                tap_code(KC_QUOT);
                tap_code(KC_SPC);
                set_mods(mod_state);
            }
            break;

        case DQUO:
            if (record->event.pressed) {
                clear_mods();
                register_code(KC_LSFT);
                tap_code(KC_QUOT);
                unregister_code(KC_LSFT);
                tap_code(KC_SPC);
                set_mods(mod_state);
            }
            break;

        case A_ACUTE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_QUOT);
                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_QUOT);
                    tap_code(KC_A);
                    set_mods(mod_state);
                }
            }
            break;

        case E_ACUTE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_QUOT);
                    register_code(KC_LSFT);
                    tap_code(KC_E);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_QUOT);
                    tap_code(KC_E);
                    set_mods(mod_state);
                }
            }
            break;

        case I_ACUTE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_QUOT);
                    register_code(KC_LSFT);
                    tap_code(KC_I);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_QUOT);
                    tap_code(KC_I);
                    set_mods(mod_state);
                }
            }
            break;

        case O_ACUTE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_QUOT);
                    register_code(KC_LSFT);
                    tap_code(KC_O);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_QUOT);
                    tap_code(KC_O);
                    set_mods(mod_state);
                }
            }
            break;

        case U_ACUTE:
            if (record->event.pressed) {
                if (get_mods() && MOD_MASK_SHIFT) {
                    clear_mods();
                    tap_code(KC_QUOT);
                    register_code(KC_LSFT);
                    tap_code(KC_U);
                    unregister_code(KC_LSFT);
                    set_mods(mod_state);
                } else {
                    clear_mods();
                    tap_code(KC_QUOT);
                    tap_code(KC_U);
                    set_mods(mod_state);
                }
            }
            break;

        case C_ACUTE:
            if (record->event.pressed) {
                register_code(KC_RALT);
                tap_code(KC_COMM);
                unregister_code(KC_RALT);
            }
            break;

        case TILDE:
            if (record->event.pressed) {
            send_string("~ ");
            }
            break;

        case GRV:
            if (record->event.pressed) {
            send_string("` ");
            }
            break;

        case SWP_MAC:
            if (record->event.pressed) {
                if(mac_state == false){
                    mac_state = true;
                }
                else{
                    mac_state = false;
                }
            }
            break;

        case P1:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                send_string("Estou indo!");
                tap_code(KC_ENT);
            }
            break;

        case P2:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                send_string("Ajuda aqui, por favor.");
                tap_code(KC_ENT);
            }
            break;

        case P3:
            if (record->event.pressed) {
                tap_code(KC_ENT);
                send_string("Entendido.");
                tap_code(KC_ENT);
            }
            break;

    }
    return true;
}

// Combos shouldn't trigger on the gaming layer.
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    if (layer_state_is(GAME_FPS) || layer_state_is(GAME_MOBA)) {
	    return false;
    }
    return true;
}

// Enable permissive hold only for some specific keys that are lesser prone to accidental activation
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return true;
        case LCTL_T(KC_SPC):
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

/*
Base alphas - COLEMAK DH
Base alphas - QWERTY
Symbols and access to other layers
Numbers and additional symbols
Function keys
Gamings layer - MOBA (Lol), FPS (Overwatch)
Accented characters
Navigation layer (arrow keys and mouse control) - DEVELOPMENT
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[COLEMAK] = LAYOUT(
    KC_Q, KC_W, KC_F, KC_P, KC_B,                                                   KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
    LALT_T(KC_A), LCTL_T(KC_R), LSFT_T(KC_S), LGUI_T(KC_T), KC_G,                   LALT_T(KC_M), LCTL_T(KC_N), LSFT_T(KC_E), LGUI_T(KC_I), KC_O, 
    KC_Z, KC_X, KC_C, KC_D, KC_V,                                                   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
        MO(EXT) , LSFT_T(KC_SPC),                                                   KC_SPC, MO(SYM)),

[COLEMAK_MAC] = LAYOUT(
    KC_Q, KC_W, KC_F, KC_P, KC_B,                                                   KC_J, KC_L, KC_U, KC_Y, KC_SCLN,
    LALT_T(KC_A), LCTL_T(KC_R), LSFT_T(KC_S), LGUI_T(KC_T), KC_G,                   LALT_T(KC_M), LCTL_T(KC_N), LSFT_T(KC_E), LGUI_T(KC_I), KC_O, 
    KC_Z, KC_X, KC_C, KC_D, KC_V,                                                   KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH,
    MO(EXT_MAC) , LSFT_T(KC_SPC),                                                   KC_SPC, MO(SYM)),

[QWERTY] = LAYOUT(
    KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I, KC_O, KC_P,
    KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K, KC_L, KC_SCLN,
    KC_Z, KC_X, KC_C, KC_V, KC_B,                   KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,
        MO(EXT), LSFT_T(KC_SPC),                    KC_SPC, MO(SYM)),

[SYM] = LAYOUT(
    KC_1, KC_2, KC_3, KC_4, KC_5,                 KC_6, KC_7, KC_8, KC_9, KC_0, 
    KC_LT, KC_LPRN, KC_LBRC, KC_LCBR, KC_DLR,     KC_EQL, KC_QUES, KC_QUOT, KC_PLUS, KC_ASTR, 
    KC_GT, KC_RPRN, KC_RBRC, KC_RCBR, KC_PERC,    KC_AT, KC_EXLM, KC_DQUO, KC_MINS, KC_SLSH, 
                          MO(FUNC), MO(SYM2),     KC_NO, KC_TRNS),

[SYM2] = LAYOUT(
    KC_GRV, KC_TILDE, KC_CIRC, KC_HASH, KC_NO,       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                 
    KC_PIPE, KC_AMPR, KC_BSLS, KC_UNDS, KC_NO,        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,     
                         KC_NO, KC_TRNS,              KC_NO, KC_TRNS),

[EXT] = LAYOUT(
    KC_ESC, LCTL(KC_W), KC_FIND, LSFT(KC_V), LSFT(KC_I),         KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_RALT,                 LCTL(KC_T), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_TAB,                  LCTL(KC_BSPC), KC_BSPC, KC_NO, KC_NO, KC_AGAIN,
                                KC_TRNS, KC_DEL,                 KC_ENT, MO(FUNC)),

[EXT_MAC] = LAYOUT(
    KC_ESC, LGUI(KC_W), KC_FIND, LSFT(KC_V), LSFT(KC_I),         KC_CAPS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_RALT,                 LGUI(KC_T), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_UNDO, KC_CUT, KC_COPY, KC_PASTE, KC_TAB,                  LALT(KC_BSPC), KC_BSPC, KC_NO, KC_NO, KC_AGAIN,
                                KC_TRNS, KC_DEL,                 KC_ENT, MO(FUNC)),

[FUNC] = LAYOUT(
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
    KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI, KC_RALT,         KC_F11, KC_F12, KC_PSCR, KC_NO,KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                   SWP_MAC, KC_NO, KC_NO, KC_NO, QK_BOOT,
                        KC_TRNS,KC_NO,                   KC_NO, KC_TRNS),


[ACC] = LAYOUT(
    KC_NO, A_ACUTE, E_ACUTE, O_ACUTE, I_ACUTE,       TO(QWERTY), KC_NO, KC_NO, KC_NO, KC_NO,
    A_GRV, A_CIRC, E_CIRC, O_CIRC, C_ACUTE,          TO(GAME_MOBA), TO(COLEMAK_MAC), KC_NO, KC_NO, KC_NO,
    KC_NO, A_TILDE, KC_NO, O_TILDE, U_ACUTE,         TO(GAME_FPS), TO(NAV), KC_NO, KC_NO, KC_NO,
                                KC_NO, KC_LSFT,        KC_NO, KC_NO),

[GAME_MOBA] = LAYOUT(
    KC_TAB, KC_1, KC_2, KC_D, KC_F,                  P1, P2, KC_NO, KC_NO, KC_NO,
    KC_4, KC_Q, KC_W, KC_E, KC_R,                    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ESC, KC_V, KC_S, KC_3, KC_B,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
              LCTL_T(KC_A), KC_SPC,                  TO(COLEMAK), TO(COLEMAK)),

[GAME_FPS] = LAYOUT(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R,                  P1, P2, KC_NO, KC_NO, KC_NO,
    KC_LSFT, KC_A, KC_S, KC_D, KC_F,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LCTL, KC_1, KC_2, KC_3, KC_4,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                       KC_C, KC_SPC,                 TO(COLEMAK), TO(COLEMAK)),

[NAV] = LAYOUT(
	KC_ESC, KC_BTN1, KC_MS_U, KC_BTN2, KC_BTN3,		 LCTL(KC_W), RCS(KC_TAB), LCTL(KC_TAB), RCS(KC_T), KC_LALT,
	KC_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP,		 KC_ENT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
	KC_LGUI, KC_WH_L, KC_WH_U, KC_WH_R, KC_PGDN,     RCS(KC_T), LCTL(KC_T), KC_ACL0, KC_ACL1, KC_ACL2,
					     KC_WH_D, TO(COLEMAK),		 KC_LCTL, KC_LSFT),

};