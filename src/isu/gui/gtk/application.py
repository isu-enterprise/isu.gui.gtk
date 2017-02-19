from isu.enterprise.configurator import createConfigurator
createConfigurator("development.ini")
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk


def main():
    win = Gtk.Window()
    win.connect("delete-event", Gtk.main_quit)
    win.show_all()
    Gtk.main()
