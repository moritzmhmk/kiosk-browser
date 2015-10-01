#include <signal.h>

#include <gtk/gtk.h>
#include <webkit/webkit.h>

void reload_browser(int);

static WebKitWebView* web_view;
static GtkWidget *window;
gchar* default_url = "https://github.com/pschultz/kiosk-browser/blob/master/README.md";

int main(int argc, char** argv) {
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

  web_view = WEBKIT_WEB_VIEW(webkit_web_view_new());

  signal(SIGHUP, reload_browser);

  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(web_view));

  if(argc > 1) {
    webkit_web_view_load_uri(web_view, argv[1]);
  }
  else {
    webkit_web_view_load_uri(web_view, default_url);
  }

  GdkScreen * screen = gtk_window_get_screen(GTK_WINDOW(window));
  gint width = gdk_screen_get_width(screen);
  gint height = gdk_screen_get_height(screen);
  gtk_window_resize(GTK_WINDOW(window), width, height);
  gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

  gtk_widget_show_all(window);
  gtk_main();

  return 0;
}

void reload_browser(int signum) {
  webkit_web_view_reload_bypass_cache(web_view);
}