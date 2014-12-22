/**
 * Planned Functionality:
 * Have a menu for Pokemon, Moves, etc.
 * Pokemon menu:
 *   Sprite at left, number/name on right, misc info as subtitle
 * Pokemon Entry:
 *   Full sprite, description, type, etc.
 */

#include <pebble.h>
#define MAIN_MENU_SECTIONS 3

static Window *window;

static SimpleMenuLayer main_menu;
static char *main_menu_choices[] = {
  "Pokémon",
  "Types",
  "Moves",
  "Abilities",
  "Egg Groups"
};

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {

}

static void click_config_provider(void *context) {

}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  main_menu = simple_menu_layer_create(bounds, window, main_menu_sections, MAIN_MENU_SECTIONS, NULL)


}

static void window_unload(Window *window) {
  simple_menu_layer_destroy(main_menu);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
