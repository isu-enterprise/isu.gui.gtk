/* icc_gui.c generated by valac 0.38.3, the Vala compiler
 * generated from icc_gui.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>


#define ICC_GUI_TYPE_APPLICATION (icc_gui_application_get_type ())
#define ICC_GUI_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), ICC_GUI_TYPE_APPLICATION, IccGuiApplication))
#define ICC_GUI_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), ICC_GUI_TYPE_APPLICATION, IccGuiApplicationClass))
#define ICC_GUI_IS_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ICC_GUI_TYPE_APPLICATION))
#define ICC_GUI_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), ICC_GUI_TYPE_APPLICATION))
#define ICC_GUI_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), ICC_GUI_TYPE_APPLICATION, IccGuiApplicationClass))

typedef struct _IccGuiApplication IccGuiApplication;
typedef struct _IccGuiApplicationClass IccGuiApplicationClass;
typedef struct _IccGuiApplicationPrivate IccGuiApplicationPrivate;
enum  {
	ICC_GUI_APPLICATION_0_PROPERTY,
	ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY,
	ICC_GUI_APPLICATION_NUM_PROPERTIES
};
static GParamSpec* icc_gui_application_properties[ICC_GUI_APPLICATION_NUM_PROPERTIES];
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
enum  {
	ICC_GUI_APPLICATION_INIT_FAILURE_SIGNAL,
	ICC_GUI_APPLICATION_ACQUIRE_WIDGETS_SIGNAL,
	ICC_GUI_APPLICATION_NUM_SIGNALS
};
static guint icc_gui_application_signals[ICC_GUI_APPLICATION_NUM_SIGNALS] = {0};

struct _IccGuiApplication {
	GtkApplication parent_instance;
	IccGuiApplicationPrivate * priv;
};

struct _IccGuiApplicationClass {
	GtkApplicationClass parent_class;
	void (*on_application_window_destroy) (IccGuiApplication* self);
	void (*init_failure) (IccGuiApplication* self);
};

struct _IccGuiApplicationPrivate {
	GtkApplicationWindow* _application_window;
};


extern gboolean icc_gui_DEBUG;
gboolean icc_gui_DEBUG = TRUE;
static gpointer icc_gui_application_parent_class = NULL;

GType icc_gui_application_get_type (void) G_GNUC_CONST;
#define ICC_GUI_APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), ICC_GUI_TYPE_APPLICATION, IccGuiApplicationPrivate))
void icc_gui_application_on_activate (IccGuiApplication* self);
GtkApplicationWindow* icc_gui_application_get_application_window (IccGuiApplication* self);
void icc_gui_application_load_ui_from_file (IccGuiApplication* self, const gchar* filename, GError** error);
void icc_gui_application_on_application_window_destroy (IccGuiApplication* self);
static void icc_gui_application_real_on_application_window_destroy (IccGuiApplication* self);
IccGuiApplication* icc_gui_application_new (void);
IccGuiApplication* icc_gui_application_construct (GType object_type);
void icc_gui_application_set_application_window (IccGuiApplication* self, GtkApplicationWindow* value);
static void icc_gui_application_real_init_failure (IccGuiApplication* self);
static GObject * icc_gui_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void _icc_gui_application_on_activate_g_application_activate (GApplication* _sender, gpointer self);
static void icc_gui_application_finalize (GObject * obj);
static void _vala_icc_gui_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_icc_gui_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


void icc_gui_application_on_activate (IccGuiApplication* self) {
	GtkApplicationWindow* _tmp0_;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->_application_window;
	if (_tmp0_ == NULL) {
		FILE* _tmp1_;
		_tmp1_ = stderr;
		fprintf (_tmp1_, "No application window set up at startup!\n");
		g_signal_emit (self, icc_gui_application_signals[ICC_GUI_APPLICATION_INIT_FAILURE_SIGNAL], 0);
	} else {
		GtkApplicationWindow* _tmp2_;
		GtkApplicationWindow* _tmp3_;
		_tmp2_ = self->priv->_application_window;
		gtk_widget_show_all ((GtkWidget*) _tmp2_);
		_tmp3_ = self->priv->_application_window;
		gtk_application_add_window ((GtkApplication*) self, (GtkWindow*) _tmp3_);
	}
}


void icc_gui_application_load_ui_from_file (IccGuiApplication* self, const gchar* filename, GError** error) {
	GtkBuilder* builder = NULL;
	GtkBuilder* _tmp0_;
	const gchar* _tmp1_;
	GError * _inner_error_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (filename != NULL);
	_tmp0_ = gtk_builder_new ();
	builder = _tmp0_;
	_tmp1_ = filename;
	gtk_builder_add_from_file (builder, _tmp1_, &_inner_error_);
	if (G_UNLIKELY (_inner_error_ != NULL)) {
		g_propagate_error (error, _inner_error_);
		_g_object_unref0 (builder);
		return;
	}
	g_signal_emit (self, icc_gui_application_signals[ICC_GUI_APPLICATION_ACQUIRE_WIDGETS_SIGNAL], 0, builder);
	_g_object_unref0 (builder);
}


static void icc_gui_application_real_on_application_window_destroy (IccGuiApplication* self) {
	gboolean _tmp0_;
	_tmp0_ = icc_gui_DEBUG;
	if (_tmp0_) {
		FILE* _tmp1_;
		_tmp1_ = stdout;
		fprintf (_tmp1_, "Normally closing application\n");
	}
	g_application_quit ((GApplication*) self);
}


void icc_gui_application_on_application_window_destroy (IccGuiApplication* self) {
	g_return_if_fail (self != NULL);
	ICC_GUI_APPLICATION_GET_CLASS (self)->on_application_window_destroy (self);
}


IccGuiApplication* icc_gui_application_construct (GType object_type) {
	IccGuiApplication * self = NULL;
	self = (IccGuiApplication*) g_object_new (object_type, NULL);
	return self;
}


IccGuiApplication* icc_gui_application_new (void) {
	return icc_gui_application_construct (ICC_GUI_TYPE_APPLICATION);
}


GtkApplicationWindow* icc_gui_application_get_application_window (IccGuiApplication* self) {
	GtkApplicationWindow* result;
	GtkApplicationWindow* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_application_window;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void icc_gui_application_set_application_window (IccGuiApplication* self, GtkApplicationWindow* value) {
	g_return_if_fail (self != NULL);
	if (icc_gui_application_get_application_window (self) != value) {
		GtkApplicationWindow* _tmp0_;
		GtkApplicationWindow* _tmp1_;
		_tmp0_ = value;
		_tmp1_ = _g_object_ref0 (_tmp0_);
		_g_object_unref0 (self->priv->_application_window);
		self->priv->_application_window = _tmp1_;
		g_object_notify_by_pspec ((GObject *) self, icc_gui_application_properties[ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY]);
	}
}


static void icc_gui_application_real_init_failure (IccGuiApplication* self) {
	FILE* _tmp0_;
	_tmp0_ = stderr;
	fputs ("Exit on failure.\n", _tmp0_);
	g_application_quit ((GApplication*) self);
}


static void _icc_gui_application_on_activate_g_application_activate (GApplication* _sender, gpointer self) {
	icc_gui_application_on_activate ((IccGuiApplication*) self);
}


static GObject * icc_gui_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	IccGuiApplication * self;
	gboolean _tmp0_;
	parent_class = G_OBJECT_CLASS (icc_gui_application_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ICC_GUI_TYPE_APPLICATION, IccGuiApplication);
	_tmp0_ = icc_gui_DEBUG;
	if (_tmp0_) {
		FILE* _tmp1_;
		_tmp1_ = stdout;
		fputs ("Run construct\n", _tmp1_);
	}
	g_signal_connect_object ((GApplication*) self, "activate", (GCallback) _icc_gui_application_on_activate_g_application_activate, self, 0);
	return obj;
}


static void icc_gui_application_class_init (IccGuiApplicationClass * klass) {
	icc_gui_application_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (IccGuiApplicationPrivate));
	((IccGuiApplicationClass *) klass)->on_application_window_destroy = (void (*) (IccGuiApplication *)) icc_gui_application_real_on_application_window_destroy;
	((IccGuiApplicationClass *) klass)->init_failure = icc_gui_application_real_init_failure;
	G_OBJECT_CLASS (klass)->get_property = _vala_icc_gui_application_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_icc_gui_application_set_property;
	G_OBJECT_CLASS (klass)->constructor = icc_gui_application_constructor;
	G_OBJECT_CLASS (klass)->finalize = icc_gui_application_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY, icc_gui_application_properties[ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY] = g_param_spec_object ("application-window", "application-window", "application-window", gtk_application_window_get_type (), G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	icc_gui_application_signals[ICC_GUI_APPLICATION_INIT_FAILURE_SIGNAL] = g_signal_new ("init-failure", ICC_GUI_TYPE_APPLICATION, G_SIGNAL_RUN_LAST, G_STRUCT_OFFSET (IccGuiApplicationClass, init_failure), NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	icc_gui_application_signals[ICC_GUI_APPLICATION_ACQUIRE_WIDGETS_SIGNAL] = g_signal_new ("acquire-widgets", ICC_GUI_TYPE_APPLICATION, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, gtk_builder_get_type ());
}


static void icc_gui_application_instance_init (IccGuiApplication * self) {
	self->priv = ICC_GUI_APPLICATION_GET_PRIVATE (self);
}


static void icc_gui_application_finalize (GObject * obj) {
	IccGuiApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, ICC_GUI_TYPE_APPLICATION, IccGuiApplication);
	_g_object_unref0 (self->priv->_application_window);
	G_OBJECT_CLASS (icc_gui_application_parent_class)->finalize (obj);
}


GType icc_gui_application_get_type (void) {
	static volatile gsize icc_gui_application_type_id__volatile = 0;
	if (g_once_init_enter (&icc_gui_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (IccGuiApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) icc_gui_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (IccGuiApplication), 0, (GInstanceInitFunc) icc_gui_application_instance_init, NULL };
		GType icc_gui_application_type_id;
		icc_gui_application_type_id = g_type_register_static (gtk_application_get_type (), "IccGuiApplication", &g_define_type_info, 0);
		g_once_init_leave (&icc_gui_application_type_id__volatile, icc_gui_application_type_id);
	}
	return icc_gui_application_type_id__volatile;
}


static void _vala_icc_gui_application_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	IccGuiApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, ICC_GUI_TYPE_APPLICATION, IccGuiApplication);
	switch (property_id) {
		case ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY:
		g_value_set_object (value, icc_gui_application_get_application_window (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_icc_gui_application_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	IccGuiApplication * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, ICC_GUI_TYPE_APPLICATION, IccGuiApplication);
	switch (property_id) {
		case ICC_GUI_APPLICATION_APPLICATION_WINDOW_PROPERTY:
		icc_gui_application_set_application_window (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



