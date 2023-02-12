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
#include <string.h>
#include <wayland-client.h>
#include <wayland-client-protocol.h>
#include <wayland-server.h>
#include <wayland-server-protocol.h>
#include <wayland-util.h>


#include <wlr/backend.h>
#include <wlr/backend/libinput.h>
#include <wlr/backend/drm.h>
#include <wlr/render/allocator.h>
#include <wlr/render/wlr_renderer.h>
#include <wlr/types/wlr_compositor.h>
#include <wlr/types/wlr_cursor.h>
#include <wlr/types/wlr_data_control_v1.h>
#include <wlr/types/wlr_data_device.h>
#include <wlr/types/wlr_drm_lease_v1.h>
#include <wlr/types/wlr_drm.h>
#include <wlr/types/wlr_export_dmabuf_v1.h>
#include <wlr/types/wlr_linux_dmabuf_v1.h>
#include <wlr/types/wlr_gamma_control_v1.h>
#include <wlr/types/wlr_idle.h>
#include <wlr/types/wlr_input_device.h>
#include <wlr/types/wlr_keyboard.h>
//#include <wlr/types/wlr_layer_shell_v1.h>
#include <wlr/types/wlr_matrix.h>
#include <wlr/types/wlr_output.h>
#include <wlr/types/wlr_output_layout.h>
#include <wlr/types/wlr_output_management_v1.h>
#include <wlr/types/wlr_pointer.h>
#include <wlr/types/wlr_presentation_time.h>
#include <wlr/types/wlr_primary_selection.h>
#include <wlr/types/wlr_primary_selection_v1.h>
#include <wlr/types/wlr_screencopy_v1.h>
#include <wlr/types/wlr_seat.h>
#include <wlr/types/wlr_server_decoration.h>
#include <wlr/types/wlr_viewporter.h>
#include <wlr/types/wlr_virtual_keyboard_v1.h>
#include <wlr/types/wlr_xcursor_manager.h>
#include <wlr/types/wlr_xdg_activation_v1.h>
//#include <wlr/types/wlr_xdg_decoration_v1.h>
//#include <wlr/types/wlr_xdg_output_v1.h>
//#include <wlr/types/wlr_xdg_shell.h>
#include <wlr/types/wlr_subcompositor.h>
#include <wlr/types/wlr_scene.h>
#include <wlr/types/wlr_output_damage.h>
#include <wlr/types/wlr_input_inhibitor.h>
#include <wlr/types/wlr_keyboard_shortcuts_inhibit_v1.h>
#include <wlr/types/wlr_virtual_pointer_v1.h>
#include <wlr/types/wlr_foreign_toplevel_management_v1.h>
#include <wlr/types/wlr_idle_inhibit_v1.h>
#include <wlr/util/log.h>
#include <wlr/util/region.h>
//#include <wlr/types/wlr_tablet_pad.h>
//#include <wlr/types/wlr_tablet_tool.h>
//#include <wlr/types/wlr_tablet_v2.h>
#include <xkbcommon/xkbcommon.h>
#include <wlr/render/egl.h>
#include <wlr/render/gles2.h>
#include <wlr/render/wlr_texture.h>
//#include <wlr/types/wlr_pointer_constraints_v1.h>
#include <wlr/types/wlr_relative_pointer_v1.h>
#include <wlr/interfaces/wlr_keyboard.h>
#include <wlr/types/wlr_xdg_foreign_registry.h>
#include <wlr/types/wlr_xdg_foreign_v1.h>
#include <wlr/types/wlr_xdg_foreign_v2.h>
#include <wlr/types/wlr_pointer_gestures_v1.h>
//#include <wlr/types/wlr_output_power_management_v1.h>
#include <wlr/types/wlr_input_method_v2.h>
#include <wlr/types/wlr_text_input_v3.h>
#include <wlr/types/wlr_touch.h>
#include <wlr/types/wlr_switch.h>
#include <wlr/config.h>
#include <wlr/backend/headless.h>
#include <wlr/backend/multi.h>
#include <wlr/backend/wayland.h>
#include <wlr/types/wlr_session_lock_v1.h>



