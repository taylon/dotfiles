
void log_keyaction(uint16_t keycode, keyrecord_t *record) {
  uprintf("%s,%02d,%02d,%d,%d,%d,%d,%d\n",
    QMK_KEYBOARD,
    record->event.key.col,
    record->event.key.row,
    record->event.pressed,
    record->tap.count,
    record->tap.interrupted,
    keycode,
    biton32(layer_state)
  );
}
