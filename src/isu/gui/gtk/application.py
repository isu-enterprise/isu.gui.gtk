from isu.enterprise.configurator import createConfigurator
createConfigurator("development.ini")
import gi
gi.require_version('Gtk', '3.0')
from gi.repository import Gtk

from isu.enterprise.application.interfaces import IApplication
from zope.interface import implementer
from zope.component import getGlobalSiteManager, getUtility


@implementer(IApplication)
class Application(object):
    name = "ISU Enterprise Stub"
    category = "Development platform"
    vendor = None

    def __init__(self):
        pass

    def run(self):
        win = Gtk.Window()
        win.connect("delete-event", Gtk.main_quit)
        win.show_all()
        Gtk.main()


GSM = getGlobalSiteManager()
GSM.registerUtility(Application())


def main():
    app = getUtility(IApplication)
    return app.run()
