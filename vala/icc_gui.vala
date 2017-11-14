using Gtk;
using GLib;

namespace Icc.Gui {
	public bool DEBUG = true;
	public class Application : Gtk.Application {

		public Gtk.ApplicationWindow application_window {private set; get; }

		construct {
			if (DEBUG) {
				stdout.puts("Run construct\n");
			}
			startup.connect(on_startup);
			activate.connect(on_activate);
		}

		public virtual signal void init_failure() {
			stderr.puts("Exit on failure.\n");
			quit();
		}

		protected void on_startup() {
			application_window = new Gtk.ApplicationWindow(this);
			application_window.destroy.connect(on_application_window_destroy);
		}

		protected  void on_activate() {
			if (application_window == null) {
				stderr.printf("No application window set up at startup!\n");
				init_failure();
			} else {
				application_window.show_all();
				add_window(application_window);
			}
		}

		public void load_ui_from_file(string filename) throws GLib.Error{
			var builder=new Gtk.Builder();
			builder.add_from_file(filename);
			acquire_widgets(this, builder);
		}

		public signal void acquire_widgets (Application app, Gtk.Builder builder);

		public virtual void on_application_window_destroy() {
			if (DEBUG) {
				stdout.printf("Normally closing application\n");
			}
			quit();
		}
	}
}
