/*#include <stdio.h>
#include <string.h>
#include <wayland-client.h>
#include <wayland-client-protocol.h>
#include <wayland-server.h>
#include <wayland-server-protocol.h>

//Connect to Display Server
struct wl_display *display = wl_display_connect(NULL);

//Create registry object
struct wl_registry *registry = wl_display_get_registry(display);

//Register global event listner
wl_registry_add_listener(registry, &registry_listener, NULL);

//Dispatch Display Server
wl_display_dispatch(display);

//Bind interface
struct wl_interface *interface = <protocol_interface>;
wl_registry_bind(registry, id, interface, version);

//Release Ressources
wl_registry_destroy(registry);
wl_display_disconnect(display);
*/

#include <stdio.h>
#include <wayland-client.h>
#include <string.h>

struct wl_display *display;
struct wl_registry *registry;
struct wl_compositor *compositor = NULL;

void registry_handle_global(void *data, struct wl_registry *registry, uint32_t name,
                            const char *interface, uint32_t version) {
  if (strcmp(interface, "wl_compositor") == 0) {
    compositor = wl_registry_bind(registry, name, &wl_compositor_interface, 1);
  }
}

const struct wl_registry_listener registry_listener = {
    registry_handle_global,
    NULL
};

int main(int argc, char **argv) {
  display = wl_display_connect(NULL);
  if (!display) {
    printf("Failed to connect to display\n");
    return 1;
  }

  registry = wl_display_get_registry(display);
  wl_registry_add_listener(registry, &registry_listener, NULL);
  wl_display_dispatch(display);
  wl_display_roundtrip(display);

  if (!compositor) {
    printf("Failed to bind to wl_compositor\n");
    return 1;
  }

  printf("Successfully connected to wl_compositor\n");
  wl_display_disconnect(display);

  return 0;
}
