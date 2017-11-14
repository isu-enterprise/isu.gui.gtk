using Gtk;
using GLib;

namespace Icc.Gui {
	public bool DEBUG = true;
	public class Application : Gtk.Application {

		public Gtk.ApplicationWindow application_window {private set; get; }
		public Gtk.Builder ui_builder {private set; get;}
		public string? filename { construct set; get; }

		construct {
			if (DEBUG) {
				stdout.puts("Run construct\n");
			}
		}

		public Application(
			string? application_id = null,
			ApplicationFlags flags,
			string? filename = null) {
			Object(application_id: application_id,
				   flags: flags,
				   filename: filename
				);

			ui_builder = null;
			application_window = null;
		}

		public virtual signal void init_failure () {
			if (DEBUG) {
				stderr.printf("Abnormally closing application\n");
			}
			// Gtk.main_quit();
			quit();
		}

		protected override void startup() {
			try {
				stdout.puts("Setup\n");
				if (filename != null) {
					load_ui_from_file(filename);
				}
			} catch (GLib.Error e) {
				stderr.printf("Could not load user interface: %s\n", e.message);
				init_failure();
			}
		}

		protected override void activate() {
			if (application_window == null) {
				stderr.printf("No application window set up at startup!\n");
				init_failure();
			} else {
				application_window.show_all();
				add_window(application_window);
			}
		}

		public void load_ui_from_file(string filename) throws GLib.Error {
			this.filename=filename;
			this.ui_builder=new Gtk.Builder();

			ui_builder.add_from_file(this.filename);
			acquire_application_window();
			acquire_widgets(this, this.ui_builder);
		}

		public virtual void acquire_widgets (Application app, Gtk.Builder builder) {
			acquire_application_window();
		}

		private void acquire_application_window (){
			application_window = ui_builder.get_object("application_window") as Gtk.ApplicationWindow;
			application_window.destroy.connect(on_application_window_destroy);
		}

		public virtual void on_application_window_destroy() {
			if (DEBUG) {
				stdout.printf("Normally closing application\n");
			}
			quit();
		}
	}
}
