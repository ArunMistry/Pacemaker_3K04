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

        self.comboBox_pacing_mode.currentTextChanged.connect(self.update_programmable_parameters)

        self.update_programmable_parameters()

        # self.horizontalLayout_device_status.addWidget(self.toggle_device_status)

    # click event of logout button
    def onclick_btn_logout(self):
        self.hide()
        self.parent.show()

    # click event of settings button
    def onclick_btn_settings(self):
        # the functionality for the settings button can be later implemented here
        pass

    def reset_parameters(self):
        self.frame_atrial_amplitude.hide()
        self.frame_atrial_pulses_width.hide()
        self.frame_atrial_refractory_period.hide()
        self.frame_post_ventricular_atrial_refractory_period.hide()
        self.frame_atrial_sensitivity.hide()
        self.frame_hysteresis.hide()
        self.frame_lower_rate_limit.hide()
        self.frame_rate_smoothing.hide()
        self.frame_upper_rate_limit.hide()
        self.frame_ventricular_amplitude.hide()
        self.frame_ventricular_pulse_width.hide()
        self.frame_ventricular_refractory_period.hide()
        self.frame_ventricular_sensitivity.hide()

    def update_programmable_parameters(self):
        self.reset_parameters()
        if self.comboBox_pacing_mode.currentText() == "VOO":
            self.label_pacing_mode.setStyleSheet("font: 12pt 'MS Shell Dlg 2';color:rgb(255, 0, 0);")
            self.frame_lower_rate_limit.show()
            self.frame_upper_rate_limit.show()
            self.frame_ventricular_amplitude.show()
            self.frame_ventricular_pulse_width.show()

        elif self.comboBox_pacing_mode.currentText() == "AOO":
            self.label_pacing_mode.setStyleSheet("font: 12pt 'MS Shell Dlg 2';color:rgb(0, 255, 0);")
            self.frame_lower_rate_limit.show()
            self.frame_upper_rate_limit.show()
            self.frame_atrial_amplitude.show()
            self.frame_atrial_pulses_width.show()

        elif self.comboBox_pacing_mode.currentText() == "AAI":
            self.label_pacing_mode.setStyleSheet("font: 12pt 'MS Shell Dlg 2';color:rgb(255, 170, 0);")
            self.frame_lower_rate_limit.show()
            self.frame_upper_rate_limit.show()
            self.frame_atrial_amplitude.show()
            self.frame_atrial_pulses_width.show()
            self.frame_atrial_sensitivity.show()
            self.frame_atrial_refractory_period.show()
            self.frame_post_ventricular_atrial_refractory_period.show()
            self.frame_hysteresis.show()
            self.frame_rate_smoothing.show()

        elif self.comboBox_pacing_mode.currentText() == "VVI":
            self.label_pacing_mode.setStyleSheet("font: 12pt 'MS Shell Dlg 2';color: rgb(0, 170, 255);")
            self.frame_lower_rate_limit.show()
            self.frame_upper_rate_limit.show()
            self.frame_ventricular_amplitude.show()
            self.frame_ventricular_pulse_width.show()
            self.frame_ventricular_sensitivity.show()
            self.frame_ventricular_refractory_period.show()
            self.frame_hysteresis.show()
            self.frame_rate_smoothing.show()




