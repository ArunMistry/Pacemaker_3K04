from PyQt5.QtWidgets import QMainWindow

from custom_widgets.py_toggle import PyToggle
from views.dashboard import Ui_Dashboard


# Dashboard controller class that will handle all the events of the widgets in the dashboard view
class Dashboard(QMainWindow, Ui_Dashboard):
    def __init__(self, parent):
        super(Dashboard, self).__init__()
        self.username = None
        self.parent = parent
        self.toggle_device_status = PyToggle()
        self.toggle_device_status.setChecked(True)
        self.setupUi(self)

    # to initialize the dashboard view after login for a particular user
    def init(self, username):
        self.username = username
        self.label_welcome.setText("Welcome, {}".format(self.username))

    # function overriding, setupUi function setup call for widgets
    def setupUi(self, Dashboard):
        Ui_Dashboard.setupUi(self, Dashboard)

        # click handlers of the buttons in the ui
        self.btn_logout.clicked.connect(self.onclick_btn_logout)
        self.btn_settings.clicked.connect(self.onclick_btn_settings)

        self.horizontalLayout_device_status.addWidget(self.toggle_device_status)

    # click event of logout button
    def onclick_btn_logout(self):
        self.hide()
        self.parent.show()

    # click event of settings button
    def onclick_btn_settings(self):
        # the functionality for the settings button can be later implemented here
        pass
