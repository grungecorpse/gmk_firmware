/* to compile this code put the next command in QMK MSYS */
/* qmk compile -kb themadnoodle/noodlepad -km grungecorpse */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    PASTE_A_LINK = SAFE_RANGE,
    LAYER_0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
    LAYER_4,
    SCREENSHOT,
    COLOR_PICKER,
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
      LT(15, KC_MPRV), M08, M09,
      M04, M05, M06,
      M01, M02, M03
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
      LT(15, M17), M18, M19,
      M14, M15, M16,
      M11, M12, M13
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

    [2] = LAYOUT_ortho_3x3( // LAYER 3

      LT(15, M27), M28, M29,
      M24, M25, M26,
      M21, M22, M23
      ),


    

    [3] = LAYOUT_ortho_3x3( // LAYER 4

      LT(15,KC_NO), KC_NO, KC_NO,
      SCREENSHOT, COLOR_PICKER, KC_NO,
      KC_NO, KC_NO, KC_NO
      ),

    [4] = LAYOUT_ortho_3x3( // LAYER 4

      LT(15,KC_NO), KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO
      ),

    [15] = LAYOUT_ortho_3x3( // LAYER WITH LAYERS

      KC_NO, KC_NO, KC_NO,
      LAYER_3, LAYER_4, KC_NO,
      LAYER_0, LAYER_1, LAYER_2
      )



/*
      KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO,
      KC_NO, KC_NO, KC_NO
      )
      */
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

    /* LAYER 0
     * ,-----------------------.
     * |   <<  |  MUTE |  >>   |  ENCODER - PRESS (MUTE) / KNOB (VOLUME CONTROL)
     * |-------+-------+-------|
     * |  STOP |  PLAY | MEDIA |
     * |-------+-------+-------|
     * | CALC  | MAIL  | PC/FN |
     * `-----------------------'
     */


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {
/// Layer switching ///
      case LAYER_0:
          if (record->event.pressed) {
            
          } else {
            layer_move(0);
          }
          break;

      case LAYER_1:
          if (record->event.pressed) {
            
          } else {
            layer_move(1);
          }
          break;

      case LAYER_2:
          if (record->event.pressed) {
            
          } else {
            layer_move(2);
          }
          break;

      case LAYER_3:
          if (record->event.pressed) {
            
          } else {
            layer_move(3);
          }
          break;

      case LAYER_4:
          if (record->event.pressed) {
            
          } else {
            layer_move(4);
          }
          break;

/// Layer 0 Custom Keys ///
    
      case M01:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_F13);
          }
         break;

      case M02:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN(SS_LSFT("s")));
          }
         break;

      case M03:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MYCM);
          }
         break;

      case M04:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MSTP);
          }
         break;

      case M05:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MPLY);
          }
         break;

      case M06:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MSEL);
          }
         break;

      case M07:
         if (record->event.pressed) {
            register_code(KC_MPRV);
          } else {
            unregister_code(KC_MPRV);
          }
         break;

      case M08:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MUTE);
          }
         break;

      case M09:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_MNXT);
          }
         break;

/// Layer 1 Custom Keys ///
      case M11:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M12:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M13:
         /// Paste a link macro ///
         if (record->event.pressed) {
           SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
           SEND_STRING(SS_LCTL("k"));
           SEND_STRING(SS_DELAY(200) SS_LCTL("v") SS_DELAY(200));
           SEND_STRING(SS_TAP(X_ENTER));
          } 
          break;
    
      case M14: // Key 1
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN("1"));
          }
         break; 

      case M15:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN("2"));
          }
         break;

      case M16:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN("3"));
          }
         break;

      case M17:
         if (record->event.pressed) {
            SEND_STRING(SS_LWIN(SS_TAP(X_TAB)));
          } else {
            
          }
         break;

      case M18:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M19:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN("d"));
          }
         break;

/// Layer 2 Custom Keys ///

      case M21: // Key 1
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
            //rgblight_mode(10);
          }
         break; 

      case M22:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M23:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M24:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LCTL(SS_LWIN(SS_LALT("1"))));
          }
         break;

      case M25:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LCTL(SS_LWIN(SS_LALT("2"))));
          }
         break;

      case M26:
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LCTL(SS_LWIN(SS_LALT("3"))));
          }
         break;

      case M27:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M28:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

      case M29:
         if (record->event.pressed) {
            
          } else {
            tap_code(KC_NO);
          }
         break;

/// Layer 3 Custom Keys ///

      case SCREENSHOT: // Key 4
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN(SS_LSFT("S")));
          }
         break;

      case COLOR_PICKER: // Key 5
         if (record->event.pressed) {
            
          } else {
            SEND_STRING(SS_LWIN(SS_LSFT("C")));
          }
         break;


        } 
        return true;
};




///Sets the default color///
  void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(85, 255, 255);
}

/// Colors for layers///

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
    
    case 3: //  for any other layers, or the default layer
        rgblight_setrgb (201 , 60 , 0);
        break;

    case 4: //  for any other layers, or the default layer
        rgblight_setrgb (255 , 61 , 168);
        break;
        }

  return state;
}

  
///ENCODER///
bool encoder_update_user(uint8_t index, bool clockwise) {

  switch (get_highest_layer(layer_state)) {
      case 1:
          if (clockwise) {
              SEND_STRING(SS_LCTL(SS_TAP(X_TAB)));
          } else {
              SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_TAB))));
          }
          break;
      case 2:
          if (clockwise) {
              SEND_STRING(SS_LCTL(SS_LWIN(SS_TAP(X_RIGHT))));
          } else {
              SEND_STRING(SS_LCTL(SS_LWIN(SS_TAP(X_LEFT))));
          }
          break;
      case 3:
          if (clockwise) {
              tap_code(KC_RIGHT);
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