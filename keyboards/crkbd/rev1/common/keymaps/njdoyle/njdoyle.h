#pragma once

#include QMK_KEYBOARD_H

// LAYERS
#define _QWERTY      0
#define _DVORAK      1
#define _COLEMAK     2
#define _COLEMAK_DH  3
#define _WISH        4
#define _WORKMAN     5
#define _LOWER       6
#define _RAISE       7
#define _NAVIGATION  8
#define _FUNCTION    9

// KEY ALIASES
#define L_LOWER MO(_LOWER)
#define L_RAISE MO(_RAISE)
#define L_FUNC  MO(_FUNCTION)
#define DE_LEFT LCTL(KC_LEFT)
#define DE_RGHT LCTL(KC_RIGHT)
#define DE_MENU LCTL(KC_F2)
#define TB_LEFT SGUI(KC_LBRC)
#define TB_RGHT SGUI(KC_RBRC)
#define TB_NEW  LGUI(KC_T)
#define BR_BACK RGUI(KC_LBRC)
#define BR_FRWD RGUI(KC_RBRC)
#define BR_TOOL LCAG(KC_SLSH)
#define KC_____ KC_TRNS
#define KC_XXXX KC_NO

enum njdoyle_keycodes {
	// DEFAULT LAYERS
	D_QWRTY = SAFE_RANGE, // QWERTY
	D_DVRAK,              // Dvorak
	D_COLEM,              // Colemak
	D_C_DH ,              // Colemak Mod-DH
	D_WORKM,              // Workman
	D_WISH,              // Colemak Mod-DHm


	// EMOTES
	E_SMILE, // Smile
	E_SHRUG, // Shrug
	E_TFLIP, // Table Flip
	E_DERP , // Derp
	E_DAPRV, // Disapprove

	// UTILITY
	NJDOYLE_SAFE_RANGE
};

#include "njdoyle_layout_base.h"

#define NJDOYLE_LAYOUT_BASE \
	[_QWERTY] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, E, R, T, Y, U, I   , O  , P   , \
		A, S, D, F, G, H, J, K   , L  , SCLN, \
		Z, X, C, V, B, N, M, COMM, DOT, SLSH  \
	), \
	[_DVORAK] = NJDOYLE_LAYOUT_BASE_KC( \
		SLSH, COMM, DOT, P, Y, F, G, C, R, L, \
		A   , O   , E  , U, I, D, H, T, N, S, \
		SCLN, Q   , J  , K, X, B, M, W, V, Z  \
	), \
	[_COLEMAK] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, F, P, G, J, L, U   , Y  , SCLN, \
		A, R, S, T, D, H, N, E   , I  , O   , \
		Z, X, C, V, B, K, M, COMM, DOT, SLSH  \
	), \
	[_COLEMAK_DH] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, W, F, P, B, J, L, U   , Y  , SCLN, \
		A, R, S, T, G, K, N, E   , I  , O   , \
		Z, X, C, D, V, M, H, COMM, DOT, SLSH  \
	), \
	[_WORKMAN] = NJDOYLE_LAYOUT_BASE_KC( \
		Q, D, R, W, B, J, F, U   , P  , SCLN, \
		A, S, H, T, G, Y, N, E   , O  , I   , \
		Z, X, M, C, V, K, L, COMM, DOT, SLSH  \
	), \
	[_WISH] = NJDOYLE_LAYOUT_BASE_KC( \
		J, P, U, O, K, B, D, R   , F  ,Q, \
		W, I, E, A, DOT, G, T, N   , S  , H,   \
		SLSH, Y, SCLN, COMM, Z, V, M, L, C, X  \
	)


bool njdoyle_process_record_user(uint16_t, keyrecord_t*) __attribute__((weak));
