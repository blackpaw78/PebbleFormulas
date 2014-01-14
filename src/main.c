#include "pebble.h"
//Arrays
#define NUM_MENU_SECTIONS 3
#define NUM_MATH_MENU_ITEMS 4
#define NUM_SCIENCE_MENU_ITEMS 3
#define NUM_THIRD_MENU_ITEMS 0

static Window *window;
static Window *AlgebraWindow;
static Window *window2;
static Layer *layer2;

static SimpleMenuLayer *simple_menu_layer;

// Sections for types of Equations
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
//Menu Items for Each Section
static SimpleMenuItem math_menu_items[NUM_MATH_MENU_ITEMS];

static SimpleMenuItem science_menu_items[NUM_SCIENCE_MENU_ITEMS];

static SimpleMenuItem third_menu_items[NUM_THIRD_MENU_ITEMS];

void AlgebraWindow_unload(Window *window) {
  layer_destroy(layer2);
  window_destroy(window2);

}
static void update_layer_callback(Layer *layer, GContext* ctx) {
  graphics_context_set_text_color(ctx, GColorBlack);
}
//Callbacks for Functionality
static void algebra_select_callback(int index, void *ctx) { 
	  AlgebraWindow = window_create();

  // Setup the window handlers
  window_set_window_handlers(AlgebraWindow, (WindowHandlers) {
    .unload = AlgebraWindow_unload,
  });
	
  Layer *window_layer = window_get_root_layer(window2);
  GRect bounds = layer_get_frame(window_layer);
  layer2 = layer_create(bounds);
  layer_set_update_proc(layer2, update_layer_callback);
  layer_add_child(window_layer, layer2);

  window_stack_push(AlgebraWindow, true /* Animated */);
}
static void window_load(Window *window) {
  int num_a_items = 0;
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Algebra",
        .subtitle = "Basic Alegbra Equations",
        .callback = algebra_select_callback,
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Geometry",
    .subtitle = "Geometric Equations",
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Trigonometry",
    .subtitle = "Trig Equations",
  };
  math_menu_items[num_a_items++] = (SimpleMenuItem){
    .title = "Calculus",
    .subtitle = "I Love Calc",
  };
        
  // Science Menu Area

  science_menu_items[0] = (SimpleMenuItem){
    .title = "Biology",
    .subtitle = "Biological Equations",
  };
  science_menu_items[1] = (SimpleMenuItem){
    .title = "Chemistry",
    .subtitle = "Chemical Equations",
  };        
  science_menu_items[2] = (SimpleMenuItem){
    .title = "Physics",
    .subtitle = "Physics Equations",
  };
  // Bind the menu items to the corresponding menu sections
  menu_sections[0] = (SimpleMenuSection){
        .title ="Math Equations",
    .num_items = NUM_MATH_MENU_ITEMS,
          .items = math_menu_items,
  };
  menu_sections[1] = (SimpleMenuSection){
    // Menu sections can also have titles as well
    .title = "Science Equations",
    .num_items = NUM_SCIENCE_MENU_ITEMS,
    .items = science_menu_items,
  };
  menu_sections[2] = (SimpleMenuSection){
                .title = "More To Come",
                .num_items = NUM_THIRD_MENU_ITEMS,
                .items = third_menu_items,

        };

  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  simple_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  layer_add_child(window_layer, simple_menu_layer_get_layer(simple_menu_layer));
}

void window_unload(Window *window) {
  simple_menu_layer_destroy(simple_menu_layer);

}

int main(void) {
  window = window_create();

  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true /* Animated */);

  app_event_loop();

  window_destroy(window);
}