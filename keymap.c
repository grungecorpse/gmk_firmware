/* to compile this code put the next command in QMK MSYS */
/* qmk compile -kb themadnoodle/noodlepad -km grungecorpse */


#include QMK_KEYBOARD_H


enum custom_keycodes {
    LAYER_INCREMENT = SAFE_RANGE,
    PASTE_A_LINK,
    M01,
    M02,
    M03,
    M04,
    M05,
    M06,
    M07,
    M08,
    M09,
    M11,
    M12,
    M13,
    M14,
    M15,
    M16,
    M17,
    M18,
    M19,
    M21,
    M22,
    M23,
    M24,
    M25,
    M26,
    M27,
    M28,
    M29
    /**/
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* LAYER 0
     * ,-----------------------.
     * |   <<  |  MUTE |  >>   |  ENCODER - PRESS (MUTE) / KNOB (VOLUME CONTROL)
     * |-------+-------+-------|
     * |  STOP |  PLAY | MEDIA |
     * |-------+-------+-------|
     * | CALC  | MAIL  | PC/FN |
     * `-----------------------'
     */

    [0] = LAYOUT_ortho_3x3(
      KC_MPRV, KC_MUTE, KC_MNXT,
      KC_MSTP, KC_MPLY, KC_MSEL,
      LAYER_INCREMENT, KC_MAIL, KC_MYCM
      ),


    /* LAYER 1
     * ,-----------------------.
     * | MODE+ |RGB TOG| MODE- |  ENCODER - PRESS (NA) / KNOB (Hue Control)
     * |-------+-------+-------|
     * |  SPD- |  SPD+ |Bright |
     * |-------+-------+-------|
     * |  SAT+ |  SAT- |       |
     * `-----------------------'
     */

    [1] = LAYOUT_ortho_3x3(
      KC_TRNS, KC_TRNS, KC_TRNS,
      LWIN(KC_1), LWIN(KC_2), LWIN(KC_3),
      LAYER_INCREMENT, LALT(KC_TAB), PASTE_A_LINK
      ),


    /* LAYER 2 (ENCODER)
     * ,-----------------------.
     * |       |       |       |  ENCODER - PRESS (NA) / KNOB (Arrow Left/Right)
     * |-------+-------+-------|
     * |       |       |       |
     * |-------+-------+-------|
     * |       |       |       |
     * `-----------------------'
     */

    [2] = LAYOUT_ortho_3x3(

      M27, M28, M29,
      M24, M25, M26,
      LAYER_INCREMENT, M22, M23
      )




      /*
      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS
      )
      */
     /*
      M27, M28, M29,
      M24, M25, M26,
      M21, M22, M23
      )
      */
};




//Switch between Leyers
    

int LAYER_LEVEL = 0;
 
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
      case LAYER_INCREMENT:
         if (record->event.pressed) {
             ++LAYER_LEVEL;
             if (LAYER_LEVEL > 2) {
                 LAYER_LEVEL = 0;
          } else {

          }
              layer_move(LAYER_LEVEL);
        } 
        break;
        return true;
/**/
    

    case PASTE_A_LINK:
      if (record->event.pressed) {
            //keydown event
            register_code(KC_LCTRL);
            register_code(KC_LSFT);
            register_code(KC_LEFT);
            unregister_code(KC_LCTRL);
            unregister_code(KC_LSFT);
            unregister_code(KC_LEFT);
            register_code(KC_LCTRL);
            register_code(KC_K);
            unregister_code(KC_LCTRL);
            unregister_code(KC_K);
            register_code(KC_LCTRL);
            register_code(KC_V);
            unregister_code(KC_LCTRL);
            unregister_code(KC_V);
            
            } else {
            //keyup event
            tap_code_delay(KC_ENTER, 80);
            } 
      break;
          }
          return true;
        
};


/* Colors for layers*/

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case 0:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case 1:
        rgblight_setrgb (0xFF,  0x00, 0xFF);
        break;
    
    case 2: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    }
  return state;
}

  
/*Sets the default color*/
  void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(85, 255, 255);
}

bool encoder_update_user(uint8_t index, bool clockwise) {

  switch (get_highest_layer(layer_state)) {
      case 1:
           if (clockwise) {
              tap_code(KC_RGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
      case 2:
          if (clockwise) {
              tap_code(KC_RGHT);
          } else {
              tap_code(KC_LEFT);
          }
          break;
      default:
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
          break;

  }
    return true;
}

/*
enum combo_events {
  LAYER_0,
  LAYER_1
};


const uint16_t PROGMEM LAYER_0_COMBO[] = {M25, M22, COMBO_END};
const uint16_t PROGMEM LAYER_1_COMBO[] = {M26, M23, COMBO_END};

combo_t key_combos[] = {
  [LAYER_0] = COMBO_ACTION(LAYER_0_COMBO),
  [LAYER_1] = COMBO_ACTION(LAYER_1_COMBO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case LAYER_0:
      if (pressed) {
        SEND_STRING("GUCCI");
      }
      break;

      case LAYER_1:
      if (pressed) {
        SEND_STRING("COOCHIE");
      }
      break;
  }
}
*/
/*
enum combos { 
  M08_M02_,
  M08_M03_,
  
};

const uint16_t PROGMEM m08_m02_[] = { M25, M22, COMBO_END};
const uint16_t PROGMEM m08_m03_[] = { M26, M23, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [M08_M02_] = COMBO(m08_m02_,COMBO_END),
  [M08_M03_] = COMBO(m08_m03_,COMBO_END),
  

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case M25_M22_:
      if (pressed) {
        layer_move(0);
      }
      break;

      case M26_M23_:
      if (pressed) {
        layer_move(1);
      }
      break;
  }
}

*/

enum combos { 
  M08_M02_,
  M08_M03_,
  M18_M11_,
  M18_M13_,
  M28_M21_,
  M28_M22_,
  
};

const uint16_t PROGMEM m08_m02_[] = { M08, M02, COMBO_END};
const uint16_t PROGMEM m08_m03_[] = { M08, M03, COMBO_END};
const uint16_t PROGMEM m18_m11_[] = { M18, M11, COMBO_END};
const uint16_t PROGMEM m18_m13_[] = { M18, M13, COMBO_END};
const uint16_t PROGMEM m28_m21_[] = { M28, M21, COMBO_END};
const uint16_t PROGMEM m28_m22_[] = { M28, M22, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [M08_M02_] = COMBO(m08_m02_,COMBO_END),
  [M08_M03_] = COMBO(m08_m03_,COMBO_END),
  [M18_M11_] = COMBO(m18_m11_,COMBO_END),
  [M18_M13_] = COMBO(m18_m13_,COMBO_END),
  [M28_M21_] = COMBO(m28_m21_,COMBO_END),
  [M28_M22_] = COMBO(m28_m22_,COMBO_END),
  
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {

    case M08_M02_:
      if (pressed) {
        layer_move(1);
      }
      break;

      case M08_M03_:
      if (pressed) {
        layer_move(2);
      }
      break;

      case M18_M11_:
      if (pressed) {
        layer_move(0);
      }
      break;

      case M18_M13_:
      if (pressed) {
        layer_move(2);
      }
      break;

       case M28_M21_:
      if (pressed) {
        layer_move(0);
      }
      break;

      case M28_M22_:
      if (pressed) {
        layer_move(1);
      }
      break;
  }
}

