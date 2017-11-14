/* icc_gui.h generated by valac 0.38.3, the Vala compiler, do not modify */


#ifndef __ICC_GUI_H__
#define __ICC_GUI_H__

#include <glib.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>

G_BEGIN_DECLS


#define ICC_GUI_TYPE_APPLICATION (icc_gui_application_get_type ())
#define ICC_GUI_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ICC_GUI_TYPE_APPLICATION, IccGuiApplication))
#define ICC_GUI_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ICC_GUI_TYPE_APPLICATION, IccGuiApplicationClass))
#define ICC_GUI_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ICC_GUI_TYPE_APPLICATION))
#define ICC_GUI_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ICC_GUI_TYPE_APPLICATION))
#define ICC_GUI_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ICC_GUI_TYPE_APPLICATION, IccGuiApplicationClass))

typedef struct _IccGuiApplication IccGuiApplication;
typedef struct _IccGuiApplicationClass IccGuiApplicationClass;
typedef struct _IccGuiApplicationPrivate IccGuiApplicationPrivate;

struct _IccGuiApplication {
	GtkApplication parent_instance;
	IccGuiApplicationPrivate * priv;
};

struct _IccGuiApplicationClass {
	GtkApplicationClass parent_class;
	void (*acquire_widgets) (IccGuiApplication* self, IccGuiApplication* app, GtkBuilder* builder);
	void (*on_application_window_destroy) (IccGuiApplication* self);
	void (*init_failure) (IccGuiApplication* self);
};


extern gboolean icc_gui_DEBUG;
GType icc_gui_application_get_type (void) G_GNUC_CONST;
IccGuiApplication* icc_gui_application_new (const gchar* application_id, GApplicationFlags flags, const gchar* filename);
IccGuiApplication* icc_gui_application_construct (GType object_type, const gchar* application_id, GApplicationFlags flags, const gchar* filename);
void icc_gui_application_load_ui_from_file (IccGuiApplication* self, const gchar* filename, GError** error);
void icc_gui_application_acquire_widgets (IccGuiApplication* self, IccGuiApplication* app, GtkBuilder* builder);
void icc_gui_application_on_application_window_destroy (IccGuiApplication* self);
GtkApplicationWindow* icc_gui_application_get_application_window (IccGuiApplication* self);
GtkBuilder* icc_gui_application_get_ui_builder (IccGuiApplication* self);
const gchar* icc_gui_application_get_filename (IccGuiApplication* self);
void icc_gui_application_set_filename (IccGuiApplication* self, const gchar* value);


G_END_DECLS

#endif
