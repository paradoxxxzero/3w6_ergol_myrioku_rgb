// Copyright 2025 Florian Mounier (https://florian.mounier.dev)

#include QMK_KEYBOARD_H

enum layers {
    L_BASE = 0, // QWERTY for Ergo-L kbd
    L_EXTRA,    // Translation for Bepolar layout with Ergo-L kbd
    L_TAP,
    L_BUTTON,
    L_NAV,
    L_MOUSE,
    L_MEDIA,
    L_NUM,
    L_SYM,
    L_FUN,
};

#define C_RDO KC_AGIN
#define C_PST KC_PSTE
#define C_CPY KC_COPY
#define C_CUT KC_CUT
#define C_UND KC_UNDO

#define TD_BOOT XXXXXXX

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_split_3x5_3(
KC_Q,              KC_W,               KC_E,               KC_R,               KC_T,                         KC_Y,               KC_U,               KC_I,               KC_O,               KC_P,    
LGUI_T(KC_A),      LALT_T(KC_S),       LCTL_T(KC_D),       LSFT_T(KC_F),       KC_G,                         KC_H,               LSFT_T(KC_J),       LCTL_T(KC_K),       LALT_T(KC_L),       LGUI_T(KC_SCLN),
LT(L_BUTTON,KC_Z), ALGR_T(KC_X),       KC_C,               KC_V,               KC_B,                         KC_N,               KC_M,               KC_COMM,            ALGR_T(KC_DOT),     LT(L_BUTTON,KC_SLSH),
                                    LT(L_MEDIA,KC_ESC), LT(L_NAV,KC_SPC),   LT(L_MOUSE,KC_TAB), LT(L_SYM,KC_ENT),   LT(L_NUM,KC_BSPC),  LT(L_FUN,KC_DEL)
    ),
    [L_EXTRA] = LAYOUT_split_3x5_3(
KC_B,              KC_U,               KC_R,               KC_E,               KC_T,                         KC_Z,               KC_V,               KC_I,               KC_H,               KC_Y,
LGUI_T(KC_A),      LALT_T(KC_SCLN),    LCTL_T(KC_L),       LSFT_T(KC_D),       KC_DOT,                       KC_W,               LSFT_T(KC_K),       LCTL_T(KC_S),       LALT_T(KC_J),       LGUI_T(KC_F),
LT(L_BUTTON,KC_C), ALGR_T(KC_P),       KC_X,               KC_N,               KC_SLSH,                      KC_O,               KC_Q,               KC_COMM,            ALGR_T(KC_M),       LT(L_BUTTON,KC_G),
                                    _______,            _______,            _______,            _______,            _______,            _______
    ),
    [L_TAP] = LAYOUT_split_3x5_3(
KC_Q,              KC_W,               KC_E,               KC_R,               KC_T,                         KC_Y,               KC_U,               KC_I,               KC_O,               KC_P,
KC_A,              KC_S,               KC_D,               KC_F,               KC_G,                         KC_H,               KC_J,               KC_K,               KC_L,               KC_QUOT,
KC_Z,              KC_X,               KC_C,               KC_V,               KC_B,                         KC_N,               KC_M,               KC_COMM,            KC_DOT,             KC_SLSH,
                                    KC_ESC,             KC_SPC,             KC_TAB,              KC_ENT,             KC_BSPC,            KC_DEL
    ),
    [L_BUTTON] = LAYOUT_split_3x5_3(
C_UND,             C_CUT,              C_CPY,              C_PST,              C_RDO,                        C_RDO,              C_PST,              C_CPY,              C_CUT,              C_UND,
KC_LGUI,           KC_LALT,            KC_LCTL,            KC_LSFT,            XXXXXXX,                      XXXXXXX,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,
C_UND,             C_CUT,              C_CPY,              C_PST,              C_RDO,                        C_RDO,              C_PST,              C_CPY,              C_CUT,              C_UND,
                                    KC_BTN3,            KC_BTN1,            KC_BTN2,             KC_BTN2,            KC_BTN1,            KC_BTN3
    ),
    [L_NAV] = LAYOUT_split_3x5_3(
TD_BOOT,           TT(L_TAP),          TT(L_EXTRA),        TT(L_BASE),         XXXXXXX,                      C_RDO,              C_PST,              C_CPY,              C_CUT,              C_UND,
KC_LGUI,           KC_LALT,            KC_LCTL,            KC_LSFT,            XXXXXXX,                      CW_TOGG,            KC_LEFT,            KC_DOWN,            KC_UP,              KC_RGHT,
XXXXXXX,           KC_ALGR,            TT(L_NUM),          TT(L_NAV),          XXXXXXX,                      KC_INS,             KC_HOME,            KC_PGDN,            KC_PGUP,            KC_END,
                                    XXXXXXX,            XXXXXXX,            XXXXXXX,             KC_ENT,             KC_BSPC,            KC_DEL   
    ),
    [L_MOUSE] = LAYOUT_split_3x5_3(
TD_BOOT,           TT(L_TAP),          TT(L_EXTRA),        TT(L_BASE),         XXXXXXX,                      C_RDO,              C_PST,              C_CPY,              C_CUT,              C_UND,
KC_LGUI,           KC_LALT,            KC_LCTL,            KC_LSFT,            XXXXXXX,                      XXXXXXX,            KC_MS_L,            KC_MS_D,            KC_MS_U,            KC_MS_R,
XXXXXXX,           KC_ALGR,            TT(L_SYM),          TT(L_MOUSE),        XXXXXXX,                      XXXXXXX,            KC_WH_L,            KC_WH_D,            KC_WH_U,            KC_WH_R,
                                    XXXXXXX,            XXXXXXX,            XXXXXXX,             KC_BTN2,            KC_BTN1,            KC_BTN3
    ),
    [L_MEDIA] = LAYOUT_split_3x5_3(
TD_BOOT,           TT(L_TAP),          TT(L_EXTRA),        TT(L_BASE),         XXXXXXX,                      RGB_TOG,            RGB_MOD,            RGB_HUI,            RGB_SAI,            RGB_VAI,
KC_LGUI,           KC_LALT,            KC_LCTL,            KC_LSFT,            XXXXXXX,                      XXXXXXX,            KC_MPRV,            KC_VOLD,            KC_VOLU,            KC_MNXT,
XXXXXXX,           KC_ALGR,            TT(L_FUN),          TT(L_MEDIA),        XXXXXXX,                      OU_AUTO,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                   XXXXXXX,            XXXXXXX,            XXXXXXX,             KC_MSTP,            KC_MPLY,            KC_MUTE
    ),
    [L_NUM] = LAYOUT_split_3x5_3(
KC_LBRC,           KC_7,               KC_8,               KC_9,               KC_RBRC,                      XXXXXXX,            TT(L_BASE),         TT(L_EXTRA),        TT(L_TAP),          TD_BOOT,
KC_SCLN,           KC_4,               KC_5,               KC_6,               KC_EQL,                       XXXXXXX,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,
KC_GRV,            KC_1,               KC_2,               KC_3,               KC_BSLS,                      XXXXXXX,            TT(L_NUM),          TT(L_NAV),          KC_ALGR,            XXXXXXX,
                                   KC_DOT,             KC_0,               KC_MINS,             XXXXXXX,            XXXXXXX,            XXXXXXX
    ),
    [L_SYM] = LAYOUT_split_3x5_3(
KC_LCBR,           KC_AMPR,            KC_ASTR,            KC_LPRN,            KC_RCBR,                      XXXXXXX,            TT(L_BASE),         TT(L_EXTRA),        TT(L_TAP),          TD_BOOT,
KC_COLN,           KC_DLR,             KC_PERC,            KC_CIRC,            KC_PLUS,                      XXXXXXX,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,
KC_TILD,           KC_EXLM,            KC_AT,              KC_HASH,            KC_PIPE,                      XXXXXXX,            TT(L_SYM),          TT(L_MOUSE),        KC_ALGR,            XXXXXXX,
                                   KC_LPRN,            KC_RPRN,            KC_UNDS,             XXXXXXX,            XXXXXXX,            XXXXXXX
    ),
    [L_FUN] = LAYOUT_split_3x5_3(
KC_F12,            KC_F7,              KC_F8,              KC_F9,              KC_PSCR,                      XXXXXXX,            TT(L_BASE),         TT(L_EXTRA),        TT(L_TAP),          TD_BOOT,
KC_F11,            KC_F4,              KC_F5,              KC_F6,              KC_SCRL,                      XXXXXXX,            KC_LSFT,            KC_LCTL,            KC_LALT,            KC_LGUI,
KC_F10,            KC_F1,              KC_F2,              KC_F3,              KC_PAUS,                      XXXXXXX,            TT(L_FUN),          TT(L_MEDIA),        KC_ALGR,            XXXXXXX,
                                   KC_APP,             KC_SPC,             KC_TAB,              XXXXXXX,            XXXXXXX,            XXXXXXX
    ),
};
// clang-format on
