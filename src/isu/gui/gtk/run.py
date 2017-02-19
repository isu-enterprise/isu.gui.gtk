#!/usr/bin/env python3
import isu.gui.gtk.application
from zope.component import getUtility
from isu.enterprise.application.interfaces import IApplication

app = getUtility(IApplication)
app.run()
