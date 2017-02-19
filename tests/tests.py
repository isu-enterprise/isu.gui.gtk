
class TestsSimple:

    def setUp(self):
        pass

    def test_something(self):
        assert 1 + 1 == 2

    def tearDown(self):
        pass


class TestImportMainApp:

    def test_import(self):
        from isu.gui.gtk import application
        assert application.main
