#include "njdoyle.h"

void njdoyle_input_switch(void) {
	register_code(KC_LCTL);
	register_code(KC_LALT);
	register_code(KC_LGUI);
	register_code(KC_LSFT);
	tap_code(KC_SPC);
	unregister_code(KC_LSFT);
	unregister_code(KC_LGUI);
	unregister_code(KC_LALT);
	unregister_code(KC_LCTL);
}

bool njdoyle_process_record_user(uint16_t keycode, keyrecord_t* record) {
	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	if (record->event.pressed) {
		switch (keycode) {
			// DEFAULT LAYERS
			case D_QWRTY: set_single_persistent_default_layer(_QWERTY     ); return false;
			case D_DVRAK: set_single_persistent_default_layer(_DVORAK     ); return false;
			case D_COLEM: set_single_persistent_default_layer(_COLEMAK    ); return false;
			case D_C_DH : set_single_persistent_default_layer(_COLEMAK_DH ); return false;
			case D_WISH:  set_single_persistent_default_layer(_WISH       ); return false;
			case D_WORKM: set_single_persistent_default_layer(_WORKMAN    ); return false;

			// EMOTES
			case E_SMILE: {
				njdoyle_input_switch();

				register_code(KC_LALT);
				tap_code(KC_3);
				tap_code(KC_0);
				tap_code(KC_C);
				tap_code(KC_4);
				unregister_code(KC_LALT);

				njdoyle_input_switch();
				return false;
			}
			case E_SHRUG: {
				njdoyle_input_switch();

				register_code(KC_LALT);
				tap_code(KC_0);
				tap_code(KC_0);
				tap_code(KC_A);
				tap_code(KC_F);
				unregister_code(KC_LALT);

				SEND_STRING("\\_(");

				register_code(KC_LALT);
				tap_code(KC_3);
				tap_code(KC_0);
				tap_code(KC_C);
				tap_code(KC_4);
				unregister_code(KC_LALT);

				SEND_STRING(")_/");

				register_code(KC_LALT);
				tap_code(KC_0);
				tap_code(KC_0);
				tap_code(KC_A);
				tap_code(KC_F);
				unregister_code(KC_LALT);

				njdoyle_input_switch();
				return false;
			}
			case E_TFLIP: {
				njdoyle_input_switch();

				tap_code16(KC_LPRN);

				register_code(KC_LALT);
				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_6);
				tap_code(KC_F);

				tap_code(KC_0);
				tap_code(KC_0);
				tap_code(KC_B);
				tap_code(KC_0);

				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_A);
				tap_code(KC_1);

				tap_code(KC_0);
				tap_code(KC_0);
				tap_code(KC_B);
				tap_code(KC_0);
				unregister_code(KC_LALT);

				tap_code16(KC_RPRN);

				register_code(KC_LALT);
				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_6);
				tap_code(KC_F);

				tap_code(KC_F);
				tap_code(KC_E);
				tap_code(KC_3);
				tap_code(KC_5);
				unregister_code(KC_LALT);

				tap_code(KC_SPC);

				register_code(KC_LALT);
				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_3);
				tap_code(KC_B);

				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_0);
				tap_code(KC_1);

				tap_code(KC_2);
				tap_code(KC_5);
				tap_code(KC_3);
				tap_code(KC_B);
				unregister_code(KC_LALT);

				njdoyle_input_switch();
				return false;
			}
			case E_DERP: {
				njdoyle_input_switch();

				register_code(KC_LALT);
				tap_code(KC_2);
				tap_code(KC_6);
				tap_code(KC_0);
				tap_code(KC_6);

				tap_code(KC_2);
				tap_code(KC_3);
				tap_code(KC_1);
				tap_code(KC_2);
				unregister_code(KC_LALT);

				SEND_STRING("(> _ <)");

				njdoyle_input_switch();
				return false;
			}
			case E_DAPRV: {
				njdoyle_input_switch();

				tap_code16(KC_LPRN);

				register_code(KC_LALT);
				tap_code(KC_0);
				tap_code(KC_C);
				tap_code(KC_A);
				tap_code(KC_0);
				unregister_code(KC_LALT);

				tap_code16(KC_UNDS);

				register_code(KC_LALT);
				tap_code(KC_0);
				tap_code(KC_C);
				tap_code(KC_A);
				tap_code(KC_0);
				unregister_code(KC_LALT);

				tap_code16(KC_RPRN);

				njdoyle_input_switch();
				return false;
			}
		}

	}

	return njdoyle_process_record_user(keycode, record);
}

