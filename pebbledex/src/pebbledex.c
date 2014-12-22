/**
 * Planned Functionality:
 * Have a menu for Pokemon, Moves, etc.
 * Pokemon menu:
 *   Sprite at left, number/name on right, misc info as subtitle
 * Pokemon Entry:
 *   Full sprite, description, type, etc.
 */

#include <pebble.h>
/* Main Menu */
#define MAIN_MENU_SECTIONS 2
#define MM_POKEMENU_ITEMS 1
#define MM_OTHER_ITEMS 3

static Window *s_main_window;

static SimpleMenuLayer *main_menu;

// first section of the main menu
static char *mm_pokemenu_names[MM_POKEMENU_ITEMS] = {
  "Pokémon"
};

// second section of the main menu
static char *mm_other_names[MM_OTHER_ITEMS] = {
  "Types",
  "Moves",
  "Abilities"
};

static SimpleMenuSection mm_sections[MAIN_MENU_SECTIONS];
static SimpleMenuItem mm_pokemenu[MM_POKEMENU_ITEMS];
static SimpleMenuItem mm_other[MM_OTHER_ITEMS];


static void setup_mm_items() {
  for(int i = 0; i < MM_POKEMENU_ITEMS; i++) {
    mm_pokemenu[i] = (SimpleMenuItem){
      .title = mm_pokemenu_names[i]
    };
  }
  for(int i = 0; i < MM_OTHER_ITEMS; i++) {
    mm_other[i] = (SimpleMenuItem){
      .title = mm_other_names[i]
    };
  }
}

static void setup_mm_sections() {
  mm_sections[0] = (SimpleMenuSection){
    .title = "Pokémon Data",
    .items = mm_pokemenu,
    .num_items = MM_POKEMENU_ITEMS
  };
  mm_sections[1] = (SimpleMenuSection){
    .title = "Attribute Data",
    .items = mm_other,
    .num_items = MM_OTHER_ITEMS
  };
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(s_main_window);
  GRect bounds = layer_get_bounds(window_layer);

  main_menu = simple_menu_layer_create(bounds, window, mm_sections, MAIN_MENU_SECTIONS, NULL);
  layer_add_child(window_layer, simple_menu_layer_get_layer(main_menu));
}

static void main_window_unload(Window *window) {

}

/* Initializer/Deinitializer */

static void init(void) {
  setup_mm_items();
  setup_mm_sections();

  s_main_window = window_create();

  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  static bool animated = true;
  window_stack_push(s_main_window, animated);
}

static void deinit(void) {
  simple_menu_layer_destroy(main_menu);
  window_destroy(s_main_window);
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", s_main_window);

  app_event_loop();
  deinit();
}
