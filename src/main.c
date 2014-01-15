#include "pebble.h"
#include "second.h"
#include "algebra.h"
#include "geometry.h"
#include "trigonometry.h"
#include "calc.h"
#include "biology.h"
#include "physics.h"
	
#define NUM_MATH_MENU_ITEMS 6
#define NUM_MENU_SECTIONS 2
#define NUM_SCIENCE_MENU_ITEMS 2
static Window *window;

static SimpleMenuLayer *simple_menu_layer;

static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];

//Menu Items
static SimpleMenuItem math_menu_items[NUM_MATH_MENU_ITEMS];
static SimpleMenuItem science_menu_items[NUM_SCIENCE_MENU_ITEMS];




//Callbacks

static void menu_select_callback(int index, void *ctx) {
  show_second_menu();
}
static void algebra_select_callback(int index, void *ctx) {
  show_algebra_menu();
}
static void geometry_select_callback(int index, void *ctx) {
  show_geometry_menu();
}
static void trig_select_callback(int index, void *ctx) {
  show_trig_menu();
}
static void calc_select_callback(int index, void *ctx) {
  show_calc_menu();
}
static void bio_select_callback(int index, void *ctx) {
  show_bio_menu();
}
static void physics_select_callback(int index, void *ctx) {
  show_physics_menu();
}


static void window_load(Window *window) {

  int num_a_items = 0;

  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Algebra",
	.subtitle = "Algebraic Equations",
    .callback = algebra_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Geometry",
	.subtitle = "Geometric Equations",
    .callback = geometry_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Trigonometry",
	.subtitle = "Trig Equations",
    .callback = trig_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Calculus",
	.subtitle = "Calc Equations",
    .callback = calc_select_callback,
  };
  science_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Biology Equations",
	.subtitle = "Bio Equations",
    .callback = bio_select_callback,
  };
  science_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Physics Equations",
	.subtitle = "Yay Physics!",
    .callback = physics_select_callback,
  };
  menu_sections[0] = (SimpleMenuSection){
  .title ="Categories",
  .num_items = NUM_MATH_MENU_ITEMS,
  .items = math_menu_items,
  };
  menu_sections[1] = (SimpleMenuSection){
  .title ="Categories",
  .num_items = NUM_SCIENCE_MENU_ITEMS,
  .items = science_menu_items,
  };
	
  // Now we prepare to initialize the simple menu layer
  // We need the bounds to specify the simple menu layer's viewport size
  // In this case, it'll be the same as the window's
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections,NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

// Deinitialize resources on window unload that were initialized on window load
static void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);
}

int main(void) {
  window = window_create();

  // Setup the window handlers
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);

  app_event_loop();

  window_destroy(window);
}
