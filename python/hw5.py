import sys
from PyQt5.QtWidgets import QMainWindow, QLabel, QAction, QWidget, QVBoxLayout, QLineEdit, QPushButton, QApplication, QDialog, QFileDialog
import hw5_module as dbfuncs

globalusername = None

class LoginPanel(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Giriş Paneli")
        layout = QVBoxLayout()
        self.username_label = QLabel("Kullanıcı Adı:")
        self.username_input = QLineEdit()
        layout.addWidget(self.username_label)
        layout.addWidget(self.username_input)

        self.password_label = QLabel("Şifre:")
        self.password_input = QLineEdit()
        self.password_input.setEchoMode(QLineEdit.Password)
        layout.addWidget(self.password_label)
        layout.addWidget(self.password_input)

        self.error_label = QLabel("")
        
        layout.addWidget(self.error_label)

        self.login_button = QPushButton("Giriş Yap")
        self.login_button.clicked.connect(self.login)
        layout.addWidget(self.login_button)

        self.register_button = QPushButton("Kayıt Ol")
        self.register_button.clicked.connect(self.register)
        layout.addWidget(self.register_button)

        self.setLayout(layout)

    def login(self):
        username = self.username_input.text()
        password = self.password_input.text()
        if dbfuncs.check_login(username, password):
            self.error_label.setStyleSheet("color: green")
            self.error_label.setText("Giriş başarılı!")
            globalusername = username
            self.replace_login_with_menu()
        else:
            self.error_label.setStyleSheet("color: red")
            self.error_label.setText("Giriş başarısız!")

    def register(self):
        username = self.username_input.text()
        password = self.password_input.text()
        dbfuncs.register_user(username, password)
        self.error_label.setStyleSheet("color: green")
        self.error_label.setText("Kayıt başarılı!")

    def replace_login_with_menu(self):
        self.menu = MainMenu()
        self.menu.show()
        self.close()
    
class MainMenu(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("Ana Menü")
        self.setGeometry(100, 100, 400, 300)
        self.create_menu()

    def create_menu(self):
        menu = self.menuBar()
        compare_menu = menu.addMenu("Karşılaştır")
        compare_menu.addAction("Metni Jaccard Algortiması ile karşılaştır", self.show_jaccard_comparison)
        compare_menu.addAction("Metni Sinüs Algoritması Karşılaştır", self.show_cosine_comparison)
    
        # İşlemler menüsü
        operations_menu = menu.addMenu("İşlemler")
        refresh_password_menu = operations_menu.addMenu("Şifre Yenile")
        change_password_action = QAction("Değiştir", self)
        change_password_action.triggered.connect(self.show_update_password_dialog)
        refresh_password_menu.addAction(change_password_action)

        # Çıkış butonu
        exit_action = QAction("Çıkış", self)
        exit_action.triggered.connect(self.close)
        menu.addAction(exit_action)

    def show_update_password_dialog(self):
        dialog = UpdatePasswordDialog()
        dialog.exec_()

    def show_jaccard_comparison(self):
        dialog = TextComparator("Jaccard")
        dialog.setWindowTitle("Metni Jaccard Algortiması ile Karşılaştır")
        dialog.exec_()

    def show_cosine_comparison(self):
        dialog = TextComparator("Cosine")
        dialog.setWindowTitle("Metni Sinüs Algoritması ile Karşılaştır")
        dialog.exec_()

class UpdatePasswordDialog(QDialog):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Şifre Güncelleme Ekranı")

        layout = QVBoxLayout()

        label = QLabel("Yeni Şifre:")
        self.password_input = QLineEdit()
        layout.addWidget(label)
        layout.addWidget(self.password_input)

        self.update_button = QPushButton("Güncelle")
        self.update_button.clicked.connect(self.update_password)
        layout.addWidget(self.update_button)

        self.setLayout(layout)

    def update_password(self):
        new_password = self.password_input.text()
        dbfuncs.change_password(globalusername, new_password)
        print("Yeni Şifre:", new_password)
        self.close()

class TextComparator(QDialog):
    def __init__(self, algorithm):
        super().__init__()
        self.algorithm = algorithm
        self.setWindowTitle("Metin Karşılaştırma")
        
        self.file1_label = QLabel("Dosya 1:")
        self.file1_textbox = QLineEdit()
        self.file1_button = QPushButton("Dosya Seç")
        self.file1_button.clicked.connect(self.select_file1)

        self.file2_label = QLabel("Dosya 2:")
        self.file2_textbox = QLineEdit()
        self.file2_button = QPushButton("Dosya Seç")
        self.file2_button.clicked.connect(self.select_file2)

        self.compare_button = QPushButton("Karşılaştır")
        self.compare_button.clicked.connect(self.compare_texts)

        self.result_label = QLabel("Karşılaştırma Sonuçları:")

        layout = QVBoxLayout()
        layout.addWidget(self.file1_label)
        layout.addWidget(self.file1_textbox)
        layout.addWidget(self.file1_button)
        layout.addWidget(self.file2_label)
        layout.addWidget(self.file2_textbox)
        layout.addWidget(self.file2_button)
        layout.addWidget(self.compare_button)
        layout.addWidget(self.result_label)

        self.setLayout(layout)

    def select_file1(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "Dosya Seç", "", "Text Files (*.txt)")
        if file_path:
            self.file1_textbox.setText(file_path)

    def select_file2(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "Dosya Seç", "", "Text Files (*.txt)")
        if file_path:
            self.file2_textbox.setText(file_path)

    def compare_texts(self):
        file1_path = self.file1_textbox.text()
        file2_path = self.file2_textbox.text()

        try:
            with open(file1_path, 'r', encoding='utf-8') as file1:
                text1 = file1.read()

            with open(file2_path, 'r', encoding='utf-8') as file2:
                text2 = file2.read()

            if self.algorithm == "Jaccard":
                similarity = dbfuncs.jaccard_similarity(text1, text2)
                self.result_label.setText(f"Jaccard Benzerlik Oranı: {similarity}")
            elif self.algorithm == "Cosine":
                similarity = dbfuncs.cosine_similarity(text1, text2)
                self.result_label.setText(f"Cosine Benzerlik Oranı: {similarity}")
        except FileNotFoundError:
            self.result_label.setText("Dosya bulunamadı.")
        except Exception as e:
            self.result_label.setText(f"Bir hata oluştu: {str(e)}")

def main():
    dbfuncs.create_database()
    app = QApplication(sys.argv)
    window = LoginPanel()
    window.show()
    sys.exit(app.exec_())
    dbfuncs.close_database()

if __name__ == "__main__":
    main()
