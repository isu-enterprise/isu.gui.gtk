using Gtk;
using GLib;

namespace Icc.Gui {
	public bool DEBUG = true;
	public class Application : Gtk.Application {

		public Gtk.ApplicationWindow application_window;
		public Gtk.Builder ui_builder;

		protected string ui_filename;

		public Application(string filename = "") throws GLib.Error {
			// base();
			this.ui_builder=new Gtk.Builder();
			application_window = null;
			if (filename == "") {
				ui_filename = null;
			} else {
				load_ui_from_file(filename);
			};
		}

		public void load_ui_from_file(string filename) throws GLib.Error {
			this.ui_filename=filename;
			this.ui_builder.add_from_file(this.ui_filename);
			acquire_application_window();
			acquire_widgets(this, this.ui_builder);
		}

		public virtual signal void acquire_widgets (Application app, Gtk.Builder builder) {
			acquire_application_window();
		}

		private void acquire_application_window (){
			application_window = ui_builder.get_object("application_window") as Gtk.ApplicationWindow;
			application_window.destroy.connect(on_application_window_destroy);
		}

		public virtual void on_application_window_destroy() {
			if (DEBUG) {
				stdout.printf("Closing application\n");
			}
			Gtk.main_quit();
		}
	}
}
